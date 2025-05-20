//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 1024

void print_usage() {
    printf("Usage: sanitize_url <input_url>\n");
    printf("This program sanitizes an input URL by removing any potential malicious characters.\n");
    printf("Created with a smile!\n");
    exit(1);
}

bool is_alnum(char c) {
    return (isalpha(c) || isdigit(c) || c == '_' || c == '-');
}

bool is_hex(char c) {
    return (isdigit(c) || (isalpha(c) && (tolower(c) >= 'a' && tolower(c) <= 'f')));
}

void sanitize_percent_encoding(char *output, const char *input, int length) {
    int i, j;
    for (i = 0; i < length; i++) {
        if (input[i] == '%') {
            if (i + 2 < length) {
                if (is_hex(input[i + 1]) && is_hex(input[i + 2])) {
                    output[i] = (char)strtoul(&input[i + 1], NULL, 16);
                    i += 2;
                } else {
                    print_usage();
                }
            } else {
                print_usage();
            }
        } else {
            output[i] = input[i];
        }
    }
    output[length] = '\0';
}

int main(int argc, char *argv[]) {
    char input_url[MAX_LENGTH];
    char output_url[MAX_LENGTH];

    if (argc != 2) {
        print_usage();
    }

    strcpy(input_url, argv[1]);

    int length = strlen(input_url);

    // Sanitize %-encoding
    sanitize_percent_encoding(output_url, input_url, length);

    // Sanitize special characters
    int i;
    for (i = 0; i < length; i++) {
        if (!isalnum(output_url[i]) && output_url[i] != '.' && output_url[i] != '/') {
            if (output_url[i] == '+' && (i < length - 1 && isalnum(output_url[i + 1]))) {
                output_url[i] = ' ';
                output_url[i + 1] = output_url[i + 1];
                i++;
            } else {
                output_url[i] = '_';
            }
        }
    }

    printf("Sanitized URL: %s\n", output_url);

    return 0;
}