//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char text;
    char morse;
} MorseTable;

void initMorseTable(MorseTable* table) {
    table->text = 'A';
    table->morse = ".-";
    table++;

    table->text = 'B';
    table->morse = "-...";
    table++;

    table->text = 'C';
    table->morse = "-.-.";
    table++;

    // Add more entries to the table...
}

char* textToMorse(const char* text) {
    MorseTable table[26];
    initMorseTable(table);

    char* morse = malloc(strlen(text) * 2 + 1);
    char* ptr = morse;

    for (const char* p = text; *p; p++) {
        if (isalpha(*p)) {
            for (MorseTable* t = table; t->text; t++) {
                if (t->text == tolower(*p)) {
                    strncat(morse, t->morse, strlen(t->morse));
                    break;
                }
            }
        } else {
            strncat(morse, " ", 1);
        }

        ptr += strlen(morse);
    }

    *ptr = '\0';

    return morse;
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    char* morse = textToMorse(argv[1]);
    printf("%s\n", morse);

    free(morse);
    return 0;
}