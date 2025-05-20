//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LEN 100
#define MAX_TRANSLATED_LEN 300

// CAT language vocabulary (post-apocalyptic theme)
const char *cat_vocab[][2] = {
    {"meow", "Greetings, human or fellow scavenger."},
    {"purr", "All is well in this wasteland."},
    {"hiss", "Beware of the dangers lurking."},
    {"scratch", "We must fight for our territory."},
    {"hunt", "Time to gather food or supplies."},
    {"sniff", "Investigate your surroundings."},
    {"whiskers", "Friend or foe?"},
    {"tail", "Watch my back."},
    {"feline", "A creature of agility."},
    {"mew", "Request for assistance."},
    {"roar", "Announce your presence!"}
};

// Function to translate human speech into Cat language
void translate_to_cat(const char *input, char *translated) {
    translated[0] = '\0';  // Initialize translated string

    // Break the input into tokens
    char *token = strtok((char *)input, " ");
    
    while (token != NULL) {
        size_t i;
        int found = 0;
        
        // Check the vocabulary
        for (i = 0; i < sizeof(cat_vocab) / sizeof(cat_vocab[0]); i++) {
            if (strcmp(token, cat_vocab[i][0]) == 0) {
                strcat(translated, cat_vocab[i][1]);
                strcat(translated, " ");  // Add a space after each translation
                found = 1;
                break;
            }
        }

        // If not found in cat vocabulary, append the original token
        if (!found) {
            strcat(translated, token);
            strcat(translated, " (unknown) ");  // Mark as unknown
        }
        
        token = strtok(NULL, " ");  // Get the next token
    }

    // Remove the trailing space
    translated[strlen(translated) - 1] = '\0';
}

// Main function
int main() {
    char input[MAX_INPUT_LEN];
    char translated[MAX_TRANSLATED_LEN];

    printf("Post-Apocalyptic Cat Language Translator\n");
    printf("Type your sentences for translation (type 'exit' to quit):\n");
    
    while (1) {
        // Get user input
        printf("> ");
        fgets(input, sizeof(input), stdin);
        
        // Remove newline character from the input
        input[strcspn(input, "\n")] = 0;

        // Exit condition
        if (strcmp(input, "exit") == 0) {
            printf("Returning to the shadows...\n");
            break;
        }

        // Perform translation
        translate_to_cat(input, translated);
        
        // Output the translated text
        printf("Cat Translation: %s\n", translated);
    }
    return 0;
}