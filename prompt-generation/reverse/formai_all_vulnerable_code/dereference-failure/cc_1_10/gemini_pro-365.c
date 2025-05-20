//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: random
#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    struct node *next;
};

struct node *create_node(char data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void push(struct node **head, char data) {
    struct node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

int is_palindrome(struct node *head) {
    struct node *p = head;
    int count = 0;
    while (p != NULL) {
        count++;
        p = p->next;
    }

    struct node *arr[count];
    int i = 0;
    p = head;
    while (p != NULL) {
        arr[i] = p;
        i++;
        p = p->next;
    }

    for (i = 0; i < count / 2; i++) {
        if (arr[i]->data != arr[count - 1 - i]->data) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char str[] = "radar";

    struct node *head = NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        push(&head, str[i]);
    }

    int result = is_palindrome(head);

    if (result) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}