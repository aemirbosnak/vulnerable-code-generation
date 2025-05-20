//FormAI DATASET v1.0 Category: Spell checking ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DICTIONARY_SIZE 5000000 // maximum number of words stored in the dictionary
#define MAX_WORD_LENGTH 50 // maximum length of a word

typedef struct node { // data structure to store the dictionary words
    char data[MAX_WORD_LENGTH];
    struct node *next;
} node_t;

void insertWord(node_t **headptr, char *word) { // insert a word into the dictionary
    node_t *newNode = malloc(sizeof(*newNode));
    strcpy(newNode->data, word); // copy the word into the new node
    newNode->next = *headptr; // insert the node at the beginning of the linked list
    *headptr = newNode;
}

int searchWord(node_t **headptr, char *word) { // search for a word in the dictionary
    node_t *current = *headptr;
    while(current != NULL) {
        if(strcmp(current->data, word) == 0) { // if the word is found
            return 1; // return 1 for true
        }
        current = current->next; // move to the next node
    }
    return 0; // return 0 for false
}

void checkSpell(char *text, node_t **dictionary) { // check the spelling of a text
    char *word;
    int i = 0;
    while(text[i] != '\0') { // loop through each character in the text
        while((text[i] < 'A' || (text[i] > 'Z' && text[i] < 'a') || text[i] > 'z') && text[i] != '\0') { // skip non-alphabetic characters
            i++;
        }
        if(text[i] == '\0') { // break out of the loop if we reached the end of the string
            break;
        }
        int j = 0;
        word = malloc(MAX_WORD_LENGTH + 1);
        while(text[i] >= 'a' && text[i] <= 'z' || text[i] >= 'A' && text[i] <= 'Z' && j < MAX_WORD_LENGTH) { // extract the word
            if(text[i] >= 'a' && text[i] <= 'z') word[j] = text[i];
            if(text[i] >= 'A' && text[i] <= 'Z') word[j] = text[i] + ('a' - 'A'); // convert capital letters to small letters
            i++;
            j++;
        }
        word[j] = '\0'; // terminate the string
        if(strlen(word) > 0 && searchWord(dictionary, word) == 0) { // if the word is not found in the dictionary
            printf("\n%s is not in the dictionary!\n", word);
        }
        free(word);
    }
}

int main() {
    node_t *dictionary = NULL; // initialize the dictionary

    char word[MAX_WORD_LENGTH];
    FILE *dictionaryFile = fopen("dictionary.txt", "r"); // open the dictionary file
    if(dictionaryFile) {
        while(fscanf(dictionaryFile, "%s", word) == 1) {
            insertWord(&dictionary, word); // insert each word into the dictionary
        }
        fclose(dictionaryFile); // close the dictionary file
    } else {
        printf("Failed to load dictionary!\n");
        return 1;
    }

    char text[10000];
    printf("Enter some text to check its spelling:\n");
    fgets(text, 10000, stdin); // read the user's input
    checkSpell(text, &dictionary); // check the spelling

    return 0;
}