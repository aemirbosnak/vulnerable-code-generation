//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to translate English to Cat Language
void translateToCatLanguage(const char *input) {
    const char *meow = "meow";
    const char *purr = "purr";
    
    // Surprised counter
    int surpriseCounter = 0;

    // Calculate the length of the input
    int length = strlen(input);
    char *catLanguage = (char *)malloc(length * 5); // Allocate enough space
    if (!catLanguage) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    catLanguage[0] = '\0'; // Initialize the string

    for (int i = 0; i < length; i++) {
        // Surprise effect logic
        if (input[i] == 'a' || input[i] == 'A') {
            strcat(catLanguage, meow);
            surpriseCounter++;
        } else if (input[i] == 'o' || input[i] == 'O') {
            strcat(catLanguage, purr);
            surpriseCounter++;
        } else {
            char temp[2] = {input[i], '\0'};
            strcat(catLanguage, temp);
        }
    }

    printf("Surprise Translation:\n");
    printf("%s\n", catLanguage);
    printf("Surprises Encountered: %d\n", surpriseCounter);

    free(catLanguage); // Deallocate memory
}

int main() {
    char input[256];

    // Prompt and read input
    printf("Enter an English sentence (up to 255 characters): ");
    fgets(input, sizeof(input), stdin);
   
    // Remove newline character if it exists
    input[strcspn(input, "\n")] = '\0';

    // Translate to Cat Language
    translateToCatLanguage(input);
    
    // Additional dosage of surprise!
    printf("Just in case you thought that was it...\nStay tuned for an encore!\n");

    // Extra Translation
    printf("Here is another surprise translation 'Wow!': ");
    translateToCatLanguage("Wow!");

    return 0;
}