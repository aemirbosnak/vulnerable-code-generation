//FormAI DATASET v1.0 Category: Spell checking ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

// Definition of Binary Search Tree Node
struct BSTNode
{
    char data[MAX_WORD_LENGTH];
    struct BSTNode* left;
    struct BSTNode* right;
};

// Function Prototypes
struct BSTNode* createBSTNode(char*);
struct BSTNode* insertBSTNode(struct BSTNode*, char*);
int searchBST(struct BSTNode*, char*);

// Utility functions
void toLowerCase(char*);

int main()
{
    struct BSTNode* root = NULL;

    // Read the dictionary file and build the binary search tree
    FILE* dictionary = fopen("dictionary.txt", "r");

    char word[MAX_WORD_LENGTH];
    while (fscanf(dictionary, "%s", word) != EOF)
    {
        toLowerCase(word);
        root = insertBSTNode(root, word);
    }

    fclose(dictionary);

    // Check the spelling of user input
    printf("Spell Checker\n");
    printf("Enter a word (Q to Quit):\n");

    char input[MAX_WORD_LENGTH];
    while (scanf("%s", input), strcmp(input, "Q") != 0)
    {
        toLowerCase(input);

        if (searchBST(root, input))
        {
            printf("%s is spelled correctly!\n", input);
        }
        else
        {
            printf("%s is misspelled!\n", input);
        }

        printf("\nEnter a word (Q to Quit):\n");
    }

    // De-allocate the memory used for the binary search tree
    return 0;
}

struct BSTNode* createBSTNode(char* word)
{
    struct BSTNode* node = (struct BSTNode*) malloc(sizeof(struct BSTNode));
    strcpy(node->data, word);
    node->left = NULL;
    node->right = NULL;

    return node;
}

struct BSTNode* insertBSTNode(struct BSTNode* root, char* word)
{
    if (root == NULL)
    {
        return createBSTNode(word);
    }

    if (strcmp(word, root->data) < 0)
    {
        root->left = insertBSTNode(root->left, word);
    }
    else if (strcmp(word, root->data) > 0)
    {
        root->right = insertBSTNode(root->right, word);
    }

    return root;
}

int searchBST(struct BSTNode* root, char* word)
{
    if (root == NULL)
    {
        return 0;
    }

    if (strcmp(word, root->data) == 0)
    {
        return 1;
    }
    else if (strcmp(word, root->data) < 0)
    {
        return searchBST(root->left, word);
    }
    else
    {
        return searchBST(root->right, word);
    }
}

void toLowerCase(char* str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        str[i] = tolower(str[i]);
        i++;
    }
}