//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define alien language mappings
#define MAX_ALIEN_LENGTH 100
#define ALIEN_WORDS 10

typedef struct {
    char english[20];
    char alien[MAX_ALIEN_LENGTH];
} DictionaryEntry;

DictionaryEntry dictionary[ALIEN_WORDS] = {
    {"hello", "zorbax"},
    {"world", "flibnob"},
    {"cat", "thrindel"},
    {"dog", "voopax"},
    {"computer", "kreezbit"},
    {"language", "gromtik"},
    {"translator", "zibrax"},
    {"friend", "nartok"},
    {"love", "kalam"},
    {"peace", "pizzul"},
};

// Function to translate from English to Alien
void translate_to_alien(const char *input, char *output) {
    char *token = strtok(strdup(input), " ");
    output[0] = '\0'; // Initialize output

    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < ALIEN_WORDS; i++) {
            if (strcmp(token, dictionary[i].english) == 0) {
                strcat(output, dictionary[i].alien);
                strcat(output, " "); // Separate words with space
                found = 1;
                break;
            }
        }
        if (!found) {
            strcat(output, token); // In case we couldn't find a translation
            strcat(output, " ");
        }
        token = strtok(NULL, " ");
    }
    output[strlen(output) - 1] = '\0'; // Remove trailing space
}

// Function to display the translated text
void display_translation(const char *english, const char *alien) {
    printf("English: %s\n", english);
    printf("Alien:   %s\n", alien);
}

char* get_user_input() {
    char *input = malloc(256);
    printf("Enter the English text to translate to Alien language:\n");
    fgets(input, 256, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character
    return input;
}

int main() {
    char *user_input = get_user_input();
    char alien_translation[MAX_ALIEN_LENGTH * 10]; // Assume max translation length
    translate_to_alien(user_input, alien_translation);
    display_translation(user_input, alien_translation);
    free(user_input);
    return 0;
}