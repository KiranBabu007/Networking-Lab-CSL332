#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main(){

int p=fork();
if(p<0)
exit(1);
else if(p>0)
 printf("I am Parent\n");
else
printf("I am Child\n");

}
