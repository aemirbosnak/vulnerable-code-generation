//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: excited
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sanitize(char *url) {
    // First, let's make the entire URL lowercase
    int i;
    int len = strlen(url);
    for (i = 0; i < len; i++)
        url[i] = tolower(url[i]);
    
    // Now, let's remove any whitespace from the beginning and end of the URL
    while (isspace((unsigned char) url[0])) {
        // Shift the string to the left
        for (i = 0; i < len; i++)
            url[i] = url[i+1];
        len--;
    }
    while (isspace((unsigned char) url[len-1])) {
        // Remove trailing whitespace
        url[len-1] = '\0';
        len--;
    }
    
    // Let's add "http://" or "https://" if they are missing
    if (strncmp(url, "http://", 7) != 0 && strncmp(url, "https://", 8) != 0) {
        char tmp[8];
        strncpy(tmp, url, 7);
        tmp[7] = '\0';
        if (strcmp(tmp, "http://") != 0) {
            strncpy(tmp, url, 8);
            tmp[8] = '\0';
            if (strcmp(tmp, "https://") != 0) {
                // Neither http:// or https:// was found, so add http:// to the beginning
                char new_url[strlen(url) + 8];
                strcpy(new_url, "http://");
                strcat(new_url, url);
                strcpy(url, new_url);
                len = strlen(url);
            }
        }
    }
    
    // Finally, let's remove any query strings or fragments from the URL
    char *fragment = strstr(url, "#");
    if (fragment != NULL) {
        *fragment = '\0';
        len = strlen(url);
    }
    char *query = strstr(url, "?");
    if (query != NULL) {
        *query = '\0';
        len = strlen(url);
    }
}

int main() {
    char url[1000];
    printf("Please enter a URL to sanitize: ");
    fgets(url, 1000, stdin);
    sanitize(url);
    printf("The sanitized URL is: %s\n", url);
    return 0;
}