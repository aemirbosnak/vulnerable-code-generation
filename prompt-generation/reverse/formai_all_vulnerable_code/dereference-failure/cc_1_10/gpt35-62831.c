//FormAI DATASET v1.0 Category: Spell checking ; Style: multivariable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

// A structure to represent dictionary words
struct TrieNode
{
    struct TrieNode* children[26];
    bool isEndOfWord;
};

// Function to create a new Trie node
struct TrieNode* createNode()
{
    struct TrieNode* node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    node->isEndOfWord = false;
    for(int i=0;i<26;i++)
        node->children[i] = NULL;
    return node;
}

// Function to insert a word into Trie
void insert(struct TrieNode* root, char* key)
{
    struct TrieNode* node = root;
    int index,len=strlen(key);

    for(int i=0;i<len;i++)
    {
        index = key[i] - 'a';
        if(!node->children[index])
            node->children[index] = createNode();
        node = node->children[index];
    }
    node->isEndOfWord = true;
}

// Main function to check spellings of words in input file
void spellCheck(char* fileName,struct TrieNode* root)
{
    char buffer[1000],word[100];
    FILE* fp = fopen(fileName,"r");

    if(fp == NULL)
    {
        printf("Failed to open file!\n");
        return;
    }

    printf("Misspelled words:\n");
    while(fscanf(fp,"%s",buffer) == 1)
    {
        int len = strlen(buffer);
        int j=0;
        bool isFound = true;

        for(int i=0;i<len;i++)
        {
            char c = buffer[i];
            if(c<97)
                c+=32;
            if(c>122 || c<97)
            {
                if(j!=0)
                {
                    word[j]='\0';
                    struct TrieNode* node = root;
                    for(int k=0;k<j;k++)
                    {
                        int index = word[k] - 'a';
                        if(!node->children[index])
                        {
                            isFound = false;
                            break;
                        }
                        node = node->children[index];
                    }
                    if(!isFound || !node->isEndOfWord)
                        printf("%s\n",word);
                }
                j=0;    
            }
            else    
                word[j++] = c;
        }
        if(j!=0)    
        {
            word[j]='\0';
            struct TrieNode* node = root;
            for(int k=0;k<j;k++)
            {
                int index = word[k] - 'a';
                if(!node->children[index])
                {
                    isFound = false;
                    break;
                }
                node = node->children[index];
            }
            if(!isFound || !node->isEndOfWord)
                printf("%s\n",word);
        }
    }
    fclose(fp);
}

// Driver function
int main()
{
    struct TrieNode* root = createNode();

    // Read input dictionary file
    FILE* fp = fopen("dictionary.txt","r");
    if(fp == NULL)
    {
        printf("Failed to open file!\n");
        return 0;
    }
    char buffer[1000];
    while(fscanf(fp,"%s",buffer) == 1)
        insert(root,buffer);
    fclose(fp);

    // Spell check input file
    spellCheck("input.txt",root);

    return 0;
}