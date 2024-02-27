#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
printf("\nWe are in F2\n");
//fork();
printf("Second\nPID=%d\n",getpid());
return 0;
}
