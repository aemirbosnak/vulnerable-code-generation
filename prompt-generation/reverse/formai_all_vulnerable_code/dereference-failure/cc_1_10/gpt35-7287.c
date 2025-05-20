//FormAI DATASET v1.0 Category: Binary search trees ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *leftChild;
    struct node *rightChild;
} node;

// function to insert a new node
node* insert(node* ptr, int value) {
    if(ptr==NULL) { // if there is no node, create a new one
        ptr=(node*)malloc(sizeof(node));
        ptr->data=value;
        ptr->leftChild=NULL;
        ptr->rightChild=NULL;
    } else if(value<ptr->data) { // if the value is smaller than the root node, insert in the left side
        ptr->leftChild=insert(ptr->leftChild,value);
    } else { // if the value is greater than or equal to the root node, insert in the right side
        ptr->rightChild=insert(ptr->rightChild,value);
    }
    return ptr;
}

// function to search for a node
node* search(node* ptr, int value) {
    if(ptr==NULL || ptr->data==value) {
        return ptr;
    } else if(value<ptr->data) {
        return search(ptr->leftChild,value);
    } else {
        return search(ptr->rightChild,value);
    }
}

// function to find the minimum value node
node* findMin(node* ptr) {
    while(ptr->leftChild!=NULL) {
        ptr=ptr->leftChild;
    }
    return ptr;
}

// function to delete a node
node* delete(node* ptr, int value) {
    if(ptr==NULL) {
        return NULL;
    } else if(value<ptr->data) {
        ptr->leftChild=delete(ptr->leftChild,value);
    } else if(value>ptr->data) {
        ptr->rightChild=delete(ptr->rightChild,value);
    } else {
        if(ptr->leftChild==NULL && ptr->rightChild==NULL) {
            free(ptr);
            ptr=NULL;
        } else if(ptr->leftChild==NULL) {
            node* temp=ptr;
            ptr=ptr->rightChild;
            free(temp);
        } else if(ptr->rightChild==NULL) {
            node* temp=ptr;
            ptr=ptr->leftChild;
            free(temp);
        } else {
            node* temp=findMin(ptr->rightChild);
            ptr->data=temp->data;
            ptr->rightChild=delete(ptr->rightChild,temp->data);
        }
    }
    return ptr;
}

// function to traverse in preorder
void preorder(node* ptr) {
    if(ptr!=NULL) {
        printf("%d ",ptr->data);
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
}

// function to traverse in inorder
void inorder(node* ptr) {
    if(ptr!=NULL) {
        inorder(ptr->leftChild);
        printf("%d ",ptr->data);
        inorder(ptr->rightChild);
    }
}

// function to traverse in postorder
void postorder(node* ptr) {
    if(ptr!=NULL) {
        postorder(ptr->leftChild);
        postorder(ptr->rightChild);
        printf("%d ",ptr->data);
    }
}

int main() {
    node* root=NULL;
    int choice,value;
    while(1) { // infinite loop
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Preorder Traversal\n");
        printf("5. Inorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d",&value);
                root=insert(root,value);
                printf("Value inserted successfully!\n");
                break;
            case 2:
                printf("Enter the value to be searched: ");
                scanf("%d",&value);
                if(search(root,value)==NULL) {
                    printf("Value not found!\n");
                } else {
                    printf("Value found!\n");
                }
                break;
            case 3:
                printf("Enter the value to be deleted: ");
                scanf("%d",&value);
                root=delete(root,value);
                printf("Value deleted successfully!\n");
                break;
            case 4:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 5:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 6:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 7:
                exit(0); // exit the program
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}