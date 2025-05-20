//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MB (1024 * 1024)

int main() {
    int i;
    char *ptr;
    size_t total_allocated = 0;

    // Allocate memory in chunks of 1 MB
    for (i = 0; i < 100; i++) {
        ptr = malloc(MB);
        if (ptr == NULL) {
            fprintf(stderr, "Error: malloc() failed\n");
            exit(EXIT_FAILURE);
        }
        total_allocated += MB;
        printf("Allocated %lu MB of memory\n", total_allocated / MB);
    }

    // Sleep for 10 seconds to give the system time to adjust to the memory usage
    sleep(10);

    // Print the current RSS (resident set size) of the process
    long rss = 0;
    FILE *proc_file = fopen("/proc/self/status", "r");
    if (proc_file == NULL) {
        fprintf(stderr, "Error: fopen() failed\n");
        exit(EXIT_FAILURE);
    }
    char line[1024];
    while (fgets(line, sizeof(line), proc_file) != NULL) {
        if (sscanf(line, "VmRSS: %ld kB", &rss) == 1) {
            break;
        }
    }
    fclose(proc_file);
    printf("Current RSS: %ld kB\n", rss);

    // Free the allocated memory
    for (i = 0; i < 100; i++) {
        free(ptr);
        ptr = NULL;
        total_allocated -= MB;
        printf("Freed %lu MB of memory\n", total_allocated / MB);
    }

    return EXIT_SUCCESS;
}