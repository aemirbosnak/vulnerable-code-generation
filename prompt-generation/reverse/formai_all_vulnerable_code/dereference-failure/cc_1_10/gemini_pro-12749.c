//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

struct Node {
    char name[50];
    int quantity;
    float price;
    struct Node *next;
};

struct Node *head = NULL;

void add_item(char *name, int quantity, float price) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    strcpy(new_node->name, name);
    new_node->quantity = quantity;
    new_node->price = price;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void print_bill() {
    struct Node *temp = head;
    printf("ITEM NAME\tQUANTITY\tPRICE\n");
    while (temp != NULL) {
        printf("%s\t%d\t%.2f\n", temp->name, temp->quantity, temp->price);
        temp = temp->next;
    }
}

float calculate_total() {
    float total = 0;
    struct Node *temp = head;
    while (temp != NULL) {
        total += temp->quantity * temp->price;
        temp = temp->next;
    }
    return total;
}

int main() {
    add_item("Coffee", 2, 1.50);
    add_item("Tea", 1, 1.25);
    add_item("Cake", 1, 2.00);
    print_bill();
    printf("Total: %.2f\n", calculate_total());
    return 0;
}