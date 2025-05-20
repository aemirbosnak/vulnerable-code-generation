//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LINE_SIZE 1024
#define MAX_FILE_SIZE (1024*1024*10) // 10MB
#define MAX_PATH_SIZE 4096

typedef struct {
    char path[MAX_PATH_SIZE];
    int fd;
    int total_bytes;
    int bytes_read;
} file_t;

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        exit(1);
    }

    file_t log_file = {0};
    strncpy(log_file.path, argv[1], MAX_PATH_SIZE);

    log_file.fd = open(log_file.path, O_RDONLY);
    if (log_file.fd == -1) {
        printf("Error opening log file: %s\n", strerror(errno));
        exit(1);
    }

    char line[MAX_LINE_SIZE] = {0};
    int total_lines = 0;
    int max_line_size = 0;

    while (fgets(line, MAX_LINE_SIZE, log_file.fd)!= NULL) {
        total_lines++;
        int line_size = strlen(line);
        if (line_size > max_line_size) {
            max_line_size = line_size;
        }
    }

    rewind(log_file.fd);

    int num_lines_read = 0;

    while (fgets(line, MAX_LINE_SIZE, log_file.fd)!= NULL) {
        num_lines_read++;
        if (num_lines_read >= total_lines - 10) { // read last 10 lines
            printf("%s", line);
        }
    }

    close(log_file.fd);
    return 0;
}