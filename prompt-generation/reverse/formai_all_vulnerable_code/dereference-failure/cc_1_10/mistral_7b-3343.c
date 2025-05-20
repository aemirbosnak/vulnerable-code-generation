//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdint.h>

#define MAX_LEN 256

typedef struct {
    bool is_valid;
    char sanitized[MAX_LEN];
} sanitized_url_t;

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

bool is_alphanumeric(char c) {
    return (isalnum(c) || (c == '_' || c == '.' || c == '-'));
}

bool validate_url(const char *url) {
    size_t len = strlen(url);
    if (len > MAX_LEN) return false;

    bool scheme_found = false;
    int i;
    for (i = 0; i < len; i++) {
        if (url[i] == ':') {
            if (i > 0 && url[i - 1] != '/') {
                if (strcmp(&url[i - len], "http") == 0 ||
                    strcmp(&url[i - len], "https") == 0) {
                    scheme_found = true;
                    break;
                }
            }
        }
        if (!scheme_found && !is_alphanumeric(url[i])) {
            return false;
        }
    }

    return true;
}

void sanitize_url(const char *url, sanitized_url_t *sanitized) {
    int i, j;
    size_t len = strlen(url);

    sanitized->is_valid = false;
    for (i = 0, j = 0; i < len && j < MAX_LEN; i++) {
        if (url[i] == '%') {
            if (i + 1 < len && isxdigit(url[i + 1])) {
                int hex = strtoul(&url[i + 1], NULL, 16);
                sanitized->sanitized[j++] = (char)hex;
                i++;
            } else {
                sanitized->is_valid = false;
                return;
            }
        } else if (url[i] == '+') {
            sanitized->sanitized[j++] = ' ';
        } else if (isalnum(url[i]) || url[i] == '.' || url[i] == '-' || url[i] == '_') {
            sanitized->sanitized[j++] = url[i];
        }
    }
    sanitized->sanitized[j] = '\0';
    sanitized->is_valid = true;
}

void print_usage() {
    printf("Usage: %s <URL>\n", "shocked_url_sanitizer");
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    sanitized_url_t sanitized_url;

    if (argc != 2) print_usage();

    if (!validate_url(argv[1])) {
        fprintf(stderr, "Invalid URL: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    sanitize_url(argv[1], &sanitized_url);

    printf("Sanitized URL: %s\n", sanitized_url.sanitized);

    return EXIT_SUCCESS;
}