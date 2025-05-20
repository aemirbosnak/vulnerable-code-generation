//FormAI DATASET v1.0 Category: Banking Record System ; Style: excited
#include<stdio.h>
#include<stdlib.h>

/*A banking record system program in C*/

struct banking_record{
  char account_name[50];
  int account_number;
  float account_balance;
  int pin;
};

int main(){
  int choice;
  int num_of_accounts=0, i=0;
  struct banking_record *bank_records;
  
  printf("\n\n\t\tWelcome to the Banking Record System!\n\n");
  
  while(1){
    printf("\n\nPlease choose an option from the following:\n\n1. Add a new account\n\n2. View the existing accounts\n\n3. Exit the program\n\n");
    scanf("%d", &choice);
    
    /*Adding a new account*/
    if(choice==1){
      num_of_accounts++;
      bank_records=(struct banking_record*)realloc(bank_records, num_of_accounts*sizeof(struct banking_record));
      printf("\n\nPlease enter the details of the new account:\n\n");
      printf("\nEnter the account name:");
      scanf("%s", bank_records[num_of_accounts-1].account_name);
      printf("\nEnter the account number:");
      scanf("%d", &bank_records[num_of_accounts-1].account_number);
      printf("\nEnter the account balance:");
      scanf("%f", &bank_records[num_of_accounts-1].account_balance);
      printf("\nEnter the account pin:");
      scanf("%d", &bank_records[num_of_accounts-1].pin);
      printf("\nThe account has been successfully created!\n\n");
    }
    /*Viewing the existing accounts*/
    else if(choice==2){
      if(num_of_accounts==0){
        printf("\n\nThere are no accounts in the system yet! Please create a new account first.\n\n");
      }
      else{
        printf("\n\nThe existing account details are as follows:\n\n");
        for(i=0;i<num_of_accounts;i++){
          printf("\n\nAccount %d:\n\n", i+1);
          printf("Account Name: %s\n\n", bank_records[i].account_name);
          printf("Account Number: %d\n\n", bank_records[i].account_number);
          printf("Account Balance: %f\n\n", bank_records[i].account_balance);
          printf("Account Pin: %d\n\n", bank_records[i].pin);
        }
      }
    }
    /*Exiting the program*/
    else if(choice==3){
      printf("\n\nThank you for using the Banking Record System! Have a nice day!\n\n");
      exit(0);
    }
    /*Invalid Input*/
    else{
      printf("\n\nInvalid Input! Please enter a valid option.\n\n");
    }
  }
  return 0;
}