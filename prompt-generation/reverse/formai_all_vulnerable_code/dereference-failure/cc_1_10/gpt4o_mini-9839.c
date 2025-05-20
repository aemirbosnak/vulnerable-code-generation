//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>

#define MAX_PINGS 10
#define BUFFER_SIZE 1024

void print_usage(char *program_name) {
    printf("Usage: %s <hostname> <pings>\n", program_name);
    printf("hostname: The host to ping (e.g., google.com)\n");
    printf("pings: The maximum number of ping attempts (default: 10)\n");
}

void handle_sigint(int sig) {
    printf("\nCaught interrupt signal. Exiting...\n");
    exit(0);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage(argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    int max_pings = (argc > 2) ? atoi(argv[2]) : MAX_PINGS;
    
    if (max_pings <= 0 || max_pings > MAX_PINGS) {
        printf("Please specify a valid number of pings (1 to %d).\n", MAX_PINGS);
        return 1;
    }

    signal(SIGINT, handle_sigint);

    char command[BUFFER_SIZE];
    int successes = 0;
    int failures = 0;

    printf("\nPinging %s for a maximum of %d times...\n", hostname, max_pings);

    for (int i = 0; i < max_pings; i++) {
        snprintf(command, sizeof(command), "ping -c 1 -W 1 %s | grep 'time='", hostname);

        FILE *ping = popen(command, "r");
        if (ping == NULL) {
            perror("Failed to run ping command");
            return 1;
        }

        char result[BUFFER_SIZE];
        if (fgets(result, sizeof(result), ping) != NULL) {
            printf("%s", result);
            successes++;
        } else {
            printf("Ping to %s failed (Timeout or unreachable)\n", hostname);
            failures++;
        }

        pclose(ping);
        sleep(1);  // Wait a second before the next ping
    }

    printf("\n--- %s Ping Statistics ---\n", hostname);
    printf("%d packets transmitted, %d received, %d%% packet loss\n",
           successes + failures, successes, 
           (failures * 100) / (successes + failures));

    return 0;
}