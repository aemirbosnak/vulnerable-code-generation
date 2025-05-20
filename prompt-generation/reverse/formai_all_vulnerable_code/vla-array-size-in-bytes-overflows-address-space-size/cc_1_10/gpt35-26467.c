//FormAI DATASET v1.0 Category: Stock market tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stock {
    char company[50];
    float price;
    float change;
};

void display(struct stock s[], int n) {
    printf("\nCompany\t\tPrice\t\tChange\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t\t%.2f\t\t%.2f\n", s[i].company, s[i].price, s[i].change);
    }
}

int main() {
    int n;
    printf("Enter the number of companies to track: ");
    scanf("%d", &n);

    struct stock s[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the name of company %d: ", i + 1);
        scanf("%s", s[i].company);
        printf("Enter the price of %s: ", s[i].company);
        scanf("%f", &s[i].price);
    }
    printf("\nInitial Stock Prices\n");
    display(s, n);

    int choice;
    float new_price;
    while (1) {
        printf("\nMenu\n");
        printf("1. Update Stock Prices\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                for (int i = 0; i < n; i++) {
                    printf("Enter the updated price of %s: ", s[i].company);
                    scanf("%f", &new_price);
                    s[i].change = new_price - s[i].price;
                    s[i].price = new_price;
                }
                printf("\nUpdated Stock Prices\n");
                display(s, n);
                break;
            case 2:
                printf("Exiting Stock Market Tracker\n");
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}