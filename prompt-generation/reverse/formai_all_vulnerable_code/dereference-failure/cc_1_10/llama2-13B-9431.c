//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LEN 100
#define MAX_CHAR 32

struct node {
    char data[MAX_LEN];
    struct node* next;
};

struct node* init_list(void) {
    struct node* head = (struct node*) malloc(sizeof(struct node));
    head->data[0] = '\0';
    head->next = NULL;
    return head;
}

void add_char(struct node** head_ref, char c) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data[0] = c;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void print_list(struct node* head) {
    while (head != NULL) {
        printf("%c", head->data[0]);
        head = head->next;
    }
    printf("\n");
}

void reverse_list(struct node** head_ref) {
    struct node* current = *head_ref;
    struct node* previous = NULL;
    while (current != NULL) {
        struct node* next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *head_ref = previous;
}

int main() {
    struct node* head = init_list();
    char c;

    // Generate a list of random characters
    while (1) {
        c = (rand() % 26) + 'a';
        add_char(&head, c);
        if (c == 'z') break;
    }

    // Print the list in reverse order
    print_list(head);

    // Reverse the list
    reverse_list(&head);

    // Print the list again
    print_list(head);

    return 0;
}