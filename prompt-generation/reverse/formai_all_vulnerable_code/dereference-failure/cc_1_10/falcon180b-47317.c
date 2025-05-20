//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: surrealist
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if character is a valid URL character
int isValidUrlChar(char c) {
    if (isalpha(c) || isdigit(c) || c == '-' || c == '.' || c == '_' || c == '~' || c == '%') {
        return 1;
    } else {
        return 0;
    }
}

// Function to sanitize a URL
char* sanitizeUrl(char* url) {
    int i = 0;
    char* sanitizedUrl = malloc(strlen(url) + 1);
    while (url[i]) {
        if (isValidUrlChar(url[i])) {
            sanitizedUrl[i] = url[i];
        } else {
            sanitizedUrl[i] = '%';
            i++;
            int hex = 0;
            while (1) {
                if (isxdigit(url[i])) {
                    sanitizedUrl[i] = url[i];
                    hex = 1;
                    break;
                } else if (url[i] == '%') {
                    i++;
                    if (isxdigit(url[i])) {
                        sanitizedUrl[i - 1] = url[i];
                        hex = 1;
                        break;
                    }
                } else {
                    i++;
                }
            }
        }
        i++;
    }
    sanitizedUrl[i] = '\0';
    return sanitizedUrl;
}

int main() {
    char* url = "https://www.example.com/path/to/page?query=string&another=query#fragment";
    char* sanitizedUrl = sanitizeUrl(url);
    printf("Sanitized URL: %s\n", sanitizedUrl);
    free(sanitizedUrl);
    return 0;
}