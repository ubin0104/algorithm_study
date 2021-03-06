#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<queue>
 
using namespace std;
 
int arr[55][55];
int parent[55];
 
int tofind(int a){
    if(a==parent[a])
        return a;
    return parent[a]=tofind(parent[a]);
}
void merge(int a,int b){
    int parentA=tofind(a);
    int parentB=tofind(b);
    if(parentA==parentB)
        return ;
    parent[parentA]=parentB;
    return ;
}
int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
        parent[i]=i;
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int connect;
            scanf("%d",&connect);
            if(connect){
                merge(i,j);        
            }
        }
    }
    int ans;
    scanf("%d",&ans);
    ans=tofind(ans);
    for(int i=1;i<M;i++){
        int a;
        scanf("%d",&a);
        if(tofind(a)==ans)
            continue;
        else{
            printf("NO"); 
            return  0;
        }
         
    }
    printf("YES");
    return 0;
}
 
 