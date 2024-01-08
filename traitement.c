#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	printf("Content-type:text/html\n\n");
	printf("<html>\n");
	printf("<head>\n");
	printf("<meta charset=\"utf-8\">\n");
	printf("<title>Premiere etape: r&eacute;sultat de votre requete de creation de site web(Fichier de configuration)</title>\n");
	printf("</head>");
	printf("<body>");

	
	char*query=getenv("QUERY_STRING");
	char server[100],dir[100],location[200],option[50],name[100];
	sscanf(query,"%*[^=]=%[^&]&%*[^=]=%[^&]&%*[^=]=%[^&]&%*[^=]=%[^&]&%*[^=]=%[^\n]",server,dir,location,option,name);
	printf("%s %s %s %s %s",server,dir,location,option,name);
	FILE*fp=fopen("/home/tsoa/tmp.txt","w");
	FILE*fp1=fopen("/etc/hosts","a+");
	//system(mkdirValue);
	if(strcmp(option,"on")==0){
		fprintf(fp,"<VirtualHost *:80>\n\tServerName %s\n\tServerAdmin webmaster@localhost\n\tDocumentRoot /var/www/%s/\n\t<Directory /var/www/%s>\n\t\tOptions Indexes FollowSymLinks\n\t\tAllowOverRide All\n\t\tRequire all granted\n\t</Directory>\n\tErrorLog /var/log/apache2/error.log\n\tCustomLog /var/log/apache2/access.log combined\n\tScriptAlias /cgi-bin/ /var/www/%s/cgi-bin/\n\t<Directory /var/www/%s/cgi-bin/>\n\t\tAllowOverRide None\n\t\tOptions +ExecCGI -MultiViews +SymLinksIfOwnerMatch\n\t\tRequire all granted\n\t</Directory>\n</Virtualhost>\n",server,dir,dir,dir,dir);
		fprintf(fp1,"127.0.0.1  %s\n",server);
		system("sudo systemctl reload apache2");
			//printf("<p>%s</p>\n",mkdirValue);
	}
	else if(strcmp(option,"off")==0){
		fprintf(fp,"<VirtualHost *:80>\n\tServerName %s\n\tServerAdmin webmaster@localhost\n\tDocumentRoot /var/www/%s/\n\t<Directory /var/www/%s>\n\t\tOptions Indexes FollowSymLinks\n\t\tAllowOverRide All\n\t\tRequire all granted\n\t</Directory>\n\tErrorLog /var/log/apache2/error.log\n\tCustomLog /var/log/apache2/access.log combined\n</Virtualhost>\n",server,dir,dir);
		fprintf(fp1,"127.0.0.1  %s\n",server);
		system("sudo systemctl reload apache2");
	}
	
	printf("<p>Reussite de la creation du fichier de configuration <a href=\"http://www.tsoa-dev.com/cgi-bin/create_web_site/creation.cgi?dir=/var/www/%s&servername=%s&fileconf=%s&name=%s\">Passer a la prochaine etape de la creation du site</a></p>\n",dir,server,location,name);
	fclose(fp);
	fclose(fp1);

	char*cmd=malloc(sizeof("cat /home/tsoa/tmp.txt")+sizeof("| sudo tee ")+sizeof(location)+1);
	strcpy(cmd,"cat /home/tsoa/tmp.txt");strcat(cmd,"| sudo tee ");strcat(cmd,location);
	system(cmd);
	free(cmd);
	system("sudo systemctl reload apache2");

	
	printf("</body>");
	printf("</html>");

	return 0;
}
