//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_URL_LEN 2048

bool is_valid_char(char c)
{
    if (isalnum(c) || c == '-') {
        return true;
    } else if (c == '.') {
        return true;
    }
    return false;
}

bool is_valid_url(char* url)
{
    int len = strlen(url);
    if (len > MAX_URL_LEN) {
        return false;
    }

    char* p = url;
    while (*p) {
        if (!is_valid_char(*p)) {
            return false;
        }
        p++;
    }
    return true;
}

char* sanitize_url(char* url)
{
    int len = strlen(url);
    char* sanitized_url = malloc(len + 1);
    char* p = url;
    char* q = sanitized_url;

    while (*p) {
        if (is_valid_char(*p)) {
            *q++ = *p;
        }
        p++;
    }
    *q = '\0';
    return sanitized_url;
}

int main()
{
    char input_url[MAX_URL_LEN];

    printf("Enter a URL: ");
    fgets(input_url, MAX_URL_LEN, stdin);

    char* sanitized_url = sanitize_url(input_url);

    if (is_valid_url(sanitized_url)) {
        printf("Sanitized URL: %s\n", sanitized_url);
    } else {
        printf("Invalid URL.\n");
    }

    free(sanitized_url);
    return 0;
}