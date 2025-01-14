#include <stdio.h>
#include <stdbool.h>
int adj[20][20],vi[20],i,j,n,start;
void dfs(int node);
void main(){
    printf("enter no of vertices :");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        vi[i]=0;
    }
    printf("enter adj matrix: ");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("A[%d][%d]",i,j);
            scanf("%d",&adj[i][j]);
        }
    }
    printf("enter starting vertex:");
    scanf("%d",&start);
    if(start<0 || start>=n){
        printf("invalid");
    }
    else{
        dfs(start);
    }
}
void dfs(int node){
    vi[node]=1;
    printf("%d",node);
    for(i=0;i<n;i++){
        if(adj[node][i]==1 && vi[i]!=1){
            dfs(i);
        }
    }
}