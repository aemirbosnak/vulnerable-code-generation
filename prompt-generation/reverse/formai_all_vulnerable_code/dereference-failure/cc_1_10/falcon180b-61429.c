//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serveraddr;
    int opt = 1;
    char recv_buffer[BUFFER_SIZE];
    int addrlen = sizeof(serveraddr);
    int i;

    if (argc!= 4) {
        printf("Usage: %s <hostname> <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: socket() failed with error %d\n", errno);
        return 1;
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        printf("Error: setsockopt() failed with error %d\n", errno);
        return 1;
    }

    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &serveraddr.sin_addr) <= 0) {
        printf("Error: inet_pton() failed\n");
        return 1;
    }

    for (i = atoi(argv[2]); i <= atoi(argv[3]); i++) {
        serveraddr.sin_port = htons(i);

        if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == 0) {
            printf("Port %d is open\n", i);
        } else if (errno!= ECONNREFUSED) {
            printf("Error: connect() failed with error %d\n", errno);
            return 1;
        }
    }

    close(sockfd);
    return 0;
}