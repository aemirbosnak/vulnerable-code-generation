//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: visionary
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *sanitize_url(char *input_url) {
    // Remove any whitespace before or after the URL
    char *url = input_url;
    while (isspace(*url)) url++;
    char *end_url = input_url + strlen(input_url) - 1;
    while (end_url > url && isspace(*end_url)) end_url--;
    *(end_url + 1) = '\0';

    // Remove any leading "http://" or "https://"
    if (strncasecmp(url, "http://", 7) == 0) {
        url += 7;
    } else if (strncasecmp(url, "https://", 8) == 0) {
        url += 8;
    }

    // Remove any trailing "/"
    end_url = url + strlen(url) - 1;
    if (*end_url == '/') {
        *end_url = '\0';
    }

    // Remove any query parameters
    char *query_start = strchr(url, '?');
    if (query_start != NULL) {
        *query_start = '\0';
    }

    // Remove any trailing whitespace after query parameters
    end_url = url + strlen(url) - 1;
    while (end_url > url && isspace(*end_url)) {
        *end_url-- = '\0';
    }

    return url;
}

int main() {
    char *url1 = " http://www.example.com/ ";
    char *url2 = "https://www.example.com/path/to/my/file.html?query_param1=foo&query_param2=";
    char *url3 = "http://www.example.com/path/to/my/file.html?query_param1=foo&query_param2=&  ";

    char *clean_url1 = sanitize_url(url1);
    char *clean_url2 = sanitize_url(url2);
    char *clean_url3 = sanitize_url(url3);

    printf("Clean URL 1: %s\n", clean_url1);
    printf("Clean URL 2: %s\n", clean_url2);
    printf("Clean URL 3: %s\n", clean_url3);

    return 0;
}