//FormAI DATASET v1.0 Category: Banking Record System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure definition for the banking record
struct BankRecord
{
    int accountNumber;
    char firstName[20];
    char lastName[20];
    float currentBalance;
};

//Function prototype for display menu
void displayMenu();

//Function prototype for addAccount
void addAccount(struct BankRecord** bankRecords, int count);

//Function prototype for deleteAccount
void deleteAccount(struct BankRecord** bankRecords, int count);

//Function prototype for updateAccount
void updateAccount(struct BankRecord* bankRecord);

//Function prototype for searchAccount
void searchAccount(struct BankRecord* bankRecord);

//Main function
int main()
{
    int choice, count=0, i;
    struct BankRecord **bankRecords; //Pointer to a pointer to struct BankRecord
    
    displayMenu(); //Display menu
    
    //Allocate memory for array of pointers to struct BankRecord
    bankRecords = (struct BankRecord **)malloc(sizeof(struct BankRecord));
    
    while(1)
    {
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                addAccount(bankRecords, count);
                count++;
                bankRecords = (struct BankRecord **)realloc(bankRecords, (count+1)*sizeof(struct BankRecord));
                break;
            case 2:
                deleteAccount(bankRecords, count);
                count--;
                bankRecords = (struct BankRecord **)realloc(bankRecords, (count)*sizeof(struct BankRecord));
                break;
            case 3:
                for(i=0; i<count; i++)
                    updateAccount(*(bankRecords+i));
                break;
            case 4:
                for(i=0; i<count; i++)
                    searchAccount(*(bankRecords+i));
                break;
            case 5:
                printf("\nBank records: \n");
                for(i=0; i<count; i++)
                {
                    printf("Account Number: %d\n", (*(bankRecords+i))->accountNumber);
                    printf("First Name: %s\n", (*(bankRecords+i))->firstName);
                    printf("Last Name: %s\n", (*(bankRecords+i))->lastName);
                    printf("Current Balance: %.2f\n", (*(bankRecords+i))->currentBalance);
                }
                break;
            case 6:
                printf("\nExiting program...");
                exit(0);
            default:
                printf("\nInvalid choice! Try again.");
        }
    }
    return 0;
}

//Function definition for displayMenu
void displayMenu()
{
    printf("Banking Record System\n");
    printf("----------------------------------------------\n");
    printf("1. Add Account\n");
    printf("2. Delete Account\n");
    printf("3. Update Account\n");
    printf("4. Search Account\n");
    printf("5. Display Accounts\n");
    printf("6. Exit\n");
    printf("----------------------------------------------\n");
}

//Function definition for addAccount
void addAccount(struct BankRecord** bankRecords, int count)
{
    int accountNumber;
    char firstName[20];
    char lastName[20];
    float currentBalance;

    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);
    printf("\nEnter first name: ");
    scanf("%s", firstName);
    printf("\nEnter last name: ");
    scanf("%s", lastName);
    printf("\nEnter current balance: ");
    scanf("%f", &currentBalance);

    // Allocate memory for new BankRecord and assign new values
    *(bankRecords+count) = (struct BankRecord *)malloc(sizeof(struct BankRecord));
    (*(bankRecords+count))->accountNumber = accountNumber;
    strcpy((*(bankRecords+count))->firstName, firstName);
    strcpy((*(bankRecords+count))->lastName, lastName);
    (*(bankRecords+count))->currentBalance = currentBalance;

    printf("\nAccount added successfully!");
}

//Function definition for deleteAccount
void deleteAccount(struct BankRecord** bankRecords, int count)
{
    int accountNumber, i, j, found=0;

    printf("\nEnter account number to delete: ");
    scanf("%d", &accountNumber);

    //Find record with matching account number and delete it
    for(i=0; i<count; i++)
    {
        if((*(bankRecords+i))->accountNumber == accountNumber)
        {
            found = 1;
            free(*(bankRecords+i));
            for(j=i; j<count-1; j++)
                *(bankRecords+j) = *(bankRecords+j+1);
            break;
        }
    }

    if(found)
        printf("\nAccount deleted successfully!");
    else
        printf("\nAccount not found!");
}

//Function definition for updateAccount
void updateAccount(struct BankRecord* bankRecord)
{
    char firstName[20];
    char lastName[20];
    float currentBalance;

    printf("\nEnter new first name for account %d: ", bankRecord->accountNumber);
    scanf("%s", firstName);
    strcpy(bankRecord->firstName, firstName);

    printf("\nEnter new last name for account %d: ", bankRecord->accountNumber);
    scanf("%s", lastName);
    strcpy(bankRecord->lastName, lastName);

    printf("\nEnter new current balance for account %d: ", bankRecord->accountNumber);
    scanf("%f", &currentBalance);
    bankRecord->currentBalance = currentBalance;

    printf("\nAccount updated successfully!");
}

//Function definition for searchAccount
void searchAccount(struct BankRecord* bankRecord)
{
    int accountNumber;

    printf("\nEnter account number to search: ");
    scanf("%d", &accountNumber);

    if(bankRecord->accountNumber == accountNumber)
    {
        printf("\nAccount found!");
        printf("\nAccount Number: %d\n", bankRecord->accountNumber);
        printf("\nFirst Name: %s\n", bankRecord->firstName);
        printf("\nLast Name: %s\n", bankRecord->lastName);
        printf("\nCurrent Balance: %.2f\n", bankRecord->currentBalance);
    }
}