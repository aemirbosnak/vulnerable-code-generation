//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<time.h>

struct MenuItem {
    char name[50];
    float price;
};

void displayMenu(struct MenuItem menu[], int n) {
    printf("\n");
    for(int i=0; i<n; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

void takeOrder(struct MenuItem menu[], int n, int customerID) {
    printf("\n");
    printf("Order for Customer %d:\n", customerID);
    int choice;
    float totalPrice = 0;
    while(1) {
        displayMenu(menu, n);
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        if(choice <= 0 || choice > n) {
            printf("Invalid choice.\n");
        }
        else {
            totalPrice += menu[choice-1].price;
            printf("\n%s added to your order.\n", menu[choice-1].name);
            break;
        }
    }
    printf("\nTotal Price: $%.2f\n", totalPrice);
}

void generateBill(struct MenuItem menu[], int n, int customerID, float totalPrice) {
    time_t now = time(0);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %X", localtime(&now));
    printf("\n");
    printf("Bill for Customer %d on %s:\n", customerID, timestamp);
    printf("-------------------------------------------------\n");
    for(int i=0; i<n; i++) {
        if(menu[i].price == totalPrice) {
            printf("%s\n", menu[i].name);
        }
    }
    printf("-------------------------------------------------\n");
    printf("Total Price: $%.2f\n", totalPrice);
}

int main() {
    int n;
    printf("Enter number of items in menu: ");
    scanf("%d", &n);
    struct MenuItem menu[n];
    printf("\n");
    for(int i=0; i<n; i++) {
        printf("Enter item %d:\n", i+1);
        scanf("%s", menu[i].name);
        printf("Enter price for %s: ", menu[i].name);
        scanf("%f", &menu[i].price);
    }
    int m;
    printf("\n");
    printf("Enter number of customers: ");
    scanf("%d", &m);
    for(int i=0; i<m; i++) {
        int customerID = i+1;
        takeOrder(menu, n, customerID);
    }
    return 0;
}