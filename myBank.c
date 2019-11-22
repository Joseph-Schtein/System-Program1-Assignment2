#include "myBank.h"
#include <stdio.h>	

#define OPEN 1
#define CLOSE 0
#define NUMBER_OF_ROWS 2
#define NUMBER_OF_BANK_ACCOUNT 50 

double bankAccount[NUMBER_OF_ROWS][NUMBER_OF_BANK_ACCOUNT];


void open(double initial_Deposit){
	int notFound = 1;	
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

void balance(int account_Number){	
	if(bankAccount[0][account_Number-901]==OPEN){
		printf("Your balance is: %0.2lf\n\n", bankAccount[1][account_Number-901]);	
	}
	
	else{
		printf("The number of this bank account isn't open\n\n");	
	}

}

void depositing(int account_Number, double amount){
	
	if(bankAccount[0][account_Number-901]==OPEN){
		bankAccount[1][account_Number-901]= bankAccount[1][account_Number-901]+amount;
		printf("Your new balance is: %0.2lf\n\n", bankAccount[1][account_Number-901]);
	}

	else{
		printf("For this bank account number the account isn't open\n\n");	
	}
}

void withdrawal(int account_Number, double amount){
	
	if(bankAccount[0][account_Number-901]==OPEN && bankAccount[1][account_Number-901]>amount){
		bankAccount[1][account_Number-901]= bankAccount[1][account_Number-901]-amount;
		printf("Your new balance is: %0.2lf\n\n", bankAccount[1][account_Number-901]);
	}

	else if(bankAccount[0][account_Number-901]==OPEN && bankAccount[1][account_Number-901]<amount){
		printf("You don't have enough funding\n\n");
	}

	else{
		printf("For this bank account number the account isn't open\n\n");	
	}
}

void close(int account_Number){
	if(bankAccount[0][account_Number-901]==OPEN){
		bankAccount[1][account_Number-901]=0;
		bankAccount[0][account_Number-901]=CLOSE;
	}

	else{
		printf("This bank account is already close\n\n");	
	}
}

void intrest(double interest_Prcentage){
	double interest_Rate = interest_Prcentage/100.0;
	for(int i = 0; i < NUMBER_OF_BANK_ACCOUNT; i++){
		if(bankAccount[0][i]==OPEN){
			bankAccount[1][i]= bankAccount[1][i]+bankAccount[1][i]*interest_Rate;
		}
		
	}
}

void print(){
	for(int i = 0; i < NUMBER_OF_BANK_ACCOUNT; i++){
		if(bankAccount[0][i]==OPEN){
		     printf("The number of the bank account: %d  ,  And the balance is:   %0.2lf\n", i+901, bankAccount[1][i]);		
		}
	}
}

void end(){
	for(int i = 0; i < NUMBER_OF_BANK_ACCOUNT; i++){	
		if(bankAccount[0][i]==OPEN){
			bankAccount[1][i]=0;
			bankAccount[0][i]=CLOSE;
		}
	}
}

