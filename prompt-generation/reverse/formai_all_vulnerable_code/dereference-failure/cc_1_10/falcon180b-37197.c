//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char* argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent* server;
    char buffer[1024];
    int n;

    if (argc < 3) {
        printf("Usage: %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("No such host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Socket creation failed\n");
        exit(1);
    }

    bzero((char*)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char*)server->h_addr, (char*)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection failed\n");
        exit(1);
    }

    while (1) {
        n = read(sockfd, buffer, sizeof(buffer));
        if (n < 0) {
            printf("Read failed\n");
            exit(1);
        }
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    return 0;
}