//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: mathematical
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[1024];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[1]);

    if (portno < 1 || portno > 65535) {
        fprintf(stderr, "Invalid port number\n");
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(0);
    }

    listen(sockfd, 5);

    while (1) {
        socklen_t clilen = sizeof(struct sockaddr_in);
        int newsockfd = accept(sockfd, (struct sockaddr *)&serv_addr, &clilen);
        if (newsockfd < 0) {
            perror("accept failed");
            exit(0);
        }

        bzero(buffer, 1024);
        n = read(newsockfd, buffer, 1024);
        if (n < 0) {
            perror("read failed");
            exit(0);
        }
        buffer[n] = '\0';
        printf("Received data: %s\n", buffer);

        bzero(buffer, 1024);
        n = write(newsockfd, buffer, 1024);
        if (n < 0) {
            perror("write failed");
            exit(0);
        }

        close(newsockfd);
    }

    return 0;
}