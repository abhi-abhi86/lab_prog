#include <stdio.h>
#include <limits.h>
#define MAX 100
int p[MAX];
int f(int x){return p[x]==x?x:p[x]=f(p[x]);}
int main(){
    int n,c[MAX][MAX],i,j,e=0,mc=0;
    printf("Enter the number of vertices: ");
    if(scanf("%d",&n)!=1) return 0;
    printf("Enter the cost matrix:\n");
    for(i=0;i<n;i++) for(j=0;j<n;j++) scanf("%d",&c[i][j]);
    for(i=0;i<n;i++) p[i]=i;
    while(e<n-1){
        int m=INT_MAX,a=-1,b=-1;
        for(i=0;i<n;i++) for(j=0;j<n;j++)
            if(c[i][j] && f(i)!=f(j) && c[i][j]<m){ m=c[i][j]; a=i; b=j; }
        if(a==-1) break;
        p[f(a)]=f(b);
        printf("Edge %d: (%d, %d) cost: %d\n", e++, a, b, m);
        mc+=m;
    }
    printf("Minimum cost: %d\n", mc);
    return 0;
}
