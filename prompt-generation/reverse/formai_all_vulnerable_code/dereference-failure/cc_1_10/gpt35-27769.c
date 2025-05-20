//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_URL_LENGTH 100

char* sanitize_url(char* url) {
    char* sanitized_url = (char*) malloc(MAX_URL_LENGTH * sizeof(char));
    int i, j;
    int length = strlen(url);
    for(i=0, j=0; i<length && j<MAX_URL_LENGTH; i++) {
        if(url[i] == '<' || url[i] == '>') {
            sanitized_url[j] = '_';
            j++;
        }
        else if(url[i] == '\"' || url[i] == '\'') {
            sanitized_url[j] = '-';
            j++;
        }
        else if(url[i] == '(' || url[i] == ')') {
            sanitized_url[j] = '[';
            sanitized_url[j+1] = url[i];
            sanitized_url[j+2] = ']';
            j+=3;
        }
        else if(url[i] == '\t' || url[i] == '\n' || url[i] == '\r') {
            sanitized_url[j] = '_';
            j++;
        }
        else if((int) url[i] < 32 || (int) url[i] > 126) {
            sanitized_url[j] = '_';
            j++;
        }
        else {
            sanitized_url[j] = url[i];
            j++;
        }
    }
    sanitized_url[j] = '\0';
    return sanitized_url;
}

int main() {
    char url[MAX_URL_LENGTH] = "https://example.com?name=<script>alert('You have been hacked!')</script>";
    char* sanitized_url;

    sanitized_url = sanitize_url(url);

    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);
    return 0;
}