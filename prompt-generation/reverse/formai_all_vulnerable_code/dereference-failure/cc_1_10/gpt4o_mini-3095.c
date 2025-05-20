//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 1024
#define MAX_TRANSLATIONS 100

typedef struct {
    char* english;
    char* alien;
} Translation;

Translation dictionary[MAX_TRANSLATIONS];
int translation_count = 0;

void initialize_dictionary() {
    dictionary[translation_count++] = (Translation){"hello", "xylthar"};
    dictionary[translation_count++] = (Translation){"world", "korvax"};
    dictionary[translation_count++] = (Translation){"cyber", "draxos"};
    dictionary[translation_count++] = (Translation){"punk", "zel'korr"};
    dictionary[translation_count++] = (Translation){"neon", "glothan"};
    dictionary[translation_count++] = (Translation){"code", "pyrax"};
    dictionary[translation_count++] = (Translation){"data", "zenith"};
    dictionary[translation_count++] = (Translation){"matrix", "vortex"};
    dictionary[translation_count++] = (Translation){"hack", "flayz"};
    dictionary[translation_count++] = (Translation){"future", "elexis"};
    // Add more translations as needed
}

char* translate_to_alien(const char* input) {
    static char translated[MAX_INPUT];
    strcpy(translated, "");

    char* token = strtok(strdup(input), " ");
    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < translation_count; i++) {
            if (strcasecmp(token, dictionary[i].english) == 0) {
                strcat(translated, dictionary[i].alien);
                strcat(translated, " ");
                found = 1;
                break;
            }
        }
        if (!found) {
            strcat(translated, token);
            strcat(translated, " "); // Keep unknown words unchanged
        }
        token = strtok(NULL, " ");
    }
    
    return translated;
}

void display_usage() {
    printf("======= Cyber Translator V1.0 =======\n");
    printf("Usage: Enter text to be translated into Alien Language.\n");
    printf("Type 'exit' to leave the program.\n");
    printf("=======================================\n");
}

int main() {
    char input[MAX_INPUT];
    initialize_dictionary();
    display_usage();

    while (1) {
        printf(">> "); // User prompt
        fgets(input, MAX_INPUT, stdin);
        
        // Remove trailing newline character
        input[strcspn(input, "\n")] = 0;

        if (strcasecmp(input, "exit") == 0) {
            printf("Exiting Cyber Translator...\n");
            break;
        }

        char* result = translate_to_alien(input);
        printf("Transalted (Alien): %s\n", result);
    }

    return 0;
}