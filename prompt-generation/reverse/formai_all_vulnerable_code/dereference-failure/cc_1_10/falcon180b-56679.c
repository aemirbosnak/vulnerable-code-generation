//Falcon-180B DATASET v1.0 Category: File handling ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1024

void paranoid_error_handling(const char* function_name, int line_number) {
    if (errno!= 0) {
        fprintf(stderr, "Error in %s at line %d: %s\n", function_name, line_number, strerror(errno));
        exit(EXIT_FAILURE);
    }
}

int main() {
    char filename[MAX_LINE_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    int fd = open(filename, O_RDONLY);
    paranoid_error_handling(__FUNCTION__, __LINE__);

    struct stat file_stats;
    fstat(fd, &file_stats);
    paranoid_error_handling(__FUNCTION__, __LINE__);

    if (!S_ISREG(file_stats.st_mode)) {
        fprintf(stderr, "Error: %s is not a regular file.\n", filename);
        exit(EXIT_FAILURE);
    }

    char* file_content = malloc(file_stats.st_size + 1);
    paranoid_error_handling(__FUNCTION__, __LINE__);

    int bytes_read = read(fd, file_content, file_stats.st_size);
    paranoid_error_handling(__FUNCTION__, __LINE__);

    file_content[bytes_read] = '\0';

    int line_number = 1;
    char* line = strtok(file_content, "\n");
    while (line!= NULL) {
        int word_count = 0;
        char* word = strtok(line, " ");
        while (word!= NULL) {
            if (isalpha(word[0])) {
                word_count++;
            }
            word = strtok(NULL, " ");
        }
        if (word_count == 0) {
            fprintf(stderr, "Error: Line %d is empty or contains only non-alphabetic characters.\n", line_number);
            exit(EXIT_FAILURE);
        }
        line_number++;
        line = strtok(NULL, "\n");
    }

    free(file_content);
    paranoid_error_handling(__FUNCTION__, __LINE__);

    close(fd);
    paranoid_error_handling(__FUNCTION__, __LINE__);

    printf("File %s contains %d lines.\n", filename, line_number - 1);

    return 0;
}