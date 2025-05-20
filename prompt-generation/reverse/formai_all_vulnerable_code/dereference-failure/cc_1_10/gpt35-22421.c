//FormAI DATASET v1.0 Category: Spell checking ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

bool isLetter(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int getIndex(char ch)
{
    if (isLetter(ch))
    {
        char lowerCase = tolower(ch);
        return lowerCase - 'a';
    }
    return -1;
}

struct Node
{
    int count;
    struct Node* children[26];
};

struct Node* createNode()
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->count = 0;
    for (int i = 0; i < 26; i++)
    {
        node->children[i] = NULL;
    }
    return node;
}

void addWord(struct Node* root, char* word)
{
    struct Node* node = root;
    for (int i = 0; i < strlen(word); i++)
    {
        int index = getIndex(word[i]);
        if (index == -1)
        {
            continue;
        }
        if (node->children[index] == NULL)
        {
            node->children[index] = createNode();
        }
        node = node->children[index];
    }
    node->count++;
}

void checkWord(struct Node* root, char* word)
{
    struct Node* node = root;
    for (int i = 0; i < strlen(word); i++)
    {
        int index = getIndex(word[i]);
        if (index == -1)
        {
            continue;
        }
        if (node->children[index] == NULL)
        {
            printf("%s is spelled incorrectly.\n", word);
            return;
        }
        else
        {
            node = node->children[index];
        }
    }
    if (node != NULL && node->count > 0)
    {
        printf("%s is spelled correctly.\n", word);
    }
    else
    {
        printf("%s is spelled incorrectly.\n", word);
    }
}

int main()
{
    struct Node* root = createNode();

    addWord(root, "hello");
    addWord(root, "world");
    addWord(root, "programming");
    addWord(root, "language");
    addWord(root, "computer");

    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);
    sentence[strcspn(sentence, "\n")] = 0;

    char* ptr = strtok(sentence, " ");
    while (ptr != NULL)
    {
        checkWord(root, ptr);
        ptr = strtok(NULL, " ");
    }

    return 0;
}