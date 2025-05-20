//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//Node structure for linked list
struct Node{
    char name[50];
    int quantity;
    float price;
    struct Node* next;
};

//Function to add a node at the end of the linked list
void addNode(struct Node** head_ref, char name[50], int quantity, float price){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    strcpy(new_node->name, name);
    new_node->quantity = quantity;
    new_node->price = price;
    new_node->next = NULL;

    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }

    struct Node* last = *head_ref;
    while(last->next!= NULL){
        last = last->next;
    }
    last->next = new_node;
}

//Function to print the linked list
void printList(struct Node* node){
    while(node!= NULL){
        printf("Name: %s\n", node->name);
        printf("Quantity: %d\n", node->quantity);
        printf("Price: %0.2f\n", node->price);
        printf("\n");
        node = node->next;
    }
}

//Function to calculate the total cost of items in the linked list
float calculateTotal(struct Node* node){
    float total = 0.0;
    while(node!= NULL){
        total += node->quantity * node->price;
        node = node->next;
    }
    return total;
}

int main(){
    struct Node* head = NULL;

    //Add nodes to the linked list
    addNode(&head, "Coffee", 2, 50.00);
    addNode(&head, "Tea", 1, 25.00);
    addNode(&head, "Cake", 1, 100.00);

    //Print the linked list
    printf("Items in the order:\n");
    printList(head);

    //Calculate the total cost of items in the order
    float total = calculateTotal(head);
    printf("\nTotal cost of the order: %0.2f\n", total);

    return 0;
}