//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define MAX_DOMAIN_LENGTH 256

char *sanitize_url(char *url);
char *extract_domain(char *url);

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    char *sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);
    char *domain = extract_domain(sanitized_url);
    printf("Domain: %s\n", domain);
    free(sanitized_url);
    free(domain);
    return 0;
}

char *sanitize_url(char *url) {
    char *sanitized_url = malloc(MAX_URL_LENGTH);
    int i = 0;
    while (url[i]!= '\0') {
        if (isalnum(url[i]) || url[i] == '-') {
            sanitized_url[i] = url[i];
        } else if (url[i] == '.') {
            sanitized_url[i] = '.';
        } else if (url[i] == '_') {
            sanitized_url[i] = '_';
        } else {
            sanitized_url[i] = '_';
            printf("Warning: Invalid character found in URL. Replaced with '_'.\n");
        }
        i++;
    }
    sanitized_url[i] = '\0';
    return sanitized_url;
}

char *extract_domain(char *url) {
    char *domain = malloc(MAX_DOMAIN_LENGTH);
    int i = strlen(url) - 1;
    while (i >= 0 && url[i]!= '.') {
        i--;
    }
    i++;
    int j = 0;
    while (i < strlen(url) && url[i]!= '\0') {
        domain[j] = url[i];
        i++;
        j++;
    }
    domain[j] = '\0';
    return domain;
}