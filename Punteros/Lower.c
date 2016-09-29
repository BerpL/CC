#include <stdio.h>

char lowerp(char *m){
	return *m +32;
}

int main(){
	char s[1] = "A";
	lowerp(s);
	printf("%c", lowerp(s));
}


