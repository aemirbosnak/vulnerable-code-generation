//FormAI DATASET v1.0 Category: Binary search trees ; Style: calm
#include<stdio.h>
#include<stdlib.h>

// Definition of the node structure
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node *newNode(int item) {
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a new node in the tree
struct node* insert(struct node* node, int data) {
    if (node == NULL) return newNode(data);

    if (data < node->data)
        node->left  = insert(node->left, data);
    else
        node->right = insert(node->right, data);

    return node;
}

// Function to search for a node in the tree
struct node* search(struct node* root, int data) {
    if (root == NULL || root->data == data)
       return root;

    if (root->data < data)
       return search(root->right, data);

    return search(root->left, data);
}

// Function to find the minimum value in a tree
struct node* minValueNode(struct node* node) {
    struct node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Function to delete a node from the tree
struct node* deleteNode(struct node* root, int data) {
    if (root == NULL) return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);

    else if (data > root->data)
        root->right = deleteNode(root->right, data);

    else {
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValueNode(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to traverse the tree in-order
void traverseInOrder(struct node *root) {
    if (root != NULL) {
        traverseInOrder(root->left);
        printf("%d \n", root->data);
        traverseInOrder(root->right);
    }
}

// Driver program
int main() {
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("In-order traversal of the BST \n");
    traverseInOrder(root);

    // Search for a node
    struct node *temp = search(root, 40);
    if(temp != NULL){
        printf("Node found: %d \n", temp->data);
    }
    else{
        printf("Node not found \n");
    }

    // Delete a node
    root = deleteNode(root, 20);
    printf("\nIn-order traversal after deleting 20 \n");
    traverseInOrder(root);

    return 0;
}