//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Define a node for a linked list
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Create a new node
node_t *create_node(int data) {
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a node at the beginning of a linked list
void insert_at_beginning(node_t **head, int data) {
    node_t *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Insert a node at the end of a linked list
void insert_at_end(node_t **head, int data) {
    node_t *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        node_t *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Delete a node from a linked list
void delete_node(node_t **head, int data) {
    node_t *current = *head;
    node_t *previous = NULL;
    while (current != NULL) {
        if (current->data == data) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

// Print a linked list
void print_linked_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Create a binary tree node
typedef struct tree_node {
    int data;
    struct tree_node *left;
    struct tree_node *right;
} tree_node_t;

// Create a new binary tree node
tree_node_t *create_tree_node(int data) {
    tree_node_t *new_node = malloc(sizeof(tree_node_t));
    if (new_node == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a node into a binary tree
void insert_into_tree(tree_node_t **root, int data) {
    if (*root == NULL) {
        *root = create_tree_node(data);
    } else {
        if (data <= (*root)->data) {
            insert_into_tree(&(*root)->left, data);
        } else {
            insert_into_tree(&(*root)->right, data);
        }
    }
}

// Print a binary tree in preorder traversal
void preorder_traversal(tree_node_t *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

// Print a binary tree in inorder traversal
void inorder_traversal(tree_node_t *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

// Print a binary tree in postorder traversal
void postorder_traversal(tree_node_t *root) {
    if (root != NULL) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ", root->data);
    }
}

// Create a graph node
typedef struct graph_node {
    int data;
    struct graph_node *next;
} graph_node_t;

// Create a new graph node
graph_node_t *create_graph_node(int data) {
    graph_node_t *new_node = malloc(sizeof(graph_node_t));
    if (new_node == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Create a graph
typedef struct graph {
    int num_vertices;
    graph_node_t **adj_list;
} graph_t;

// Create a new graph
graph_t *create_graph(int num_vertices) {
    graph_t *new_graph = malloc(sizeof(graph_t));
    if (new_graph == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    new_graph->num_vertices = num_vertices;
    new_graph->adj_list = malloc(sizeof(graph_node_t *) * num_vertices);
    if (new_graph->adj_list == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < num_vertices; i++) {
        new_graph->adj_list[i] = NULL;
    }
    return new_graph;
}

// Add an edge to a graph
void add_edge(graph_t *graph, int src, int dest) {
    graph_node_t *new_node = create_graph_node(dest);
    new_node->next = graph->adj_list[src];
    graph->adj_list[src] = new_node;
}

// Print a graph
void print_graph(graph_t *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("%d: ", i);
        graph_node_t *current = graph->adj_list[i];
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Create a linked list
    node_t *head = NULL;
    insert_at_beginning(&head, 1);
    insert_at_beginning(&head, 2);
    insert_at_beginning(&head, 3);
    insert_at_end(&head, 4);
    insert_at_end(&head, 5);
    insert_at_end(&head, 6);
    print_linked_list(head);

    // Create a binary tree
    tree_node_t *root = NULL;
    insert_into_tree(&root, 10);
    insert_into_tree(&root, 5);
    insert_into_tree(&root, 15);
    insert_into_tree(&root, 2);
    insert_into_tree(&root, 7);
    insert_into_tree(&root, 12);
    insert_into_tree(&root, 20);
    printf("Preorder traversal: ");
    preorder_traversal(root);
    printf("\n");
    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");
    printf("Postorder traversal: ");
    postorder_traversal(root);
    printf("\n");

    // Create a graph
    graph_t *graph = create_graph(5);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 4);
    add_edge(graph, 3, 4);
    print_graph(graph);

    return 0;
}