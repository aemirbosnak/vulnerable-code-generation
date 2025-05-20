//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUF_SIZE 1024

void sanitize_url(char *url) {
    char *p = url;
    char *q = url;

    while (*p) {
        if (*p == '&' && (*(p+1) == 'a' || *(p+1) == 'A') && (*(p+2) == 'm' || *(p+2) == 'M') && (*(p+3) == 'p' || *(p+3) == 'P') && *(p+4) == ';') {
            *q++ = '&';
            p += 5;
        } else if (*p == '%') {
            if (!isxdigit(*(p+1)) || !isxdigit(*(p+2))) {
                *q++ = ' ';
                p += 3;
            } else {
                *q++ = '%';
                *q++ = *(++p);
                *q++ = *(++p);
                p++;
            }
        } else if (*p == '+') {
            *q++ = ' ';
            p++;
        } else {
            *q++ = *p++;
        }
    }

    *q = '\0';
}

int main(int argc, char *argv[]) {
    char *url = NULL;
    char buf[BUF_SIZE];

    if (argc != 2) {
        printf("Usage: %s <url>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    url = argv[1];
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}