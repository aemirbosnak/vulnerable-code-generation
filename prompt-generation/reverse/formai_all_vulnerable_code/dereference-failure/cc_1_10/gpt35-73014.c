//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAXLINE 100

// Function to set up the client socket
int client_setup(char *host, int port) {
    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    inet_pton(AF_INET, host, &servaddr.sin_addr);

    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    return sockfd;
}

// Function to send request to the server and get response
void send_request(int sockfd, char *command, char *buffer) {
    write(sockfd, command, strlen(command));

    read(sockfd, buffer, MAXLINE);
}

int main(int argc, char **argv) {
    char *host = "localhost";
    int port = 8000;

    if(argc == 2) {
        host = argv[1];
    }
    else if(argc == 3) {
        host = argv[1];
        port = atoi(argv[2]);
    }

    int sockfd = client_setup(host, port);

    char buffer[MAXLINE];
    char command[MAXLINE];

    while(1) {
        printf("Enter a command: ");
        fgets(command, MAXLINE, stdin);

        if(strcmp(command, "exit\n") == 0) {
            close(sockfd);
            break;
        }

        send_request(sockfd, command, buffer);
        printf("%s", buffer);
    }

    return 0;
}