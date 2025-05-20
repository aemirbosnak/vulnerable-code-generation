//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <ctype.h>

#define LIST_SIZE 10
#define ARROW "   ^"
#define LINE "----------"

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void print_list(Node *head) {
    Node *current = head;

    printf("\nLinked List Visualization:\n");
    printf("%s\n", LINE);

    while (current != NULL) {
        printf("| %d ", current->data);
        fflush(stdout);
        usleep(50000);

        if (current->next != NULL) {
            printf("%s ", ARROW);
            fflush(stdout);
            usleep(50000);
        }

        current = current->next;

        if (current != NULL) {
            printf("%s\n", LINE);
            fflush(stdout);
        }
    }
}

void create_list(Node **head) {
    Node *new_node, *current;
    int i;

    *head = NULL;

    for (i = 0; i < LIST_SIZE; i++) {
        new_node = (Node *) malloc(sizeof(Node));
        new_node->data = rand() % 100;
        new_node->next = NULL;

        if (*head == NULL) {
            *head = new_node;
            current = new_node;
        } else {
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = new_node;
        }
    }
}

int main() {
    Node *head = NULL;
    srand(time(NULL));

    printf("Generating random list of size %d:\n", LIST_SIZE);
    create_list(&head);

    printf("\nRandom List:\n");
    print_list(head);

    free(head);

    return 0;
}