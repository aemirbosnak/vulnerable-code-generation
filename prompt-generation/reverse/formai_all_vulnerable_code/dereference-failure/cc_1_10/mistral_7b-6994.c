//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <limits.h>
#include <errno.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MAX_URL_LENGTH 4096
#define BAD_CHARS "\\/:*?\"<>|"

void sanitize_url(char *url) {
    int length = strlen(url);
    int i, j, k;

    for (i = 0; i < length; i++) {
        if (isalnum(url[i]) || strchr(BAD_CHARS, url[i])) {
            for (j = i + 1; j < length; j++) {
                if (isalnum(url[j]) || strchr(BAD_CHARS, url[j])) {
                    continue;
                }

                if (url[i] == '.' && url[j] == '/') {
                    memmove(&url[i], &url[j], length - j);
                    length -= j - i;
                    j -= i;
                    i--;
                } else {
                    for (k = j; k < length; k++) {
                        url[k] = url[k + 1];
                    }
                    length--;
                    j--;
                }
            }
        }
    }

    url[length] = '\0';
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char url[MAX_URL_LENGTH];
    strcpy(url, argv[1]);

    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}