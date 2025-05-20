//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>

#define BUF_SIZE 1024

// Function to sanitize a URL
void sanitize_url(char* url) {
    char* buf = malloc(BUF_SIZE);
    char* token = strtok(url, "://");
    strcpy(buf, token);

    char* scheme = strtok(NULL, "://");
    strcat(buf, "://");
    strcat(buf, scheme);

    token = strtok(buf, "/");
    strcat(buf, "/");
    strcat(buf, token);

    while (token!= NULL) {
        if (strlen(token) > 0 && strcmp(token, ".")!= 0 && strcmp(token, "..")!= 0) {
            strcat(buf, "/");
            strcat(buf, token);
        }
        token = strtok(NULL, "/");
    }

    // Check if the URL is valid
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    struct addrinfo* result = NULL;
    int ret = getaddrinfo(buf, NULL, &hints, &result);

    if (ret!= 0 || result == NULL) {
        printf("Invalid URL: %s\n", url);
        free(buf);
        return;
    }

    free(buf);
}

int main() {
    char* url = "http://example.com/path/to/file.html?query=string";
    sanitize_url(url);
    return 0;
}