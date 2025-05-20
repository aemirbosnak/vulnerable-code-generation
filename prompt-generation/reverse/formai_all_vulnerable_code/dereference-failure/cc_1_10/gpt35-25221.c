//FormAI DATASET v1.0 Category: Spell checking ; Style: imaginative
/*
 * Spell Checking Program in C
 * Author: [Your Name]
 * Email: [Your Email]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Dictionary size */
#define DICT_SIZE 100000

/* Word size */
#define MAX_WORD_SIZE 100

/* Character to integer conversion */
#define C2I(c) ((int)c - (int)'a')

/* Node structure for Trie */
struct Node
{
    int isWord;
    struct Node *next[26];
};

/* Initializes a new Node */
struct Node* initNode()
{
    int i;
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->isWord = 0;
    for(i = 0; i < 26; i++)
        node->next[i] = NULL;
    return node;
}

/* Insert a word into the trie */
void insert(struct Node *root, char *word)
{
    int i, n = strlen(word);
    struct Node *node = root;
    for(i = 0; i < n; i++)
    {
        int index = C2I(tolower(word[i])); /* Convert character to index */
        if(!node->next[index])
            node->next[index] = initNode();
        node = node->next[index];
    }
    node->isWord = 1;
}

/* Search for a word in the trie */
int search(struct Node *root, char *word)
{
    int i, n = strlen(word);
    struct Node *node = root;
    for(i = 0; i < n; i++)
    {
        int index = C2I(tolower(word[i])); /* Convert character to index */
        if(!node->next[index])
            return 0;
        node = node->next[index];
    }
    return node->isWord;
}

/* Check if a character is a letter */
int isLetter(char c)
{
    if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
        return 1;
    return 0;
}

/* Spell check function */
void spellCheck(struct Node *root, char *text)
{
    char word[MAX_WORD_SIZE];
    int i, j, k = 0, n = strlen(text);
    for(i = 0; i < n; i++)
    {
        if(isLetter(text[i])) /* Collect letters to form a word */
            word[k++] = tolower(text[i]);
        else if(k != 0) /* Word ends */
        {
            word[k] = '\0';
            if(!search(root, word)) /* Word not found in dictionary */
                printf("%s ", word);
            k = 0;
        }
    }
    if(k != 0) /* Check if there is any remaining word */
    {
        word[k] = '\0';
        if(!search(root, word)) /* Word not found in dictionary */
            printf("%s ", word);
    }
}

int main()
{
    FILE *fin, *fout;
    char word[MAX_WORD_SIZE], text[MAX_WORD_SIZE];
    struct Node *root = initNode();

    /* Populate the dictionary */
    fin = fopen("dictionary.txt", "r");
    while(fscanf(fin, "%s", word) != EOF)
        insert(root, word);
    fclose(fin);

    /* Spell check a text file */
    fin = fopen("text.txt", "r");
    fout = fopen("output.txt", "w");
    while(fscanf(fin, "%s", text) != EOF)
    {
        spellCheck(root, text);
        fprintf(fout, "%s ", text);
    }
    fclose(fin);
    fclose(fout);

    return 0;
}