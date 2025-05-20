//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUF_SIZE 1024

/* Simple UDP client that sends a message to the given IP/Port */

int main(int argc, char* argv[]) {
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;
    char buf[BUF_SIZE];
    int PORT;
    char* IP;

    if (argc != 3) {
        printf("Usage: %s <IP_Address> <Port_Number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    IP = argv[1];
    PORT = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd < 0) {
        perror("Unable to create socket");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));
    memset(buf, 0, sizeof(buf));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr(IP);

    printf("Enter message: ");
    fgets(buf, BUF_SIZE, stdin);

    int len = strlen(buf);
    if (buf[len - 1] == '\n') {
        buf[len - 1] = '\0';
    }

    if (sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        perror("UDP sendto error");
        exit(EXIT_FAILURE);
    }

    printf("Message sent.\n");

    close(sockfd);

    return 0;
}