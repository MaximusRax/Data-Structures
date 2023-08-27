#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int stack[SIZE];
int Top=-1;

int main(int argc, char **argv)
{
	printf("Implementing Stack Using Array.. \n");
	int opt;
	do{
		#ifdef _WIN32
			system("cls");
		#endif
		#ifdef __linux__
			system("clear");
		#endif
		printf("\n1.\tPush.");
		printf("\n2.\tPop");
		printf("\n3.\tPeek");
		printf("\n4.\tExit");
		printf("\nSelect Option: ");
		scanf("%d", &opt);
		switch(opt){
			case 1:
				printf("\nEnter Element: ");
				int no;
				scanf("%d", &no);
				if(isdigit(no)){
					printf("\n!Please Enter No only..");
					break;
				}
				int stat=push(no);
				if(stat!=-1){
					printf("%d is Inserted successfully.", no);
				}else
					printf("\n!Operation Failed");
				break;
			case 2:
				printf("\nRemoving Element..");
				int el=pop();
				if(el!=-1)
					printf("\n!%d Removed successfully.", el);
				else
					printf("\n!Error Element not Removed.");
				break;
			case 3:
				printf("\nElement at Top : %d", peek());
				break;
			case 4:
				return 0;
			default:
				printf("!Try again.");
		}
	}while(opt!=4);
	
	return 0;
}

int push(int no){
	if(Top==SIZE-1 && Top!=0){
		printf("\n!Overflow.");
		return -1;
	}
	else if(Top==-1){
		Top=0;
		stack[Top]=no;
	}
	else {
		Top++;
		stack[Top]=no;
	}
	return no;
}

int pop(){
	if(Top==-1 ){
		printf("\n!Underflow.");
	}else{
// 		Top--;
		return stack[--Top]; 
	}
}
int peek(){
	if(Top!=-1){
		return stack[Top];
	}
}
