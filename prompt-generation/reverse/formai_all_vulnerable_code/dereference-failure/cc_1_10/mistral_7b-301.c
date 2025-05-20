//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

// Function to generate a random string
char* random_string(int length) {
    char *str = malloc(length * sizeof(char));
    if (str == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < length; i++) {
        str[i] = 'A' + (rand() % 26);
    }
    str[length] = '\0';

    return str;
}

// Function to backup a file with a random name
void backup_file(char* filename) {
    int fd_src, fd_dst;
    char src_path[1024], dest_path[1024];
    char *random_extension = random_string(5);

    strcpy(src_path, filename);
    strcat(src_path, ":");

    fd_src = open(src_path, O_RDONLY);
    if (fd_src == -1) {
        perror("Failed to open source file");
        free(random_extension);
        exit(EXIT_FAILURE);
    }

    strcpy(dest_path, "/mnt/backup/");
    strcat(dest_path, filename);
    strcat(dest_path, random_extension);

    fd_dst = open(dest_path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd_dst == -1) {
        perror("Failed to open destination file");
        close(fd_src);
        free(random_extension);
        exit(EXIT_FAILURE);
    }

    ssize_t bytes_read;
    char buffer[4096];

    while ((bytes_read = read(fd_src, buffer, sizeof(buffer))) > 0) {
        write(fd_dst, buffer, bytes_read);
    }

    close(fd_src);
    close(fd_dst);

    printf("Backed up %s to %s\n", filename, dest_path);
    free(random_extension);
}

int main() {
    char *files[] = {"/etc/passwd", "/etc/group", "/home/user/documents/important.txt"};

    for (int i = 0; i < sizeof(files) / sizeof(char*); i++) {
        backup_file(files[i]);
    }

    printf("All files have been backed up with surprise!\n");

    return EXIT_SUCCESS;
}