//FormAI DATASET v1.0 Category: Port Scanner ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MIN_PORT 1
#define MAX_PORT 65535
#define RAND_PORT (MIN_PORT + rand() % (MAX_PORT - MIN_PORT + 1))

typedef struct {
    int start_port;
    int end_port;
    char *host;
} ScanParams;

void error_exit(const char *msg) {
    fprintf(stderr, "[ERROR] %s\n", msg);
    exit(EXIT_FAILURE);
}

void scan_port(int port, const char *host) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return;
    }

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) >= 0) {
        fprintf(stderr, "[INFO] Port %d is open", port);
    }

    close(sockfd);
}

void parse_args(int argc, char **argv, ScanParams *params) {
    if (argc < 2) {
         error_exit("Please provide a host to scan.");
    }

    params->host = argv[1];
    params->start_port = MIN_PORT;
    params->end_port = MAX_PORT;

    if (argc >= 3) {
        params->start_port = atoi(argv[2]);
        if (params->start_port < MIN_PORT || params->start_port > MAX_PORT) {
            error_exit("Invalid starting port");
        }
    }

    if (argc >= 4) {
        params->end_port = atoi(argv[3]);
        if (params->end_port < MIN_PORT || params->end_port > MAX_PORT) {
            error_exit("Invalid ending port");
        }
    }
}

void run_scan(const ScanParams *params) {
    printf("[INFO] Scanning host %s from port %d to %d...\n", params->host, params->start_port, params->end_port);
    for (int i = params->start_port; i <= params->end_port; i++) {
        printf("[INFO] Scanning port %d...\n", i);
        scan_port(i, params->host);

        // Romeo and Juliet references
        if (i == 139) {
            printf("%s: O Romeo, Romeo! Wherefore art thou Romeo?\n", params->host);
            printf("%s: Deny thy father and refuse thy name;\n", params->host);
        } else if (i == 445) {
            printf("%s: What's in a name? That which we call a rose\n", params->host);
            printf("%s: By any other name would smell as sweet;\n", params->host);
        }
    }
}

int main(int argc, char **argv) {
    srand(time(NULL)); // Randomize port when nothing is specified

    ScanParams params;
    parse_args(argc, argv, &params);

    run_scan(&params);

    return 0;
}