//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sanitizeURL(char *url) {
    int i, j;
    char domain[100], cleanedURL[1000];

    // trim leading and trailing white spaces
    i = 0;
    while (isspace(url[i])) {
        i++;
    }
    j = strlen(url) - 1;
    while (isspace(url[j])) {
        j--;
    }
    strncpy(cleanedURL, url + i, j - i + 1);
    cleanedURL[j - i + 1] = '\0';

    // extract domain name
    i = 0;
    j = 0;
    while (cleanedURL[i] != '\0' && cleanedURL[i] != '/') {
        domain[j] = cleanedURL[i];
        i++;
        j++;
    }
    domain[j] = '\0';

    // check if domain is valid
    if (strstr(domain, "http") != NULL || strstr(domain, "www") != NULL) {
        printf("Invalid URL: domain name cannot include http or www\n");
        return;
    }

    // convert domain to lowercase
    i = 0;
    while (domain[i] != '\0') {
        domain[i] = tolower(domain[i]);
        i++;
    }

    // replace all non-alphanumeric characters with '-'
    i = 0;
    j = 0;
    while (cleanedURL[i] != '\0') {
        if (isalnum(cleanedURL[i])) {
            cleanedURL[j] = cleanedURL[i];
        } else {
            cleanedURL[j] = '-';
        }
        i++;
        j++;
    }
    cleanedURL[j] = '\0';

    printf("Sanitized URL: https://%s/%s\n", domain, cleanedURL);
}

int main() {
    char url[1000];

    printf("Enter URL to sanitize: ");
    fgets(url, 1000, stdin);

    sanitizeURL(url);

    return 0;
}