//FormAI DATASET v1.0 Category: Text processing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 100

// Define a struct to store each file descriptor and the associated buffer and read status
typedef struct {
    int fd;
    char buffer[MAX_LINE_LENGTH];
    bool read_done;
} FileData;

// Define a function to check if a character is a whitespace
bool is_whitespace(char c) {
    return isspace(c) || c == '\0';
}

// Define a function to split a string into tokens
int split_line_into_tokens(char* line, char** tokens) {
    int num_tokens = 0;
    char* token = strtok(line, " ");
    while (token != NULL) {
        tokens[num_tokens] = token;
        num_tokens++;
        token = strtok(NULL, " ");
    }
    return num_tokens;
}

// Define a function to read a file asynchronously
void read_file_async(FileData* file_data) {
    ssize_t num_bytes = read(file_data->fd, file_data->buffer, MAX_LINE_LENGTH);
    file_data->buffer[num_bytes] = '\0';
    if (num_bytes > 0) {
        file_data->read_done = false;
    } else {
        file_data->read_done = true;
        close(file_data->fd);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename1> <filename2> ...\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create an array of FileData structs for each file descriptor and buffer
    FileData* file_datas = malloc(argc * sizeof(FileData));
    for (int i = 1; i < argc; i++) {
        int fd = open(argv[i], O_RDONLY);
        if (fd == -1) {
            fprintf(stderr, "Error: could not open file %s\n", argv[i]);
            exit(EXIT_FAILURE);
        }
        file_datas[i].fd = fd;
        file_datas[i].read_done = false;
    }

    while (true) {
        // Read from each file asynchronously and check if all reads are done
        bool all_reads_done = true;
        for (int i = 1; i < argc; i++) {
            if (!file_datas[i].read_done) {
                read_file_async(&file_datas[i]);
                all_reads_done = false;
            }
        }
        if (all_reads_done) {
            break;
        }

        // Process each file line by line
        for (int i = 1; i < argc; i++) {
            if (file_datas[i].read_done) {
                continue;
            }

            char* line_start = file_datas[i].buffer;
            char* line_end = strchr(file_datas[i].buffer, '\n');
            if (line_end == NULL) {
                continue;
            }
            *line_end = '\0';

            char* tokens[MAX_TOKENS];
            int num_tokens = split_line_into_tokens(line_start, tokens);

            for (int j = 0; j < num_tokens; j++) {
                printf("%s ", tokens[j]);
            }
            printf("\n");

            memmove(file_datas[i].buffer, line_end + 1, strlen(line_end + 1) + 1);
        }
    }

    free(file_datas);
    return 0;
}