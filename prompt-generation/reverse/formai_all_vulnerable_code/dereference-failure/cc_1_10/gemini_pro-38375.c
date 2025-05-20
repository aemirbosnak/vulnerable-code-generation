//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Morse code tree
typedef struct node {
    char c;
    struct node *left;
    struct node *right;
} node_t;

// Create a new node
node_t *new_node(char c) {
    node_t *n = malloc(sizeof(node_t));
    n->c = c;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Insert a character into the tree
void insert(node_t **root, char c, const char *code) {
    if (*root == NULL) {
        *root = new_node(c);
    }
    if (*code == '\0') {
        return;
    }
    if (*code == '.') {
        insert(&(*root)->left, c, code + 1);
    } else if (*code == '-') {
        insert(&(*root)->right, c, code + 1);
    }
}

// Convert a character to Morse code
char *to_morse(node_t *root, char c) {
    if (root == NULL) {
        return NULL;
    }
    if (root->c == c) {
        return "";
    }
    char *left = to_morse(root->left, c);
    if (left != NULL) {
        return strcat(left, ".");
    }
    char *right = to_morse(root->right, c);
    if (right != NULL) {
        return strcat(right, "-");
    }
    return NULL;
}

// Convert a string to Morse code
char *to_morse_string(node_t *root, char *s) {
    if (s == NULL || *s == '\0') {
        return "";
    }
    char *morse = to_morse(root, *s);
    if (morse == NULL) {
        return NULL;
    }
    char *rest = to_morse_string(root, s + 1);
    if (rest == NULL) {
        free(morse);
        return NULL;
    }
    return strcat(morse, rest);
}

// Print the Morse code tree
void print_tree(node_t *root) {
    if (root == NULL) {
        return;
    }
    printf("%c: ", root->c);
    if (root->left != NULL) {
        printf(". ");
        print_tree(root->left);
    }
    if (root->right != NULL) {
        printf("- ");
        print_tree(root->right);
    }
    printf("\n");
}

// Free the Morse code tree
void free_tree(node_t *root) {
    if (root == NULL) {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main() {
    // Create the Morse code tree
    node_t *root = NULL;
    insert(&root, 'A', ".-");
    insert(&root, 'B', "-...");
    insert(&root, 'C', "-.-.");
    insert(&root, 'D', "-..");
    insert(&root, 'E', ".");
    insert(&root, 'F', "..-.");
    insert(&root, 'G', "--.");
    insert(&root, 'H', "....");
    insert(&root, 'I', "..");
    insert(&root, 'J', ".---");
    insert(&root, 'K', "-.-");
    insert(&root, 'L', ".-..");
    insert(&root, 'M', "--");
    insert(&root, 'N', "-.");
    insert(&root, 'O', "---");
    insert(&root, 'P', ".--.");
    insert(&root, 'Q', "--.-");
    insert(&root, 'R', ".-.");
    insert(&root, 'S', "...");
    insert(&root, 'T', "-");
    insert(&root, 'U', "..-");
    insert(&root, 'V', "...-");
    insert(&root, 'W', ".--");
    insert(&root, 'X', "-..-");
    insert(&root, 'Y', "-.--");
    insert(&root, 'Z', "--..");
    insert(&root, '0', "-----");
    insert(&root, '1', ".----");
    insert(&root, '2', "..---");
    insert(&root, '3', "...--");
    insert(&root, '4', "....-");
    insert(&root, '5', ".....");
    insert(&root, '6', "-....");
    insert(&root, '7', "--...");
    insert(&root, '8', "---..");
    insert(&root, '9', "----.");
    insert(&root, ' ', " ");

    // Print the Morse code tree
    print_tree(root);

    // Convert a string to Morse code
    char *s = "HELLO WORLD";
    char *morse = to_morse_string(root, s);
    if (morse != NULL) {
        printf("%s\n", morse);
    } else {
        printf("Error converting string to Morse code\n");
    }

    // Free the Morse code tree
    free_tree(root);

    return 0;
}