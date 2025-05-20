//Gemma-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Morse_CODE_LENGTH 20

typedef struct MorseCodeEntry {
    char character;
    char* code;
} MorseCodeEntry;

MorseCodeEntry* createMorseCodeEntry(char character, char* code) {
    MorseCodeEntry* entry = malloc(sizeof(MorseCodeEntry));
    entry->character = character;
    entry->code = strdup(code);
    return entry;
}

void printMorseCode(MorseCodeEntry* entry) {
    printf("%c: ", entry->character);
    printf("%s\n", entry->code);
}

int main() {
    MorseCodeEntry* entries = createMorseCodeEntry('a', ".-");
    entries = createMorseCodeEntry('b', "-...");
    entries = createMorseCodeEntry('c', "-.-.");
    entries = createMorseCodeEntry('d', "-..");
    entries = createMorseCodeEntry('e', ".");
    entries = createMorseCodeEntry('f', "..-.");
    entries = createMorseCodeEntry('g', "--.");
    entries = createMorseCodeEntry('h', "....");
    entries = createMorseCodeEntry('i', "..");
    entries = createMorseCodeEntry('j', ".---");
    entries = createMorseCodeEntry('k', "-.-");
    entries = createMorseCodeEntry('l', ".-..");
    entries = createMorseCodeEntry('m', "--");
    entries = createMorseCodeEntry('n', "-.");
    entries = createMorseCodeEntry('o', "---");
    entries = createMorseCodeEntry('p', ".--.");
    entries = createMorseCodeEntry('q', "--.-");
    entries = createMorseCodeEntry('r', ".-");
    entries = createMorseCodeEntry('s', "...");
    entries = createMorseCodeEntry('t', "-");
    entries = createMorseCodeEntry('u', "..-");
    entries = createMorseCodeEntry('v', "...-");
    entries = createMorseCodeEntry('w', ".--");
    entries = createMorseCodeEntry('x', "-..--");
    entries = createMorseCodeEntry('y', "--..");
    entries = createMorseCodeEntry('z', "---.");

    printMorseCode(entries);

    return 0;
}