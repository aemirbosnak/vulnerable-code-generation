//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFFER_SIZE];
    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"Error, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    printf("Connected to FTP Server.\n");
    while(1) {
        bzero(buffer, BUFFER_SIZE);
        printf("Enter FTP command: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        strtok(buffer, "\n");

        n = send(sockfd, buffer, strlen(buffer), 0);
        if (n < 0) {
            perror("Error writing to socket");
            exit(1);
        }

        bzero(buffer, BUFFER_SIZE);
        n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
        if (n < 0) {
            perror("Error reading from socket");
            exit(1);
        }

        printf("%s\n", buffer);
        if(strcmp(buffer, "GOODBYE") == 0) {
            break;
        }
    }

    close(sockfd);
    return 0;
}