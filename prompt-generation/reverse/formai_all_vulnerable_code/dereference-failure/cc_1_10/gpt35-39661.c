//FormAI DATASET v1.0 Category: Banking Record System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Banking Record System in a Cyberpunk Style */

typedef struct {
    char name[20];
    char address[50];
    int account_no;
    float balance;
} customer;

/* The function prototypes */

void add_customer(customer *ptr, int *cust_count);
void view_all_customers(customer *ptr, int cust_count);
void withdraw(customer *ptr, int cust_count);
void deposit(customer *ptr, int cust_count);

int main()
{
    int option, cust_count = 0;
    customer *ptr = (customer *) malloc(sizeof(customer));

    do {
        printf("\nCyberBank - The Future of Money\n");

        printf("\n[1] Add a Customer");
        printf("\n[2] View All Customers");
        printf("\n[3] Withdraw Money");
        printf("\n[4] Deposit Money");
        printf("\n[5] Exit");

        printf("\n\nPlease Enter your Option: ");
        scanf("%d", &option);

        if (option == 1) {
            add_customer(ptr, &cust_count);
        }
        else if (option == 2) {
            view_all_customers(ptr, cust_count);
        }
        else if (option == 3) {
            withdraw(ptr, cust_count);
        }
        else if (option == 4) {
            deposit(ptr, cust_count);
        }
        else if (option == 5) {
            printf("\nThank you for choosing CyberBank - The Future of Money!\n");
            exit(0);
        }
        else {
            printf("\nInvalid Option!\n");
        }
    } while (option != 5);

    return 0;
}

void add_customer(customer *ptr, int *cust_count)
{
    printf("\nEnter Customer Name: ");
    scanf("%s", (ptr + *cust_count)->name);

    printf("Enter Customer Address: ");
    scanf("%s", (ptr + *cust_count)->address);

    printf("Enter Customer Account No: ");
    scanf("%d", &(ptr + *cust_count)->account_no);

    printf("Enter Customer Balance: ");
    scanf("%f", &(ptr + *cust_count)->balance);

    (*cust_count)++;

    printf("\nCustomer Added Successfully!\n");
}

void view_all_customers(customer *ptr, int cust_count)
{
    if (cust_count == 0) {
        printf("\nNo Records Found!\n");
        return;
    }

    printf("\nCustomer List:\n");

    for (int i = 0; i < cust_count; i++) {
        printf("\nCustomer No: %d", i + 1);
        printf("\nName: %s", (ptr + i)->name);
        printf("\nAddress: %s", (ptr + i)->address);
        printf("\nAccount No: %d", (ptr + i)->account_no);
        printf("\nBalance: %.2f", (ptr + i)->balance);
        printf("\n");
    }
}

void withdraw(customer *ptr, int cust_count)
{
    int account_no, found = 0;
    float amount;

    printf("\nEnter Account No: ");
    scanf("%d", &account_no);

    for (int i = 0; i < cust_count; i++) {
        if ((ptr + i)->account_no == account_no) {
            found = 1;

            printf("Enter Withdrawal Amount: ");
            scanf("%f", &amount);

            if ((ptr + i)->balance < amount) {
                printf("\nInsufficient Balance!\n");
                return;
            }

            (ptr + i)->balance -= amount;

            printf("\nAmount Withdrawn Successfully!\n");
            printf("\nNew Balance: %.2f\n", (ptr + i)->balance);

            break;
        }
    }

    if (!found) {
        printf("\nAccount Not Found!\n");
    }
}

void deposit(customer *ptr, int cust_count)
{
    int account_no, found = 0;
    float amount;

    printf("\nEnter Account No: ");
    scanf("%d", &account_no);

    for (int i = 0; i < cust_count; i++) {
        if ((ptr + i)->account_no == account_no) {
            found = 1;

            printf("Enter Deposit Amount: ");
            scanf("%f", &amount);

            (ptr + i)->balance += amount;

            printf("\nAmount Deposited Successfully!\n");
            printf("\nNew Balance: %.2f\n", (ptr + i)->balance);

            break;
        }
    }

    if (!found) {
        printf("\nAccount Not Found!\n");
    }
}