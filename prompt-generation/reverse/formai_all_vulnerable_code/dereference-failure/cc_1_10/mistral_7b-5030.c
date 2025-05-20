//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

#define LOG_FILE "/var/log/access.log"
#define BUF_SIZE 4096
#define HEADER_SIZE 81
#define CLIENT_ADDR_SIZE 17
#define MAX_CLIENTS 1024
#define REQUEST_SIZE 2048
#define SEPARATOR " - "

typedef struct {
    char client_addr[CLIENT_ADDR_SIZE];
    char request[REQUEST_SIZE];
} log_entry;

int main(void) {
    int i, fd, rc, num_entries;
    char *log_data;
    log_entry *entries;

    fd = open(LOG_FILE, O_RDONLY);
    if (fd < 0) {
        perror("Failed to open log file");
        exit(EXIT_FAILURE);
    }

    struct stat file_stat;
    fstat(fd, &file_stat);
    log_data = mmap(NULL, file_stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    close(fd);

    if (log_data == MAP_FAILED) {
        perror("Failed to map log file to memory");
        exit(EXIT_FAILURE);
    }

    num_entries = file_stat.st_size / (HEADER_SIZE + BUF_SIZE);
    entries = calloc(num_entries, sizeof(log_entry));

    for (i = 0; i < num_entries; i++) {
        memcpy(entries[i].client_addr, log_data + (i * (HEADER_SIZE + BUF_SIZE)) + HEADER_SIZE, CLIENT_ADDR_SIZE);
        char *request_start = log_data + (i * (HEADER_SIZE + BUF_SIZE)) + HEADER_SIZE + CLIENT_ADDR_SIZE;
        char *request_end = request_start;
        while (*request_end != '\n' && request_end < log_data + file_stat.st_size) {
            request_end++;
        }
        memcpy(entries[i].request, request_start, request_end - request_start);
        entries[i].request[request_end - request_start] = '\0';
    }

    for (i = 0; i < MAX_CLIENTS && i < num_entries; i++) {
        printf("Client %s requested %s\n", entries[i].client_addr, entries[i].request);
        if (strstr(entries[i].request, SEPARATOR) != NULL) {
            char *method = strtok(entries[i].request, SEPARATOR);
            char *resource = strtok(NULL, SEPARATOR);
            if (strcmp(method, "GET") == 0) {
                printf("Resource %s requested using GET method\n", resource);
            }
        }
    }

    munmap(log_data, file_stat.st_size);
    free(entries);

    return EXIT_SUCCESS;
}