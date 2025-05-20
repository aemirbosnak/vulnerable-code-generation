//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

// Function to translate English words to Alien language
char* translateToAlien(const char* englishWord) {
    // Setting up the poetic translations
    if (strcmp(englishWord, "love") == 0) return "kralia";
    if (strcmp(englishWord, "star") == 0) return "shi'rak";
    if (strcmp(englishWord, "heart") == 0) return "zha'in";
    if (strcmp(englishWord, "rose") == 0) return "qlen'ta";
    if (strcmp(englishWord, "moon") == 0) return "vaelun";
    if (strcmp(englishWord, "dream") == 0) return "luri'tha";
    if (strcmp(englishWord, "eternal") == 0) return "na'quil";
    
    return englishWord; // Default return if no translation found
}

// Function to create love poem in alien language
void createLovePoem(const char* englishPoem) {
    char* token;
    char* poemCopy = malloc(strlen(englishPoem) + 1);
    strcpy(poemCopy, englishPoem);
    
    printf("In the language of love, your words transform to:\n");
    token = strtok(poemCopy, " "); 

    while (token != NULL) {
        printf("%s ", translateToAlien(token)); 
        token = strtok(NULL, " ");
    }

    printf("\n\nOh, how sweet are the whispers of your heart!\n");
    printf("In this alien embrace, our love knows no bounds...\n");
    
    free(poemCopy);
}

int main() {
    char englishPoem[MAX];

    printf("Dearest, enter your romantic words and let them dance:\n");
    fgets(englishPoem, sizeof(englishPoem), stdin);
    
    // Remove the newline character from ending if present
    englishPoem[strcspn(englishPoem, "\n")] = '\0';
    
    // Create the love poem in alien language
    createLovePoem(englishPoem);
    
    return 0;
}