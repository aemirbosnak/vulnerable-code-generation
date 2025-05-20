//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* sanitize_url(char url[]) {

    // Make sure URL is null terminated
    url[strlen(url)] = '\0';
    
    // Make sure URL is lowercase
    for (int i = 0; i < strlen(url); i++) {
        url[i] = tolower(url[i]);
    }

    // Remove any trailing slashes
    for (int i = strlen(url) - 1; i >= 0; i--) {
        if (url[i] == '/') {
            url[i] = '\0';
        } else {
            break;
        }
    }

    // Remove duplicates in slashes 
    for (int i = strlen(url) - 1; i >= 0; i--) {
        if (url[i] == '/') {
            if (url[i-1] == '/') {
                memmove(url + i - 1, url + i, strlen(url) - i + 1);
            }   
        }
    }

    // Remove leading http or https
    if (strstr(url, "http://") == url) {
        char* new_url = url + strlen("http://");
        memmove(url, new_url, strlen(new_url) + 1);
    } else if (strstr(url, "https://") == url) {
        char* new_url = url + strlen("https://");
        memmove(url, new_url, strlen(new_url) + 1);
    }

    // Remove index.html
    int len = strlen(url);
    if (strstr(url + len - 10, "index.html") == url + len - 10) {
        url[len - 10] = '\0';
    }

    return url;
}

int main() {
    char url[1000];

    // Prompt for URL
    printf("Enter a URL:");
    scanf("%s", url);

    // Sanitize the URL
    char* sanitized_url = sanitize_url(url);

    // Print the sanitized URL
    printf("The sanitized URL is: %s\n", sanitized_url);

    return 0;
}