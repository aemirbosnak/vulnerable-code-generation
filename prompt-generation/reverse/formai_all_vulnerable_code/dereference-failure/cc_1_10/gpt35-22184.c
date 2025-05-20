//FormAI DATASET v1.0 Category: Binary search trees ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char* location;
    char* hideout;
    struct node* left;
    struct node* right;
} Node;

Node* createNode(char* location, char* hideout) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->location = strdup(location);
    node->hideout = strdup(hideout);
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert(Node* node, char* location, char* hideout) {
    if (node == NULL) {
        return createNode(location, hideout);
    }
    if (strcmp(location, node->location) < 0) {
        node->left = insert(node->left, location, hideout);
    } else {
        node->right = insert(node->right, location, hideout);
    }
    return node;
}

Node* search(Node* node, char* location) {
    if (node == NULL) {
        return NULL;
    }
    if (strcmp(location, node->location) == 0) {
        return node;
    } else if (strcmp(location, node->location) < 0) {
        return search(node->left, location);
    } else {
        return search(node->right, location);
    }
}

void printTree(Node* node) {
    if (node == NULL) {
        return;
    }
    printTree(node->left);
    printf("Location: %s\n", node->location);
    printf("Hideout: %s\n", node->hideout);
    printTree(node->right);
}

int main() {
    Node* root = NULL;
    root = insert(root, "Baker Street", "221B");
    insert(root, "Whitechapel", "Jack the Ripper's Lair");
    insert(root, "Kensington Gardens", "The Serpentine");
    insert(root, "Limehouse", "The opum dens on Wah Fu Lane");
    insert(root, "Camden Town", "Stables Market");
    insert(root, "Paddington", "The train station");
    insert(root, "Shoreditch", "Cargo nightclub");
    insert(root, "Hoxton", "The Hoxton hotel");
    insert(root, "Soho", "The Cat and Fiddle pub");
    insert(root, "Mayfair", "The Dorchester hotel");
    insert(root, "Covent Garden", "The Royal Opera House");

    printf("These are the known hideouts that we know of:\n\n");
    printTree(root);

    char location[100];
    printf("\nEnter location of interest: ");
    scanf("%s", location);

    Node* result = search(root, location);
    if (result == NULL) {
        printf("\nNo hideouts found for location %s\n", location);
    } else {
        printf("\nHideout found for location %s:\n", location);
        printf("Hideout: %s\n", result->hideout);
    }

    return 0;
}