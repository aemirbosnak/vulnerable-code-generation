//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure to hold Cat language words
typedef struct CatWordNode {
    char* englishWord;
    char* catWord; // Cat language equivalent
    struct CatWordNode* next;
} CatWordNode;

// Function prototypes
CatWordNode* createNode(const char *english, const char *cat);
void addWord(CatWordNode** head, const char *english, const char *cat);
void translateWord(CatWordNode* head, const char *word);
void freeList(CatWordNode* head);
void loadDictionary(CatWordNode** head, const char* filename);
void interactiveTranslation(CatWordNode* head);

int main() {
    CatWordNode* dictionary = NULL;
    
    loadDictionary(&dictionary, "cat_dictionary.txt");
    interactiveTranslation(dictionary);
    
    freeList(dictionary);
    return 0;
}

// Function to create a new word node
CatWordNode* createNode(const char *english, const char *cat) {
    CatWordNode* newNode = (CatWordNode*)malloc(sizeof(CatWordNode));
    newNode->englishWord = strdup(english);
    newNode->catWord = strdup(cat);
    newNode->next = NULL;
    return newNode;
}

// Function to add a word to the linked list
void addWord(CatWordNode** head, const char *english, const char *cat) {
    CatWordNode* newNode = createNode(english, cat);
    newNode->next = *head;
    *head = newNode;
}

// Function to translate a given word
void translateWord(CatWordNode* head, const char *word) {
    CatWordNode* current = head;
    while (current != NULL) {
        if (strcmp(current->englishWord, word) == 0) {
            printf("The Cat language equivalent of '%s' is '%s'.\n", word, current->catWord);
            return;
        }
        current = current->next;
    }
    printf("The word '%s' is not found in the Cat language dictionary.\n", word);
}

// Function to free the linked list
void freeList(CatWordNode* head) {
    CatWordNode* current = head;
    CatWordNode* nextNode;
    
    while (current != NULL) {
        nextNode = current->next;
        free(current->englishWord);
        free(current->catWord);
        free(current);
        current = nextNode;
    }
}

// Function to load dictionary from a file
void loadDictionary(CatWordNode** head, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }
    
    char english[100];
    char cat[100];
    while (fscanf(file, "%99s %99s", english, cat) != EOF) {
        addWord(head, english, cat);
    }
    
    fclose(file);
}

// Function for interactive user input for translation
void interactiveTranslation(CatWordNode* head) {
    char input[100];
    
    printf("Welcome to the Cat Language Translator! Type 'exit' to quit.\n");
    
    while (1) {
        printf("Enter an English word to translate: ");
        scanf("%99s", input);
        
        if (strcmp(input, "exit") == 0) {
            break;
        }
        
        translateWord(head, input);
    }
}