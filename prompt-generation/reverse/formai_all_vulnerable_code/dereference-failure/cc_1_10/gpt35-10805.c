//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to sanitize the given URL
char *sanitize_URL(char *url) {
    int len = strlen(url);
    char *sanitized_url = (char*) malloc(len+1);
    int j = 0;

    for(int i=0; i<len; i++) {
        if(url[i] == ' ' || url[i] == '\t') {
            sanitized_url[j++] = '+';
        }
        else if(url[i] == '\"') {
            sanitized_url[j++] = '%';
            sanitized_url[j++] = '2';
            sanitized_url[j++] = '2';
        }
        else if(url[i] == '<') {
            sanitized_url[j++] = '%';
            sanitized_url[j++] = '3';
            sanitized_url[j++] = 'C';
        }
        else if(url[i] == '>') {
            sanitized_url[j++] = '%';
            sanitized_url[j++] = '3';
            sanitized_url[j++] = 'E';
        }
        else if(url[i] == '#') {
            sanitized_url[j++] = '%';
            sanitized_url[j++] = '2';
            sanitized_url[j++] = '3';
        }
        else if((url[i] >= 'A' && url[i] <= 'Z') ||
                (url[i] >= 'a' && url[i] <= 'z') ||
                (url[i] >= '0' && url[i] <= '9') ||
                (url[i] == '-') || (url[i] == '.') ||
                (url[i] == '_') || (url[i] == '~') ||
                (url[i] == '/')) {
            sanitized_url[j++] = url[i];
        }
        else {
            sanitized_url[j++] = '%';
            sanitized_url[j++] = '2';
            sanitized_url[j++] = '5';
        }
    }

    sanitized_url[j] = '\0';

    return sanitized_url;
}

// Main function
int main() {
    char url[1000];
    printf("Enter the URL to be sanitized: ");
    fgets(url, 1000, stdin);
    url[strcspn(url, "\n")] = 0; // Removing the new line at the end of the input

    char *sanitized_url = sanitize_URL(url);
    printf("The sanitized URL is: %s\n", sanitized_url);

    free(sanitized_url);

    return 0;
}