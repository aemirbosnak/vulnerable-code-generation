//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ART_WIDTH 40
#define ART_HEIGHT 5
#define ART_SET_SIZE 26

const char art_set[ART_SET_SIZE][ART_WIDTH] = {
    "--------",
    "-------O",
    "O-------",
    "O-______",
    "O--...--",
    "O---..--",
    "O--....-",
    "O-----..",
    "O----...",
    "O-----.-",
    "O------.",
    "O--------",
    "------O--",
    "------O-",
    "-------O",
    "-------|",
    "-------|",
    "-------|",
    "--------",
    "--------",
    "--------",
    "--------",
    "--------",
    "--------",
    "--------",
    "--------",
    "--------",
    "--------",
    "--------"
};

void generate_ascii_art(char letter) {
    int index = tolower(letter) - 'a';

    if (index < 0 || index >= ART_SET_SIZE) {
        printf("Invalid input: '%c'.\n", letter);
        return;
    }

    printf("\n");
    for (int i = 0; i < ART_HEIGHT; ++i) {
        printf("%s\n", art_set[index] + i * ART_WIDTH);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    char first_letter = argv[1][0];

    if (!isalpha(first_letter)) {
        printf("Error: Invalid input: '%c' is not a valid first letter.\n", first_letter);
        return 1;
    }

    generate_ascii_art(first_letter);

    return 0;
}