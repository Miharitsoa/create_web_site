#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
	
	
	printf("Content-type:text/html\n\n");
	printf("<html>\n");
	printf("<head>\n");
	printf("<meta charset=\"utf-8\">\n");
	printf("<title>Dernière etape: r&eacute;sultat de votre requete de creation de site web</title>\n");
	printf("</head>");
	printf("<body>");
	FILE*fp=fopen("/usr/lib/cgi-bin/create_web_site/site.txt","w");
	char ligne[100];
	char*query=getenv("QUERY_STRING");
	char*server=strtok(query,"=");char*serverValue=strtok(NULL,"&");
	char*conf=strtok(NULL,"=");char*confValue=strtok(NULL,"&");
	char*name=strtok(NULL,"=");char*nameValue=strtok(NULL,"\0");
	
	char*enableSite="sudo a2ensite ";
	char*redir=" > site.txt";
	char*cmd=malloc(sizeof(enableSite)+sizeof(nameValue)+sizeof(redir)+1);
	strcpy(cmd,enableSite);strcat(cmd,nameValue);strcat(cmd,redir);
	system(cmd);
	while(fgets(ligne,sizeof(ligne),fp)!=NULL){
		printf("<p>%s</p>",ligne);
	}
	free(cmd);
	system("sudo systemctl reload apache2");
	//
	//printf("Location: http://www.tsoa-dev.com/cgi-bin/create_web_site/success.cgi?servername=%s\r\n",serverValue);
	//printf("<p>Redirection en cours ...</p>");
	printf("<p>Le site a ete cree et active avec succes <a href=\"http://%s\">Tester</a></p>",serverValue);
	
	fclose(fp);
	printf("</body>");
	printf("</html>");
	return 0;
}
