//Falcon2-11B DATASET v1.0 Category: Browser Plugin ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Function to check if the port is open or not
int check_port(int port) {
    struct sockaddr_in server;
    int sockfd, valread;
    socklen_t len;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket creation error");
        return -1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;

    len = sizeof(server);

    if (connect(sockfd, (struct sockaddr *) &server, len) < 0) {
        perror("Connection error");
        return -1;
    }

    if (read(sockfd, &valread, sizeof(valread)) == sizeof(valread)) {
        printf("Port %d is open\n", port);
        return 0;
    } else {
        printf("Port %d is not open\n", port);
        return -1;
    }

    close(sockfd);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s port\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    if (check_port(port) == 0) {
        printf("Port %d is open\n", port);
    } else {
        printf("Port %d is not open\n", port);
    }

    return 0;
}