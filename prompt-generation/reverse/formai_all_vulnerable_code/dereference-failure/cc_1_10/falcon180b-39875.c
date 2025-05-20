//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

typedef struct word_count {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

typedef struct node {
    struct node* left;
    struct node* right;
    WordCount data;
} Node;

Node* create_node(char* word) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->data.word, word);
    new_node->data.count = 1;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_word(Node* node, char* word) {
    if (node == NULL) {
        node = create_node(word);
    } else if (strcmp(node->data.word, word) == 0) {
        node->data.count++;
    } else if (strcmp(node->data.word, word) > 0) {
        insert_word(node->left, word);
    } else {
        insert_word(node->right, word);
    }
}

void print_in_order(Node* node) {
    if (node!= NULL) {
        print_in_order(node->left);
        printf("%s: %d\n", node->data.word, node->data.count);
        print_in_order(node->right);
    }
}

int main() {
    FILE* file = fopen("romeo_and_juliet.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char word[MAX_WORD_LEN];
    int word_count = 0;

    Node* root = NULL;

    while (fscanf(file, "%s", word)!= EOF) {
        insert_word(root, word);
        word_count++;
    }

    printf("Total words: %d\n", word_count);
    print_in_order(root);

    fclose(file);
    return 0;
}