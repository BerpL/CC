#include<stdio.h>
#include<string.h>
#define MAXLINES 5000    /** max #lines to be sorted */
#define MAXLEN 1000      /** MAX LENGTH OF ANY INPUT LINE **/
#define ALLOCSIZE 10000  /** size of available space */

static char allocbuf[ALLOCSIZE];   /**storage for allox **/
static char *allocp = allocbuf;    /** next free position **/

char *lineptr[MAXLINES];  /** poinbter to text lines**/

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void mqsort(char *lineptr[],int left, int right);

int main(){
	
	int nlines;
	if( (nlines = readlines(lineptr, 4)) >=0){
		mqsort(lineptr,0,nlines-1);
		writelines(lineptr,nlines);
		return 0;
	}
	else
	{
		printf("error: input too big to sort \n");
		return 1;
	}
 
} 

char* malloc(int n){

	if(allocbuf + ALLOCSIZE - allocp >= n){
			allocp += n;
			return allocp - n; 
	}
	
	return 0;
}

int mgetline(char *p, int x)
{		int c, n;
		n = 0;
        while ((c = getchar()) != EOF && c != '\n' && x--) 
															
															 
                *p++ = c;
                n++;
        if (*p == '\n') 
                *p++ = c;
                n++;
        
        *p = '\0';
        return n;                                                 
}

int readlines(char *lineptr[], int maxlines){  
	
	int len, nlines;
	char *p, line[MAXLEN];
	nlines = 0;
	
	while( (len=mgetline(line, MAXLEN)) >0){              																													
		if( (nlines >= maxlines) || (p=malloc(len)) == NULL)
			return -1;
		else{
			
			line[len-1] = '\0'; 
			strcpy(p,line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}

void writelines(char *lineptr[], int nlines){
	while(nlines-- >0){
		printf("%s \n", *lineptr++);
	}
}
  
void mswap(char *v[],int i, int j)
{
	char *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
 
int mstrcmp(char *s, char *t){
	
	while(*s == *t && s++ && t++){
		if(*s == '\0')
			return 0;
	} 
	return *s-*t;
}
void mqsort(char *v[], int left, int right){
	
	int i, last;
	
	if(left >=right)  
		return;
	mswap(v, left, (left+right)/2);
	last = left;
	 
	for(i=left+1; i<=right; i++){
		if(mstrcmp(v[i],v[left]) < 0){
				mswap(v, ++last, i);
		}
	}
	mswap(v,left,last);
	mqsort(v,left,last-1);
	mqsort(v,last+1,right);
}


 
 
