//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

/* Function prototypes */
void sanitize_url(char *url);
void remove_trailing_slash(char *url);
void remove_duplicate_slash(char *url);
void replace_spaces(char *url);

/* Main function */
int main() {
    char url[MAX_LENGTH];
    
    /* Get user input */
    printf("Enter a URL: ");
    fgets(url, MAX_LENGTH, stdin);

    /* Sanitize the URL */
    sanitize_url(url);

    /* Display the sanitized URL */
    printf("Sanitized URL: %s\n", url);

    return 0;
}

/* Function to sanitize the URL */
void sanitize_url(char *url) {
    remove_trailing_slash(url);
    remove_duplicate_slash(url);
    replace_spaces(url);
}

/* Function to remove trailing slash */
void remove_trailing_slash(char *url) {
    int len = strlen(url);

    /* Check if the last character is a slash */
    if(url[len-1] == '/') {
        url[len-1] = '\0';  /* Remove the slash */
    }
}

/* Function to remove duplicate slashes */
void remove_duplicate_slash(char *url) {
    int len = strlen(url);
    int i, j;

    /* Loop through the URL and remove duplicate slashes */
    for(i = 0, j = 0; i < len; i++) {
        if(url[i] == '/' && url[i+1] == '/') {
            continue;
        }
        url[j++] = url[i];
    }
    url[j] = '\0';
}

/* Function to replace spaces with %20 */
void replace_spaces(char *url) {
    int len = strlen(url);
    int i, j;

    /* Loop through the URL and replace the spaces */
    for(i = 0, j = 0; i < len; i++) {
        if(url[i] == ' ') {
            url[j++] = '%';
            url[j++] = '2';
            url[j++] = '0';
        }
        else {
            url[j++] = url[i];
        }
    }
    url[j] = '\0';
}