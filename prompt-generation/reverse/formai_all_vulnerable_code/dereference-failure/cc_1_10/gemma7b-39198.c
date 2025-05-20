//Gemma-7B DATASET v1.0 Category: Database querying ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Romeo and Juliet database structure
typedef struct {
    char name[50];
    int age;
    char faction;
    struct node* next;
} node;

// Create a linked list to store the Romeo and Juliet data
node* head = NULL;

// Function to insert a new node into the linked list
void insert(char* name, int age, char faction) {
    node* newNode = (node*)malloc(sizeof(node));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->faction = faction;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
        head = newNode;
    }
}

// Function to find a node in the linked list
node* find(char* name) {
    node* current = head;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to update a node in the linked list
void update(char* name, int age, char faction) {
    node* nodeToUpdate = find(name);
    if (nodeToUpdate) {
        strcpy(nodeToUpdate->name, name);
        nodeToUpdate->age = age;
        nodeToUpdate->faction = faction;
    }
}

// Function to delete a node from the linked list
void delete(char* name) {
    node* previous = NULL;
    node* current = head;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            current = NULL;
        } else {
            previous = current;
            current = current->next;
        }
    }
}

int main() {
    // Insert some data into the linked list
    insert("Romeo", 18, 'A');
    insert("Juliet", 16, 'B');
    insert(" Mercutio", 20, 'A');
    insert("Benvolio", 19, 'B');
    insert("Tybalt", 17, 'B');

    // Update the data of a node
    update("Romeo", 21, 'A');

    // Delete a node from the linked list
    delete("Mercutio");

    // Print the data of the nodes
    node* current = head;
    while (current) {
        printf("%s, %d, %c\n", current->name, current->age, current->faction);
        current = current->next;
    }

    return 0;
}