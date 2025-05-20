//MISTRAL-7B DATASET v1.0 Category: File system simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_FILE_NAME 100
#define MAX_LINE_SIZE 256
#define MAX_NUM_FILES 10

typedef struct File {
    char name[MAX_FILE_NAME];
    int size;
    struct File *next;
} File;

File *head = NULL;

int create_file(char *name, int size) {
    File *new_file = (File *) malloc(sizeof(File));
    strcpy(new_file->name, name);
    new_file->size = size;
    new_file->next = head;
    head = new_file;
    int fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("Error opening file");
        return -1;
    }
    if (write(fd, "", size) < 0) {
        perror("Error writing to file");
        close(fd);
        return -1;
    }
    close(fd);
    return 0;
}

int read_file(char *name, char *buffer, int buffer_size) {
    int fd = open(name, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return -1;
    }
    ssize_t bytes_read = read(fd, buffer, buffer_size - 1);
    if (bytes_read < 0) {
        perror("Error reading from file");
        close(fd);
        return -1;
    }
    buffer[bytes_read] = '\0';
    close(fd);
    return bytes_read;
}

int delete_file(char *name) {
    File *current = head;
    File *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            unlink(name);
            free(current);
            return 0;
        }
        previous = current;
        current = current->next;
    }

    return -1;
}

int main() {
    create_file("file1.txt", 10);
    create_file("file2.txt", 20);

    char buffer[MAX_LINE_SIZE];
    int bytes_read;

    printf("Contents of file1.txt:\n");
    bytes_read = read_file("file1.txt", buffer, MAX_LINE_SIZE);
    printf("%s", buffer);

    printf("\nDeleting file1.txt\n");
    delete_file("file1.txt");

    pid_t pid = fork();

    if (pid < 0) {
        perror("Error forking process");
        exit(1);
    } else if (pid > 0) {
        wait(NULL);
        printf("Child process finished executing\n");
    } else {
        bytes_read = read_file("file2.txt", buffer, MAX_LINE_SIZE);
        printf("Contents of file2.txt in child process:\n%s\n", buffer);
        exit(0);
    }

    return 0;
}