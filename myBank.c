#include "myBank.h"
#include <stdio.h>	

double bankAccount[NUMBER_OF_ROWS][NUMBER_OF_BANK_ACCOUNT]={0};

void open(){
	int notFound =1;	
	double initial_Deposit;
	printf("What would be your initiat depositsir:\n");			
	if(scanf("%lf", &initial_Deposit)==1){			
		initial_Deposit=(initial_Deposit*100)/100.0;											
	
		if(initial_Deposit>=0){
			for(int i = 0; i < NUMBER_OF_BANK_ACCOUNT && notFound; i++){
				if(bankAccount[0][i]==CLOSE){
					bankAccount[0][i] = OPEN;
					bankAccount[1][i] = bankAccount[1][i]+initial_Deposit;			
					i=i+901;
					printf("The number of your bank account is %d\n\n", i);
					notFound = 0;		
				}
			
				else if(i==49){
					printf("We're sorry we don't have a account for you\n\n");	
				}
			}
		}
	

		else{
			printf("The amount you enter is negative\n");
			printf("Please choose a new action\n");
		}

	}

	else{	
	printf("You enter non valid input\n"); 		
	} 
}




void balance(){	
	int accountNumber;
	printf("What is your bank account:\n");			
	if(scanf("%d", &accountNumber)==1){
							

		if(accountNumber<901 || accountNumber>950){
			printf("The number you enter is not valid\n");
			printf("Please choose a new action\n");
		}

		else{
			if(bankAccount[0][accountNumber-901]==OPEN){
				printf("Your balance is: %0.2lf\n\n", bankAccount[1][accountNumber-901]);	
			}
		

			else{
				printf("The number of this bank account isn't open\n\n");	
			}
		}
	}	
	
	else{
		printf("you enter a non integer number for bank account");
	}
}




void depositing(){
	int account_Number;
	double amount;
	printf("Please enter your bank account \n");
	if(scanf("%d", &account_Number)==1){		
				
		if(account_Number<901 || account_Number>950){
			printf("The number you enter is not valid\n");
			printf("Please choose a new action\n");
		}
	
		else if(bankAccount[0][account_Number-901]==OPEN){
			printf("Please enter a number of NIS for deposit:\n");	
			if(scanf("%lf",&amount)==1){	
				if(amount>0){
					bankAccount[1][account_Number-901]= bankAccount[1][account_Number-901]+amount;
					printf("Your new balance is: %0.2lf\n\n", bankAccount[1][account_Number-901]);
				}

				else{
					printf("You need to enter a positive number\n");
				}
			}

			else{
				printf("You need to enter a number\n");			
			}
		}

		else{
			printf("For this bank account number the account isn't open\n\n");	
		}
	}
	printf("Please choose a new action\n\n");	
	
}





void withdrawal(){
	int account_Number;
	double amount;
	printf("Please enter your bank account l\n");
	if(scanf("%d", &account_Number)==1){
			
		if(account_Number<901 || account_Number>950){
			printf("The number you enter is not valid\n");
			printf("Please choose a new action\n\n");
		}

		else{	
			printf("Please enter a number of NIS for withdraw:\n");
			if(scanf("%lf", &amount)==1){
				amount = (amount*100)/100.0;
			
				if(bankAccount[0][account_Number-901]==OPEN && bankAccount[1][account_Number-901]>amount && amount>0){
					bankAccount[1][account_Number-901]= bankAccount[1][account_Number-901]-amount;
					printf("Your new balance is: %0.2lf\n\n", bankAccount[1][account_Number-901]);
				}
				
				else if(amount <=0){
					printf("You can't draw a non positve number of NIS\n\n");
				}

				else if(bankAccount[0][account_Number-901]==OPEN && bankAccount[1][account_Number-901]<amount){
					printf("You don't have enough funding\n\n");
				}

				else{
					printf("For this bank account number of this account isn't open\n\n");
				}
			}

			else{
				printf("You didn't enter a number for withdraw\n\n");
			}
	
		}
	}

	else{
		printf("You enter non valid nuber for bank accout\n\n");
		printf("Please choose a new action\n\n");		
	}
}





void close(){
	int account_Number;	
	printf("We're sorry that you leaving, what is your bank account\n");
	if(scanf("%d", &account_Number)==1){
				
		if(account_Number<901 || account_Number>950){
			printf("The number you enter is not valid\n");
			printf("Please choose a new action\n");
		}

		else if(bankAccount[0][account_Number-901]==OPEN){
			bankAccount[1][account_Number-901]=0;
			bankAccount[0][account_Number-901]=CLOSE;
		}

		else{
			printf("This bank account is already close\n\n");		
		}
	}
	
	else{
		printf("You need to type an integer for accses to this bank account\n\n");
		printf("Please choose a new action\n\n");	
	}
}





void intrest(){
	int interest_Rate; 
	printf("Please choose the intrst by precentage integer\n");			
	if(scanf("%d", &interest_Rate)==1){		
		if(interest_Rate>0){		
			for(int i = 0; i < NUMBER_OF_BANK_ACCOUNT; i++){
				if(bankAccount[0][i]==OPEN){
					bankAccount[1][i]+= bankAccount[1][i]*interest_Rate/100.0;
					bankAccount[1][i]= (bankAccount[1][i]*100)/100.0;
				}
			}
		}
	

		else{
			printf("You can't give a negative intrest\n");
		}
	}

	else{
		printf("you need to give a number for intrest\n\n");
	}
}





void print(){
	for(int i = 0; i < NUMBER_OF_BANK_ACCOUNT; i++){
		if(bankAccount[0][i]==OPEN){
		     printf("The number of the bank account: %d  ,  And the balance is:   %0.2lf\n", i+901, bankAccount[1][i]);		
		}
	}
	printf("\n\n");
}





void end(){
	for(int i = 0; i < NUMBER_OF_BANK_ACCOUNT; i++){	
		if(bankAccount[0][i]==OPEN){
			bankAccount[1][i]=0;
			bankAccount[0][i]=CLOSE;
		}
	}
}

