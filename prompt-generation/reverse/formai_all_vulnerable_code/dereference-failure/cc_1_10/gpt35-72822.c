//FormAI DATASET v1.0 Category: Banking Record System ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char *acc_num;
    char *name;
    char *address;
    char *phone_num;
    float balance;
} customer;

void add_customer(customer *customers[], int *num_customers){
    char name[50], address[100], phone_num[15], acc_num[10];
    float balance;

    printf("Enter Account Number: ");
    scanf("%s", acc_num);

    printf("Enter Name: ");
    scanf("%s", name);

    printf("Enter Address: ");
    scanf("%s", address);

    printf("Enter Phone Number: ");
    scanf("%s", phone_num);

    printf("Enter Opening Balance: ");
    scanf("%f", &balance);

    customer *new_cust = (customer *) malloc(sizeof(customer));
    new_cust->name = (char *) malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(new_cust->name, name);
    new_cust->address = (char *) malloc(sizeof(char) * (strlen(address) + 1));
    strcpy(new_cust->address, address);
    new_cust->phone_num = (char *) malloc(sizeof(char) * (strlen(phone_num) + 1));
    strcpy(new_cust->phone_num, phone_num);
    new_cust->acc_num = (char *) malloc(sizeof(char) * (strlen(acc_num) + 1));
    strcpy(new_cust->acc_num, acc_num);
    new_cust->balance = balance;

    customers[*num_customers] = new_cust;
    (*num_customers)++;
}

void display_customers(customer *customers[], int num_customers){
    printf("\nCustomers:\n");
    for(int i = 0; i < num_customers; i++){
        printf("-------------\n");
        printf("Account Number: %s\n", customers[i]->acc_num);
        printf("Name: %s\n", customers[i]->name);
        printf("Address: %s\n", customers[i]->address);
        printf("Phone Number: %s\n", customers[i]->phone_num);
        printf("Balance: %.2f\n", customers[i]->balance);
        printf("-------------\n");
    }
}

void deposit(customer *customers[], int num_customers){
    char acc_num[10];
    float amount;
    int found_customer = 0;

    printf("Enter Account Number: ");
    scanf("%s", acc_num);

    for(int i = 0; i < num_customers; i++){
        if(strcmp(customers[i]->acc_num, acc_num) == 0){
            found_customer = 1;
            printf("Enter Amount: ");
            scanf("%f", &amount);
            customers[i]->balance += amount;
            printf("New Balance: %.2f\n", customers[i]->balance);
            break;
        }
    }

    if(!found_customer){
        printf("Sorry, Customer not found.\n");
    }
}

void withdraw(customer *customers[], int num_customers){
    char acc_num[10];
    float amount;
    int found_customer = 0;

    printf("Enter Account Number: ");
    scanf("%s", acc_num);

    for(int i = 0; i < num_customers; i++){
        if(strcmp(customers[i]->acc_num, acc_num) == 0){
            found_customer = 1;
            printf("Enter Amount: ");
            scanf("%f", &amount);
            if(customers[i]->balance < amount){
                printf("Sorry, insufficient balance.\n");
            }
            else{
                customers[i]->balance -= amount;
                printf("New Balance: %.2f\n", customers[i]->balance);
            }
            break;
        }
    }

    if(!found_customer){
        printf("Sorry, Customer not found.\n");
    }
}

int main(){
    customer *customers[100] = {NULL};
    int num_customers = 0;
    int choice;

    printf("C Bank Record System\n");

    while(1){
        printf("\nMenu:\n");
        printf("1. Add Customer\n");
        printf("2. Display All Customers\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_customer(customers, &num_customers);
                break;
            case 2:
                display_customers(customers, num_customers);
                break;
            case 3:
                deposit(customers, num_customers);
                break;
            case 4:
                withdraw(customers, num_customers);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Choice.\n");
                break;
        }
    }

    return 0;
}