//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HOST_LENGTH 256
#define BUFFER_SIZE 512

void print_usage() {
    printf("Usage: ./ping_test <host> <number_of_attempts>\n");
    printf("Example: ./ping_test google.com 4\n");
}

int is_valid_host(const char *host) {
    if (strlen(host) == 0 || strlen(host) > MAX_HOST_LENGTH) {
        return 0;
    }
    return 1;
}

void execute_ping(const char *host, int attempts) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "ping -c %d %s", attempts, host);
    printf("Executing command: %s\n", command);
    int result = system(command);
    
    if (result == -1) {
        perror("Error executing ping command");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *host = argv[1];
    int attempts = atoi(argv[2]);

    if (!is_valid_host(host)) {
        print_usage();
        fprintf(stderr, "Error: Invalid host name\n");
        return EXIT_FAILURE;
    }

    if (attempts <= 0) {
        print_usage();
        fprintf(stderr, "Error: Number of attempts must be greater than 0\n");
        return EXIT_FAILURE;
    }

    printf("Pinging host: %s for %d attempts...\n", host, attempts);
    execute_ping(host, attempts);

    return EXIT_SUCCESS;
}