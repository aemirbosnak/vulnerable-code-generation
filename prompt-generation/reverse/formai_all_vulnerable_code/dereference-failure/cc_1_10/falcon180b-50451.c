//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_TOKENS 1000

char *tokens[MAX_TOKENS];
int num_tokens = 0;

void tokenize(char *str) {
    char *token;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            token = (char*)malloc(sizeof(char) * (i + 1));
            strncpy(token, str, i);
            token[i] = '\0';
            tokens[num_tokens++] = token;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    char ch;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            char str[100];
            str[0] = ch;
            str[1] = '\0';
            tokenize(str);
        }
    }

    fclose(file);

    printf("Word count:\n");
    for (int i = 0; i < num_tokens; i++) {
        printf("%s %d\n", tokens[i], i + 1);
    }

    return 0;
}