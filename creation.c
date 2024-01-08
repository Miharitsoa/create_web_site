#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	printf("Content-type:text/html\n\n");
	printf("<html>\n");
	printf("<head>\n");
	printf("<meta charset=\"utf-8\">\n");
	printf("<title>Deuxieme etape: r&eacute;sultat de votre requete de creation de site web(Repertoire de travail)</title>\n");
	printf("</head>");
	printf("<body>");

	
	char*query=getenv("QUERY_STRING");
	char*dir=strtok(query,"=");char*dirValue=strtok(NULL,"&");
	char*server=strtok(NULL,"=");char*serverValue=strtok(NULL,"&");
	char*conf=strtok(NULL,"=");char*confValue=strtok(NULL,"&");
	char*name=strtok(NULL,"=");char*nameValue=strtok(NULL,"\0");printf("<p>%s</p>",nameValue);
	char*mkdir="sudo mkdir ";
	char*cp="sudo cp /var/www/html/index.html ";
	
	char*cmd=malloc(sizeof(mkdir)+sizeof(dirValue)+1);
	strcpy(cmd,mkdir);strcat(cmd,dirValue);
	system(cmd);
	free(cmd);
	cmd=malloc(sizeof(cp)+sizeof(dirValue)+1);
	strcpy(cmd,cp);strcat(cmd,dirValue);
	system(cmd);
	free(cmd);
	system("sudo systemctl reload apache2");
	printf("<p>Reussite de la creation du repertoire de travail du site web <a href=\"http://www.tsoa-dev.com/cgi-bin/create_web_site/activation.cgi?servername=%s&conf=%s&name=%s\">Activer votre site web (obligatoire)</a></p>",serverValue,confValue,nameValue);
/*	else
		printf("<p>Erreur lors de la creation du site web <a href=\"http://www.tsoa-dev.com/cgi-bin/create_web_site/createurDeSite.cgi\">Reesayer</a></p>");	
*/	printf("</body>");
	printf("</html>");

	return 0;
}
