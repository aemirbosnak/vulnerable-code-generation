//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 2048

char* sanitize_url(char* url) {
    char* sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));
    int i, j;
    
    // Remove leading and trailing whitespace
    while (isspace(*url)) {
        url++;
    }
    while (isspace(*(url + strlen(url) - 1))) {
        url[strlen(url) - 1] = '\0';
    }
    
    // Convert to lowercase
    for (i = 0, j = 0; url[i]!= '\0'; i++) {
        if (isalpha(url[i])) {
            sanitized_url[j++] = tolower(url[i]);
        } else {
            sanitized_url[j++] = url[i];
        }
    }
    sanitized_url[j] = '\0';
    
    // Remove invalid characters
    char* valid_chars = "abcdefghijklmnopqrstuvwxyz0123456789-_.~:/?#[]@!$&'()*+,;=";
    for (i = 0, j = 0; sanitized_url[i]!= '\0'; i++) {
        if (strchr(valid_chars, sanitized_url[i])!= NULL) {
            sanitized_url[j++] = sanitized_url[i];
        }
    }
    sanitized_url[j] = '\0';
    
    // Add "http://" if not already present
    if (!strstr(sanitized_url, "http://")) {
        strcat(sanitized_url, "http://");
    }
    
    return sanitized_url;
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    char* sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}