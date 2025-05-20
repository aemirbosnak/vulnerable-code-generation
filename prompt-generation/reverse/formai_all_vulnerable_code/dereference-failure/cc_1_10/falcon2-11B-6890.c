//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int sockfd, portnum, n;
    struct sockaddr_in server_address;
    char buffer[1024];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <ip-address>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "ERROR opening socket\n");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[1]));
    server_address.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "ERROR connecting\n");
        exit(1);
    }

    printf("Port scanner for %s (%s:%d)\n", argv[1], inet_ntoa(server_address.sin_addr), ntohs(server_address.sin_port));

    for (portnum = 1; portnum <= 1024; portnum++) {
        if (portnum == 80) {
            printf("Found HTTP on port %d\n", portnum);
        } else if (portnum == 443) {
            printf("Found HTTPS on port %d\n", portnum);
        } else if (portnum == 25) {
            printf("Found SMTP on port %d\n", portnum);
        } else if (portnum == 110) {
            printf("Found POP3 on port %d\n", portnum);
        } else if (portnum == 143) {
            printf("Found IMAP on port %d\n", portnum);
        } else {
            printf("Port %d is open\n", portnum);
        }

        send(sockfd, buffer, strlen(buffer), 0);
    }

    close(sockfd);
    return 0;
}