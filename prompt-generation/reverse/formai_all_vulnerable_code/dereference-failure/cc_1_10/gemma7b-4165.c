//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct item {
    char name[20];
    int quantity;
    float price;
    struct item* next;
};

struct customer {
    char name[20];
    int account_number;
    struct customer* next;
};

struct sale {
    struct item* item_list;
    struct customer* customer_list;
    int total_amount;
    struct sale* next;
};

void insert_item(struct item** head, char name, int quantity, float price) {
    struct item* new_item = (struct item*)malloc(sizeof(struct item));
    strcpy(new_item->name, name);
    new_item->quantity = quantity;
    new_item->price = price;
    new_item->next = NULL;

    if (*head == NULL) {
        *head = new_item;
    } else {
        (*head)->next = new_item;
    }
}

void insert_customer(struct customer** head, char name, int account_number) {
    struct customer* new_customer = (struct customer*)malloc(sizeof(struct customer));
    strcpy(new_customer->name, name);
    new_customer->account_number = account_number;
    new_customer->next = NULL;

    if (*head == NULL) {
        *head = new_customer;
    } else {
        (*head)->next = new_customer;
    }
}

void insert_sale(struct sale** head, struct item* item_list, struct customer* customer_list, int total_amount) {
    struct sale* new_sale = (struct sale*)malloc(sizeof(struct sale));
    new_sale->item_list = item_list;
    new_sale->customer_list = customer_list;
    new_sale->total_amount = total_amount;
    new_sale->next = NULL;

    if (*head == NULL) {
        *head = new_sale;
    } else {
        (*head)->next = new_sale;
    }
}

int main() {
    struct item* head_item = NULL;
    struct customer* head_customer = NULL;
    struct sale* head_sale = NULL;

    // Insert items
    insert_item(&head_item, "Panadol", 10, 20.0);
    insert_item(&head_item, "Ibuprofen", 5, 15.0);
    insert_item(&head_item, "Acetaminophen", 7, 12.0);

    // Insert customers
    insert_customer(&head_customer, "John Doe", 12345);
    insert_customer(&head_customer, "Jane Doe", 65432);

    // Insert sales
    insert_sale(&head_sale, head_item, head_customer, 500);
    insert_sale(&head_sale, head_item, head_customer, 300);

    // Print sales
    struct sale* current_sale = head_sale;
    while (current_sale) {
        printf("Customer name: %s\n", current_sale->customer_list->name);
        printf("Account number: %d\n", current_sale->customer_list->account_number);
        printf("Total amount: %d\n", current_sale->total_amount);

        struct item* current_item = current_sale->item_list;
        while (current_item) {
            printf("Item name: %s\n", current_item->name);
            printf("Quantity: %d\n", current_item->quantity);
            printf("Price: %.2f\n", current_item->price);
            printf("\n");
        }

        current_sale = current_sale->next;
    }

    return 0;
}