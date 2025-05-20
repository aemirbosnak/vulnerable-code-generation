//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define ERR_EXIT(m) do{perror(m);exit(1);}while(0)

void my_open(const char *pathname, int flags, mode_t mode) {
    int fd = open(pathname, flags, mode);
    if (fd < 0) {
        ERR_EXIT("open");
    }
    printf("Successfully opened file: %s\n", pathname);
}

void my_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Error: Out of memory!\n");
        exit(EXIT_FAILURE);
    }
    printf("Successfully allocated memory of size: %zu bytes\n", size);
}

void my_strcpy(char *dest, const char *src) {
    strcpy(dest, src);
    if (strlen(dest) + strlen(src) >= 256) {
        fprintf(stderr, "Error: String copy too long!\n");
        exit(EXIT_FAILURE);
    }
}

void my_chmod(const char *pathname, mode_t mode) {
    if (chmod(pathname, mode) < 0) {
        ERR_EXIT("chmod");
    }
}

int main() {
    const char *pathname = "./test.txt";
    char str[256] = {0};

    my_open(pathname, O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    my_malloc(sizeof(int) * 10);

    my_strcpy(str, "This is a test string.");

    my_chmod(pathname, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    printf("Contents of the file before writing:\n");
    char buffer[1024] = {0};
    ssize_t bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
    if (bytes_read > 0) {
        printf("Read %ld bytes from stdin.\n", bytes_read);
        write(STDOUT_FILENO, buffer, bytes_read);
    }

    printf("\nWriting to the file...\n");
    int fd = open(pathname, O_WRONLY);
    if (fd < 0) {
        ERR_EXIT("open");
    }

    int num = 42;
    if (write(fd, &num, sizeof(num)) != sizeof(num)) {
        ERR_EXIT("write");
    }

    close(fd);

    printf("Reading the file contents:\n");
    fd = open(pathname, O_RDONLY);
    if (fd < 0) {
        ERR_EXIT("open");
    }

    int read_num;
    if (read(fd, &read_num, sizeof(num)) != sizeof(num)) {
        ERR_EXIT("read");
    }

    printf("The number in the file is: %d\n", read_num);
    close(fd);

    printf("Done.\n");
    return EXIT_SUCCESS;
}