//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Please, give me a word or a sentence in English: ");
    char input[100];
    fgets(input, 100, stdin);

    // Remove the newline character from the input
    input[strcspn(input, "\n")] = 0;

    // Convert the input to lowercase
    for (int i = 0; input[i] != '\0'; i++) {
        input[i] = tolower(input[i]);
    }

    // Create a dictionary of English words and their Cat Language translations
    char *englishWords[] = {"hello", "world", "cat", "dog", "mouse"};
    char *catLanguageTranslations[] = {"nya", "nyan", "nyaa", "nyau", "nyaun"};

    // Translate the input to Cat Language
    char *output = malloc(100);
    int outputIndex = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        // Check if the current character is a space
        if (input[i] == ' ') {
            output[outputIndex++] = ' ';
            continue;
        }

        // Find the index of the current character in the English words array
        int index = -1;
        for (int j = 0; j < 5; j++) {
            if (input[i] == englishWords[j][0]) {
                index = j;
                break;
            }
        }

        // If the current character is not found in the English words array, add it to the output as is
        if (index == -1) {
            output[outputIndex++] = input[i];
        } else {
            // Add the Cat Language translation of the current character to the output
            for (int j = 0; catLanguageTranslations[index][j] != '\0'; j++) {
                output[outputIndex++] = catLanguageTranslations[index][j];
            }
        }
    }

    // Add a newline character to the output
    output[outputIndex++] = '\n';

    // Print the output
    printf("The translation in Cat Language is: %s", output);

    // Free the allocated memory
    free(output);

    return 0;
}