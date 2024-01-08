#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//<>

int main(){
	printf("Content-type:text/html\n\n");
	printf("<html>\n");
	printf("<head>\n");
	printf("<meta charset=\"utf-8\">\n");
	printf("<title>Créez votre propre site web en seulement quelques clics</title>\n");
	printf("<style>\n.container{max-width: 600px;margin-left: 50px;margin-right: 50px;	margin-top: 15px;margin-bottom: 15px;background-color: white;color: white;");
	printf("padding: 30px;box-shadow: 0 0 10px rgba(0,0,0,0.1);display: flex;align-items: center;justify-content: center;text-align: center;}\n");
	printf("h2{text-align: center;color: black;margin-bottom: 40px;}\n");
	printf("label{display: block;font-weight: bold;}\n");
	printf("input[type=\"text\"],input[type=\"checkbox\"]{width: 55%;padding: 4px 8px;border: 3px solid blue;border-radius: 10px;background-color: white;color: black;text-align: left;font-size: 14pt;}\n");
	printf("button[type=\"submit\"]{display: inline-flex;width: 35%;height: 5%;padding: 6px 12px;background-color: blue;font-size: 15pt;color: white;border: 10px;");
	printf("border-radius: 10px;cursor: pointer;text-align: center;justify-content: center;}\n");
	printf("button[type=\"submit\"]:hover{background-color: darkblue;}\nform{text-align:left;align-items:left;}\n</style>\n");
	printf("</head>");
	printf("<body>");
	printf("<center>\n");
	//printf("<div class=\"container\">\n");
	printf("<h2>Veuillez remplir le formulaire ci-dessous avec les informations necessaires pour pouvoir creer votre propre site web</h2>\n");
	//printf("</div>");
	printf("</center>\n");
	printf("<form action=\"generateWebSite.cgi\" method=\"get\">\n");
	printf("<br><br>Nom sans extension de votre fichier de configuration en un mot: <input type=\"text\" name=\"confFile\" id=\"confFile\" required><br>\n");
	printf("<br><br>Nom de domaine:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <input type=\"text\" name=\"ServerName\" id=\"ServerName\" required><br>\n");
	printf("<br><br>Nom du Repertoire de travail sur le serveur apache2:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <input type=\"text\" name=\"DocumentRoot\" id=\"DocumentRoot\" required><br>\n");
	printf("<br><br><input type=\"radio\" name=\"cgi-option\" value=\"on\" required>Enable CGI <input type=\"radio\" name=\"cgi-option\" value=\"off\" required>Disable CGI\n");
	printf("<br><br><center>");printf("<br><button type=\"submit\">Cr&eacute;er</button>\n");printf("</center>\n");
	printf("</form>\n");
	
	
	printf("</body>");
	printf("</html>");
	return 0;
}
