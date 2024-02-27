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


// Terminal Code

// csea2@sjcet-H81M-DS2:~/Kiran$ gcc f1.c -o f1
// csea2@sjcet-H81M-DS2:~/Kiran$ gcc f2.c -o f2
// csea2@sjcet-H81M-DS2:~/Kiran$ ./f1
