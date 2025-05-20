//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * @brief           Function to sanitize a given URL
 * @param  url      The original URL
 * @param  len      Length of the original URL
 * @return          The sanitized URL
 */
char *sanitize_url(char *url, size_t len) {
    char *sanitized_url = malloc(len * sizeof(char)); // allocate memory for the new string
    int index = 0; // index of the current character in the sanitized string
    int domain_started = 0; // flag to indicate if we have started reading the domain name
    int after_slash = 0; // flag to indicate if we are currently reading the path
    int double_slash = 0; // flag to indicate if we have encountered a double slash in the URL
    for (int i = 0; i < len; i++) {
        char c = url[i];
        if (isspace(c)) {
            continue;
        }
        if (!domain_started) {
            if (c == '/' && i > 0 && url[i-1] == '/') {
                double_slash = 1;
            }
            if (c == '/' || i == len-1) {
                if (double_slash) {
                    sanitized_url[index++] = '/';
                }
                if (i == len-1) {
                    sanitized_url[index++] = c;
                }
                domain_started = 1;
            } else {
                sanitized_url[index++] = tolower(c);
            }
        } else {
            if (after_slash || (c != ':' && c != '?' && c != '#')) {
                sanitized_url[index++] = c;
                if (c == '/') {
                    after_slash = 1;
                }
            }
        }
    }
    sanitized_url[index] = '\0'; // null terminate the string
    return sanitized_url;
}

int main() {
    char url[] = "       hTTps://   WwW.ExaMplE.cOM///Path/to/ResoUrCe//?qUeRy=string#ifragment   ";
    size_t len = strlen(url);
    char *sanitized_url = sanitize_url(url, len);
    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}