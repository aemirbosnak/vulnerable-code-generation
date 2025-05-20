//FormAI DATASET v1.0 Category: Port Scanner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    printf("Scanning ports on %s\n", hostname);

    struct hostent *host = gethostbyname(hostname);

    if (host == NULL) {
        printf("Could not resolve hostname\n");
        exit(1);
    }

    int socketfd = socket(AF_INET, SOCK_STREAM, 0);

    if (socketfd < 0) {
        printf("Could not create socket\n");
        exit(1);
    }

    struct sockaddr_in server_address;
    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *) host->h_addr, (char *) &server_address.sin_addr.s_addr, host->h_length);
    server_address.sin_port = htons(port);

    int connection_status = connect(socketfd, (struct sockaddr *) &server_address, sizeof(server_address));

    if (connection_status < 0) {
        printf("Port %d: Closed\n", port);
    } else {
        printf("Port %d: Open\n", port);
        close(socketfd);
    }

    return 0;
}