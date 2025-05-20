//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

void scanPort(int port) {
    struct sockaddr_in serv_addr;
    int sockfd, n;
    char buffer[256];
    char host[NI_MAXHOST];
    struct hostent *hostInfo;

    hostInfo = gethostbyname("127.0.0.1");
    if (hostInfo == NULL) {
        printf("ERROR: Unknown host.\n");
        exit(1);
    }

    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)hostInfo->h_addr, hostInfo->h_length);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    if (send(sockfd, "GET / HTTP/1.1\r\n\r\n", 41, 0) < 0) {
        perror("ERROR sending request");
        exit(1);
    }

    if ((n = recv(sockfd, buffer, 256, 0)) < 0) {
        perror("ERROR receiving response");
        exit(1);
    }

    if (n > 0) {
        printf("Port %d is open.\n", port);
    } else {
        printf("Port %d is closed.\n", port);
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: port_scanner <IP Address> <Port>\n");
        exit(1);
    }

    int port = atoi(argv[2]);
    scanPort(port);

    return 0;
}