#include<stdio.h>

struct node{
 unsigned dist[20];
 unsigned from[20];
}rt[10];

void main(){

int i,j,k,count,n;
int dmat[20][20];

printf("Enter the no. of nodes:");
scanf("%d",&n);
printf("Enter the matrix:");
for(i=0;i<n;i++){
for(j=0;j<n;j++){
scanf("%d",&dmat[i][j]);
if(i==j) dmat[i][j]=0;
rt[i].dist[j]=dmat[i][j];
rt[i].from[j]=j;
}
}

do{
count=0;
for(i=0;i<n;i++){
for(j=0;j<n;j++){
for(k=0;k<n;k++){
if(rt[i].dist[j]> dmat[i][k]+ rt[k].dist[j]){
rt[i].dist[j]=dmat[i][k]+ rt[k].dist[j];
rt[i].from[j]=k;
count++;
}

}
}}
}while(count!=0);

for(i=0;i<n;i++){
printf("State value of router %d\n\n:",i+1);
for(j=0;j<n;j++){
printf("Node %d via %d distance %d \n",j+1 ,rt[i].from[j]+1,rt[i].dist[j]);
}

}



}
