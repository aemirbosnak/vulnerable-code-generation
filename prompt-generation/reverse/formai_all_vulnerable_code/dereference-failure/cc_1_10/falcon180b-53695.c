//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_TREE_HEIGHT 100

struct tree_node {
    char word[MAX_WORD_LENGTH];
    int height;
    struct tree_node *left;
    struct tree_node *right;
};

struct tree_node *create_node(char *word) {
    struct tree_node *new_node = (struct tree_node *)malloc(sizeof(struct tree_node));
    strcpy(new_node->word, word);
    new_node->height = rand() % MAX_TREE_HEIGHT + 1;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void print_tree(struct tree_node *root, int space) {
    if (root == NULL)
        return;

    space += 10;

    print_tree(root->right, space);

    printf("\n");
    for (int i = 0; i < space; i++)
        printf(" ");
    printf("%s\n", root->word);

    print_tree(root->left, space);
}

void delete_tree(struct tree_node *root) {
    if (root == NULL)
        return;

    delete_tree(root->left);
    delete_tree(root->right);

    free(root);
}

int main() {
    srand(time(NULL));

    struct tree_node *root = NULL;

    char input_buffer[MAX_WORD_LENGTH];

    printf("Enter words (type 'done' when finished):\n");

    while (fgets(input_buffer, MAX_WORD_LENGTH, stdin)!= NULL) {
        if (strcmp(input_buffer, "done") == 0)
            break;

        char *word = strtok(input_buffer, " ");
        struct tree_node *new_node = create_node(word);

        if (root == NULL)
            root = new_node;
        else {
            struct tree_node *current = root;

            while (1) {
                if (strcmp(word, current->word) < 0) {
                    if (current->left == NULL) {
                        current->left = new_node;
                        break;
                    } else
                        current = current->left;
                } else {
                    if (current->right == NULL) {
                        current->right = new_node;
                        break;
                    } else
                        current = current->right;
                }
            }
        }
    }

    printf("Binary search tree:\n");
    print_tree(root, 0);

    delete_tree(root);

    return 0;
}