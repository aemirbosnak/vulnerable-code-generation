//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define ESCAPE_CHAR '%'

char hex_to_char(const char *hex) {
    return (char) strtol(hex, NULL, 16);
}

void encode_char(char ch, char *result, int *pos) {
    sprintf(&result[*pos], "%%%02X", (unsigned char) ch);
    *pos += 3; // Increase position by 3 for '%XX'
}

void sanitize_url(const char *url, char *sanitized_url) {
    int pos = 0;

    for (int i = 0; url[i] != '\0' && pos < MAX_URL_LENGTH - 1; i++) {
        char ch = url[i];

        // Allow safe characters
        if (isalnum(ch) || strchr("-._~", ch) != NULL) {
            sanitized_url[pos++] = ch;
        } else if (ch == ' ') {
            // Replace spaces with '%20'
            strcpy(&sanitized_url[pos], "%20");
            pos += 3; // Increase position by 3 for '%20'
        } else {
            // Encode other characters
            encode_char(ch, sanitized_url, &pos);
        }
    }
    sanitized_url[pos] = '\0'; // Null-terminate the sanitized URL
}

void print_usage(const char *program_name) {
    printf("Usage: %s <url>\n", program_name);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    char *url = argv[1];
    char sanitized_url[MAX_URL_LENGTH];

    sanitize_url(url, sanitized_url);

    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);

    return EXIT_SUCCESS;
}