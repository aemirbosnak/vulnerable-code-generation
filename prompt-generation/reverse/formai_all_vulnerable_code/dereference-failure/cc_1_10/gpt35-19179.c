//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: minimalist
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LEN 1000

bool is_valid_scheme(char *scheme) {
    char valid_schemes[][10] = {"http", "https", "ftp", "ssh"};
    int i, num_valid_schemes = sizeof(valid_schemes) / sizeof(valid_schemes[0]);
    for (i = 0; i < num_valid_schemes; i++) {
        if (strcmp(valid_schemes[i], scheme) == 0) {
            return true;
        }
    }
    return false;
}

bool is_valid_domain(char *domain) {
    return (strlen(domain) > 0 && strchr(domain, ' ') == NULL);
}

bool is_valid_path(char *path) {
    return (strlen(path) > 0 && strchr(path, ' ') == NULL);
}

bool is_valid_query_string(char *query_string) {
    return (strlen(query_string) > 0 && strchr(query_string, ' ') == NULL);
}

char *url_sanitizer(char *url) {
    char *url_copy = malloc(sizeof(char) * MAX_URL_LEN);
    strcpy(url_copy, url);

    char *scheme = strtok(url_copy, ":");
    if (!is_valid_scheme(scheme)) {
        scheme = "http";
    }
    char *domain = strtok(NULL, "/");
    if (!is_valid_domain(domain)) {
        domain = "localhost";
    }
    char *path = strtok(NULL, "?");
    if (!is_valid_path(path)) {
        path = "/";
    }
    char *query_string = strtok(NULL, "");
    if (!is_valid_query_string(query_string)) {
        query_string = "";
    }

    char *sanitized_url = malloc(sizeof(char) * MAX_URL_LEN);
    sprintf(sanitized_url, "%s://%s%s?%s", scheme, domain, path, query_string);

    free(url_copy);
    return sanitized_url;
}

int main() {
    char url1[] = "https://www.example.com/path/to/page?q1=abc&q2=xyz";
    char *sanitized_url1 = url_sanitizer(url1);
    printf("Sanitized URL1: %s\n", sanitized_url1);
    free(sanitized_url1);

    char url2[] = "ftp:   / /   bad domain.com/not a page/?q=bad query";
    char *sanitized_url2 = url_sanitizer(url2);
    printf("Sanitized URL2: %s\n", sanitized_url2);
    free(sanitized_url2);

    char url3[] = "invalid-url";
    char *sanitized_url3 = url_sanitizer(url3);
    printf("Sanitized URL3: %s\n", sanitized_url3);
    free(sanitized_url3);

    return 0;
}