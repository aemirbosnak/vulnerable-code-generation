//Falcon2-11B DATASET v1.0 Category: URL Sanitizer ; Style: brave
#include <stdio.h>
#include <string.h>

char *sanitize_url(char *url) {
    char *sanitized_url = (char *)malloc(strlen(url) * sizeof(char));
    if (sanitized_url == NULL) {
        printf("Error: Out of memory.\n");
        return NULL;
    }
    strcpy(sanitized_url, url);

    // Sanitize the URL
    int i = 0;
    while (i < strlen(sanitized_url)) {
        if (sanitized_url[i] == '%') {
            i++;
            if (i >= strlen(sanitized_url)) {
                printf("Error: Invalid URL.\n");
                free(sanitized_url);
                return NULL;
            }
            if (sanitized_url[i] >= '0' && sanitized_url[i] <= '9') {
                i++;
                int num = 0;
                while (i < strlen(sanitized_url) && sanitized_url[i] >= '0' && sanitized_url[i] <= '9') {
                    num = (num * 10) + (sanitized_url[i] - '0');
                    i++;
                }
                sanitized_url[i - 1] = num / 16;
                sanitized_url[i] = num % 16 + '0';
            } else if (sanitized_url[i] >= 'A' && sanitized_url[i] <= 'F') {
                i++;
                int num = 0;
                while (i < strlen(sanitized_url) && sanitized_url[i] >= 'A' && sanitized_url[i] <= 'F') {
                    num = (num * 16) + (sanitized_url[i] - 'A' + 10);
                    i++;
                }
                sanitized_url[i - 1] = num / 16;
                sanitized_url[i] = num % 16 + '0';
            } else {
                printf("Error: Invalid URL.\n");
                free(sanitized_url);
                return NULL;
            }
        }
        i++;
    }

    return sanitized_url;
}

int main() {
    char url[100];
    printf("Enter a URL: ");
    fgets(url, sizeof(url), stdin);
    url[strcspn(url, "\n")] = '\0'; // Remove newline character
    char *sanitized_url = sanitize_url(url);
    if (sanitized_url!= NULL) {
        printf("Sanitized URL: %s\n", sanitized_url);
        free(sanitized_url);
    }
    return 0;
}