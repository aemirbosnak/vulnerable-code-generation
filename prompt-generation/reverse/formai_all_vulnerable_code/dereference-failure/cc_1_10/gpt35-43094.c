//FormAI DATASET v1.0 Category: Stock market tracker ; Style: distributed
#include <stdio.h>

// Define the Node structure for a Linked List
struct Node {
    char* symbol;
    double price;
    struct Node* next;
};

int main() {
    // Initialize the Linked List with 3 Nodes
    struct Node* head = NULL;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->symbol = "AAPL";
    head->price = 157.41;
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->symbol = "GOOGL";
    head->next->price = 1065.23;
    head->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->symbol = "AMZN";
    head->next->next->price = 1777.08;
    head->next->next->next = NULL;

    // Display initial prices of each stock
    printf("Initial prices:\n");
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%s: %f\n", curr->symbol, curr->price);
        curr = curr->next;
    }

    // Simulate changes in stock prices
    double priceChange[3] = { -2.57, 1.84, -3.32 };
    int i = 0;
    curr = head;
    while (curr != NULL) {
        curr->price += priceChange[i];
        i++;
        curr = curr->next;
    }

    // Display updated prices of each stock
    printf("\nUpdated prices:\n");
    curr = head;
    while (curr != NULL) {
        printf("%s: %f\n", curr->symbol, curr->price);
        curr = curr->next;
    }

    return 0;
}