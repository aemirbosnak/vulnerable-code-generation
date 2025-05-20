//FormAI DATASET v1.0 Category: Spell checking ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define DICTIONARY "dictionary.txt"

/**
 * This is a program to check the spelling of words in a text file against a dictionary.
 * The dictionary file must be specified as a constant at the top of the code.
 *
 * The program will output each word along with a message indicating if it is spelled correctly or not.
 **/

// Define a linked list node structure to store the dictionary words
typedef struct node
{
    char word[46];
    struct node *next;
} node;

node *hashtable[26] = {NULL}; // Initialize to NULL

// Function to append new nodes to the end of the linked list
void append(node **llist, char *word)
{
    node *new_node = malloc(sizeof(node));
    strcpy(new_node->word, word);
    new_node->next = NULL;

    // If the list is empty, make the new node the head
    if (*llist == NULL)
    {
        *llist = new_node;
    }
    else
    {
        // Otherwise, traverse the list and append the new node to the end
        node *temp = *llist;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Function to free memory allocated for the linked list
void free_list(node *llist)
{
    while (llist != NULL)
    {
        node *temp = llist;
        llist = llist->next;
        free(temp);
    }
}

// Function to hash a string and return an index into the hashtable
int hash(char *word)
{
    return tolower(word[0]) - 'a';
}

void load_dictionary()
{
    FILE *file = fopen(DICTIONARY, "r");
    if (file == NULL)
    {
        printf("Could not open file: %s\n", DICTIONARY);
        exit(1);
    }

    char word[46];

    // Read each word from the file and add it to the hashtable
    while (fscanf(file, "%45s", word) != EOF)
    {
        int index = hash(word);
        append(&hashtable[index], word);
    }

    fclose(file);
}

bool check_word(char *word)
{
    int index = hash(word);

    // Traverse the linked list at the appropriate index of the hashtable
    node *temp = hashtable[index];
    while (temp != NULL)
    {
        if (strcasecmp(temp->word, word) == 0)
        {
            return true; // Word is in the dictionary, so it is spelled correctly
        }
        temp = temp->next;
    }

    return false; // Word is not in the dictionary, so it is spelled incorrectly
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <text file>\n", argv[0]);
        exit(1);
    }

    load_dictionary();

    // Open the text file for reading
    FILE *text = fopen(argv[1], "r");
    if (text == NULL)
    {
        printf("Could not open file: %s\n", argv[1]);
        exit(1);
    }

    char word[46];
    int count = 0;

    // Read each word from the text file and check if it is spelled correctly
    while (fscanf(text, "%45s", word) != EOF)
    {
        // Remove any punctuation from the end of the word
        int len = strlen(word);
        if (len > 0 && ispunct(word[len-1]))
        {
            word[len-1] = '\0';
        }

        // Check if the word is spelled correctly
        if (check_word(word))
        {
            printf("%s: Correct\n", word);
        }
        else
        {
            printf("%s: Incorrect\n", word);
            count++;
        }
    }

    fclose(text);

    printf("\n");
    printf("%d total misspelled words.\n", count);

    // Free memory allocated for the linked list
    for (int i = 0; i < 26; i++)
    {
        free_list(hashtable[i]);
    }

    return 0;
}