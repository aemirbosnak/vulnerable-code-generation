//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_char(char c) {
    if (isalnum(c) || c == '.' || c == '-' || c == '_' || c == '~' || c == '/') {
        return 1;
    }
    return 0;
}

void sanitize_url(char* url) {
    // Remove leading/trailing whitespace
    char* start = url;
    char* end = url + strlen(url) - 1;
    while (isspace(*start)) {
        start++;
    }
    while (isspace(*end)) {
        end--;
    }
    *end = '\0';

    // Remove invalid characters
    char* sanitized_url = malloc(MAX_URL_LENGTH);
    char* curr_pos = sanitized_url;
    int curr_pos_len = 0;
    for (char* pos = start; pos <= end; pos++) {
        if (is_valid_url_char(*pos)) {
            curr_pos[curr_pos_len++] = *pos;
        }
    }
    curr_pos[curr_pos_len] = '\0';

    // Replace invalid characters with %XX
    char* hex_buffer = malloc(3 * MAX_URL_LENGTH);
    char* hex_pos = hex_buffer;
    for (char* pos = curr_pos; *pos; pos++) {
        if (!is_valid_url_char(*pos)) {
            sprintf(hex_pos, "%%%02X", *pos);
            hex_pos += 3;
        } else {
            *hex_pos++ = *pos;
        }
    }
    *hex_pos = '\0';

    strcpy(url, curr_pos);
    free(curr_pos);
    free(hex_buffer);
}

int main() {
    char input_url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    fgets(input_url, MAX_URL_LENGTH, stdin);

    sanitize_url(input_url);

    printf("Sanitized URL: %s\n", input_url);

    return 0;
}