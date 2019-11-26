#include<stdio.h>
#include"myBank.h"


int main(){
	
	char select;
	
	do{	

		printf("Please enter O for open a new bank account\n");
		printf("Please enter B for check what is your balance\n");
		printf("Please enter D for deposit to your bank account\n");
		printf("Please enter W for withdraw from your bank account\n");
		printf("Please enter C for close your bank account\n");
		printf("Please enter I for add intrest\n");
		printf("Please enter P print all the accounts\n");
		printf("Please enter E to end the program\n\n");
		printf("Please enter a letter\n");		
		
		if(scanf("  %c", &select)==1){				
			switch(select){

				case 'O':		
					open();
					break;				
						
	
				case 'B':
					balance();		
					break;
	
				case 'D':
					depositing();
					break;
			
	
				case 'W':
					withdrawal();
					break;
			
	
				case 'C':
					close();			
					break;
	
				case 'I':
					intrest();
					break;
					
	
				case 'P':
					print();
					break;
			
	
				case 'E':
					end();
					break;
	
				default:
					printf("You choose a worng letter, please choose again\n");
					
	
			}
		}

		else{
			printf("Please enter a char as in the menu");
		}
				
	
	}while(select!='E');
	
	return 0;
}
