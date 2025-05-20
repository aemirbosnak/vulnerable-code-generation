//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 128
#define MAX_WORD_LENGTH 30

typedef struct Translation {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
    struct Translation* next;
} Translation;

Translation* hashTable[TABLE_SIZE];

unsigned int hash(const char* str) {
    unsigned int hashValue = 0;
    while (*str) {
        hashValue += *str++;
    }
    return hashValue % TABLE_SIZE;
}

void insertTranslation(const char* english, const char* alien) {
    unsigned int index = hash(english);
    Translation* newTranslation = (Translation*)malloc(sizeof(Translation));
    strcpy(newTranslation->english, english);
    strcpy(newTranslation->alien, alien);
    newTranslation->next = hashTable[index];
    hashTable[index] = newTranslation;
}

const char* translate(const char* english) {
    unsigned int index = hash(english);
    Translation* current = hashTable[index];
    while (current) {
        if (strcmp(current->english, english) == 0) {
            return current->alien;
        }
        current = current->next;
    }
    return NULL;
}

void loadTranslations() {
    insertTranslation("hello", "glorp");
    insertTranslation("goodbye", "fleep");
    insertTranslation("friend", "zork");
    insertTranslation("enemy", "blargh");
    insertTranslation("peace", "swizzle");
    insertTranslation("love", "plarn");
    insertTranslation("war", "zaboo");
    insertTranslation("star", "kirok");
    insertTranslation("planet", "frindle");
    insertTranslation("universe", "grumble");
}

void freeTranslations() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Translation* current = hashTable[i];
        while (current) {
            Translation* temp = current;
            current = current->next;
            free(temp);
        }
    }
}

void printMenu() {
    printf("Welcome to the Alien Language Translator!\n");
    printf("1. Translate English to Alien\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

int main() {
    loadTranslations();
    int choice;
    char input[MAX_WORD_LENGTH];

    while (1) {
        printMenu();
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter an English word: ");
            scanf("%s", input);
            const char* translation = translate(input);
            if (translation) {
                printf("Alien Translation: %s\n", translation);
            } else {
                printf("Translation not found.\n");
            }
        } else if (choice == 2) {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    freeTranslations();
    return 0;
}