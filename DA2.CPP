#include <stdio.h>
#include <conio.h>
#include <limits.h>

#define N 4

int tsp(int g[N][N],int m,int p) {
    int i,b=INT_MAX,c;
    if(m==(1<<N)-1) return g[p][0];
    for(i=0;i<N;i++) if(!(m&(1<<i))) {
        c=g[p][i]+tsp(g,m|(1<<i),i);
        if(c<b) b=c;
    }
    return b;
}

void main() {
    int g[N][N]={{0,2,5,7},{2,0,8,3},{5,8,0,1},{7,3,1,0}};
    clrscr();
    printf("Minimum Cost of the TSP:%d",tsp(g,1,0));
    getch();
}
