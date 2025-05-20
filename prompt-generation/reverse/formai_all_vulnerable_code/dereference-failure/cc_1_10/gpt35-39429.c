//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: random
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 100
#define INVALID_URL "INVALID URL"

char* sanitize_url(char* url) {
    char* sanitized_url = (char*) malloc(sizeof(char) * MAX_URL_LENGTH);
    memset(sanitized_url, 0, MAX_URL_LENGTH);

    if (strncmp(url, "http://", 7) != 0 && strncmp(url, "https://", 8) != 0) {
        strcpy(sanitized_url, INVALID_URL);
        return sanitized_url;
    }

    char* temp_url = url + 7;
    int i = 0;

    while (*temp_url != '\0') {
        if (i >= MAX_URL_LENGTH - 1) {
            strcpy(sanitized_url, INVALID_URL);
            return sanitized_url;
        }

        if (isalnum(*temp_url) || *temp_url == '.' || *temp_url == '-' || *temp_url == '_') {
            sanitized_url[i++] = *temp_url;
        } else if (*temp_url == '/') {
            sanitized_url[i++] = '\0';
            break;
        } else {
            strcpy(sanitized_url, INVALID_URL);
            return sanitized_url;
        }

        temp_url++;
    }

    return sanitized_url;
}

void test_case(char* url) {
    char* sanitized_url = sanitize_url(url);

    printf("URL: %s, Sanitized URL: %s\n", url, sanitized_url);

    free(sanitized_url);
}

int main() {
    printf("Starting URL Sanitizer Program...\n");

    test_case("https://www.google.com/search?q=example");
    test_case("http://example.com/path/to/page");
    test_case("ftp://example.com/file.zip");
    test_case("http://example_com");
    test_case("http://example.com///////////////");

    printf("Program Terminated.\n");

    return 0; 
}