//FormAI DATASET v1.0 Category: Banking Record System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// struct for storing bank record
struct BankRecord{
    int accountNumber;
    float balance;
};

int main(){
    int n;
    printf("Enter the number of customers: ");
    scanf("%d", &n);

    // initialize array of BankRecord structs
    struct BankRecord records[n];

    // loop to enter customer data
    for(int i=0; i<n; i++){
        printf("\nEnter Account Number for Customer %d: ", i+1);
        scanf("%d", &records[i].accountNumber);
        printf("Enter Initial Balance for Customer %d: ", i+1);
        scanf("%f", &records[i].balance);
    }

    // loop to perform transactions
    int transactionType, accountNum;
    float amount;
    do{
        printf("\nEnter Account Number: ");
        scanf("%d", &accountNum);
        int customerIndex = -1;
        // search for customer by account number
        for(int i=0; i<n; i++){
            if(records[i].accountNumber == accountNum){
                customerIndex = i;
                break;
            }
        }
        if(customerIndex == -1){
            printf("Invalid Account Number.\n");
            continue;
        }
        else{
            printf("\n1: Deposit Amount\n2: Withdraw Amount\n3: View Current Balance\n4: Exit\n");
            scanf("%d", &transactionType);
            switch(transactionType){
                case 1:
                    printf("Enter Amount to Deposit: ");
                    scanf("%f", &amount);
                    records[customerIndex].balance += amount;
                    printf("Deposit Successful. New Balance: %.2f\n", records[customerIndex].balance);
                    break;
                case 2:
                    printf("Enter Amount to Withdraw: ");
                    scanf("%f", &amount);
                    if(amount > records[customerIndex].balance){
                        printf("Insufficient Balance.\n");
                    }
                    else{
                        records[customerIndex].balance -= amount;
                        printf("Withdrawal Successful. New Balance: %.2f\n", records[customerIndex].balance);
                    }
                    break;
                case 3:
                    printf("Current Balance: %.2f\n", records[customerIndex].balance);
                    break;
                case 4:
                    break;
                default:
                    printf("Invalid Transaction Type.\n");
            }
        }
    } while(transactionType != 4);

    return 0;
}