//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_URL_LEN 2048

typedef struct {
    char *scheme;
    char *host;
    char *port;
    char *path;
    char *query;
    char *fragment;
} URLParts;

int parseURL(char *url, URLParts *parts) {
    // Parse the scheme
    char *p = strchr(url, ':');
    if (p == NULL) {
        return -1;
    }
    *p = '\0';
    parts->scheme = strdup(url);
    *p++ = ':';

    // Parse the host
    p = strchr(p, '/');
    if (p == NULL) {
        return -1;
    }
    *p = '\0';
    parts->host = strdup(p);
    *p++ = '/';

    // Parse the port
    if (*p == ':') {
        p = strchr(p + 1, '/');
        if (p == NULL) {
            return -1;
        }
        *p = '\0';
        parts->port = strdup(p + 1);
        *p++ = '/';
    }

    // Parse the path
    p = strchr(p, '?');
    if (p == NULL) {
        parts->path = strdup(p);
    } else {
        *p = '\0';
        parts->path = strdup(p);
        *p++ = '?';
    }

    // Parse the query
    p = strchr(p, '#');
    if (p == NULL) {
        parts->query = strdup(p);
    } else {
        *p = '\0';
        parts->query = strdup(p);
        *p++ = '#';
    }

    // Parse the fragment
    parts->fragment = strdup(p);

    return 0;
}

int sanitizeURL(char *url, char *sanitizedURL) {
    // Parse the URL
    URLParts parts;
    int rc = parseURL(url, &parts);
    if (rc != 0) {
        return -1;
    }

    // Sanitize the scheme
    if (strcmp(parts.scheme, "http") != 0 && strcmp(parts.scheme, "https") != 0) {
        return -1;
    }

    // Sanitize the host
    if (strlen(parts.host) == 0) {
        return -1;
    }

    // Sanitize the port
    if (parts.port != NULL && strlen(parts.port) > 5) {
        return -1;
    }

    // Sanitize the path
    if (strlen(parts.path) == 0) {
        return -1;
    }

    // Sanitize the query
    if (parts.query != NULL && strlen(parts.query) > 1024) {
        return -1;
    }

    // Sanitize the fragment
    if (parts.fragment != NULL && strlen(parts.fragment) > 1024) {
        return -1;
    }

    // Rebuild the sanitized URL
    strcpy(sanitizedURL, parts.scheme);
    strcat(sanitizedURL, "://");
    strcat(sanitizedURL, parts.host);
    if (parts.port != NULL) {
        strcat(sanitizedURL, ":");
        strcat(sanitizedURL, parts.port);
    }
    strcat(sanitizedURL, parts.path);
    if (parts.query != NULL) {
        strcat(sanitizedURL, "?");
        strcat(sanitizedURL, parts.query);
    }
    if (parts.fragment != NULL) {
        strcat(sanitizedURL, "#");
        strcat(sanitizedURL, parts.fragment);
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return -1;
    }

    char sanitizedURL[MAX_URL_LEN];
    int rc = sanitizeURL(argv[1], sanitizedURL);
    if (rc != 0) {
        printf("Error: Invalid URL\n");
        return -1;
    }

    printf("Sanitized URL: %s\n", sanitizedURL);

    return 0;
}