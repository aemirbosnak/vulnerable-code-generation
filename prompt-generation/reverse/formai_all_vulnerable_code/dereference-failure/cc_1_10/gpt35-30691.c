//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DOT '.'
#define DASH '-'
#define SPACE '/'

char* letters[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
    "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
    "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
    "-.--", "--.."
};

char* numbers[] = {
    "-----", ".----", "..---", "...--", "....-", ".....",
    "-....", "--...", "---..", "----."
};

char* morse(int c) {
    int i;
    if (c >= 'a' && c <= 'z') {
        i = c - 'a';
        return letters[i];
    } else if (c >= 'A' && c <= 'Z') {
        i = c - 'A';
        return letters[i];
    } else if (c >= '0' && c <= '9') {
        i = c - '0';
        return numbers[i];
    } else if (c == ' ') {
        return SPACE;
    } else {
        return "";
    }
}

void encode(char* text) {
    char* p = text;
    while (*p != '\0') {
        char* m = morse(*p);
        printf("%s ", m);
        p++;
    }
    printf("\n");
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <text>\n", argv[0]);
        exit(1);
    }
    encode(argv[1]);
    return 0;
}