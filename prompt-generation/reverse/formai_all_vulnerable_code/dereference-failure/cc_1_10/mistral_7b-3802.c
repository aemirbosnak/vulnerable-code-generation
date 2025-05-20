//MISTRAL-7B DATASET v1.0 Category: Email Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_EMAIL_SIZE 1024
#define MAX_LINE_LENGTH 256

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void read_email_file(const char *filename) {
    int fd, bytes_read;
    char buffer[MAX_LINE_LENGTH];
    size_t email_length = 0;
    char *email = malloc(MAX_EMAIL_SIZE);
    memset(email, 0, MAX_EMAIL_SIZE);

    if ((fd = open(filename, O_RDONLY)) < 0) {
        die("Failed to open email file: ");
    }

    while ((bytes_read = read(fd, buffer, MAX_LINE_LENGTH)) > 0) {
        size_t line_length = strlen(buffer);

        if (email_length + line_length + 1 >= MAX_EMAIL_SIZE) {
            free(email);
            die("Email size exceeded.\n");
        }

        strncat(email, buffer, line_length + 1);
        email_length += line_length + 1;
    }

    if (bytes_read < 0) {
        die("Failed to read email file: ");
    }

    close(fd);

    printf("\nEmail content:\n%s\n", email);
    free(email);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        die("Usage: email_client <email_file>");
    }

    setuid(getuid()); // Run as the same user as the current user
    setgid(getgid()); // Run as the same group as the current user

    umask(0); // Clear umask to prevent unnecessary file permissions

    read_email_file(argv[1]);

    return EXIT_SUCCESS;
}