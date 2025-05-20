//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 1024

bool is_alnum(char c) {
    return (isalpha(c) || isdigit(c) || c == '_');
}

bool is_hex(char c) {
    return (isdigit(c) || (isalpha(c) && (tolower(c) >= 'a' && tolower(c) <= 'f')));
}

bool is_valid_char(char c) {
    return is_alnum(c) || is_hex(c) || c == ':' || c == '/' || c == '?' || c == '&' || c == '#' || c == '=' || c == '$-_~+.';
}

void sanitize_string(char *str) {
    int len = strlen(str);
    int i = 0;

    while (i < len) {
        if (!is_valid_char(str[i])) {
            for (int j = i; j < len; j++) {
                str[j] = str[j + 1];
            }
            len--;
            i--;
        }
        i++;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <URL to sanitize>\n", argv[0]);
        return 1;
    }

    char url[MAX_LEN];
    strcpy(url, argv[1]);

    sanitize_string(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}

// Enthusiastically yours,
// The C URL Sanitizer Team 🤩