//FormAI DATASET v1.0 Category: Port Scanner ; Style: imaginative
// Welcome to the Pirate Port Scanner!
// Arrrr you ready to scan some ports, matey?
// Let's hoist the anchor and set sail on this code adventure!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MIN_PORT 1
#define MAX_PORT 65535

void print_usage(char *program_name) {
    printf("Usage: %s <target_ip> [-p <port_range>]\n", program_name);
    printf("Example: %s 127.0.0.1 -p 1-1000\n", program_name);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage(argv[0]);
        return 1;
    }

    char* target_ip = argv[1];
    int min_port = MIN_PORT;
    int max_port = MAX_PORT;

    // parse arguments and set port range if specified
    if (argc == 4) {
        if (strcmp(argv[2], "-p") != 0) {
            print_usage(argv[0]);
            return 1;
        }

        char* port_range_str = argv[3];
        char* dash_pos = strchr(port_range_str, '-');

        if (dash_pos == NULL) {
            print_usage(argv[0]);
            return 1;
        }

        *dash_pos = '\0';
        min_port = atoi(port_range_str);
        max_port = atoi(dash_pos + 1);
    }

    printf("Scanning ports %d-%d on %s...\n", min_port, max_port, target_ip);

    // create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket");
        return 1;
    }

    // prepare target address
    struct sockaddr_in target_addr;
    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr(target_ip);

    // scan ports
    for (int port = min_port; port <= max_port; port++) {
        target_addr.sin_port = htons(port);
        if (connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr)) == 0) {
            printf("Port %d is open\n", port);
        }
    }

    close(sockfd);

    printf("Scan complete!\n");

    return 0;
}