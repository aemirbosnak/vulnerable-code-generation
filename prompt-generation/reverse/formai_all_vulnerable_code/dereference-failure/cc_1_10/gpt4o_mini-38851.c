//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to translate a word into Cat Language
char* translate_to_cat(const char* word) {
    // Calculating lengths
    int length = strlen(word);
    // Allocating space for the translated word (adding "meow" at the end)
    char* cat_word = (char*)malloc(length + 5);
    
    // Constructing the cat word
    strcpy(cat_word, word);
    strcat(cat_word, " meow");

    return cat_word;
}

// Function to translate a sentence into Cat Language
void translate_sentence_to_cat_language(const char* sentence) {
    // Splitting the sentence into words
    char sentence_copy[256];
    strcpy(sentence_copy, sentence);
    
    char* token = strtok(sentence_copy, " ");
    printf("Cat Language Translation:\n");
    
    // Translating each word
    while (token != NULL) {
        char* cat_translation = translate_to_cat(token);
        printf("%s ", cat_translation);
        free(cat_translation);
        token = strtok(NULL, " ");
    }
    
    printf("\n");
}

// Main function
int main() {
    char input[256];
    
    printf("Welcome to the Cat Language Translator!\n");
    printf("Enter a sentence to translate (type 'exit' to quit):\n");
    
    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);
        
        // Removing the newline character at the end of input
        input[strcspn(input, "\n")] = 0;

        // Exit condition
        if (strcmp(input, "exit") == 0) {
            break;
        }
        
        // Translating the sentence into Cat Language
        translate_sentence_to_cat_language(input);
    }
    
    printf("Thank you for using the Cat Language Translator!\n");
    return 0;
}