//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAX_BUFFER 1024

// Function to send a command to the server
int sendCommand(int sockfd, char* command) {
    char buffer[MAX_BUFFER];
    snprintf(buffer, sizeof(buffer), "%s\r\n", command);

    return send(sockfd, buffer, strlen(buffer), 0);
}

// Function to receive a response from the server
int receiveResponse(int sockfd) {
    char buffer[MAX_BUFFER];
    int nbytes = recv(sockfd, buffer, sizeof(buffer), 0);

    printf("%s", buffer);

    if (nbytes < 0) {
        perror("read error");
        exit(1);
    }

    return nbytes;
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAX_BUFFER];

    if (argc < 3) {
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("error opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr, "error, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;

    bcopy((char *) server -> h_addr,
        (char *) &serv_addr.sin_addr.s_addr,
            server -> h_length);

    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("error connecting");
        exit(1);
    }

    printf("Connected to POP3 server.\n");

    receiveResponse(sockfd);

    sendCommand(sockfd, "USER myusername");
    receiveResponse(sockfd);

    sendCommand(sockfd, "PASS mypassword");
    receiveResponse(sockfd);

    sendCommand(sockfd, "STAT");
    receiveResponse(sockfd);

    sendCommand(sockfd, "LIST");
    receiveResponse(sockfd);

    sendCommand(sockfd, "RETR 1");
    receiveResponse(sockfd);

    sendCommand(sockfd, "QUIT");
    receiveResponse(sockfd);

    printf("Connection closed.\n");

    close(sockfd);

    return 0;
}