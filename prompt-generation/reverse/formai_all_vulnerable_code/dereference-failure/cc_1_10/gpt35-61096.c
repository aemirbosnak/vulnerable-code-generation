//FormAI DATASET v1.0 Category: Port Scanner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void usage(char *program_name) {
    printf("Usage: %s <target_ip> <start_port> <end_port>\n", program_name);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        usage(argv[0]);
        return 1;
    }

    char *target_ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    printf("Scanning ports %d to %d on %s\n", start_port, end_port, target_ip);

    struct hostent *host;
    host = gethostbyname(target_ip);

    if (host == NULL) {
        printf("Error resolving hostname.\n");
        return 1;
    }

    struct sockaddr_in target_address;
    target_address.sin_family = AF_INET;
    target_address.sin_addr = *((struct in_addr *) host->h_addr);

    int socket_desc, port;
    struct timeval tv;
    tv.tv_sec = 3;
    tv.tv_usec = 0;

    for (port = start_port; port <= end_port; port++) {
        target_address.sin_port = htons(port);

        socket_desc = socket(AF_INET, SOCK_STREAM, 0);
        if (socket_desc == -1) {
            printf("Error creating socket.\n");
            return 1;
        }

        setsockopt(socket_desc, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(struct timeval));

        if (connect(socket_desc, (struct sockaddr *) &target_address, sizeof(target_address)) == 0) {
            printf("Port %d open.\n", port);
        }

        close(socket_desc);
    }

    return 0;
}