#include<stdio.h>


int strend(char *m, char *n){
	
		int i, len;
		len = 0;
		for(i=0;(*m)!='\0';i++){
			
			m++;
		}
		--m; 
	
		for(i=0;(*n)!='\0';i++){
			
			n++;
			len++;
		}  
		--n; 
		
		for(i=0;(*m == *n) && (len!=0);i++){
			m--;
			n--;
			len--;
		}
		--n;
		
		if (len==0) 
			return 1;
		
		return 0;
}


int main(){
	
	char s[20] = "I am feeling good";
	char t[20] = "good";
	strend(s,t);
	printf("%d", strend(s,t));
}


