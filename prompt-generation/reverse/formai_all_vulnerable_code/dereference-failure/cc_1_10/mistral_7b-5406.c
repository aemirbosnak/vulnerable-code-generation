//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: Alan Turing
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LEN 256

typedef struct {
    char str[MAX_LEN];
    int len;
} String;

void sanitize(String *str) {
    int i, j;
    bool valid = true;

    for (i = 0; str->str[i] && valid; i++) {
        if (isalnum(str->str[i]) || str->str[i] == '.' || str->str[i] == '/') {
            str->str[i] = (char)tolower(str->str[i]);
        } else {
            valid = false;
        }

        for (j = i + 1; j < str->len && valid; j++) {
            if (str->str[i] == str->str[j] && str->str[i] != '/') {
                valid = false;
                str->str[j] = '\0';
                str->len = j;
                break;
            }
        }

        if (!valid) {
            str->len = i;
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    String input;
    int i;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    strncpy(input.str, argv[1], MAX_LEN);
    input.len = strlen(argv[1]);

    sanitize(&input);

    printf("Sanitized URL: %s\n", input.str);

    for (i = 0; i < input.len; i++) {
        if (input.str[i] == '/') {
            printf("/");
        } else {
            printf("%c", input.str[i]);
        }
    }

    return 0;
}