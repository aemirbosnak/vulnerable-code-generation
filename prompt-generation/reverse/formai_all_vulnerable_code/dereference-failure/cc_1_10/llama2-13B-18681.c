//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

#define MAX_STRING_LENGTH 1024
#define MAX_NUMBER_OF_SEARCH_ATTEMPTS 10

struct node {
    int data;
    struct node *next;
};

int search_algorithm(struct node *head, int target) {
    int found = 0;
    struct node *current = head;

    while (current != NULL) {
        if (current->data == target) {
            found = 1;
            break;
        }
        current = current->next;
    }

    return found;
}

int main() {
    struct node *head = NULL;
    int target = 12;

    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        int data = rand() % 10;
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = data;
        new_node->next = head;
        head = new_node;
    }

    for (int i = 0; i < 10; i++) {
        int found = search_algorithm(head, target);
        if (found) {
            printf("Found %d at position %d\n", target, i);
        } else {
            printf("Not found %d\n", target);
        }
    }

    return 0;
}