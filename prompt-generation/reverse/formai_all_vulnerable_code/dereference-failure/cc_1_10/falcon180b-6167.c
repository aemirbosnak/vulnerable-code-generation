//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 10
#define MAX_STRING 100

typedef struct node {
    int id;
    char *string;
    struct node *next;
} Node;

Node *new_node(int id, char *string) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->id = id;
    n->string = strdup(string);
    n->next = NULL;
    return n;
}

void delete_node(Node *n) {
    free(n->string);
    free(n);
}

void print_list(Node *head) {
    Node *n = head;
    while (n!= NULL) {
        printf("%d %s\n", n->id, n->string);
        n = n->next;
    }
}

int search_string(Node *head, char *string) {
    Node *n = head;
    while (n!= NULL) {
        if (strcmp(n->string, string) == 0)
            return n->id;
        n = n->next;
    }
    return -1;
}

int main() {
    int i, n;
    char string[MAX_STRING];

    Node *head = NULL;

    printf("Enter number of strings: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter string %d: ", i+1);
        scanf("%s", string);
        head = new_node(i+1, string);
    }

    printf("Enter string to search: ");
    scanf("%s", string);

    int result = search_string(head, string);

    if (result == -1)
        printf("String not found.\n");
    else
        printf("String found with ID %d.\n", result);

    print_list(head);

    return 0;
}