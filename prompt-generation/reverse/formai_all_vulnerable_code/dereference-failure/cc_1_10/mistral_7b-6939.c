//MISTRAL-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

#define DOT 0
#define DASH 1
#define SPACE 2
#define LENGTH 3
#define BEEP_TIME 100
#define MIN_BETWEEN_LETTERS 300
#define MIN_BETWEEN_WORDS 700

char morse[26][LENGTH] = {
    ".-", // A
    "-...", // B
    "-.-.", // C
    "-..", // D
    ".", // E
    "..-.", // F
    "--.", // G
    "....", // H
    "..", // I
    ".---", // J
    "-.-", // K
    ".-..", // L
    "--", // M
    "-.", // N
    "---", // O
    ".--.", // P
    "--.-", // Q
    ".-.", // R
    "...", // S
    "-", // T
    "..-", // U
    "...-", // V
    ".--", // W
    "-..-", // X
    "--..", // Y
    "-----", // Z
};

void beep(int length) {
    write(1, "\007", 1);
    usleep(length);
}

void signal(char signal[]) {
    int i;
    for (i = 0; i < LENGTH; i++) {
        switch (signal[i]) {
            case DOT:
                beep(BEEP_TIME);
                usleep(BEEP_TIME);
                break;
            case DASH:
                beep(BEEP_TIME * 3);
                usleep(BEEP_TIME);
                break;
            case SPACE:
                usleep(MIN_BETWEEN_LETTERS);
                break;
        }
    }
    usleep(MIN_BETWEEN_WORDS);
}

void print_morse(char text[]) {
    int i, j;
    char *token;
    char *tokens[128];
    char *saveptr;

    strtok_r(text, " ", &saveptr);
    i = 0;
    while (saveptr != NULL) {
        tokens[i++] = strtok_r(NULL, " ", &saveptr);
    }

    for (j = 0; j < i; j++) {
        printf("%s: ", tokens[j]);
        signal(morse[*tokens[j] - 'A']);
    }
}

int main(int argc, char **argv) {
    char text[128];

    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    strcpy(text, argv[1]);
    print_morse(text);

    return EXIT_SUCCESS;
}