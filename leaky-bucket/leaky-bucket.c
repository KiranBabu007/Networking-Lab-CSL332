#include<stdio.h>

void main(){
    int n,incoming,outgoing,buck_size=50,store=0;
 printf("Enter the no. of incoming packets:");
        scanf("%d",&n);

    while(n>0){
        printf("Enter the size of incoming packet:");
        scanf("%d",&incoming);

        if(incoming<=(buck_size-store)){
            printf("Incoming packet size:%d\n",incoming);
            store+=incoming;
        }
        else{
            printf("Dropped packet size:%d\n",incoming-(buck_size-store));
            store=buck_size;
        }
        n--;
        printf("bucket size after outgoing packet:%d\n",store-outgoing);

    }
}