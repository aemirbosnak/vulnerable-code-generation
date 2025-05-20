//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

struct node {
    char data;
    int freq;
    struct node *next;
};

struct node *create_node(char data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->freq = 1;
    new_node->next = NULL;
    return new_node;
}

struct node *insert_node(struct node *root, char data) {
    struct node *temp = root;
    while (temp->next!= NULL) {
        if (temp->data == data) {
            temp->freq++;
            return root;
        }
        temp = temp->next;
    }
    struct node *new_node = create_node(data);
    new_node->next = root;
    root = new_node;
    return root;
}

struct node *create_tree(char *text) {
    struct node *root = NULL;
    int i = 0;
    while (text[i]!= '\0') {
        root = insert_node(root, text[i]);
        i++;
    }
    return root;
}

struct node *create_tree_freq(char *text) {
    struct node *root = NULL;
    int i = 0;
    while (text[i]!= '\0') {
        root = insert_node(root, text[i]);
        i++;
    }
    struct node *temp = root;
    while (temp!= NULL) {
        temp->freq = 1;
        temp = temp->next;
    }
    return root;
}

void print_tree(struct node *root) {
    struct node *temp = root;
    while (temp!= NULL) {
        printf("%c %d\n", temp->data, temp->freq);
        temp = temp->next;
    }
}

void delete_tree(struct node *root) {
    struct node *temp = root;
    while (temp!= NULL) {
        struct node *next_node = temp->next;
        free(temp);
        temp = next_node;
    }
}

int main() {
    char text[MAX_SIZE];
    printf("Enter the text: ");
    scanf("%s", text);
    struct node *tree = create_tree(text);
    printf("Original tree:\n");
    print_tree(tree);
    struct node *tree_freq = create_tree_freq(text);
    printf("\nFrequency tree:\n");
    print_tree(tree_freq);
    delete_tree(tree);
    delete_tree(tree_freq);
    return 0;
}