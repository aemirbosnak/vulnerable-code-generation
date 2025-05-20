//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define PASSWD_FILE "/etc/passwd"

void find_and_replace(char *file, char *search, char *replace) {
    int fd = open(file, O_RDWR);
    if (fd < 0) {
        perror("Error opening file");
        exit(1);
    }

    off_t file_size = lseek(fd, 0, SEEK_END);
    char *buffer = malloc(file_size + 1);
    if (buffer == NULL) {
        perror("Error allocating memory");
        close(fd);
        exit(1);
    }

    lseek(fd, 0, SEEK_SET);
    ssize_t bytes_read = read(fd, buffer, file_size);
    if (bytes_read < 0) {
        perror("Error reading file");
        free(buffer);
        close(fd);
        exit(1);
    }

    size_t search_len = strlen(search);
    size_t replace_len = strlen(replace);

    char *next_search = buffer;
    while ((next_search = strstr(next_search, search))) {
        size_t remaining_len = file_size - (next_search - buffer);
        char *next_replace = malloc(remaining_len + replace_len + 1);

        memmove(next_replace, buffer, next_search - buffer);
        strcpy(next_replace + (next_search - buffer), replace);
        memmove(next_replace + (strlen(replace) + next_search - buffer), next_search + search_len, remaining_len - (next_search - buffer));

        lseek(fd, next_search - buffer, SEEK_SET);
        write(fd, next_replace, strlen(next_replace));

        free(next_replace);

        file_size -= (next_search - buffer);
        buffer = realloc(buffer, file_size + 1);
    }

    lseek(fd, 0, SEEK_SET);
    write(fd, buffer, file_size);
    close(fd);

    free(buffer);

    printf("Replaced '%s' with '%s' in %s\n", search, replace, file);
}

int main() {
    if (access(PASSWD_FILE, F_OK) != 0) {
        perror("Error: passwd file not found");
        exit(1);
    }

    find_and_replace(PASSWD_FILE, "root", "admin");

    return 0;
}