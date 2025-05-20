//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 21
#define MAX_DATA_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    char buffer[MAX_DATA_SIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return 1;
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        return 1;
    }

    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        return 1;
    }

    printf("Connected to FTP server\n");

    while (1) {
        memset(buffer, 0, MAX_DATA_SIZE);
        printf("> ");
        fgets(buffer, MAX_DATA_SIZE, stdin);

        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0) {
            perror("ERROR writing to socket");
            return 1;
        }

        memset(buffer, 0, MAX_DATA_SIZE);
        n = read(sockfd, buffer, MAX_DATA_SIZE);
        if (n < 0) {
            perror("ERROR reading from socket");
            return 1;
        }

        printf("%s", buffer);

        if (strcmp(buffer, "221 Goodbye\n") == 0) {
            break;
        }
    }

    close(sockfd);

    return 0;
}