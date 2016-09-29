#include <stdio.h>


void strcatpuntero(char *s, char *t)
{
	while((*s)!='\0')
		s++;
	while((*s++ = *t++) != '\0')
		;

}
int main()  
{
	char s[6] = "Compu";
	char t[6] = "tacion";
	
	strcatpuntero(s,t);
	printf("%s",s);
}


