//FormAI DATASET v1.0 Category: Binary search trees ; Style: medieval
#include<stdio.h>

// Define the struct for BST nodes in a medieval style
struct knight{
    int power;
    int gold;
    struct knight* left;
    struct knight* right;
};

// Declare function to create a new knight (i.e. BST node)
struct knight* new_knight(int power, int gold){
    struct knight* new_node = (struct knight*)malloc(sizeof(struct knight));
    new_node->power = power;
    new_node->gold = gold;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Declare function to insert a new knight into the BST
struct knight* insert(struct knight* root, int power, int gold){
    if (root == NULL){ // If the root is null, create a new node
        return new_knight(power, gold);
    }
    if (power < root->power){ // If the power is less than the root, insert into the left subtree
        root->left = insert(root->left, power, gold);
    }
    else if (power > root->power){ // If the power is greater than the root, insert into the right subtree
        root->right = insert(root->right, power, gold);
    }
    return root; 
}

// Declare function to traverse the BST using inorder traversal
void inorder_traversal(struct knight* root){
    if(root != NULL){ // If the root is not null
        inorder_traversal(root->left); // Traverse the left subtree
        printf("Power: %d, Gold: %d\n", root->power, root->gold); // Print the knight's power and gold
        inorder_traversal(root->right); // Traverse the right subtree
    }
}

// The main function which sets up the BST with knights and their attributes
int main(){
    struct knight* root = NULL; // Initialize the root
    root = insert(root, 7, 20);
    root = insert(root, 4, 10);
    root = insert(root, 9, 40);
    root = insert(root, 6, 30);
    root = insert(root, 5, 25);
    root = insert(root, 1, 5);
    root = insert(root, 10, 50);
    root = insert(root, 2, 7);
    root = insert(root, 3, 8);

    printf("Inorder traversal of knights' power and gold:\n");
    inorder_traversal(root);
    return 0;
}