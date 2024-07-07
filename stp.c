#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

struct frame { int data,seq;};
struct frame p ={0,0};

int ack,disconnect=0,error_ack=1,error_frame=1;
char turn='s';


void sender(){
 static int flag=0;
if(turn=='s'){
	if(!error_ack){
	printf("SENDER:RESENDING PACKET %d\n",p.seq);
	}
	else{
	if(flag) printf("SENDER : ACK RECIEVED FOR %d \n",ack);
	if(p.seq==5) {disconnect=1; return;}
	p.seq++; p.data++;
        printf("SENDER: Sending packet %d\n", p.seq);
	
	flag=1;
	}
	error_frame=rand()%4;
	if(!error_frame){
	printf("SENDER:ERROR SENDING PACKET\n");
	}
	turn='r';

}

}

void receiver(){
 static int expected_seq=1;
 if(turn=='r' && error_frame){
 if(p.seq==expected_seq){
 printf("RECEIVER:PACKET %d RECIEVED\n",p.seq);
 ack=p.seq;
 expected_seq++;
 }
 else{
printf("RECEIVER:DUPLICATE PACKET %d\n",expected_seq-1);
ack=expected_seq-1;
}
error_ack=rand()%4;
if(!error_ack) printf("RECEIVER: ERROR WHILE SENDING ACK\n");
turn='s';

}



}

int main(){
while(!disconnect){
sender();
usleep(1000000);
receiver();
}


return 0;
}


