//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 20
#define MAX_ARRAY_LEN 10

typedef struct node {
    char *str;
    struct node *next;
} node_t;

node_t *create_list(void) {
    node_t *head = NULL;
    node_t *curr = NULL;
    char str[MAX_STR_LEN];

    // Create a list of strings
    printf("Enter a list of strings: ");
    while (scanf("%19s", str) == 1) {
        curr = (node_t *) malloc(sizeof(node_t));
        curr->str = str;
        curr->next = head;
        head = curr;
    }

    return head;
}

void print_list(node_t *head) {
    node_t *curr = head;

    // Print the list of strings
    printf("List of strings:\n");
    while (curr != NULL) {
        printf("%s\n", curr->str);
        curr = curr->next;
    }
}

int main(void) {
    node_t *head = create_list();
    print_list(head);

    // Dynamic memory allocation for an array
    int arr[MAX_ARRAY_LEN];
    for (int i = 0; i < MAX_ARRAY_LEN; i++) {
        arr[i] = i * 2;
    }

    // Print the array
    printf("Array: ");
    for (int i = 0; i < MAX_ARRAY_LEN; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the memory allocated for the array
    for (int i = 0; i < MAX_ARRAY_LEN; i++) {
        free(arr[i]);
    }

    return 0;
}