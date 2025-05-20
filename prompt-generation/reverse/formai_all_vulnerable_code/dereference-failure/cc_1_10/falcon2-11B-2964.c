//Falcon2-11B DATASET v1.0 Category: Network Packet Monitoring ; Style: single-threaded
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

int main() {
    int sockfd, len, n;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "gethostbyname() failed\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(5000);

    while (1) {
        len = sizeof(cli_addr);
        n = recvfrom(sockfd, &len, 1, 0, (struct sockaddr *) &cli_addr, &len);

        if (n == -1) {
            perror("recvfrom failed");
            exit(1);
        }

        printf("Received message from %s:%d:\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
        printf("Message length: %d\n", len);
        printf("Message data: ");
        for (int i = 0; i < len; i++) {
            printf("%02X", (unsigned char) ntohs(*(unsigned char *) &len));
        }
        printf("\n");
    }

    return 0;
}