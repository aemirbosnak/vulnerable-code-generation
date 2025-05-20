//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

//global variables
int number_of_transactions = 0;
float total_expense = 0;
float *expense_list = NULL;
char **description_list = NULL;

//function to add transaction
void add_transaction(){
    printf("Enter the amount spent: ");
    float amount;
    scanf("%f", &amount);

    printf("Enter the description: ");
    char description[50];
    scanf("%s", description);

    total_expense += amount;

    expense_list = (float*)realloc(expense_list, (number_of_transactions+1)*sizeof(float));
    expense_list[number_of_transactions] = amount;

    description_list = (char**)realloc(description_list, (number_of_transactions+1)*sizeof(char*));
    description_list[number_of_transactions] = (char*)malloc((strlen(description)+1)*sizeof(char));
    strcpy(description_list[number_of_transactions], description);

    number_of_transactions++;

    printf("\nTransaction added successfully!\n");
}

//function to delete last transaction
void delete_last_transaction(){
    if(number_of_transactions == 0){
        printf("\nNo transactions found!\n");
        return;
    }

    total_expense -= expense_list[number_of_transactions-1];

    free(description_list[number_of_transactions-1]);
    description_list = (char**)realloc(description_list, (number_of_transactions-1)*sizeof(char*));

    expense_list = (float*)realloc(expense_list, (number_of_transactions-1)*sizeof(float));

    number_of_transactions--;

    printf("\nLast transaction deleted successfully!\n");
}

//function to display all transactions
void display_transactions(){
    printf("\n----------Expense Tracker----------\n");

    if(number_of_transactions == 0){
        printf("\nNo transactions found!\n");
        return;
    }

    printf("\nNumber of transactions: %d\n", number_of_transactions);
    printf("Total expense: %.2f\n\n", total_expense);

    printf("Transactions:\n");

    for(int i=0; i<number_of_transactions; i++){
        printf("%d. %s - $%.2f\n", i+1, description_list[i], expense_list[i]);
    }

    printf("\n");

}

//function to clear all transactions
void clear_all(){
    if(number_of_transactions == 0){
        printf("\nNo transactions found!\n");
        return;
    }

    for(int i=0; i<number_of_transactions; i++){
        free(description_list[i]);
    }

    free(expense_list);
    free(description_list);

    expense_list = NULL;
    description_list = NULL;
    number_of_transactions = 0;
    total_expense = 0;

    printf("\nAll transactions cleared successfully!\n");
}

int main(){
    printf("----------Expense Tracker----------\n\n");

    char option;
    do{
        printf("1. Add Transaction\n");
        printf("2. Delete Last Transaction\n");
        printf("3. Display All Transactions\n");
        printf("4. Clear All Transactions\n");
        printf("5. Exit\n\n");

        printf("Enter your option: ");
        scanf(" %c", &option); //adding a space before %c to ignore the newline character

        option = toupper(option);

        switch(option){

            case '1': add_transaction();
                      break;
            case '2': delete_last_transaction();
                      break;
            case '3': display_transactions();
                      break;
            case '4': clear_all();
                      break;
            case '5': break;
            default: printf("\nInvalid option, please try again!\n\n");
        }

    } while(option != '5');

    printf("\nThank you for using our Expense Tracker!\n");
    return 0;
}