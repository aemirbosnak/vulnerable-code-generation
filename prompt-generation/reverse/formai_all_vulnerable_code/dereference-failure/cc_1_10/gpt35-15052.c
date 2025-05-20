//FormAI DATASET v1.0 Category: Spell checking ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define WORD_LENGTH 50  // Maximum length of a word

struct node {
    char word[WORD_LENGTH];  // Word in the dictionary
    char definition[WORD_LENGTH];  // Definition of the word
    struct node *next;  // Pointer to the next node in the linked list
};

struct node *dictionary[26];  // Array of linked lists to store words alphabetically

// Hash function to determine index for a word
int get_index(char c) {
    return (int) c - 97;
}

// Function to add a word to the dictionary
void add_word(char* word, char* definition) {
    int index = get_index(word[0]);
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    strcpy(new_node->word, word);
    strcpy(new_node->definition, definition);
    new_node->next = NULL;
    if (dictionary[index] == NULL) {
        dictionary[index] = new_node;
    } else {
        struct node *temp = dictionary[index];
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
    }
}

// Function to search for a word in the dictionary
void search_word(char* word) {
    int index = get_index(word[0]);
    struct node *temp = dictionary[index];
    while(temp != NULL) {
        if (strcmp(temp->word, word) == 0) {
            printf("The word %s is spelled correctly and its definition is %s\n", temp->word, temp->definition);
            return;
        }
        temp = temp->next;
    }
    printf("The word %s is misspelled\n", word);
}

int main() {
    char dict[WORD_LENGTH], word[WORD_LENGTH], definition[WORD_LENGTH];
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open dictionary file\n");
        exit(1);
    }
    // Load dictionary into memory
    while(fscanf(fp, "%s %s", word, definition) != EOF) {
        add_word(word, definition);
    }
    fclose(fp);
    printf("Enter a word to check its spelling (enter q to quit):\n");
    while(scanf("%s", word) == 1) {
        if (strcmp(word, "q") == 0) {
            return 0;
        }
        search_word(word);
        printf("Enter a word to check its spelling (enter q to quit):\n");
    }
    return 0;
}