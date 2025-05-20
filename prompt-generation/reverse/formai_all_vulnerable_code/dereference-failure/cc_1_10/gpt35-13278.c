//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: invasive
#include <stdio.h>
#include <string.h>

// Function to convert C Cat language to English
char* translate(char* cCat) {
    // Stored translations
    char** translations = malloc(sizeof(char*) * 4);
    translations[0] = "meow";       // translates to "for"
    translations[1] = "purr";       // translates to "while"
    translations[2] = "hiss";       // translates to "if"
    translations[3] = "scratch";    // translates to "else"
    
    // Tokenize input string
    char* token;
    const char delimiter[2] = " ";
    token = strtok(cCat, delimiter);

    // Loop through tokens and translate
    char* english = malloc(sizeof(char) * 100);
    while (token != NULL) {
        // Check for translations to replace
        if (strcmp(token, "meow") == 0) {
            strcat(english, "for");
        } else if (strcmp(token, "purr") == 0) {
            strcat(english, "while");
        } else if (strcmp(token, "hiss") == 0) {
            strcat(english, "if");
        } else if (strcmp(token, "scratch") == 0) {
            strcat(english, "else");
        } else {
            strcat(english, token);
        }

        // Add space between words
        strcat(english, " ");

        // Get next token
        token = strtok(NULL, delimiter);
    }

    // Free memory and return translated string
    free(translations);
    return english;
}

int main() {
    // Set C Cat input
    char* cCat = "hiss i > 5 scratch meow printf(\"i is greater than 5\")";

    // Translate to English and print result
    char* english = translate(cCat);
    printf("%s", english);

    // Free memory
    free(english);

    return 0;
}