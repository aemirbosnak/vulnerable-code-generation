//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <regex.h>

#define MAX_LEN 1024
#define OUT_FILE "output.txt"

void sanitize_url(char *url) {
    regex_t regex;
    int reti;
    char *errmsg;

    reti = regcomp(&regex, "^[a-z]+://[^/?#]*[/?].*$", REG_EXTENDED);

    if (reti) {
        fprintf(stderr, "Regex compilation failed: %s\n", regerror(reti, &regex, NULL, 0));
        exit(1);
    }

    regmatch_t match;
    reti = regexec(&regex, url, 1, &match, 0);

    regfree(&regex);

    if (!reti) {
        int i, j, len;
        char *output = malloc(strlen(url) + 1);

        for (i = match.rm_so, j = 0; i < strlen(url); i++, j++) {
            if (url[i] == '/') {
                output[j] = '_';
            } else {
                if (isalnum(url[i])) {
                    output[j] = tolower(url[i]);
                } else {
                    output[j] = '-';
                }
            }
            len = j + 1;
            if (url[i] == '?' || url[i] == '#') {
                output[len] = '\0';
                break;
            }
        }

        int fd = open(OUT_FILE, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
        write(fd, output, strlen(output));
        close(fd);

        printf("Sanitized URL: %s\n", output);
        free(output);
    } else {
        fprintf(stderr, "Invalid URL format: %s\n", url);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        exit(1);
    }

    sanitize_url(argv[1]);

    return 0;
}