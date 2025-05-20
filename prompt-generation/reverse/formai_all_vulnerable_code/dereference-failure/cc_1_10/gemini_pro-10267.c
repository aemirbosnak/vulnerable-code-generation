//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: energetic
// Prepare for the meow-jestic translation journey!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our feline dictionary
char cat_dictionary[][25] = {
    "Meow", "Purr", "Hiss", "Trill", "Chirp",
    "Yowl", "Caterwaul", "Mrow", "Mrrp", "Mew"
};

// Translation function - let's turn human into cat!
char *translate_to_cat(char *human_phrase) {
    // Allocate memory for the cat-translated phrase
    char *cat_phrase = (char *)malloc(strlen(human_phrase) * 3);

    // Loop through each character in the human phrase
    int i = 0;
    while (human_phrase[i] != '\0') {
        // Convert the character to lowercase for easier comparison
        char lowercase = tolower(human_phrase[i]);

        // Search for the corresponding cat word in our dictionary
        int found = 0;
        for (int j = 0; j < 10; j++) {
            if (strcmp(cat_dictionary[j], &lowercase) == 0) {
                strcat(cat_phrase, cat_dictionary[j]);
                found = 1;
                break;
            }
        }

        // If no translation found, use the original character
        if (!found) {
            char str[2];
            sprintf(str, "%c", lowercase);
            strcat(cat_phrase, str);
        }

        i++;
    }

    // Return the cat-translated phrase with a cute meow at the end
    return strcat(cat_phrase, " Meow!");
}

int main(void) {
    // Let's get the human phrase we want to translate
    char human_phrase[100];
    printf("Enter a phrase you want to translate into cat language: ");
    gets(human_phrase);

    // Translate the human phrase into cat language
    char *cat_phrase = translate_to_cat(human_phrase);

    // Display the cat-translated phrase with style!
    printf("\nYour phrase in cat language is:\n");
    printf("---------------------------------\n");
    printf("%s\n", cat_phrase);
    printf("---------------------------------\n");

    // Free the memory allocated for the cat-translated phrase
    free(cat_phrase);

    return 0; // Mission accomplished - human to cat translation complete!
}