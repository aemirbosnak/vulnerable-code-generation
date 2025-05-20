//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct node {
    char *name;
    float price;
    struct node *next;
};

void add_stock(struct node **head, char *name, float price) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));

    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }

    new_node->name = name;
    new_node->price = price;
    new_node->next = *head;
    *head = new_node;
}

void delete_stock(struct node **head, char *name) {
    struct node *temp = *head;

    if (temp!= NULL && strcmp(temp->name, name) == 0) {
        *head = temp->next;
        free(temp);
    } else {
        while (temp!= NULL && strcmp(temp->name, name)!= 0) {
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("Stock not found\n");
        } else {
            struct node *del_node = temp->next;
            temp->next = temp->next->next;
            free(del_node);
        }
    }
}

void display_stocks(struct node *head) {
    while (head!= NULL) {
        printf("%s - $%.2f\n", head->name, head->price);
        head = head->next;
    }
}

void update_stock_price(struct node **head, char *name, float new_price) {
    struct node *temp = *head;

    while (temp!= NULL && strcmp(temp->name, name)!= 0) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Stock not found\n");
    } else {
        temp->price = new_price;
    }
}

int main() {
    struct node *head = NULL;

    add_stock(&head, "AAPL", 150.00);
    add_stock(&head, "GOOG", 1000.00);
    add_stock(&head, "MSFT", 200.00);

    printf("Initial stocks:\n");
    display_stocks(head);

    update_stock_price(&head, "AAPL", 160.00);

    printf("\nAfter updating AAPL stock price:\n");
    display_stocks(head);

    delete_stock(&head, "GOOG");

    printf("\nAfter deleting GOOG stock:\n");
    display_stocks(head);

    return 0;
}