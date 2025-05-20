//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_URL_LENGTH 1024
#define SCHEME_LENGTH 4
#define PORT_LENGTH 6

// Function to check if a character is a valid URL character
bool is_valid_url_char(char c) {
    if (isalnum(c) || (c == '.' || c == '-' || c == '_' || c == '~' || c == ':' || c == '/')) {
        return true;
    }
    return false;
}

// Function to sanitize a URL
char *sanitize_url(char *url) {
    char *output = malloc(MAX_URL_LENGTH);
    int output_index = 0;
    int input_index = 0;

    // Copy the scheme (http, https, etc.)
    if (strlen(url) >= SCHEME_LENGTH && strncmp(url, "http", SCHEME_LENGTH) == 0) {
        strncpy(output, url, SCHEME_LENGTH);
        output[SCHEME_LENGTH] = ':';
        output[SCHEME_LENGTH + 1] = '/';
        output_index += SCHEME_LENGTH + 2;
        input_index += SCHEME_LENGTH;
    }

    // Copy the hostname
    while (url[input_index] != '/' && url[input_index] != '?') {
        if (is_valid_url_char(url[input_index])) {
            output[output_index++] = url[input_index];
        }
        input_index++;
    }

    // Copy the port number if present
    if (url[input_index] == ':') {
        int port_index = input_index;
        while (isdigit(url[++port_index])) {}
        port_index--;
        strncpy(output + output_index, url + port_index, PORT_LENGTH + 1);
        output_index += PORT_LENGTH + 1;
    }

    // Copy the rest of the URL
    strcpy(output + output_index, url + input_index);

    output[MAX_URL_LENGTH - 1] = '\0';

    return output;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        exit(1);
    }

    char *sanitized_url = sanitize_url(argv[1]);
    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);

    return 0;
}