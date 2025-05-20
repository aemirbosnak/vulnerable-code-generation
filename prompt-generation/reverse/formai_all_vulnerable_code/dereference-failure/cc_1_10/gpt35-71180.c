//FormAI DATASET v1.0 Category: Database Indexing System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_PHONE_NUM_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char phoneNum[MAX_PHONE_NUM_LEN];
} Contact;

typedef struct TreeNode {
    Contact* contact;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(Contact* contact) {
    TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
    node->contact = contact;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insertNode(TreeNode** root, Contact* contact) {
    if (*root == NULL) {
        *root = createNode(contact);
        return;
    }

    int cmp = strcmp(contact->name, (*root)->contact->name);
    if (cmp < 0) {
        insertNode(&((*root)->left), contact);
    } else if (cmp > 0) {
        insertNode(&((*root)->right), contact);
    } else {
        printf("Contact with name '%s' already exists.\n", contact->name);
    }
}

Contact* search(TreeNode* root, char* name) {
    if (root == NULL) {
        return NULL;
    }

    int cmp = strcmp(name, root->contact->name);
    if (cmp < 0) {
        return search(root->left, name);
    } else if (cmp > 0) {
        return search(root->right, name);
    } else {
        return root->contact;
    }
}

void inOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    inOrderTraversal(root->left);
    printf("%s - %s\n", root->contact->name, root->contact->phoneNum);
    inOrderTraversal(root->right);
}

int main() {
    TreeNode* root = NULL;

    Contact* contact1 = (Contact*) malloc(sizeof(Contact));
    strcpy(contact1->name, "John Smith");
    strcpy(contact1->phoneNum, "123-456-7890");
    insertNode(&root, contact1);

    Contact* contact2 = (Contact*) malloc(sizeof(Contact));
    strcpy(contact2->name, "Jane Doe");
    strcpy(contact2->phoneNum, "234-567-8901");
    insertNode(&root, contact2);

    Contact* contact3 = (Contact*) malloc(sizeof(Contact));
    strcpy(contact3->name, "Bob Johnson");
    strcpy(contact3->phoneNum, "345-678-9012");
    insertNode(&root, contact3);

    Contact* searchResult = search(root, "Jane Doe");
    if (searchResult != NULL) {
        printf("Found contact: %s - %s\n", searchResult->name, searchResult->phoneNum);
    }

    inOrderTraversal(root);

    return 0;
}