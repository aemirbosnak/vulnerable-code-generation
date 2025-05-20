//FormAI DATASET v1.0 Category: Data structures visualization ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

//Define a simple structure to store data
typedef struct Node {
    int data;
    struct Node* next;
} Node;

//Function to insert a node at the end of the list
void insert(Node** head, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    //If the list is empty, the new node becomes the head
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    //Otherwise, iterate through the list and append the new node
    Node* curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new_node;
}

//Function to print the list in a visually appealing way
void print_list(Node* head) {
    printf("\n");

    //Iterate through the list and print each node's data
    Node* curr = head;
    int count = 1;
    while (curr != NULL) {
        printf("%3d| %3d\t", count, curr->data);
        for (int i = 0; i < curr->data; i++) {
            printf("*");
        }
        printf("\n");
        curr = curr->next;
        count++;
    }
}

int main() {
    Node* head = NULL;
    srand(time(NULL));

    //Insert 5 random nodes into the list
    for (int i = 0; i < 5; i++) {
        insert(&head, rand() % 10 + 1);
    }

    //Print the list initially
    print_list(head);
    
    while (1) {
        //Insert a random node at the end of the list
        insert(&head, rand() % 10 + 1);

        //Print the updated list
        printf("\033[2J\033[;H");
        print_list(head);

        //Wait for 1 second before adding another node
        sleep(1);
    }

    return 0;
}