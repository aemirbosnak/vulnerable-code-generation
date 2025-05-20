//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <math.h>

#define LOG_FILE "/var/log/messages"
#define LOG_SIZE 1024000
#define LOG_SEARCH "ERROR"

int main() {
    // Open the log file
    int fd = open(LOG_FILE, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    // Get the size of the log file
    struct stat st;
    if (fstat(fd, &st) == -1) {
        perror("fstat");
        return EXIT_FAILURE;
    }

    // Memory-map the log file
    char *log = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (log == MAP_FAILED) {
        perror("mmap");
        return EXIT_FAILURE;
    }

    // Search the log file for the search string
    char *found = strstr(log, LOG_SEARCH);
    if (found == NULL) {
        printf("No errors found in log file.\n");
        return EXIT_SUCCESS;
    }

    // Get the timestamp of the error
    time_t timestamp = (time_t)atoi(found - 20);
    struct tm *tm = localtime(&timestamp);

    // Print the error message
    printf("Error found in log file:\n");
    printf("Timestamp: %s", asctime(tm));
    printf("Error message: %s\n", found);

    // Unmap the log file
    if (munmap(log, st.st_size) == -1) {
        perror("munmap");
        return EXIT_FAILURE;
    }

    // Close the log file
    if (close(fd) == -1) {
        perror("close");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}