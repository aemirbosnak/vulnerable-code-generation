//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char letter;
    unsigned char value;
} character;

// Function to calculate checksum of a single character
unsigned char calculate_checksum(character character) {
    unsigned char checksum = character.value;
    for (int i = 0; i < 256; i++) {
        if (i != character.value && (checksum & 1))
            checksum ^= i;
        checksum = (checksum << 1) | (checksum >> 7);
    }
    return checksum;
}

// Function to calculate checksum of a string
unsigned char string_checksum(const char* string) {
    unsigned char checksum = 0;
    int length = strlen(string);
    for (int i = 0; i < length; i++) {
        character current_character = {string[i], strlen(&string[i]) + string[i]};
        checksum = calculate_checksum(current_character) ^ checksum;
    }
    return checksum;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    unsigned char input_checksum = string_checksum(argv[1]);
    printf("Input checksum: %#x\n", input_checksum);

    // Medieval Knights' chants
    printf("\nHear ye, hear ye, knights of the realm,\n");
    printf("Gather round, bring thy helm and shield,\n");
    printf("In this mystic art, we shall partake,\n");
    printf("To calculate a checksum, our noble goal.\n");
    printf("\nForsooth, this strange device we hail,\n");
    printf("A parchment scroll, inscribed with grace,\n");
    printf("With characters, its meaning to unveil,\n");
    printf("Each one transformed, in magic's embrace.\n");

    // Calculate checksum of each character in the given string
    for (int i = 0; i < strlen(argv[1]); i++) {
        character current_character = {argv[1][i], strlen(&argv[1][i]) + argv[1][i]};
        unsigned char current_checksum = calculate_checksum(current_character);
        printf("Character: %c, Checksum: %#x\n", current_character.letter, current_checksum);
    }

    // Combine all character checksums to find the final checksum
    unsigned char final_checksum = 0;
    for (int i = 0; i < strlen(argv[1]); i++) {
        character current_character = {argv[1][i], strlen(&argv[1][i]) + argv[1][i]};
        final_checksum = calculate_checksum(current_character) ^ final_checksum;
    }

    printf("\nThus, our noble quest, we now have found,\n");
    printf("The final checksum, in this hallowed ground,\n");
    printf("To verify the integrity, without a doubt,\n");
    printf("Comparing it with the input, a sage and wise knight would surely shout.\n");

    unsigned char given_checksum = string_checksum(argv[1]);
    if (final_checksum == given_checksum) {
        printf("Input and final checksums match, verily!\n");
    } else {
        printf("Input and final checksums differ, alas, a cautionary tale unfolds.\n");
    }

    return 0;
}