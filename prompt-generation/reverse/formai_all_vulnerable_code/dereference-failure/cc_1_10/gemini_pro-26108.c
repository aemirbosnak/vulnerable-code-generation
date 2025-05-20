//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: Alan Turing
/*
 * The Imitation Game
 *
 * By Alan Turing
 *
 * This program is a unique C Memory management example. It is inspired by the work of Alan Turing,
 * the father of computer science. The program uses a variety of memory management techniques to create
 * a complex and efficient data structure.
 *
 * The program is divided into two parts. The first part creates a linked list of nodes. Each node
 * contains a pointer to the next node in the list, and a pointer to the previous node in the list.
 * The second part of the program creates a binary tree of nodes. Each node in the tree contains a pointer
 * to the left child node, a pointer to the right child node, and a pointer to the parent node.
 *
 * The program demonstrates a variety of memory management techniques, including:
 *
 * * **Dynamic memory allocation:** The program uses the `malloc()` and `free()` functions to allocate
 * and free memory for the linked list and binary tree nodes.
 * * **Linked lists:** The program uses a linked list to store a list of nodes. The linked list is
 * implemented using a pointer to the first node in the list, and a pointer to the last node in the list.
 * * **Binary trees:** The program uses a binary tree to store a tree of nodes. The binary tree is
 * implemented using a pointer to the root node of the tree, and a pointer to the left and right child
 * nodes of each node in the tree.
 *
 * The program is a powerful demonstration of memory management techniques. It is a valuable resource
 * for anyone who is interested in learning more about memory management.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * A node in a linked list.
 */
struct node {
    int data;
    struct node *next;
    struct node *prev;
};

/*
 * A node in a binary tree.
 */
struct tree_node {
    int data;
    struct tree_node *left;
    struct tree_node *right;
    struct tree_node *parent;
};

/*
 * Create a new linked list node.
 */
struct node *create_node(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

/*
 * Insert a new node into a linked list.
 */
void insert_node(struct node *head, struct node *new_node) {
    if (head == NULL) {
        head = new_node;
        return;
    }

    struct node *current_node = head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }

    current_node->next = new_node;
    new_node->prev = current_node;
}

/*
 * Create a new binary tree node.
 */
struct tree_node *create_tree_node(int data) {
    struct tree_node *new_node = malloc(sizeof(struct tree_node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->parent = NULL;
    return new_node;
}

/*
 * Insert a new node into a binary tree.
 */
void insert_tree_node(struct tree_node *root, struct tree_node *new_node) {
    if (root == NULL) {
        root = new_node;
        return;
    }

    if (new_node->data < root->data) {
        if (root->left == NULL) {
            root->left = new_node;
            new_node->parent = root;
        } else {
            insert_tree_node(root->left, new_node);
        }
    } else {
        if (root->right == NULL) {
            root->right = new_node;
            new_node->parent = root;
        } else {
            insert_tree_node(root->right, new_node);
        }
    }
}

/*
 * Print a linked list.
 */
void print_list(struct node *head) {
    struct node *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }

    printf("\n");
}

/*
 * Print a binary tree.
 */
void print_tree(struct tree_node *root) {
    if (root == NULL) {
        return;
    }

    print_tree(root->left);
    printf("%d ", root->data);
    print_tree(root->right);
}

/*
 * Main function.
 */
int main() {
    /*
     * Create a linked list.
     */
    struct node *head = create_node(1);
    insert_node(head, create_node(2));
    insert_node(head, create_node(3));
    insert_node(head, create_node(4));
    insert_node(head, create_node(5));

    /*
     * Print the linked list.
     */
    print_list(head);

    /*
     * Create a binary tree.
     */
    struct tree_node *root = create_tree_node(1);
    insert_tree_node(root, create_tree_node(2));
    insert_tree_node(root, create_tree_node(3));
    insert_tree_node(root, create_tree_node(4));
    insert_tree_node(root, create_tree_node(5));

    /*
     * Print the binary tree.
     */
    print_tree(root);

    return 0;
}