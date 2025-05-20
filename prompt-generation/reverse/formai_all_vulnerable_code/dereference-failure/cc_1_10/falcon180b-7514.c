//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LEN 1000
#define CODE_LEN 5
#define CODE_SEP " "
#define CODE_SEP_LEN strlen(CODE_SEP)

struct code {
    char *text;
    char *morse;
};

struct code codes[] = {
    {"A", ".-"},
    {"B", "-..."},
    {"C", "-.-."},
    {"D", "-.."},
    {"E", "."},
    {"F", "..-."},
    {"G", "--."},
    {"H", "...."},
    {"I", ".."},
    {"J", ".---"},
    {"K", "-.-"},
    {"L", ".-.."},
    {"M", "--"},
    {"N", "-."},
    {"O", "---"},
    {"P", ".--."},
    {"Q", "--.-"},
    {"R", ".-."},
    {"S", "..."},
    {"T", "-"},
    {"U", "..-"},
    {"V", "...-"},
    {"W", ".--"},
    {"X", "-..-"},
    {"Y", "-.--"},
    {"Z", "--.."},
    {"1", ".----"},
    {"2", "..---"},
    {"3", "...--"},
    {"4", "....-"},
    {"5", "....."},
    {"6", "-...."},
    {"7", "--..."},
    {"8", "---.."},
    {"9", "----."},
    {"0", "-----"}
};

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    char *text = argv[1];
    int len = strlen(text);
    char *morse = malloc(len * CODE_SEP_LEN + 1);
    char *ptr = morse;

    for (int i = 0; i < len; i++) {
        char ch = toupper(text[i]);
        for (int j = 0; j < CODE_LEN; j++) {
            if (codes[j].text[0] == ch) {
                strcpy(ptr, codes[j].morse);
                break;
            }
        }
        ptr += strlen(ptr);
        if (i < len - 1) {
            strcpy(ptr, CODE_SEP);
            ptr += CODE_SEP_LEN;
        }
    }

    printf("%s\n", morse);

    return 0;
}