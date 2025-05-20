//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool is_alnum(char c) {
    return (isalpha(c) || isdigit(c) || c == '_');
}

bool is_hex(char c) {
    return (isdigit(c) || (islower(c) && (c >= 'a' && c <= 'f')) || (isupper(c) && (c >= 'A' && c <= 'F')));
}

bool is_valid_hex(const char* str, size_t length) {
    size_t i;
    bool valid = true;

    for (i = 0; i < length; i += 2) {
        if (!is_hex(str[i]) || !is_hex(str[i + 1])) {
            valid = false;
            break;
        }
    }

    return valid;
}

void sanitize_url(const char* url, char* output, size_t output_size) {
    size_t i = 0, j = 0;
    bool in_percent_encoding = false;

    while (url[i] != '\0') {
        if (i + 3 >= strlen(url) && !in_percent_encoding) {
            // No more characters to check for percent encoding, so stop sanitizing
            break;
        }

        if (in_percent_encoding) {
            if (is_hex(url[i + 1]) && is_hex(url[i + 2])) {
                output[j++] = (char) strtol(&url[i], NULL, 16);
                i += 3;
                continue;
            }

            // Invalid hex character, so print a percent sign and the original character
            output[j++] = '%';
            output[j++] = url[i++];
            continue;
        }

        if (url[i] == '%') {
            in_percent_encoding = true;
            continue;
        }

        if (url[i] == ':') {
            // Don't allow colon in the path or query part of the URL
            if (strchr(url, '?') == NULL) {
                fprintf(stderr, "Invalid URL: colon not allowed in the path\n");
                exit(EXIT_FAILURE);
            }

            // Allow colon in the scheme part of the URL
            if (i > 0 && url[i - 1] != '/') {
                output[j++] = url[i];
            }

            i++;
            continue;
        }

        if (url[i] == '/') {
            // Don't allow double slashes in the path part of the URL
            if (i > 0 && url[i - 1] == '/') {
                fprintf(stderr, "Invalid URL: double slash not allowed in the path\n");
                exit(EXIT_FAILURE);
            }

            output[j++] = url[i];
            continue;
        }

        if (!is_alnum(url[i]) && url[i] != '.' && url[i] != '-' && url[i] != '_') {
            if (i > 0 && (is_alnum(url[i - 1]) || url[i - 1] == '.')) {
                output[j++] = url[i];
                continue;
            }
        }

        output[j++] = url[i];
        i++;
    }

    output[j] = '\0';
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    size_t output_size = 1024;
    char output[1024];

    sanitize_url(argv[1], output, output_size);

    printf("Sanitized URL: %s\n", output);

    return EXIT_SUCCESS;
}