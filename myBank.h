#ifndef MYBANK_H
#define COMPLEX_H

#define OPEN 1
#define CLOSE 0
#define NUMBER_OF_ROWS 2
#define NUMBER_OF_BANK_ACCOUNT 50 

extern double bankAccount[NUMBER_OF_ROWS][NUMBER_OF_BANK_ACCOUNT];

void open();

void balance();

void depositing();

void withdrawal();

void close();

void intrest();

void print();

void end();

#endif
