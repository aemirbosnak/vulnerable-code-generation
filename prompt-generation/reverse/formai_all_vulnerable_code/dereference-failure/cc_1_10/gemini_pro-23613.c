//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Function to encode a URL
char *encode_url(char *url) {
    char *encoded_url = curl_easy_escape(NULL, url, 0);
    if (encoded_url == NULL) {
        fprintf(stderr, "Error: could not encode URL\n");
        exit(EXIT_FAILURE);
    }
    return encoded_url;
}

// Function to decode a URL
char *decode_url(char *url) {
    char *decoded_url = curl_easy_unescape(NULL, url, 0, NULL);
    if (decoded_url == NULL) {
        fprintf(stderr, "Error: could not decode URL\n");
        exit(EXIT_FAILURE);
    }
    return decoded_url;
}

// Function to print the usage of the program
void print_usage() {
    printf("Usage: url_sanitizer [encode|decode] [URL]\n");
    printf("Example:\n");
    printf("    url_sanitizer encode https://www.example.com/test\n");
    printf("    url_sanitizer decode https%3A%2F%2Fwww.example.com%2Ftest\n");
}

int main(int argc, char **argv) {
    if (argc < 3) {
        print_usage();
        exit(EXIT_FAILURE);
    }

    char *operation = argv[1];
    char *url = argv[2];

    if (strcmp(operation, "encode") == 0) {
        char *encoded_url = encode_url(url);
        printf("Encoded URL: %s\n", encoded_url);
        free(encoded_url);
    } else if (strcmp(operation, "decode") == 0) {
        char *decoded_url = decode_url(url);
        printf("Decoded URL: %s\n", decoded_url);
        free(decoded_url);
    } else {
        print_usage();
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}