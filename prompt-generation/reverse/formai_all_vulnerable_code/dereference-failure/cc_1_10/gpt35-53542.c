//FormAI DATASET v1.0 Category: Binary search trees ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>

/* The node structure*/
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

/*  Function to create a new node with the given data */
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                      malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}

/* Function to insert a new node in BST */
struct node* Insert(struct node* root, int data)
{
  /* If the tree is empty, return a new node */
  if (root == NULL)
  {
    return(newNode(data));
  }
  else
  {
    /* Otherwise, recur down the tree */
    if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    /* return the (unchanged) node pointer */
    return root;
  }
}

/* Function to search a node in BST */
struct node* Search(struct node* root, int data)
{
    /* If the tree is empty or the key is present return root*/
    if (root == NULL || root->data == data)
    {
        return root;
    }
    /* If the key is smaller than root's key, recur left */
    else if (data < root->data)
    {
        return Search(root->left, data);
    }
    /* Else recur right */
    else
    {
        return Search(root->right, data);
    }
}

/* Function to find the minimum value node in BST */
struct node* minNode(struct node* node)
{
    struct node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

/* Function to delete a node in BST */
struct node* deleteNode(struct node* root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    /* If the key to be deleted is smaller than the root's key, recur left */
    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    /* If the key to be deleted is greater than the root's key recur right */
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        /* node with only one child or no child */
        if (root->left == NULL)
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        /* node with two children: Get the inorder successor (smallest in the right subtree) */
        struct node* temp = minNode(root->right);

        /* Copy the inorder successor's content to this node */
        root->data = temp->data;

        /* Delete the inorder successor */
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

/* Function to traverse the tree in inorder */
void Inorder(struct node* root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        printf("%d ", root->data);
        Inorder(root->right);
    }
}

/* The main function */
int main()
{
    struct node* root = NULL;
    int choice = 1, data;

    while (choice != 0)
    {
        printf("Choose from the following options:\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Search for a node\n");
        printf("4. Inorder traversal of the tree\n");
        printf("0. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 0:
                printf("Exiting\n");
                break;

            case 1:
                printf("Enter the integer data to be inserted: ");
                scanf("%d", &data);
                root = Insert(root, data);
                printf("Inserted successfully!\n");
                break;

            case 2:
                printf("Enter the integer data to be deleted: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                printf("Deleted successfully!\n");
                break;

            case 3:
                printf("Enter the integer data to be searched: ");
                scanf("%d", &data);
                if (Search(root, data) == NULL)
                {
                    printf("%d was not found in the tree\n", data);
                }
                else
                {
                    printf("%d was found in the tree\n", data);
                }
                break;

            case 4:
                printf("Inorder traversal of the tree: ");
                Inorder(root);
                printf("\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}