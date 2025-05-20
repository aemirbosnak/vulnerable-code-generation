//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define DATA_SIZE 1024

void error(const char *msg){
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]){

    // Socket Variables
    int sockfd, n;
    char buffer[DATA_SIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Command line argument validation
    if(argc < 3){
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(1);
    }

    // Get server details
    server = gethostbyname(argv[1]);

    if(server == NULL){
        fprintf(stderr, "Error: no such host\n");
        exit(1);
    }

    // Set up the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0){
        error("Error: could not open socket");
    }

    // Set server address properties
    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    bcopy((char*) server->h_addr, (char*) &serv_addr.sin_addr.s_addr, server->h_length);

    // Connect to server
    if(connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0){
        error("Error: could not connect to server");
    }

    // Get user input
    printf("FTP client started...\n");

    while( 1 ){

        printf("ftp> ");
        bzero(buffer, DATA_SIZE);
        fgets(buffer, DATA_SIZE, stdin);

        if(strlen(buffer) <= 1){
            continue;
        }

        // Send command to server
        n = send(sockfd, buffer, strlen(buffer), 0);
        if(n < 0){
            error("Error: could not write to socket");
        }

        // Receive response from server
        bzero(buffer, DATA_SIZE);
        n = recv(sockfd, buffer, DATA_SIZE - 1, 0);
        if(n < 0){
            error("Error: could not read from socket");
        }

        printf("%s\n", buffer);

    }

    close(sockfd);

    return 0;
}