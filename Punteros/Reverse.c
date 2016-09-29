#include <stdio.h>
#include <stdlib.h>

void reversepuntero(char *m) {
	char *p = m, n;
	int i;
	for (i=0;(*m) != '\0';i++)
		m++;
	m--;
	for (i=0;(m > p);i++) {
		n = *m;
		*m-- = *p;
		*p++ = n;
	}
}

int main(){
    char s[10]= "Novato";
    reversepuntero(s);
    printf("%s",s);
}
