//FormAI DATASET v1.0 Category: Binary search trees ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create_node(int data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node* insert_node(struct node* root, int data)
{
    if(root == NULL)
    {
        root = create_node(data);
        return root;
    }
    else
    {
        if(data <= root->data)
        {
            root->left = insert_node(root->left, data);
        }
        else
        {
            root->right = insert_node(root->right, data);
        }
        return root;
    }
}

void inorder_traversal(struct node* root)
{
    if(root == NULL)
    {
        return;
    }
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

int search(struct node* root, int data)
{
    if(root == NULL)
    {
        return 0;
    }
    else if(root->data == data)
    {
        return 1;
    }
    else if(data <= root->data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}

int main()
{
    struct node* root = NULL;
    int choice, data, found;

    while(1)
    {
        printf("\nEnter Choice:\n1. Insert\n2. Traverse\n3. Search\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                root = insert_node(root, data);
                printf("Data Inserted Successfully!\n");
                break;

            case 2:
                printf("Inorder Traversal: ");
                inorder_traversal(root);
                printf("\n");
                break;

            case 3:
                printf("Enter data to be searched: ");
                scanf("%d", &data);
                found = search(root, data);
                if(found == 1)
                {
                    printf("Data Found!\n");
                }
                else
                {
                    printf("Data Not Found!\n");
                }
                break;

            case 4:
                printf("Exiting Program!\n");
                exit(0);
                break;

            default:
                printf("Please Enter a Valid Choice!\n");
                break;
        }
    }

    return 0;
}