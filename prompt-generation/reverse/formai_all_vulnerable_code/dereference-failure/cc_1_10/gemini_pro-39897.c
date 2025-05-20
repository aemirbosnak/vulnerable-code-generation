//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prepare your vocal cords for some hysterical text manipulation!

// Our cast of hilarious characters
char *words[] = {
    "bananas", "monkeys", "unicorns", "elves", "zombies",
    "ninjas", "pirates", "dragons", "fairies", "aliens"
};

// Get ready for some chaotic word transformations!
char *transform(char *word) {
    static char buffer[100] = {0};
    int i, len;
    
    len = strlen(word);

    // Chuckle-worthy character replacements
    for (i = 0; i < len; i++) {
        switch (word[i]) {
            case 'a':
                buffer[i] = 'e';
                break;
            case 'e':
                buffer[i] = 'i';
                break;
            case 'i':
                buffer[i] = 'o';
                break;
            case 'o':
                buffer[i] = 'u';
                break;
            case 'u':
                buffer[i] = 'a';
                break;
            default:
                buffer[i] = word[i];
                break;
        }
    }

    return buffer;
}

// Brace yourself for an uproarious word scramble!
char *scramble(char *word) {
    static char buffer[100] = {0};
    int i, len;
    char temp;

    len = strlen(word);

    // Prepare for a whirlwind of character swaps
    for (i = 0; i < len; i++) {
        if (i % 2 == 0) {
            temp = word[i];
            word[i] = word[i+1];
            word[i+1] = temp;
        }
    }

    strcpy(buffer, word);
    return buffer;
}

// Get ready for a rib-tickling word concatenation frenzy!
char *concatenate(char *word1, char *word2) {
    static char buffer[200] = {0};
    int len1, len2;

    len1 = strlen(word1);
    len2 = strlen(word2);

    // Brace yourself for some outrageous word combos
    strcpy(buffer, word1);
    buffer[len1] = ' ';
    strcat(buffer, word2);

    return buffer;
}

// Time for a side-splitting word generator extravaganza!
void generate_words() {
    char *transformed, *scrambled, *concatenated;
    int i, j, len;

    len = sizeof(words) / sizeof(char*);

    // Prepare for a word-bending roller coaster!
    for (i = 0; i < len; i++) {
        printf("Original word: %s\n", words[i]);
        transformed = transform(words[i]);
        printf("Transformed word: %s\n", transformed);
        scrambled = scramble(words[i]);
        printf("Scrambled word: %s\n", scrambled);
        for (j = i+1; j < len; j++) {
            concatenated = concatenate(words[i], words[j]);
            printf("Concatenated word: %s\n", concatenated);
        }
        printf("\n");
    }
}

// Buckle up for a text-mangling extravaganza!
int main() {
    // Set the stage for laughter-inducing text gymnastics
    printf("Prepare yourself for a text-mangling extravaganza!\n\n");
    generate_words();

    // Leave 'em rolling on the floor with laughter
    printf("And there you have it, folks! Text processing at its most side-splittingly ridiculous!\n");

    return 0;
}