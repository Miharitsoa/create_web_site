#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

//<>

int main(){
	// Affiche une page avec le script CGI pour voir la réussite ou l'échec de la création du site web car les informations doivent être correctement remplies 
	printf("Content-type:text/html\n\n");
	printf("<html>\n");
	printf("<head>\n");
	printf("<meta charset=\"utf-8\">\n");
	printf("<title>R&eacute;sultat de votre requete de creation de site web</title>\n");
	printf("</head>");
	printf("<body>");

	// Récupération des données de l'URL à traiter pour mettre sur pied son site si les données entrées sont correctes
	char*query=getenv("QUERY_STRING");
	char*conffile=strtok(query,"=");
	char*conffileValue=strtok(NULL,"&");printf("<p>Nom du fichier de configuration sans l'extension .conf: %s</p>",conffileValue);
	char*servername=strtok(NULL,"=");
	char*servernameValue=strtok(NULL,"&");printf("<p>Nom de domaine du site web: %s</p>",servernameValue);
	char*documentroot=strtok(NULL,"=");
	char*documentrootValue=strtok(NULL,"&");printf("<p>Nom du repertoire de travail: %s</p>",documentrootValue);
	char*option=strtok(NULL,"=");
	char*optionValue=strtok(NULL,"\n");printf("<p>Configurer cgi ou non(on/off): %s</p>",optionValue);
	
	// Chaînes de caractères nécessaires pour l'écriture des fichiers de configurations du site web
	
	// Chaînes de caractères représentant les commandes nécessaires pour le traitement des fichiers
	char*locationOfConfFiles="/etc/apache2/sites-available/";
	char*reloadServer="sudo systemctl reload apache2";
	char*hosts="/etc/hosts";
	char*fileConf=strcat(conffileValue,".conf");printf("<p>Nom avec extension du fichier de configuration: %s</p>",fileConf);
	char*createFileConfLocation=malloc(sizeof(locationOfConfFiles)+sizeof(fileConf)+1);
	strcpy(createFileConfLocation,locationOfConfFiles);strcat(createFileConfLocation,fileConf);
	printf("<p>Chemin absolu du fichier de configuration du site: %s</p>",createFileConfLocation);

	printf("<a href=\"http://www.tsoa-dev.com/cgi-bin/create_web_site/traitement.cgi?servername=%s&dir=%s&location=%s&cgi-option=%s&name=%s\">Cliquez ici pour la creation</a>",servernameValue,documentrootValue,createFileConfLocation,optionValue,fileConf);
	free(createFileConfLocation);
//	free(cmd);
	printf("</body>");
	printf("</html>");
	return 0;
}

