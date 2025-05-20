//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <time.h>

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in serverAddr;
    struct hostent *server;
    struct sockaddr_in fromAddr;
    int fromLen = sizeof(fromAddr);
    char *line = NULL;
    size_t len = 0;
    ssize_t readLen;
    int numMessages = 0;
    int i = 0;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s server-name\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Unknown host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(110);
    memcpy((char*)serverAddr.sin_addr.s_addr, (char*)server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Connection failed");
        exit(1);
    }

    printf("Connected to %s\n", argv[1]);

    while (1) {
        readLen = recv(sockfd, &line, sizeof(line), 0);
        if (readLen < 0) {
            perror("recv failed");
            exit(1);
        }

        if (readLen == 0) {
            break;
        }

        printf("%s", line);

        free(line);
        line = NULL;
    }

    close(sockfd);
    return 0;
}