//Falcon-180B DATASET v1.0 Category: Data mining ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct node {
    char *data;
    int freq;
    struct node *next;
};

struct node *root = NULL;

void insert(char *str) {
    int i, len = strlen(str);
    struct node *temp = root;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    new_node->data = (char *)malloc(len * sizeof(char));
    strcpy(new_node->data, str);
    new_node->freq = 1;
    new_node->next = NULL;

    if (root == NULL) {
        root = new_node;
        return;
    }

    while (temp!= NULL) {
        if (strcmp(temp->data, str) == 0) {
            temp->freq++;
            return;
        }
        temp = temp->next;
    }

    new_node->next = root;
    root = new_node;
}

void display(int k) {
    struct node *temp = root;
    int count = 0;

    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }

    while (temp!= NULL) {
        if (temp->freq >= k) {
            printf("%s %d\n", temp->data, temp->freq);
            count++;
        }
        temp = temp->next;
    }
}

int main() {
    char *str[] = {"apple", "banana", "orange", "apple", "banana", "banana", "grape", "orange", "pear", "orange"};
    int n = sizeof(str) / sizeof(str[0]);

    for (int i = 0; i < n; i++) {
        insert(str[i]);
    }

    printf("Frequencies of fruits:\n");
    display(2);

    return 0;
}