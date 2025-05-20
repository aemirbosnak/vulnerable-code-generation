//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for dictionary words
typedef struct WordNode {
    char word[50];
    struct WordNode* next;
} WordNode;

// Function to create a new word node
WordNode* createWordNode(const char* word) {
    WordNode* newNode = (WordNode*) malloc(sizeof(WordNode));
    strcpy(newNode->word, word);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a word into the dictionary linked list
void insertWord(WordNode** head, const char* word) {
    WordNode* newNode = createWordNode(word);
    newNode->next = *head;
    *head = newNode;
}

// Function to check if a word exists in the dictionary
int checkWord(WordNode* head, const char* word) {
    WordNode* current = head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return 1; // Word found
        }
        current = current->next;
    }
    return 0; // Word not found
}

// Function to load dictionary words from a file into a linked list
WordNode* loadDictionary(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Could not open dictionary file.\n");
        return NULL;
    }

    WordNode* head = NULL;
    char word[50];
    while (fscanf(file, "%49s", word) == 1) {
        insertWord(&head, word);
    }
    
    fclose(file);
    return head;
}

// Function to check spelling of words in a sentence
void checkSpelling(WordNode* dictionary, const char* sentence) {
    char word[50];
    const char* ptr = sentence;
    
    while (*ptr) {
        int len = 0;
        while (*ptr && (isalpha(*ptr) || *ptr == '\'' )) {
            word[len++] = *ptr++;
        }
        word[len] = '\0';

        if (len > 0 && !checkWord(dictionary, word)) {
            printf("Misspelled word: %s\n", word);
        }

        // Skip non-alphabetic characters
        while (*ptr && !isalpha(*ptr)) {
            ptr++;
        }
    }
}

int main() {
    const char* dictionaryFile = "dictionary.txt"; // Name of the dictionary file
    WordNode* dictionary = loadDictionary(dictionaryFile);

    if (dictionary == NULL) {
        return 1; // Error loading dictionary
    }

    char sentence[256];
    
    printf("Enter a sentence (type 'exit' to quit):\n");
    
    while (1) {
        fgets(sentence, sizeof(sentence), stdin);
        sentence[strcspn(sentence, "\n")] = 0; // Remove newline character
        
        if (strcmp(sentence, "exit") == 0) {
            break;
        }

        checkSpelling(dictionary, sentence);
    }

    // Free dictionary memory
    WordNode* current = dictionary;
    while (current != NULL) {
        WordNode* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}