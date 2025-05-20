//MISTRAL-7B DATASET v1.0 Category: Data recovery tool ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10) // 10MB
#define BUFFER_SIZE 4096

typedef struct {
    char name[256];
    off_t start;
    off_t length;
} FileFragment;

void print_usage() {
    printf("Usage: ExcitingDataRecoveryTool <corrupted_file> <output_prefix>\n");
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
    }

    char *input_file = argv[1];
    char *output_prefix = argv[2];

    int fd_input = open(input_file, O_RDONLY);
    if (fd_input < 0) {
        perror("Error opening input file");
        exit(1);
    }

    struct stat file_stat;
    fstat(fd_input, &file_stat);

    if (file_stat.st_size > MAX_FILE_SIZE) {
        printf("Input file size is too large!\n");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    off_t current_position = 0;
    FileFragment fragments[file_stat.st_size / BUFFER_SIZE + 1];
    int num_fragments = 0;

    while (read(fd_input, buffer, BUFFER_SIZE) > 0) {
        strcpy(fragments[num_fragments].name, output_prefix);
        strcat(fragments[num_fragments].name, ".frag");
        fragments[num_fragments].start = current_position;
        fragments[num_fragments].length = strlen(buffer);
        write(STDOUT_FILENO, buffer, strlen(buffer)); // Print fragment to console for debugging purposes
        current_position += strlen(buffer);
        num_fragments++;
    }

    close(fd_input);

    fd_input = open("output.index", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd_input < 0) {
        perror("Error creating output index file");
        exit(1);
    }

    for (int i = 0; i < num_fragments; i++) {
        write(fd_input, &fragments[i], sizeof(FileFragment));
    }

    close(fd_input);

    printf("Data recovery successful! Fragments saved to output_prefix.frag\n");

    return 0;
}