//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function to sanitize the URL
void sanitize_url(char* url) {
    int i, j;
    char tmp[MAX_URL_LENGTH];

    // Remove leading and trailing whitespace
    while(isspace(*url)) {
        url++;
    }
    while(isspace(*(url + strlen(url) - 1))) {
        url[strlen(url) - 1] = '\0';
    }

    // Convert to lowercase
    for(i = 0; url[i]; i++) {
        url[i] = tolower(url[i]);
    }

    // Remove invalid characters
    strcpy(tmp, url);
    for(i = 0, j = 0; tmp[i]; i++) {
        if(isalnum(tmp[i]) || tmp[i] == '-') {
            url[j++] = tmp[i];
        }
    }
    url[j] = '\0';
}

int main(int argc, char* argv[]) {
    if(argc!= 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char url[MAX_URL_LENGTH];
    strcpy(url, argv[1]);

    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}