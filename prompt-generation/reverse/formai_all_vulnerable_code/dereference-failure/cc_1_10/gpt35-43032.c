//FormAI DATASET v1.0 Category: System administration ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    printf("Welcome to the Super Admin Program!\n");
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    char* filename = argv[1];
    printf("Opening file %s...\n", filename);
    int fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644);
    if (fd == -1) {
        printf("Error opening file!\n");
        exit(1);
    }
    printf("File opened successfully!\n");
    printf("What would you like to write to the file?\n");
    char buffer[1024];
    fgets(buffer, 1024, stdin);
    int length = strlen(buffer);
    if (write(fd, buffer, length) != length) {
        printf("Error writing to file!\n");
        close(fd);
        exit(1);
    }
    printf("Write successful!\n");
    printf("Would you like to read the file contents? (y/n)\n");
    char response = getchar();
    if (response == 'y') {
        printf("Reading file contents...\n");
        lseek(fd, 0, SEEK_SET);
        char* read_buffer = malloc(sizeof(char) * length);
        if (read(fd, read_buffer, length) != length) {
            printf("Error reading file!\n");
            close(fd);
            exit(1);
        }
        printf("%s\n", read_buffer);
        free(read_buffer);
    }
    printf("Closing file %s...\n", filename);
    close(fd);
    printf("Goodbye and thank you for using the Super Admin Program!\n");
    return 0;
}