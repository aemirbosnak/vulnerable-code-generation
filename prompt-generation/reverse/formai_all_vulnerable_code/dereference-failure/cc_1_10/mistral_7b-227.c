//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_LIST_SIZE 1000
#define MAX_NAME_LEN 50

// Strange structure for a mailing list node
typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    bool is_subscribed;
    struct strange_node* next;
} strange_node;

// Function to add a new node to the mailing list
void add_to_list(strange_node** list, const char* name, int age) {
    strange_node* new_node = (strange_node*) malloc(sizeof(strange_node));
    strcpy(new_node->name, name);
    new_node->age = age;
    new_node->is_subscribed = true;
    new_node->next = *list;
    *list = new_node;
}

// Function to print the mailing list
void print_list(strange_node* list) {
    strange_node* current = list;
    while (current != NULL) {
        printf("%s (%d years old)%s", current->name, current->age,
            current->next == NULL ? "" : "\n");
        current = current->next;
    }
}

int main() {
    strange_node* mailing_list = NULL;

    // Adding some nodes to the mailing list
    add_to_list(&mailing_list, "John Doe", 30);
    add_to_list(&mailing_list, "Jane Smith", 28);
    add_to_list(&mailing_list, "Bob Johnson", 42);

    // Printing the mailing list
    printf("Mailing list:\n");
    print_list(mailing_list);

    // Freeing the memory used by the mailing list
    strange_node* current = mailing_list;
    while (mailing_list != NULL) {
        mailing_list = current->next;
        free(current);
        current = mailing_list;
    }

    return 0;
}