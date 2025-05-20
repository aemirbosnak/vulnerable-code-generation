//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: genious
#include<stdio.h>
#include<string.h>

// Function to sanitize the URL
char* sanitizeURL(char* url) {
    char* sanitized_url = url;
    int len = strlen(url);
    int i = 0;

    // Removing leading and trailing spaces
    while(sanitized_url[0] == ' ')
        sanitized_url++;

    while(sanitized_url[len-1] == ' ')
        sanitized_url[--len] = 0;

    // Checking for forbidden characters
    for(i = 0; i < len; i++) {
        if(sanitized_url[i] == '<' || sanitized_url[i] == '>' || sanitized_url[i] == '\"' ||
            sanitized_url[i] == '\'' || sanitized_url[i] == '|' || sanitized_url[i] == '&')
            return NULL;
    }

    // Removing any protocols from the url
    if(strstr(sanitized_url, "http://") == sanitized_url)
        sanitized_url += 7;
    else if(strstr(sanitized_url, "https://") == sanitized_url)
        sanitized_url += 8;

    return sanitized_url;
}

// Driver code
int main() {
    char url[100];
    char* sanitized_url = NULL;

    printf("Enter a URL: ");
    scanf("%s", url);

    sanitized_url = sanitizeURL(url);

    if(sanitized_url == NULL) {
        printf("The URL contains forbidden characters!\n");
    }
    else {
        printf("The sanitized URL is %s\n", sanitized_url);
    }

    return 0;
}