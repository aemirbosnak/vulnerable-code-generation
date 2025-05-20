//FormAI DATASET v1.0 Category: Binary search trees ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

typedef struct node Node;

//function to create a new node
Node* create_node(int val){
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

//function to add a new node to the Binary Search Tree
Node* add_node(Node* root, int val){

    if(root == NULL){
        return create_node(val);
    }

    if(val < root->data){
        root->left = add_node(root->left, val);
    }
    else if(val > root->data){
        root->right = add_node(root->right, val);
    }

    return root;
}

//function to search for a node in the Binary Search Tree
Node* search_node(Node* root, int val){

    if(root == NULL){
        return NULL;
    }

    if(root->data == val){
        return root;
    }
    else if(val < root->data){
        return search_node(root->left, val);
    }
    else{
        return search_node(root->right, val);
    }
}

//function to get the maximum value node in the Binary Search Tree
Node* get_max_val(Node* node){
    
    Node* current = node;

    while (current && current->right != NULL){
        current = current->right;
    }

    return current;
}

//function to delete a node from the Binary Search Tree
Node* delete_node(Node* root, int val){

    if(root == NULL){
        return NULL;
    }

    if(val < root->data){
        root->left = delete_node(root->left, val);
    }
    else if(val > root->data){
        root->right = delete_node(root->right, val);
    }
    else{

        if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = get_max_val(root->left);
        root->data = temp->data;
        root->left = delete_node(root->left, temp->data);
    }

    return root;
}

//function to traverse the Binary Search Tree in-order
void in_order_traversal(Node* root){
    if(root == NULL){
        return;
    }

    in_order_traversal(root->left);
    printf("%d ", root->data);
    in_order_traversal(root->right);
}

int main(){

    Node* root = NULL;

    //Inserting nodes
    root = add_node(root, 50);
    root = add_node(root, 30);
    root = add_node(root, 70);
    root = add_node(root, 20);
    root = add_node(root, 40);
    root = add_node(root, 60);
    root = add_node(root, 80);

    //Traversing in-order
    printf("\nIn-order traversal of the Binary Search Tree: \n");
    in_order_traversal(root);

    //Deleting node
    printf("\n\nDeleting the node with value 20: \n");
    root = delete_node(root, 20);

    //Traversing in-order after deletion
    printf("\nIn-order traversal after deleting the node with value 20: \n");
    in_order_traversal(root);

    return 0;
}