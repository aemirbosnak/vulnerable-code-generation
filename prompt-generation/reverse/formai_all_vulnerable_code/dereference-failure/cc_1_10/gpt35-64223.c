//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Data Structure for Baggage
struct Baggage {
    int weight;
    char destination[20];
    struct Baggage *next;
};

// Function to add Baggage
void addBaggage(struct Baggage **head_ref, int weight, char destination[]) {
    struct Baggage *new_node = (struct Baggage*) malloc(sizeof(struct Baggage));
    new_node->weight = weight;
    strcpy(new_node->destination, destination);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to print all baggage
void printBaggage(struct Baggage *node) {
    while (node != NULL) {
        printf("Destination: %s \t Weight: %d kgs\n", node->destination, node->weight);
        node = node->next;
    }
}

int main() {
    struct Baggage *head = NULL;
    int choice, weight;
    char destination[20];
    do {
        printf("Enter your choice\n1. Add Baggage\n2. Print all Baggage\n3. Exit\n");
        scanf("%d", &choice); // Take user Input
        switch(choice) {
            case 1: // Choice 1
                printf("Enter destination: ");
                scanf("%s", destination);
                printf("Enter weight of baggage (in kgs): ");
                scanf("%d", &weight);
                addBaggage(&head, weight, destination); // Call Function to add baggage
                break;
            case 2: // Choice 2
                if(head == NULL){
                    printf("No Baggage available!\n");
                }
                else{
                    printBaggage(head); // Call function to print all baggage
                }
                break;
            case 3: // Choice 3
                printf("Thank You for using the Airport Baggage Handling System!");
                break;
            default: // Invalid Choice
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while(choice != 3);
    return 0;
}