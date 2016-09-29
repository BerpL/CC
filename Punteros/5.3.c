#include <stdio.h>


void strcatpuntero(char *m, char *n)
{
	int i;

	for(i=0;(*m)!='\0';i++)
		m++;
	for(i=0;(*m++ = *n++)!= '\0';i++)
		;

}
int main()  
{
	char s[6] = "Compu";
	char t[6] = "tacion";
	
	strcatpuntero(s,t);
	printf("%s",s);
}

