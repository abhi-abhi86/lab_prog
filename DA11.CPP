#include <stdio.h>
#include <limits.h>

int main(void){
    int n, i, j, ne=1, min_cost=0, source;
    int cost[20][20], visited[20]={0}, a=0,u=0,v=0,b=0,min;
    printf("Enter the no. of nodes:");
    if(scanf("%d",&n)!=1) return 0;
    printf("\nEnter the cost matrix:\n");
    for(i=1;i<=n;i++) for(j=1;j<=n;j++) scanf("%d",&cost[i][j]);
    printf("\nEnter the root node:");
    scanf("%d",&source);
    visited[source]=1;
    printf("\nMinimum cost spanning tree is\n");
    while(ne<n){
        min=INT_MAX;
        for(i=1;i<=n;i++) for(j=1;j<=n;j++)
            if(cost[i][j]<min && visited[i]){ min=cost[i][j]; a=u=i; b=v=j; }
        if(!visited[v]){ printf("\nEdge %d\t(%d->%d)=%d\n", ne++, a, b, min); min_cost+=min; visited[b]=1; }
        cost[a][b]=cost[b][a]=INT_MAX;
    }
    printf("\nMinimum cost=%d\n",min_cost);
    return 0;
}
