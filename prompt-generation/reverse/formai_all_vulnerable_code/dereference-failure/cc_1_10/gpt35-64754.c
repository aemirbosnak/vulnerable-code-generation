//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// function to sanitize URL
char* sanitizeURL(const char *url) {

    char *sanitized_url = NULL;
    int i, j = 0;

    // allocate memory for sanitized_url
    sanitized_url = (char*) malloc(strlen(url) + 1);
    if(sanitized_url == NULL) {
        printf("Error: out of memory\n");
        exit(1);
    }

    // copy characters from url to sanitized_url
    for(i = 0; url[i] != '\0'; i++) {

        // convert all characters to lowercase
        sanitized_url[j] = tolower(url[i]);

        // if the character is a space, replace it with '%20'
        if(sanitized_url[j] == ' ') {
            sanitized_url[j] = '%';
            sanitized_url[j+1] = '2';
            sanitized_url[j+2] = '0';
            j += 2;
        }
        j++;
    }

    // terminate sanitized_url with null character
    sanitized_url[j] = '\0';
    return sanitized_url;
}

int main() {

    char url[1000], *sanitized_url;

    // get input URL from user
    printf("Enter URL: ");
    fgets(url, sizeof(url), stdin);

    // remove newline character from url, if any
    url[strcspn(url, "\n")] = 0;

    // sanitize url
    sanitized_url = sanitizeURL(url);

    // print sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    // free memory allocated for sanitized_url
    free(sanitized_url);

    return 0;
}