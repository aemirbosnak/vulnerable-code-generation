//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LETTERS 10
#define MAX_LENGTH 256

typedef struct {
    char *content;
    int length;
} Letter;

void write_letter(Letter *letter, const char *text) {
    letter->length = strlen(text);
    letter->content = (char *)malloc((letter->length + 1) * sizeof(char));
    if (letter->content == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    strcpy(letter->content, text);
}

void read_letter(const Letter *letter) {
    printf("----------------------------\n");
    printf("Letter:\n%s\n", letter->content);
    printf("----------------------------\n");
}

void release_letter(Letter *letter) {
    free(letter->content);
    letter->content = NULL;
}

int main() {
    Letter *letters[MAX_LETTERS];
    char *romeo_love = "But, soft! What light through yonder window breaks?";
    char *juliet_love = "O Romeo, Romeo! wherefore art thou Romeo?";

    // Initialize letters
    for (int i = 0; i < MAX_LETTERS; i++) {
        letters[i] = (Letter *)malloc(sizeof(Letter));
        if (letters[i] == NULL) {
            fprintf(stderr, "Memory allocation failed!\n");
            exit(EXIT_FAILURE);
        }
    }

    // Romeo writes love letters
    for (int i = 0; i < 5; i++) {
        write_letter(letters[i], romeo_love);
    }

    // Juliet responds with her letters of love
    for (int i = 5; i < MAX_LETTERS; i++) {
        write_letter(letters[i], juliet_love);
    }

    // Reading the letters
    printf("Romeo's Letters:\n");
    for (int i = 0; i < 5; i++) {
        read_letter(letters[i]);
    }

    printf("Juliet's Letters:\n");
    for (int i = 5; i < MAX_LETTERS; i++) {
        read_letter(letters[i]);
    }

    // Releasing the allocated memory
    for (int i = 0; i < MAX_LETTERS; i++) {
        release_letter(letters[i]);
        free(letters[i]);
    }

    return 0;
}