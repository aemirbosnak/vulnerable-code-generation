//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LEN 2048

int is_valid_url_char(char ch)
{
    // Check if the character is valid for a URL
    if (isalnum(ch) || ch == '.' || ch == '-' || ch == '_' || ch == '~' || ch == '%' || ch == '+' || ch == '=' || ch == '&' || ch == '#' || ch == '?') {
        return 1;
    } else {
        return 0;
    }
}

int is_valid_url(char* url)
{
    // Check if the URL is valid
    int i, len;
    len = strlen(url);
    for (i = 0; i < len; i++) {
        if (!is_valid_url_char(url[i])) {
            return 0;
        }
    }
    return 1;
}

void sanitize_url(char* url)
{
    // Sanitize the URL
    int i, j;
    char* new_url;
    int len;
    len = strlen(url);
    new_url = (char*)malloc(MAX_URL_LEN);
    j = 0;
    for (i = 0; i < len; i++) {
        if (is_valid_url_char(url[i])) {
            new_url[j++] = url[i];
        }
    }
    new_url[j] = '\0';
    strcpy(url, new_url);
    free(new_url);
}

int main()
{
    // Test the URL sanitizer
    char url[MAX_URL_LEN];
    printf("Enter a URL: ");
    scanf("%s", url);
    sanitize_url(url);
    if (is_valid_url(url)) {
        printf("Sanitized URL: %s\n", url);
    } else {
        printf("Invalid URL\n");
    }
    return 0;
}