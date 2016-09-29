#include <stdio.h>

char reversepuntero(char *m){
	int i;
	char *p;
	for(i=0;(*m)!='\0';i++)
		m++;
	--m;
	for(i=0;(*p)!=0;i++)
		--p;
	return p;
}

int main(){
	char s[5] = "Hola";
	reversepuntero(s);
	printf("%c", reversepuntero(s));
}

