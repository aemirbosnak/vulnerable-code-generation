//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    char occupation[50];
} Person;

typedef struct Node {
    Person data;
    struct Node *next;
} Node;

void print_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%s, %d, %s\n", current->data.name, current->data.age, current->data.occupation);
        current = current->next;
    }
}

int main() {
    Node *head = NULL;
    Node *new_node = NULL;

    printf("--- Case File ---\n");
    printf("Sherlock Holmes investigates a mystery involving some peculiar individuals.\n");

    // Add some individuals to the list
    new_node = (Node *) malloc(sizeof(Node));
    strcpy(new_node->data.name, "Dr. Watson");
    new_node->data.age = 35;
    strcpy(new_node->data.occupation, "Doctor");
    new_node->next = head;
    head = new_node;

    new_node = (Node *) malloc(sizeof(Node));
    strcpy(new_node->data.name, "Mrs. Hudson");
    new_node->data.age = 52;
    strcpy(new_node->data.occupation, "Landlady");
    new_node->next = head;
    head = new_node;

    new_node = (Node *) malloc(sizeof(Node));
    strcpy(new_node->data.name, "Professor Moriarty");
    new_node->data.age = 45;
    strcpy(new_node->data.occupation, "Villain");
    new_node->next = head;
    head = new_node;

    // Visualize the case file
    printf("\n--- Case File Contents ---\n");
    print_list(head);

    // Free the memory
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}