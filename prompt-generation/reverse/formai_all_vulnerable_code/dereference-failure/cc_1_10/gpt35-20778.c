//FormAI DATASET v1.0 Category: Port Scanner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

void scan_ports(char *hostname, int start_port, int end_port);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <hostname> <start_port> <end_port>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    printf("Scanning ports %d to %d on %s...\n", start_port, end_port, hostname);

    scan_ports(hostname, start_port, end_port);

    return 0;
}

void scan_ports(char *hostname, int start_port, int end_port) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    server = gethostbyname(hostname);

    if (server == NULL) {
        printf("Error: No such host found\n");
        exit(1);
    }

    for (portno = start_port; portno <= end_port; portno++) {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);

        if (sockfd < 0) {
            perror("Error opening socket");
            exit(1);
        }

        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(portno);
        serv_addr.sin_addr.s_addr = inet_addr(inet_ntoa(*((struct in_addr*)server->h_addr)));

        if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == 0) {
            printf("Port %d - OPEN\n", portno);
        }

        close(sockfd);
    }
}