//Falcon2-11B DATASET v1.0 Category: Network Packet Monitoring ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);
    if (portno <= 0 || portno >= 65536) {
        fprintf(stderr, "Invalid port number\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
    if (sockfd < 0) {
        fprintf(stderr, "Failed to create socket\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Failed to bind socket\n");
        exit(1);
    }

    while (1) {
        n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&cli_addr, (socklen_t *)&n);
        if (n <= 0) {
            fprintf(stderr, "Failed to receive packet\n");
            exit(1);
        }

        printf("Source Address: %s\n", inet_ntoa(cli_addr.sin_addr));
        printf("Destination Address: %s\n", inet_ntoa(serv_addr.sin_addr));
        printf("Protocol: %d\n", ntohs(cli_addr.sin_port));
        printf("Payload:\n%s\n", buffer);
    }

    close(sockfd);
    return 0;
}