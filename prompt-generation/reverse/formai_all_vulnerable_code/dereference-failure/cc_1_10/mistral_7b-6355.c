//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <regex.h>

#define MAX_INPUT_SIZE 1024

bool is_alphanumeric(char c) {
    return (isalnum(c) || c == '_' || c == '-');
}

bool is_valid_char(char c) {
    return is_alphanumeric(c) || strchr("/%:@.", &c) != NULL;
}

bool sanitize_url(const char *input, char *output, size_t output_size) {
    if (input == NULL || output == NULL) {
        return false;
    }

    int i = 0, j = 0;

    while (input[i] && j < output_size - 1) {
        if (is_valid_char(input[i])) {
            output[j++] = input[i];
        }

        i++;
    }

    output[j] = '\0';

    return true;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input> <output>\n", argv[0]);
        return 1;
    }

    char input[MAX_INPUT_SIZE], output[MAX_INPUT_SIZE];
    strcpy(input, argv[1]);
    size_t input_size = strlen(input);

    if (!sanitize_url(input, output, MAX_INPUT_SIZE)) {
        perror("Error sanitizing URL");
        return 1;
    }

    printf("Sanitized URL: %s\n", output);

    return 0;
}