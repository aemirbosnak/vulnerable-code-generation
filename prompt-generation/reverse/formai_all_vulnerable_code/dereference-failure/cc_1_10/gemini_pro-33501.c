//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A shape-shifting sorcerer to cast spells of Morse code
typedef struct {
    char letter;
    char* morse;
} Spell;

// An array of spells for our sorcerer
Spell spells[] = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."},
    {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"},
    {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"},
    {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
    {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"},
    {'Z', "--.."}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"},
    {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."},
    {'8', "---.."}, {'9', "----."}, {'0', "-----"}, {' ', " "},
};

// A function to summon the sorcerer's spellbook
Spell* find_spell(char letter) {
    for (int i = 0; i < 36; i++) {
        if (spells[i].letter == letter) {
            return &spells[i];
        }
    }
    return NULL;
}

// A function to cast a spell and transform text into Morse code
char* cast_spell(char* text) {
    int text_length = strlen(text);
    char* morse_code = malloc(text_length * 5); // Allocate enough space for the transformed code
    int morse_index = 0;
    for (int i = 0; i < text_length; i++) {
        Spell* spell = find_spell(text[i]);
        if (spell) {
            strcat(morse_code, spell->morse);
            morse_index += strlen(spell->morse);
        }
    }
    return morse_code;
}

int main() {
    char text[] = "Hello World!";
    char* morse_code = cast_spell(text);
    printf("Original Text: %s\n", text);
    printf("Morse Code: %s\n", morse_code);
    free(morse_code);
    return 0;
}