//FormAI DATASET v1.0 Category: Banking Record System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer {
    char name[50];
    int acc_num;
    float balance;
};

void new_customer(struct customer *c, int n);
void transaction(struct customer *c, int n);

int main() {
    int choice, n;
    struct customer *c;

    printf("Welcome to our Banking Record System!\n");
    printf("Enter the number of customers you want to add: ");
    scanf("%d", &n);

    c = (struct customer*)malloc(n * sizeof(struct customer));
    new_customer(c, n);

    do {
        printf("\nSelect an option:\n");
        printf("1. Process a transaction\n");
        printf("2. Add a new customer\n");
        printf("3. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                transaction(c, n);
                break;
            case 2:
                n++;
                c = (struct customer*)realloc(c, n * sizeof(struct customer));
                new_customer(&c[n-1], 1);
                break;
            case 3:
                printf("Thank you for using our Banking Record System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    free(c);
    return 0;
}

void new_customer(struct customer *c, int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("\nCustomer #%d:\n", i+1);
        printf("Name: ");
        fflush(stdin);
        gets(c[i].name);
        printf("Account Number: ");
        scanf("%d", &c[i].acc_num);
        printf("Initial Balance: ");
        scanf("%f", &c[i].balance);
    }
}

void transaction(struct customer *c, int n) {
    int acc, i;
    float amt;

    printf("Enter Account Number: ");
    scanf("%d", &acc);

    for (i = 0; i < n; i++) {
        if (c[i].acc_num == acc) {
            printf("Account Holder Name: %s", c[i].name);
            printf("\nCurrent Balance: $%.2f", c[i].balance);
            printf("\nEnter transaction amount: ");
            scanf("%f", &amt);
            c[i].balance += amt;
            printf("\nNew Balance: $%.2f", c[i].balance);
            return;
        }
    }

    printf("\nInvalid Account Number.");
}