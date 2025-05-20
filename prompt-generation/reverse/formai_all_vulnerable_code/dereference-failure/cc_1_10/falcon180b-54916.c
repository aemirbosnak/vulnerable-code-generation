//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000

typedef struct {
    char word[MAX_SIZE];
    int count;
} Word;

typedef struct node {
    struct node* left;
    struct node* right;
    Word data;
} Node;

Node* create_node(Word word) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->data.word, word.word);
    new_node->data.count = word.count;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

int compare(Word a, Word b) {
    return strcmp(a.word, b.word);
}

Node* insert(Node* root, Word word) {
    if (root == NULL) {
        return create_node(word);
    }

    if (compare(word, root->data) < 0) {
        root->left = insert(root->left, word);
    } else if (compare(word, root->data) > 0) {
        root->right = insert(root->right, word);
    }

    return root;
}

void inorder(Node* root) {
    if (root!= NULL) {
        inorder(root->left);
        printf("%s %d\n", root->data.word, root->data.count);
        inorder(root->right);
    }
}

void search(Node* root, char* word) {
    if (root == NULL) {
        printf("Word not found\n");
        return;
    }

    if (strcmp(word, root->data.word) == 0) {
        printf("%s %d\n", root->data.word, root->data.count);
        return;
    }

    if (strcmp(word, root->data.word) < 0) {
        search(root->left, word);
    } else {
        search(root->right, word);
    }
}

int main() {
    Word words[] = {{"apple", 3}, {"banana", 2}, {"cherry", 1}, {"date", 1}, {"elderberry", 1}};
    int n = sizeof(words) / sizeof(Word);

    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, words[i]);
    }

    printf("Inorder traversal:\n");
    inorder(root);

    char search_word[MAX_SIZE];
    printf("\nEnter a word to search: ");
    scanf("%s", search_word);
    search(root, search_word);

    return 0;
}