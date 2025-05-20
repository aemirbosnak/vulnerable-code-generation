//Gemma-7B DATASET v1.0 Category: Performance-Critical Component ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#pragma optimize("speed")
#endif

__inline__ int hash(char *str) {
    int h = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        h = (h * 33) + str[i];
    }
    return h;
}

struct node {
    char *str;
    struct node *next;
};

struct node *insert(struct node *head, char *str) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->str = strdup(str);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct node *curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    return head;
}

void search(struct node *head, char *str) {
    struct node *curr = head;
    while (curr) {
        if (strcmp(curr->str, str) == 0) {
            printf("Found: %s\n", curr->str);
            return;
        }
        curr = curr->next;
    }

    printf("Not found: %s\n", str);
}

int main() {
    struct node *head = NULL;
    insert(head, "a");
    insert(head, "b");
    insert(head, "c");
    insert(head, "d");

    search(head, "b");
    search(head, "e");

    return 0;
}