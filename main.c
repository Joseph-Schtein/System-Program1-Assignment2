#include<stdio.h>
#include"myBank.h"


int main(){
	
	char select;
	int ch, bankAccount;
	double amount, intrestRate;

	
	


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
		
		scanf("  %c", &select);				
		while( (ch = getchar()) != '\n' && ch != EOF);
		switch(select){

			case 'O':		
				printf("What would be your initiat depositsir:\n");			
				scanf("%lf", &amount);			
				amount = (amount*100)/100.0;								

				if(amount>=0){			
					open(amount);
				}
				else{
					printf("The amount you enter is negative\n");
					printf("Please choose a new action\n");
				}
				break;				
						
	
			case 'B':
				printf("What is your bank account:\n");			
				scanf("%d", &bankAccount);
							

				if(bankAccount<901 || bankAccount>950){
					printf("The number you enter is not valid\n");
					printf("Please choose a new action\n");
				}
			
				else{
					balance(bankAccount);
				}		
				break;

			case 'D':
				printf("Please enter your bank account and amount of NIS you want to deposit\n");
				scanf("%d%lf", &bankAccount,&amount);		
				
				if(bankAccount<901 || bankAccount>950){
					printf("The number you enter is not valid\n");
					printf("Please choose a new action\n");
				}			
			
				else{
					printf("Please enter a number of NIS for deposit:\n");			
					amount = (amount*100)/100.0;
					if(amount>=0){	
						depositing(bankAccount ,amount);
					}
					
					else{
						printf("You can't enter non positive number\n");
						printf("Please choose a new action\n");
					}	
				}	
				break;
		

			case 'W':
				printf("Please enter your bank account and amount of NIS you want to withdrawl\n");
				scanf("%d%lf", &bankAccount,&amount);


				if(bankAccount<901 || bankAccount>950){
					printf("The number you enter is not valid\n");
					printf("Please choose a new action\n");
				}	
			
				else{
					printf("Please enter a number of NIS for withdraw:\n");
					amount = (amount*100)/100.0;
					if(amount>=0){	
						withdrawal(bankAccount ,amount);
					}
				
					else{
						printf("You can't enter non positive number\n");
						printf("Please choose a new action\n");
					}
				}
				break;
		

			case 'C':
				printf("We're sorry that you leaving, what is your bank account\n");
				scanf("%d", &bankAccount);
			
				if(bankAccount<901 || bankAccount>950){
					printf("The number you enter is not valid\n");
					printf("Please choose a new action\n");
				}
			
				else{
					close(bankAccount);
				}			
				break;

			case 'I':
				printf("Please choose the intrst by precentage");			
				scanf("%lf", &intrestRate);
			
				if(intrestRate>0){
					intrest(intrestRate);
				}

				else{
					printf("You can't enter non positive number\n");
				}
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

	}while(select!='E');

	return 0;
}
