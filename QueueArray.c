#include <stdio.h>
#include <stdlib.h>
#define SIZE 10


int queue[SIZE];
int front=-1,rear=-1;
int opt, no, o;

int push(int);
int pop();
int peekBeg();
int peekEnd();

int main(int argc, char **argv)
{
	printf("Queue Using Array.\n");
	opt=-1;
	do{
		#ifdef _WIN32
			system("cls");
		#endif
		#ifdef __linux__
			system("clear");
		#endif
		printf("\n1.\tPush");
		printf("\n2.\tPop");
		printf("\n3.\tPeek");
		printf("\n4.\tExit");
		printf("\n  Select Option: ");
		scanf("%d", &opt);
		switch(opt){
			case 1:
				printf("Enter Element to Push : ");
				scanf("%d", &no);
				if(push(no)>0){
					printf("\n%d is Push SUccesfulyy.",no);
				}
				else
					printf("\n!Failed To push element...");
				break;
				
			case 2:
				if(pop()>0){
					printf("\nDeletion Succusfully..");
				}else
					printf("\n!Delection Failed");
				break;
			case 3:
				system("clear");
				printf("\n1.\tBeginning");
				printf("\n2.\tEnding");
				printf("\nSelect Option: ");
				scanf("%d", &o);
				if(o==1){
					no=peekBeg();
				}
				else if(o==2)
					no=peekEnd();
				else{
					printf("\n!Invalid option");
					break;
				}
				printf("\n%d Is the element.", no);
				break;
				
// 			default:
// 				printf("\n!Invalid Options.\n");
		}
		
	}while(opt!=4);
	
	return 0;
}


int push(int no ){
	if(rear==SIZE-1 && front==0){
		printf("\nOverflow");
		return -1;
	}
	else if (rear==-1 || front==-1){
		rear=front=0;
		queue[rear]=no;
	}
	
	else{
		++rear;
		queue[rear]=no;
	}
// 	printf("%d", front);
	return no;
}

int peekBeg(){
	if(rear==front){
		printf("\nQueue Is Empty.");	
	}
	return queue[rear];
}

int peekEnd(){
	if(rear==front){
		printf("\nQueue is Empty");
	}
	return queue[front];
}

int pop(){
	if(front==-1 || front>rear){
		printf("\nUnderfLow");
		return -1;
	}
	else
		++front;
	return queue[front];
}
