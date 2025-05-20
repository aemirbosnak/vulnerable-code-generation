//FormAI DATASET v1.0 Category: Data structures visualization ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define a struct for holding a person's name and age
typedef struct {
    char *name;
    int age;
} Person;

// Define a linked list node for holding a person and a pointer to the next node
typedef struct node {
    Person *person;
    struct node *next;
} Node;

// Function for creating a new person
Person *create_person(char *name, int age) {
    // Allocate memory for the person struct
    Person *person = malloc(sizeof(Person));
    if (person == NULL) {
        printf("Error: Failed to allocate memory for person\n");
        exit(1);
    }

    // Allocate memory for the name string and copy the parameter name into it
    int name_len = strlen(name);
    person->name = malloc(name_len + 1);
    if (person->name == NULL) {
        printf("Error: Failed to allocate memory for name\n");
        exit(1);
    }
    strcpy(person->name, name);

    // Set the age parameter
    person->age = age;

    return person;
}

// Function for creating a new linked list node with the given person
Node *create_node(Person *person) {
    // Allocate memory for the node struct
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        printf("Error: Failed to allocate memory for node\n");
        exit(1);
    }

    // Set the node's person pointer
    node->person = person;

    // Set the node's next pointer to NULL
    node->next = NULL;

    return node;
}

// Function for adding a person to the end of a linked list
void add_person(Node **head_ptr, Person *person) {
    // Create a new linked list node with the given person
    Node *new_node = create_node(person);

    // If the linked list is empty, set the head pointer to the new node
    if (*head_ptr == NULL) {
        *head_ptr = new_node;
        return;
    }

    // Find the last node in the linked list
    Node *last_node = *head_ptr;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }

    // Set the last node's next pointer to the new node
    last_node->next = new_node;
}

// Function for printing a person's name and age
void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
}

// Function for printing a linked list of people
void print_list(Node *head) {
    // If the linked list is empty, print a message indicating that
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }

    // Iterate over each node in the linked list and print the person it contains
    Node *node = head;
    while (node != NULL) {
        print_person(node->person);
        node = node->next;
    }
}

int main() {
    // Create some example people
    Person *alice = create_person("Alice", 25);
    Person *bob = create_person("Bob", 30);
    Person *charlie = create_person("Charlie", 40);

    // Create a linked list and add the people to it
    Node *head = NULL;
    add_person(&head, alice);
    add_person(&head, bob);
    add_person(&head, charlie);

    // Print the linked list
    printf("Here are the people in the list:\n");
    print_list(head);

    // Free the memory allocated for the people and the linked list nodes
    free(alice->name);
    free(alice);
    free(bob->name);
    free(bob);
    free(charlie->name);
    free(charlie);
    Node *node = head;
    while (node != NULL) {
        Node *next_node = node->next;
        free(node->person->name);
        free(node->person);
        free(node);
        node = next_node;
    }

    return 0;
}