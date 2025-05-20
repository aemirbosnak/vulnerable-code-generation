//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_INPUT_SIZE 1024
#define LOG_FILE "url_sanitizer.log"

char *sanitize_url(char *url)
{
    char *output = malloc(MAX_INPUT_SIZE);
    int i, j = 0;

    for (i = 0; url[i] && i < MAX_INPUT_SIZE - 1; i++) {
        if (url[i] == ' ') {
            url[i] = '_';
        } else if (url[i] == '?') {
            url[i] = '\0';
            break;
        } else {
            output[j++] = url[i];
        }
    }

    output[j] = '\0';
    return output;
}

int main(int argc, char *argv[])
{
    int fd;
    char *url;
    char *clean_url;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    url = argv[1];
    clean_url = sanitize_url(url);

    fd = open(LOG_FILE, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if (fd < 0) {
        perror("open");
        free(clean_url);
        exit(EXIT_FAILURE);
    }

    fprintf(fd, "[%s] -> [%s]\n", url, clean_url);

    printf("Sanitized URL: %s\n", clean_url);

    free(clean_url);
    close(fd);

    return EXIT_SUCCESS;
}