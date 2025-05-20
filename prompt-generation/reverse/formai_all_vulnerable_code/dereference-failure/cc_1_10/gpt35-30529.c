//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char** argv) {

    if (argc != 3) {
        printf("Usage: ./ftpclient hostname port\n");
        exit(1);
    }

    char* hostname = argv[1];
    int port = atoi(argv[2]);

    printf("Connecting to %s:%d...\n", hostname, port);

    // create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // get host information
    struct hostent* server = gethostbyname(hostname);
    if (!server) {
        fprintf(stderr, "No such host: %s\n", hostname);
        exit(1);
    }

    // set up server address struct
    struct sockaddr_in serveraddr;
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy(server->h_addr, &(serveraddr.sin_addr.s_addr), server->h_length);
    serveraddr.sin_port = htons(port);

    // connect to server
    if (connect(sockfd, (struct sockaddr*) &serveraddr, sizeof(serveraddr)) < 0) {
        perror("connect");
        exit(1);
    }

    // print welcome message from server
    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // enter main loop
    while (1) {
        // get command from user
        bzero(buffer, BUFFER_SIZE);
        printf("ftp> ");
        fgets(buffer, BUFFER_SIZE, stdin);
        strtok(buffer, "\n"); // remove newline character

        // send command to server
        if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
            perror("send");
            continue;
        }

        // exit loop if user types "quit"
        if (strcmp(buffer, "quit") == 0) {
            break;
        }

        // print response from server
        bzero(buffer, BUFFER_SIZE);
        recv(sockfd, buffer, BUFFER_SIZE, 0);
        printf("%s", buffer);
    }

    // close socket
    close(sockfd);

    return 0;
}