//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a baggage item
typedef struct baggage_item {
    char *name;
    int weight;
    struct baggage_item *next;
} baggage_item;

// Define a function to insert a baggage item into a linked list
void insert_baggage_item(baggage_item **head, char *name, int weight) {
    baggage_item *new_item = malloc(sizeof(baggage_item));
    new_item->name = strdup(name);
    new_item->weight = weight;
    new_item->next = NULL;

    if (*head == NULL) {
        *head = new_item;
    } else {
        (*head)->next = new_item;
    }
}

// Define a function to calculate the total weight of a baggage item list
int calculate_total_weight(baggage_item *head) {
    int total_weight = 0;
    while (head) {
        total_weight += head->weight;
        head = head->next;
    }
    return total_weight;
}

// Define a function to print the baggage item list
void print_baggage_items(baggage_item *head) {
    while (head) {
        printf("%s (%.2f kg)\n", head->name, head->weight);
        head = head->next;
    }
}

int main() {
    // Create a linked list of baggage items
    baggage_item *baggage_list = NULL;

    // Insert some baggage items
    insert_baggage_item(&baggage_list, "Laptop", 15);
    insert_baggage_item(&baggage_list, "Toiletries", 5);
    insert_baggage_item(&baggage_list, "Clothing", 20);
    insert_baggage_item(&baggage_list, "Documents", 2);

    // Print the baggage items
    print_baggage_items(baggage_list);

    // Calculate the total weight of the baggage items
    int total_weight = calculate_total_weight(baggage_list);

    // Print the total weight
    printf("Total weight: %.2f kg\n", total_weight);

    return 0;
}