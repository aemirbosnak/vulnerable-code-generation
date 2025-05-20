//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 10000

char* sanitize_url(char* url) {
    char* sanitized_url = malloc(sizeof(char) * MAX_LENGTH);
    int i, j;

    for(i = 0, j = 0; i < strlen(url); i++, j++) {
        if(url[i] == ' ') {
            sanitized_url[j++] = '%';
            sanitized_url[j++] = '2';
            sanitized_url[j] = '0';
        }
        else if(url[i] == '/') {
            sanitized_url[j++] = '%';
            sanitized_url[j] = '2';
            sanitized_url[j+1] = 'F';
        }
        else if(url[i] == ':') {
            sanitized_url[j++] = '%';
            sanitized_url[j] = '3';
            sanitized_url[j+1] = 'A';
        }
        else if(url[i] == '?') {
            sanitized_url[j++] = '%';
            sanitized_url[j] = '3';
            sanitized_url[j+1] = 'F';
        }
        else if(url[i] == '=') {
            sanitized_url[j++] = '%';
            sanitized_url[j] = '3';
            sanitized_url[j+1] = 'D';
        }
        else if(url[i] == '&') {
            sanitized_url[j++] = '%';
            sanitized_url[j] = '2';
            sanitized_url[j+1] = '6';
        }
        else {
            sanitized_url[j] = url[i];
        }
    }
    sanitized_url[j] = '\0';
    return sanitized_url;
}

int main(void) {
    char url[MAX_LENGTH];
    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_LENGTH, stdin);
    url[strcspn(url, "\n")] = '\0';
    char* sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}