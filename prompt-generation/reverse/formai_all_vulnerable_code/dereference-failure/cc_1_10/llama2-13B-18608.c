//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define MAX_LOG_SIZE 1024 * 1024 * 10

struct log_entry {
    char timestamp[20];
    char client_ip[15];
    char request_method[10];
    char request_url[100];
    int response_code;
    char response_reason[100];
};

int main(void) {
    // Open the log file
    int fd = open("access.log", O_RDONLY);
    if (fd == -1) {
        perror("Error opening log file");
        return 1;
    }

    // Get the log file size
    struct stat stat;
    if (fstat(fd, &stat) == -1) {
        perror("Error stat'ing log file");
        close(fd);
        return 1;
    }

    // Check if the log file is too large
    if (stat.st_size > MAX_LOG_SIZE) {
        printf("Log file is too large (%zu bytes)\n", stat.st_size);
        close(fd);
        return 1;
    }

    // Mmap the log file
    char *log_buffer = mmap(NULL, stat.st_size, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
    if (log_buffer == MAP_FAILED) {
        perror("Error mmapping log file");
        close(fd);
        return 1;
    }

    // Parse the log entries
    char *ptr = log_buffer;
    char *end = log_buffer + stat.st_size;
    while (ptr < end) {
        // Get the timestamp
        char *timestamp = ptr;
        ptr += strcspn(ptr, "\n");

        // Get the client IP
        char *client_ip = ptr;
        ptr += strcspn(ptr, "\n");

        // Get the request method and URL
        char *request_method = ptr;
        char *request_url = ptr;
        ptr += strcspn(ptr, "\n");

        // Get the response code and reason
        int response_code = atoi(ptr);
        char *response_reason = ptr + 1;
        ptr += strcspn(ptr, "\n");

        // Print the log entry
        printf("[%s] %s %s %s %d %s\n", timestamp, client_ip, request_method, request_url, response_code, response_reason);
    }

    // Unmap the log file
    munmap(log_buffer, stat.st_size);

    return 0;
}