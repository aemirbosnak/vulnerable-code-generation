//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <regex.h>
#include <ctype.h>

#define MAX_URL_LEN 2048
#define MAX_DOMAIN_LEN 256

// Function to check if a string is a valid URL
int isValidURL(char *url)
{
    if (strlen(url) > MAX_URL_LEN) {
        return 0;
    }

    regex_t regex;
    int ret = regcomp(&regex, "^(https?://)?(www\\.)?[-a-zA-Z0-9@:%._+~#=]{1,256}\\.[a-zA-Z0-9()]{1,6}\\b([-a-zA-Z0-9()@:%_+.~#?&/=]*)", REG_EXTENDED);
    if (ret != 0) {
        return 0;
    }

    ret = regexec(&regex, url, 0, NULL, 0);
    regfree(&regex);
    if (ret != 0) {
        return 0;
    }

    return 1;
}

// Function to extract the domain from a URL
char *extractDomain(char *url)
{
    char *domain = malloc(MAX_DOMAIN_LEN);
    if (domain == NULL) {
        return NULL;
    }

    char *p = strstr(url, "://");
    if (p == NULL) {
        p = url;
    } else {
        p += 3;
    }

    char *q = strchr(p, '/');
    if (q == NULL) {
        q = p + strlen(p);
    }

    strncpy(domain, p, q - p);

    return domain;
}

// Function to sanitize a URL
char *sanitizeURL(char *url)
{
    char *sanitizedURL = malloc(MAX_URL_LEN);
    if (sanitizedURL == NULL) {
        return NULL;
    }

    char *p = strstr(url, "//");
    if (p == NULL) {
        p = url;
    } else {
        p += 2;
    }

    char *q = strchr(p, '/');
    if (q == NULL) {
        q = p + strlen(p);
    }

    strncpy(sanitizedURL, p, q - p);

    return sanitizedURL;
}

// Function to test the URL sanitizer
int main()
{
    char url[] = "https://www.example.com/path/to/file.html";

    printf("Original URL: %s\n", url);

    if (!isValidURL(url)) {
        printf("Invalid URL\n");
        return 1;
    }

    char *domain = extractDomain(url);
    if (domain == NULL) {
        printf("Failed to extract domain\n");
        return 1;
    }

    printf("Domain: %s\n", domain);

    char *sanitizedURL = sanitizeURL(url);
    if (sanitizedURL == NULL) {
        printf("Failed to sanitize URL\n");
        return 1;
    }

    printf("Sanitized URL: %s\n", sanitizedURL);

    free(domain);
    free(sanitizedURL);

    return 0;
}