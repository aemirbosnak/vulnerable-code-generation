//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct {
    char alien_char[5];
    char human_trans[10];
} Translation;

Translation translations[] = {
    {"zzz19", "hello"},
    {"kl33r", "goodbye"},
    {"qa40x", "please"},
    {"nm11v", "thank you"},
    {"sb67t", "sorry"},
    {"fj04a", "yes"},
    {"pl55u", "no"},
    {"uy82p", "help"},
    {"de22r", "stop"},
    {"gi45n", "love"}
};

const int num_translations = sizeof(translations) / sizeof(Translation);
const int max_translation_length = 10;
const int max_alien_length = 5;

bool is_valid_alien_char(char* alien_char) {
    for (int i = 0; i < max_alien_length; i++) {
        char curr_char = alien_char[i];
        if (curr_char == '\0') {
            break;
        }
        if (!isalpha(curr_char) && !isdigit(curr_char)) {
            return false;
        }
    }
    return true;
}

bool is_valid_human_trans(char* human_trans) {
    for (int i = 0; i < max_translation_length; i++) {
        char curr_char = human_trans[i];
        if (curr_char == '\0') {
            break;
        }
        if (!isalpha(curr_char)) {
            return false;
        }
    }
    return true;
}

char* translate_to_human(char* alien_text) {
    char* human_text = (char*) malloc(sizeof(char) * max_translation_length + 1);
    bool found_translation = false;
    for (int i = 0; i < num_translations; i++) {
        if (strcmp(translations[i].alien_char, alien_text) == 0) {
            strcpy(human_text, translations[i].human_trans);
            found_translation = true;
            break;
        }
    }
    if (!found_translation) {
        sprintf(human_text, "Could not translate %s", alien_text);
    }
    return human_text;
}

bool validate_input(char* input) {
    if (strlen(input) == 0) {
        printf("Input cannot be empty.\n");
        return false;
    }
    for (int i = 0; i < strlen(input); i++) {
        if (!isalpha(input[i]) && !isdigit(input[i])) {
            printf("Input contains invalid characters: %c\n", input[i]);
            return false;
        }
    }
    if (strlen(input) > max_alien_length) {
        printf("Input exceeds maximum translation length of %d.\n", max_alien_length);
        return false;
    }
    return true;
}

void translate_input(char* input, char* output) {
    if (validate_input(input)) {
        if (is_valid_alien_char(input)) {
            strcpy(output, translate_to_human(input));
        } else if (is_valid_human_trans(input)) {
            bool found_translation = false;
            for (int i = 0; i < num_translations; i++) {
                if (strcmp(translations[i].human_trans, input) == 0) {
                    strcpy(output, translations[i].alien_char);
                    found_translation = true;
                    break;
                }
            }
            if (!found_translation) {
                sprintf(output, "Could not translate %s", input);
            }
        } else {
            printf("Input not recognized as either alien or human text.\n");
        }
    }
}

void print_greeting() {
    printf("Welcome to the Alien Language Translator!\n");
    printf("Enter 'quit' to exit at any time.\n");
    printf("Enter a string to translate:\n");
}

void print_translation(char* input, char* output) {
    printf("Translation for '%s': %s\n", input, output);
    printf("Enter another string to translate:\n");
}

void handle_input(char* input) {
    char output[max_translation_length + 1];
    memset(output, 0, sizeof(output));
    if (strcmp(input, "quit") == 0) {
        printf("Goodbye!\n");
        exit(0);
    } else {
        translate_input(input, output);
        print_translation(input, output);
    }
}

void get_input(char* input) {
    char buf[max_alien_length + 1];
    memset(buf, 0, sizeof(buf));
    scanf("%s", buf);
    fgets(input, max_alien_length + 1, stdin);
    input[strlen(input) - 1] = '\0';
    strcat(buf, input);
    strcpy(input, buf);
}

int main() {
    print_greeting();
    while (true) {
        char input[max_alien_length + 1];
        memset(input, 0, sizeof(input));
        get_input(input);
        handle_input(input);
    }
    return 0;
}