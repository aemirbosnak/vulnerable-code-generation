//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Claude Shannon
/*
 *  Author: Claude Shannon
 *  Version: 1.0
 *  Description: C program to sanitize URLs using a Shannon-style approach.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 256

char* sanitize_url(char* url) {
    int i, j;
    char* sanitized_url = (char*) malloc(MAX_URL_LENGTH * sizeof(char));

    // Remove any whitespace characters from the beginning or end of the URL
    int length = strlen(url);
    while (isspace(url[length - 1])) {
        length--;
    }
    while (*url && isspace(*url)) {
        length--;
        url++;
    }
    strncpy(sanitized_url, url, length);
    sanitized_url[length] = '\0';

    // Replace any occurrences of ' ' with '%20'
    int num_spaces = 0;
    for (i = 0; i < length; i++) {
        if (sanitized_url[i] == ' ') {
            num_spaces++;
        }
    }
    if (num_spaces > 0) {
        int new_length = length + (num_spaces * 2);
        sanitized_url = realloc(sanitized_url, new_length * sizeof(char));
        for (i = length - 1, j = new_length - 1; i >= 0; i--) {
            if (sanitized_url[i] == ' ') {
                sanitized_url[j--] = '0';
                sanitized_url[j--] = '2';
                sanitized_url[j--] = '%';
            } else {
                sanitized_url[j--] = sanitized_url[i];
            }
        }
        sanitized_url[new_length] = '\0';
    }

    // Remove any fragments or query strings from the URL
    char* hash_position = strchr(sanitized_url, '#');
    char* question_mark_position = strchr(sanitized_url, '?');
    int end_position = length;
    if (hash_position != NULL) {
        end_position = hash_position - sanitized_url;
    } else if (question_mark_position != NULL) {
        end_position = question_mark_position - sanitized_url;
    }
    sanitized_url[end_position] = '\0';

    // If the sanitized URL starts with "http://" or "https://", return it
    char* http_position = strstr(sanitized_url, "http://");
    char* https_position = strstr(sanitized_url, "https://");
    char* secure_position = strstr(sanitized_url, "shttp://");
    if (http_position == sanitized_url || https_position == sanitized_url || secure_position == sanitized_url) {
        return sanitized_url;
    } else {
        // Otherwise, add "http://" to the beginning of the sanitized URL and return it
        char* final_sanitized_url = (char*) malloc((strlen(sanitized_url) + 8) * sizeof(char));
        strncpy(final_sanitized_url, "http://", 7);
        strncat(final_sanitized_url, sanitized_url, strlen(sanitized_url));
        final_sanitized_url[strlen(sanitized_url) + 7] = '\0';
        free(sanitized_url);
        return final_sanitized_url;
    }
}

int main(int argc, char** argv) {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    char* sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}