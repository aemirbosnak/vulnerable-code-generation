//Gemma-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_CODE_LENGTH 255

typedef struct MorseCodeEntry {
    char character;
    char* code;
} MorseCodeEntry;

MorseCodeEntry* createMorseCodeEntry(char character, char* code) {
    MorseCodeEntry* entry = (MorseCodeEntry*)malloc(sizeof(MorseCodeEntry));
    entry->character = character;
    entry->code = code;
    return entry;
}

void printMorseCode(MorseCodeEntry* entry) {
    printf("%c: ", entry->character);
    for(int i = 0; entry->code[i] != '\0'; i++) {
        switch(entry->code[i]) {
            case '.':
                printf(".- ");
                break;
            case '-':
                printf("-.. ");
                break;
            case '_':
                printf(". ");
                break;
            default:
                break;
        }
    }
    printf("\n");
}

int main() {
    MorseCodeEntry* entries[] = {
        createMorseCodeEntry('a', ".-"),
        createMorseCodeEntry('b', "-"),
        createMorseCodeEntry('c', "-.."),
        createMorseCodeEntry('d', "."),
        createMorseCodeEntry('e', "..")
    };

    for(int i = 0; i < 5; i++) {
        printMorseCode(entries[i]);
    }

    return 0;
}