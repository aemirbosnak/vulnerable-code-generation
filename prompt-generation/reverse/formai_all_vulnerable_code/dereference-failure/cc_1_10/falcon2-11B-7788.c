//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[1024];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        sockfd = accept(sockfd, (struct sockaddr *) NULL, NULL);
        if (sockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        printf("Connected by %s\n", inet_ntoa(serv_addr.sin_addr));

        while ((n = read(sockfd, buffer, sizeof(buffer))) > 0) {
            buffer[n] = '\0';
            printf("Client said: %s\n", buffer);
        }
        printf("Disconnected\n");
        close(sockfd);
        break;
    }

    return 0;
}