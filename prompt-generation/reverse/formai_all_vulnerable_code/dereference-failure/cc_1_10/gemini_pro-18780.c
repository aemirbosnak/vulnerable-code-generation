//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: genius
// Symphony of Data Structures - A C Visualization Masterpiece

#include <stdio.h>
#include <stdlib.h>

// Canvas Colors
#define GREEN "32"
#define BLUE "34"
#define RED "31"
#define YELLOW "33"
#define PURPLE "35"

// Nodes for Linked List
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Create a Node
Node *create_node(int data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Linked List Operations
typedef struct LinkedList {
    Node *head;
} LinkedList;

void insert_at_beginning(LinkedList *list, int data) {
    Node *new_node = create_node(data);
    new_node->next = list->head;
    list->head = new_node;
}

void insert_at_end(LinkedList *list, int data) {
    Node *new_node = create_node(data);
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void delete_at_beginning(LinkedList *list) {
    if (list->head != NULL) {
        Node *temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
}

void delete_at_end(LinkedList *list) {
    if (list->head != NULL) {
        Node *current = list->head;
        Node *prev = NULL;
        while (current->next != NULL) {
            prev = current;
            current = current->next;
        }
        if (prev != NULL) {
            prev->next = NULL;
        }
        free(current);
    }
}

// Print Linked List
void print_linked_list(LinkedList *list) {
    Node *current = list->head;
    printf("\n[ ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("]\n");
}

// Binary Search Tree Operations
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *create_tree_node(int data) {
    TreeNode *new_node = (TreeNode *) malloc(sizeof(TreeNode));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_into_bst(TreeNode **root, int data) {
    if (*root == NULL) {
        *root = create_tree_node(data);
    } else if (data < (*root)->data) {
        insert_into_bst(&(*root)->left, data);
    } else {
        insert_into_bst(&(*root)->right, data);
    }
}

TreeNode *search_in_bst(TreeNode *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (root->data == data) {
        return root;
    } else if (data < root->data) {
        return search_in_bst(root->left, data);
    } else {
        return search_in_bst(root->right, data);
    }
}

// Print Binary Search Tree in ASCII Art
#define ESC_SEQ "\x1b["
#define CURSOR_POS "%d;%df"

void print_tree_ascii_art(TreeNode *root, int level, int x, int y) {
    if (root != NULL) {
        // Print left subtree
        print_tree_ascii_art(root->left, level + 1, x - 1, y - 2);
        // Print node
        printf(ESC_SEQ CURSOR_POS, y, x);
        if (root->data < 0) {
            printf(PURPLE "%d" ESC_SEQ "0m", root->data);
        } else if (root->data == 0) {
            printf(GREEN "%d" ESC_SEQ "0m", root->data);
        } else {
            printf(BLUE "%d" ESC_SEQ "0m", root->data);
        }
        // Print right subtree
        print_tree_ascii_art(root->right, level + 1, x + 1, y - 2);
    }
}

// Main Function - A Symphony of Data Structures
int main() {
    // Linked List
    LinkedList linked_list = {NULL};
    insert_at_beginning(&linked_list, 5);
    insert_at_beginning(&linked_list, 3);
    insert_at_end(&linked_list, 7);
    insert_at_end(&linked_list, 9);

    printf("Linked List: ");
    print_linked_list(&linked_list);

    delete_at_beginning(&linked_list);
    printf("Linked List after Deleting First Node: ");
    print_linked_list(&linked_list);

    delete_at_end(&linked_list);
    printf("Linked List after Deleting Last Node: ");
    print_linked_list(&linked_list);

    // Binary Search Tree
    TreeNode *root = NULL;
    insert_into_bst(&root, 10);
    insert_into_bst(&root, 5);
    insert_into_bst(&root, 20);
    insert_into_bst(&root, 2);
    insert_into_bst(&root, 7);
    insert_into_bst(&root, 15);
    insert_into_bst(&root, 25);
    insert_into_bst(&root, -5);
    insert_into_bst(&root, 0);
    insert_into_bst(&root, -2);

    printf("\nBinary Search Tree in ASCII Art:\n");
    for (int i = 0; i <= 70; i++) printf("=");
    printf("\n");
    print_tree_ascii_art(root, 0, 35, 15);

    TreeNode *found_node = search_in_bst(root, -2);
    if (found_node != NULL) {
        printf("\nFound Node: %d\n", found_node->data);
    }

    return 0;
}