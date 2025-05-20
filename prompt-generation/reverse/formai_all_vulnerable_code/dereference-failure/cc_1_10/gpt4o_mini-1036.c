//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Node structure for linked list representation of Alien Language characters
typedef struct Node {
    char alienCharacter;
    char englishEquivalent[50];
    struct Node* next;
} Node;

// Function prototypes
Node* createNode(char alienCharacter, const char* englishEquivalent);
void insertNode(Node** head, char alienCharacter, const char* englishEquivalent);
char* translateToEnglish(Node* head, const char* alienText);
void freeList(Node* head);
void displayTranslation(const char* alienText, const char* translation);

int main() {
    Node* translationDictionary = NULL;

    // Building Alien Language to English Dictionary
    insertNode(&translationDictionary, 'A', "Alpha");
    insertNode(&translationDictionary, 'B', "Beta");
    insertNode(&translationDictionary, 'C', "Gamma");
    insertNode(&translationDictionary, 'D', "Delta");
    insertNode(&translationDictionary, 'E', "Epsilon");

    // TODO: Extend this with more translations...

    char alienText[256];
    printf("Enter Alien Language text: ");
    fgets(alienText, sizeof(alienText), stdin);
    alienText[strcspn(alienText, "\n")] = 0;  // remove trailing newline

    char* translation = translateToEnglish(translationDictionary, alienText);
    displayTranslation(alienText, translation);

    // Free allocated memory
    free(translation);
    freeList(translationDictionary);

    return 0;
}

// Create a new linked list node
Node* createNode(char alienCharacter, const char* englishEquivalent) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->alienCharacter = alienCharacter;
        strcpy(newNode->englishEquivalent, englishEquivalent);
        newNode->next = NULL;
    }
    return newNode;
}

// Insert a new node into the linked list
void insertNode(Node** head, char alienCharacter, const char* englishEquivalent) {
    Node* newNode = createNode(alienCharacter, englishEquivalent);
    newNode->next = *head;
    *head = newNode;
}

// Translate Alien Language to English
char* translateToEnglish(Node* head, const char* alienText) {
    size_t translationLength = strlen(alienText) * 10;  // Estimating max translation length
    char* translation = (char*) malloc(translationLength);
    if (translation == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    translation[0] = '\0';  // Initialize translation string
    for (size_t i = 0; i < strlen(alienText); ++i) {
        char found = 0;
        for (Node* current = head; current != NULL; current = current->next) {
            if (current->alienCharacter == alienText[i]) {
                strcat(translation, current->englishEquivalent);
                strcat(translation, " ");  // Add a space between words
                found = 1;
                break;
            }
        }
        if (!found) {
            strcat(translation, "[Unknown]");
            strcat(translation, " ");
        }
    }
    return translation;
}

// Free the linked list
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Display the translation result
void displayTranslation(const char* alienText, const char* translation) {
    printf("Alien Text: %s\n", alienText);
    printf("Translation: %s\n", translation);
}