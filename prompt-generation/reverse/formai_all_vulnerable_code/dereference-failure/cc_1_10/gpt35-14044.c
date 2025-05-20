//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];

    if (argc < 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Connected to server at %s:%d\n", argv[1], portno);

    while(1) {
        printf("Enter message: ");
        bzero(buffer,BUFFER_SIZE);
        fgets(buffer,255,stdin);

        n = write(sockfd, buffer, strlen(buffer));

        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }

        bzero(buffer,BUFFER_SIZE);

        n = read(sockfd, buffer, BUFFER_SIZE);

        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        printf("QoS report: %s\n",buffer);
    }

    close(sockfd);
    return 0;
}