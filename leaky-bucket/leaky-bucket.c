#include<stdio.h>

void main(){
    int n,incoming,outgoing,buck_size=50,store=0;
 printf("Enter the no. of inputs and outgoing rate:");
        scanf("%d %d",&n,&outgoing);

    while(n>0){
        printf("Enter the size of incoming packet:");
        scanf("%d",&incoming);

        if(incoming<=(buck_size-store)){
            printf("Incoming packet size:%d\n",incoming);
            store+=incoming;
            printf("bucket is filled %d out of %d\n",store,buck_size);
        }
        else{
            printf("Dropped packet size:%d\n",incoming-(buck_size-store));
            store=buck_size;
            printf("bucket is filled %d out of %d\n",store,buck_size);
        }
        store-=outgoing;
        if (store<0){
            store=0;
        }
        printf("bucket state after outgoing.. filled %d out of %d\n",store,buck_size);
        n--;
    }
}