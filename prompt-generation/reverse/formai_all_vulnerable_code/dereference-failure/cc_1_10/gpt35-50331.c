//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function prototypes
bool is_valid_char(char c);
bool is_valid_scheme(char* scheme);
bool is_valid_hostname(char* hostname);
bool is_valid_pathname(char* pathname);
bool is_valid_query(char* query);
bool is_valid_fragment(char* fragment);
void sanitize_url(char* url);

int main() {
    char url[256];
    printf("Enter a URL to sanitize: ");
    fgets(url, sizeof(url), stdin);
    sanitize_url(url);
    printf("Sanitized URL: %s", url);
    return 0;
}

// Function to check if a character is valid
bool is_valid_char(char c) {
    if (c >= 'a' && c <= 'z') {
        return true;
    }
    if (c >= 'A' && c <= 'Z') {
        return true;
    }
    if (c >= '0' && c <= '9') {
        return true;
    }
    // valid characters: . - _ ~
    if (c == '.' || c == '-' || c == '_' || c == '~') {
        return true;
    }
    return false;
}

// Function to check if the given scheme is valid
bool is_valid_scheme(char* scheme) {
    // valid schemes: http, https, ftp, mailto
    if (strcmp(scheme, "http") == 0) {
        return true;
    }
    if (strcmp(scheme, "https") == 0) {
        return true;
    }
    if (strcmp(scheme, "ftp") == 0) {
        return true;
    }
    if (strcmp(scheme, "mailto") == 0) {
        return true;
    }
    return false;
}

// Function to check if the given hostname is valid
bool is_valid_hostname(char* hostname) {
    int len = strlen(hostname);
    if (len == 0 || len > 255) {
        return false;
    }
    if (hostname[0] == '.' || hostname[len-1] == '.') {
        return false;
    }
    char* token = strtok(hostname, ".");
    while (token != NULL) {
        if (strlen(token) > 63) {
            return false;
        }
        for (int i=0; i<strlen(token); i++) {
            if (!is_valid_char(token[i])) {
                return false;
            }
        }
        token = strtok(NULL, ".");
    }
    return true;
}

// Function to check if the given pathname is valid
bool is_valid_pathname(char* pathname) {
    int len = strlen(pathname);
    if (len == 0 || len > 2048) {
        return false;
    }
    // valid characters in pathname: / - _ . ~
    for (int i=0; i<len; i++) {
        if (pathname[i] != '/' && pathname[i] != '-' && pathname[i] != '_' && pathname[i] != '.' && pathname[i] != '~') {
            if (!is_valid_char(pathname[i])) {
                return false;
            }
        }
    }
    return true;
}

// Function to check if the given query string is valid
bool is_valid_query(char* query) {
    int len = strlen(query);
    if (len > 2048) {
        return false;
    }
    // valid characters in query string: ? = & - _ . ~
    for (int i=0; i<len; i++) {
        if (query[i] != '?' && query[i] != '=' && query[i] != '&' && query[i] != '-' && query[i] != '_' && query[i] != '.' && query[i] != '~') {
            if (!is_valid_char(query[i])) {
                return false;
            }
        }
    }
    return true;
}

// Function to check if the given fragment is valid
bool is_valid_fragment(char* fragment) {
    int len = strlen(fragment);
    if (len > 2048) {
        return false;
    }
    // valid characters in fragment: # - _ . ~
    for (int i=0; i<len; i++) {
        if (fragment[i] != '#' && fragment[i] != '-' && fragment[i] != '_' && fragment[i] != '.' && fragment[i] != '~') {
            if (!is_valid_char(fragment[i])) {
                return false;
            }
        }
    }
    return true;
}

// Function to sanitize the given URL
void sanitize_url(char* url) {
    // Remove newline character from the end of the string
    int len = strlen(url);
    if (url[len-1] == '\n') {
        url[len-1] = '\0';
    }

    // Separate URL components
    char* scheme = strtok(url, ":/");
    char* hostname = strtok(NULL, ":/");    // also handles userinfo
    char* port = strtok(NULL, "/");
    char* pathname = strtok(NULL, "?");
    char* query = strtok(NULL, "#");
    char* fragment = strtok(NULL, "");

    // Validate and sanitize each component
    if (scheme != NULL && !is_valid_scheme(scheme)) {
        scheme[0] = '\0';
    }
    if (hostname != NULL && !is_valid_hostname(hostname)) {
        hostname[0] = '\0';
    }
    if (port != NULL) {
        int port_num = atoi(port);
        if (port_num < 1 || port_num > 65535) {
            port[0] = '\0';
        }
    }
    if (pathname != NULL && !is_valid_pathname(pathname)) {
        pathname[0] = '/';
        pathname[1] = '\0';
    }
    if (query != NULL && !is_valid_query(query)) {
        query[0] = '\0';
    }
    if (fragment != NULL && !is_valid_fragment(fragment)) {
        fragment[0] = '\0';
    }
}