//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node {
    char word[100];
    int count;
    struct node *left;
    struct node *right;
};

struct node *create_node(char *word) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    strcpy(newnode->word, word);
    newnode->count = 1;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node *insert_word(struct node *root, char *word) {
    if (root == NULL) {
        root = create_node(word);
        return root;
    }

    if (strcmp(word, root->word) < 0)
        root->left = insert_word(root->left, word);
    else
        root->right = insert_word(root->right, word);

    root->count++;

    return root;
}

void print_words(struct node *root, int space) {
    if (root == NULL)
        return;

    print_words(root->right, space + 4);

    printf("%*s%d\t%s\n", space, "", root->count, root->word);

    print_words(root->left, space + 4);
}

int main() {
    FILE *file;
    char word[100];
    struct node *root = NULL;

    file = fopen("words.txt", "r");

    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fscanf(file, "%s", word)!= EOF) {
        root = insert_word(root, word);
    }

    fclose(file);

    printf("Words in the tree:\n");
    print_words(root, 0);

    return 0;
}