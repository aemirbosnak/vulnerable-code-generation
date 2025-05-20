//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>

typedef struct {
    char* url;
    char* protocol;
    char* host;
    char* path;
    char* query;
    char* fragment;
} UrlParts;

UrlParts* parse_url(char* url) {
    UrlParts* parts = malloc(sizeof(UrlParts));
    parts->url = strdup(url);
    char* scheme_end = strchr(parts->url, ':');
    if (!scheme_end) {
        free(parts);
        return NULL;
    }
    scheme_end[0] = '\0';
    *scheme_end++ = '\0';
    parts->protocol = strdup(parts->url);
    parts->host = strdup(scheme_end);
    char* path_start = strchr(parts->host, '/');
    if (!path_start) {
        free(parts->protocol);
        free(parts->host);
        free(parts);
        return NULL;
    }
    path_start[0] = '\0';
    *path_start++ = '\0';
    parts->path = strdup(path_start);
    char* query_start = strchr(parts->path, '?');
    if (!query_start) {
        free(parts->protocol);
        free(parts->host);
        free(parts->path);
        free(parts);
        return NULL;
    }
    query_start[0] = '\0';
    *query_start++ = '\0';
    parts->query = strdup(query_start);
    parts->fragment = NULL;
    return parts;
}

void free_url_parts(UrlParts* parts) {
    free(parts->url);
    free(parts->protocol);
    free(parts->host);
    free(parts->path);
    free(parts->query);
    free(parts->fragment);
    free(parts);
}

char* sanitize_url(char* url) {
    UrlParts* parts = parse_url(url);
    if (!parts) {
        return NULL;
    }
    char* sanitized_url = malloc(strlen(parts->protocol) + strlen(parts->host) + strlen(parts->path) + 7);
    sprintf(sanitized_url, "%s://%s%s", parts->protocol, parts->host, parts->path);
    free_url_parts(parts);
    return sanitized_url;
}

int main() {
    char* url = "http://example.com/path?query=string#fragment";
    char* sanitized_url = sanitize_url(url);
    printf("%s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}