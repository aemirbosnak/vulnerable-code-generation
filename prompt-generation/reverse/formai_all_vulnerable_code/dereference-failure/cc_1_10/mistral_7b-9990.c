//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Node {
    char name[50];
    float price;
    unsigned int shares;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(char* name, float price, unsigned int shares) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->price = price;
    newNode->shares = shares;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, Node* newNode) {
    if (root == NULL) {
        root = newNode;
    } else if (strcmp(newNode->name, root->name) < 0) {
        root->left = insertNode(root->left, newNode);
    } else {
        root->right = insertNode(root->right, newNode);
    }
    return root;
}

void calculateMarketCapitalization(Node* root, float* totalMarketCapitalization) {
    if (root == NULL) {
        return;
    }

    calculateMarketCapitalization(root->left, totalMarketCapitalization);

    float companyMarketCapitalization = root->price * root->shares;
    *totalMarketCapitalization += companyMarketCapitalization;

    calculateMarketCapitalization(root->right, totalMarketCapitalization);
}

void displayTopCompanies(Node* root, float totalMarketCapitalization, int* counter) {
    if (root == NULL) {
        return;
    }

    displayTopCompanies(root->right, totalMarketCapitalization, counter);

    float companyMarketCapitalization = root->price * root->shares;
    if (*counter < 5) {
        printf("%d. %s: Market Capitalization = %.2f, Price = %.2f, Shares = %d\n", *counter + 1, root->name, companyMarketCapitalization, root->price, root->shares);
        (*counter)++;
    } else {
        if (companyMarketCapitalization > totalMarketCapitalization * 0.95) {
            printf("%d. %s: Market Capitalization = %.2f, Price = %.2f, Shares = %d\n", *counter + 1, root->name, companyMarketCapitalization, root->price, root->shares);
            (*counter)++;
        }
        return;
    }

    displayTopCompanies(root->left, totalMarketCapitalization, counter);
}

int main() {
    Node* root = NULL;

    root = insertNode(root, createNode("Microsoft", 270.5, 6000000));
    root = insertNode(root, createNode("Apple", 150.0, 8000000));
    root = insertNode(root, createNode("Google", 2000.0, 1000000));
    root = insertNode(root, createNode("Facebook", 300.0, 12000000));
    root = insertNode(root, createNode("Amazon", 3500.0, 20000000));
    root = insertNode(root, createNode("Tesla", 1000.0, 5000000));

    float totalMarketCapitalization = 0;
    int counter = 0;

    calculateMarketCapitalization(root, &totalMarketCapitalization);

    printf("\nTotal Market Capitalization: %.2f\n", totalMarketCapitalization);

    displayTopCompanies(root, totalMarketCapitalization, &counter);

    return 0;
}