//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>

#define MAX_URL_LENGTH 2048

regex_t url_regex;

int is_valid_url(char* url) {
    int ret = regexec(&url_regex, url, 0, NULL, 0);
    if (ret == 0) {
        return 1;
    } else {
        return 0;
    }
}

void sanitize_url(char* url) {
    char sanitized_url[MAX_URL_LENGTH];
    int i = 0;
    int j = 0;
    while (url[i]!= '\0') {
        if (isalnum(url[i]) || url[i] == '.' || url[i] == '-' || url[i] == '_' || url[i] == '~' || url[i] == '/' || url[i] == '?' || url[i] == '&' || url[i] == '=' || url[i] == '+' || url[i] == '%' || url[i] == '$' || url[i] == ',') {
            sanitized_url[j++] = url[i];
        }
        i++;
    }
    sanitized_url[j] = '\0';
    strcpy(url, sanitized_url);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char* url = argv[1];
    sanitize_url(url);

    if (is_valid_url(url)) {
        printf("Valid URL: %s\n", url);
    } else {
        printf("Invalid URL: %s\n", url);
    }

    return 0;
}