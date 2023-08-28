
#include <stdio.h>
#include <stdlib.h>
// #define SIZE 10

int push(int);
int pop();

typedef struct node{
	int data;
	struct node *next;
} NODE;

NODE  *start=NULL;


int length=0;
int main(int argc, char **argv)
{
	int data;
	printf("\nLink List program.\nEnter -0 to Exit\n");
	do{
		printf("\nEnter Data:");
		scanf("%d", &data);
		if(data!=-0){
		    if(push(data)<0){
			    printf("\nUnable to Push into List..");
			    break;
	        }
		    length=length+1;
		}
	}while(data!=-0);
	int stat;
// 	NODE *node=start;
	
	for(int i=0; i<length ; ++i){
		stat=pop();
		if(stat<0)
			printf("!Operation Failed.");
		else
			printf(" %d \n", stat);
		
	}
	
	
	return 0;
}

int push(int no){
	
	NODE *node=malloc(sizeof(NODE));
	node->data=no;
	if(start==NULL){
		node->next=NULL;
		start=node;
		length=length+1;
		return no;
	}
	else{
		node->next=start;
		start=node;
		length=length+1;
		return no;
	}
	return -1;
}

int pop(){
	if(start==NULL){
		printf("\nList is Empty.\n");
		length=0;
		return -1;
	}
	if(start->next==NULL){
		int stat=start->data;
		// printf("\nList Deleted With Data : %d", stat);
		free(start);
		length=length-1;
		return stat;
	}
	else{
		NODE *prev, *node=start;
		while(node->next!=NULL){
			prev=node;
			node=node->next;
		}
		int no=node->data;
		free(node);
		length=length-1;
		prev->next=NULL;
		return no;
	}
	
}

