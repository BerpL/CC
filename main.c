#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int transpuesta(int **t, int **y);
int promedio(int *p, int len);

int main()
{
    struct punto{
    int x;
    int y;
    };
    struct punto p1 = {1,2};
    struct punto p2 = {2,3};

    int **q[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int **y[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int **t[3][3];
    int **r[3][3];
    int p[10] = {1,2,1,4};

    printf("%d", promedio(p,4));
    return 0;
}

//float distancia(float p1, float p2){
//    float res;
//    res = pow(p1.x - p2.x,0.5)+ pow(p1.y - p2.y,0.5);
//    return res;
//}

int transpuesta(int **t, int **y){
    int i = 0, lim = 3;
    while(i<lim){
        int j = 0;
        while(j<lim){
            *(*(t+j)+i)=*(*(y+i)+j);
            ++j;
    }
    ++i;
    }
}

int promedio(int *p, int len){
    int res = 1;
    int i ;
    for (i=0;i<len;++i){
        res = res + (*p);
        *p++;
    }
    return res/len;
}

