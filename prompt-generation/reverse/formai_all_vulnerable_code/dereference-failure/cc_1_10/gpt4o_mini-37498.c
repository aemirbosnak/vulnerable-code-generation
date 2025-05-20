//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define MAX_WORD_LENGTH 50
#define MAX_WORDS 20

void surreal_string_manipulation(char *input) {
    printf("Whispers of the surreal begin...\n");
    char *words[MAX_WORDS];
    int word_count = 0;

    // Tokenizing the string with surreal intention
    char *token = strtok(input, " ");
    while (token != NULL && word_count < MAX_WORDS) {
        words[word_count++] = token;
        token = strtok(NULL, " ");
    }

    // Creating a new surreal phrase
    char *surreal_phrase = malloc(MAX_LINE_LENGTH);
    surreal_phrase[0] = '\0'; // Start with an empty string

    printf("Dreams woven from your words:\n");
    for (int i = 0; i < word_count; ++i) {
        // An example of a surrealist transformation
        if (i % 2 == 0) {
            strcat(surreal_phrase, words[i]);
            strcat(surreal_phrase, "-");
        } else {
            char temp[MAX_WORD_LENGTH];
            sprintf(temp, "%s:%s ", words[i], "waltzing through shadows");
            strcat(surreal_phrase, temp);
        }
    }

    // Simulating an irreversible metamorphosis
    printf("Metamorphosed Phrase: %s\n", surreal_phrase);

    char *dreamscape = malloc(MAX_LINE_LENGTH);
    snprintf(dreamscape, MAX_LINE_LENGTH, "In the land of %s, unravels the hue of time.", surreal_phrase);
    printf("In the land of dreams: %s\n", dreamscape);

    // Reversing the surreal phrase
    char reversed[MAX_LINE_LENGTH];
    int j = 0;
    for (int i = strlen(surreal_phrase) - 1; i >= 0; --i) {
        reversed[j++] = surreal_phrase[i];
    }
    reversed[j] = '\0';

    printf("Backwards through the mist: %s\n", reversed);

    // Counting vowels and consonants
    int vowels = 0, consonants = 0;
    for (int i = 0; i < strlen(surreal_phrase); ++i) {
        char c = tolower(surreal_phrase[i]);
        if (isalpha(c)) {
            if (strchr("aeiou", c)) {
                vowels++;
            } else {
                consonants++;
            }
        }
    }

    printf("Vowels: %d | Consonants: %d\n", vowels, consonants);

    // Freeing allocated memory
    free(surreal_phrase);
    free(dreamscape);
}

int main() {
    // A surreal canvas awaits your brushstrokes
    char input[MAX_LINE_LENGTH];
    printf("Enter your stream of consciousness:\n");
    if (fgets(input, MAX_LINE_LENGTH, stdin) != NULL) {
        // Strip newline character, if present
        input[strcspn(input, "\n")] = 0;
        surreal_string_manipulation(input);
    }

    printf("As the echoes fade, may your thoughts dance in the void...\n");
    return 0;
}