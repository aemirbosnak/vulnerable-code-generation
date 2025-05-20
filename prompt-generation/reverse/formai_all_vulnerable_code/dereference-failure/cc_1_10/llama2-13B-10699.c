//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_LEN 1024
#define BUFFER_SIZE 4096

struct log_entry {
    char timestamp[20];
    char ip_address[15];
    char request_method[10];
    char request_uri[100];
    char response_code[3];
    char response_reason[50];
};

int main() {
    // Open the log file
    FILE *log_file = fopen("access.log", "r");

    // Check if the file exists
    if (log_file == NULL) {
        perror("Error opening log file");
        return 1;
    }

    // Get the file size
    long file_size = ftell(log_file);

    // Calculate the memory needed to store the log
    size_t memory_needed = file_size * sizeof(struct log_entry);

    // Allocate memory for the log
    struct log_entry *log = mmap(NULL, memory_needed, PROT_READ, MAP_FILE | MAP_PRIVATE, -1, 0);

    // Check if the memory allocation failed
    if (log == MAP_FAILED) {
        perror("Error mapping the log file");
        return 2;
    }

    // Set the file pointer to the beginning of the file
    rewind(log_file);

    // Read the log entries
    while (read(fileno(log_file), log, BUFFER_SIZE) > 0) {
        // Parse the log entry
        char *timestamp = log->timestamp;
        char *ip_address = log->ip_address;
        char *request_method = log->request_method;
        char *request_uri = log->request_uri;
        char *response_code = log->response_code;
        char *response_reason = log->response_reason;

        // Print the log entry
        printf("[%s] [%s] %s %s %s %s\n", timestamp, ip_address, request_method, request_uri, response_code, response_reason);
    }

    // Unmap the memory
    munmap(log, memory_needed);

    // Close the log file
    fclose(log_file);

    return 0;
}