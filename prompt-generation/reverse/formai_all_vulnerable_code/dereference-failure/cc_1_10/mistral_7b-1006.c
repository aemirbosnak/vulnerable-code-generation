//MISTRAL-7B DATASET v1.0 Category: Cat Language Translator ; Style: genius
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_LEN 1000

typedef struct Cat {
    char name[20];
    int age;
    char color[10];
} Cat;

void meow(int volume) {
    printf("%s\n", (volume > 5) ? "MEOWWWW" : "MEOW");
}

void translate(char *input) {
    char output[MAX_LEN];
    int i = 0, j = 0, k;

    while (input[i] != '\0') {
        if (isalpha(input[i])) {
            switch (input[i]) {
                case 'A':
                    strcat(output, "Miaow");
                    break;
                case 'E':
                    strcat(output, "Purr");
                    break;
                case 'I':
                    strcat(output, "Meow");
                    break;
                case 'O':
                    strcat(output, "Hiss");
                    break;
                case 'U':
                    strcat(output, "Roar");
                    break;
                default:
                    strcat(output, &input[i]);
            }
            i++;
        } else if (input[i] == ' ') {
            strcat(output, " ");
            i++;
        } else if (input[i] == '(') {
            i++; // consume '('
            while (input[i] != ')') {
                if (isdigit(input[i])) {
                    int num = 0;
                    while (isdigit(input[i])) {
                        num = num * 10 + (input[i] - '0');
                        i++;
                    }
                    meow(num);
                } else {
                    i++;
                }
            }
            i++; // consume ')'
        } else {
            strcat(output, &input[i]);
            i++;
        }
    }

    printf("%s\n", output);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <Cat Language Input>\n", argv[0]);
        return 1;
    }

    translate(argv[1]);

    return 0;
}