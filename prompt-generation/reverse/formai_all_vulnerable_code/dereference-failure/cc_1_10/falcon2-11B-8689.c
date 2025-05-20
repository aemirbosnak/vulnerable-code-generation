//Falcon2-11B DATASET v1.0 Category: URL Sanitizer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 1024

void sanitize_url(char* url) {
    int i, j;
    int valid_chars = 0;
    char* sanitized_url = (char*)malloc(MAX_URL_LENGTH * sizeof(char));

    for (i = 0; i < strlen(url); i++) {
        if (url[i] >= 'A' && url[i] <= 'Z') {
            valid_chars = 1;
            sanitized_url[i] = url[i];
        } else if (url[i] >= 'a' && url[i] <= 'z') {
            valid_chars = 1;
            sanitized_url[i] = url[i];
        } else if (url[i] >= '0' && url[i] <= '9') {
            valid_chars = 1;
            sanitized_url[i] = url[i];
        } else if (url[i] == '-' || url[i] == '_' || url[i] == '.') {
            valid_chars = 1;
            sanitized_url[i] = url[i];
        } else {
            valid_chars = 0;
            break;
        }
    }

    if (valid_chars == 1) {
        printf("Sanitized URL: %s\n", sanitized_url);
    } else {
        printf("Invalid URL\n");
    }

    free(sanitized_url);
}

int main() {
    char url[MAX_URL_LENGTH];

    printf("Enter a URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    url[strcspn(url, "\n")] = '\0';

    sanitize_url(url);

    return 0;
}