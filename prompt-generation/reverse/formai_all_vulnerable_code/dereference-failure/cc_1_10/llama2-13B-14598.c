//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 100
#define MAX_DEPTH 5

// Structure to represent a node in the recursive function
typedef struct node {
    char *str;
    int len;
    struct node *next;
} node_t;

// Function to generate a random string of given length
void generate_random_str(char *str, int len) {
    int i, j;
    for (i = 0; i < len; i++) {
        str[i] = 'a' + (rand() % 26);
    }
}

// Function to print the string in a recursive manner
void print_str_rec(node_t *head) {
    if (head == NULL) {
        return;
    }

    printf("%s", head->str);

    // Recursively print the next node
    print_str_rec(head->next);
}

// Main function
int main() {
    node_t *head = NULL;

    // Generate a random string of length 10
    char str[MAX_STR_LEN];
    generate_random_str(str, 10);

    // Create a node for the generated string
    head = (node_t *) malloc(sizeof(node_t));
    head->str = str;
    head->len = strlen(str);
    head->next = NULL;

    // Recursively print the string
    print_str_rec(head);

    return 0;
}