//MISTRAL-7B DATASET v1.0 Category: System administration ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {

    // Check if the correct number of arguments are provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create the directory
    int ret = mkdir(argv[1], 0755);
    if (ret == -1) {
        perror("Error creating directory");
        exit(EXIT_FAILURE);
    }

    // Change the working directory to the newly created directory
    ret = chdir(argv[1]);
    if (ret == -1) {
        perror("Error changing directory");
        exit(EXIT_FAILURE);
    }

    // Copy config.txt file to the newly created directory
    char source_file[] = "config.txt";
    char destination_file[100];
    strcpy(destination_file, argv[1]);
    strcat(destination_file, "/config.txt");

    int fd_in = open(source_file, O_RDONLY);
    int fd_out = open(destination_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if (fd_in == -1 || fd_out == -1) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    ssize_t read_bytes;
    char buffer[1024];

    while ((read_bytes = read(fd_in, buffer, sizeof(buffer))) > 0) {
        write(fd_out, buffer, read_bytes);
    }

    close(fd_in);
    close(fd_out);

    // Print success message and the path to the newly created directory
    printf("Directory %s created and config.txt file copied successfully.\n", argv[1]);
    printf("New directory path: %s/\n", argv[1]);

    return EXIT_SUCCESS;
}