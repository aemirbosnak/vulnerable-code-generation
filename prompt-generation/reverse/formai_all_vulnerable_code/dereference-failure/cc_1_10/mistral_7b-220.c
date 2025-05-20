//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: Cryptic
#define _CRYPTIC_URL_SANITIZER_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LEN 256
char input[MAX_LEN];
char output[MAX_LEN];
bool is_valid_char(char c);
void sanitize_url();

int main(int argc, char **argv) {
    if (argc > 1) {
        strcpy(input, argv[1]);
        sanitize_url();
        printf("%s\n", output);
    }
    return 0;
}

bool is_valid_char(char c) {
    if (isalnum(c) || (c == '.' || c == '-' || c == '_')) {
        return true;
    }
    return false;
}

void sanitize_url() {
    int i = 0, j = 0;
    for (; input[i] != '\0'; i++) {
        if (is_valid_char(input[i])) {
            output[j++] = input[i];
        }
        if ((input[i] == ' ') || (input[i] == '\t')) {
            continue;
        }
        if ((input[i] == '+') && (i < (sizeof(input) - 1)) && is_valid_char(input[i + 1])) {
            output[j++] = ' ';
            i++;
            continue;
        }
        if (input[i] == '%') {
            if ((i < (sizeof(input) - 3)) &&
                (isxdigit(input[i + 1]) && isxdigit(input[i + 2]))) {
                sscanf(&input[i], "%2x", &i);
                output[j++] = (char)i;
                i += 2;
                continue;
            }
        }
        if (input[i] == '&') {
            if (i > 0 && is_valid_char(input[i - 1])) {
                continue;
            }
            strcpy(&output[j], "&amp;");
            j += 5;
            i++;
            continue;
        }
        if (input[i] == '<') {
            strcpy(&output[j], "&lt;");
            j += 3;
            continue;
        }
        if (input[i] == '>') {
            strcpy(&output[j], "&gt;");
            j += 3;
            continue;
        }
        if (input[i] == '\'') {
            strcpy(&output[j], "&apos;");
            j += 5;
            continue;
        }
        if (input[i] == '\"') {
            strcpy(&output[j], "&quot;");
            j += 5;
            continue;
        }
    }
    output[j] = '\0';
}