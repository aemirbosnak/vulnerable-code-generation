//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Function to connect to POP3 server
int connectToPOP3(char* hostname, int port) {
    int sockfd = -1;
    struct hostent *server;
    struct sockaddr_in serveraddr;

    if ((server = gethostbyname(hostname)) == NULL) {
        fprintf(stderr, "ERROR: hostname not found\n");
        return -1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "ERROR opening socket\n");
        return -1;
    }

    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    serveraddr.sin_addr = *((struct in_addr *)server->h_addr);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        fprintf(stderr, "ERROR connecting to server\n");
        return -1;
    }

    return sockfd;
}

// Function to send POP3 command to the server
int sendPOP3Command(int sockfd, char* command) {
    int bytesWritten;
    bytesWritten = write(sockfd, command, strlen(command));
    if (bytesWritten < 0) {
        fprintf(stderr, "ERROR writing to socket\n");
        return -1;
    }

    return bytesWritten;
}

// Function to receive POP3 response from the server
int receivePOP3Response(int sockfd, char* response) {
    int bytesRead;
    bytesRead = read(sockfd, response, sizeof(response));
    if (bytesRead < 0) {
        fprintf(stderr, "ERROR reading from socket\n");
        return -1;
    }

    return bytesRead;
}

// Function to get POP3 status
int getPOP3Status(char* response) {
    int status = 0;
    int i;
    for (i = 0; i < strlen(response); i++) {
        if (response[i] == '+' && response[i+1] == '+') {
            status = 1;
            break;
        }
    }
    return status;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    int sockfd = connectToPOP3(argv[1], atoi(argv[2]));
    if (sockfd < 0) {
        return 1;
    }

    char command[100];
    sprintf(command, "USER %s\r\n", "username");
    sendPOP3Command(sockfd, command);

    char response[100];
    receivePOP3Response(sockfd, response);
    int status = getPOP3Status(response);

    if (status == 1) {
        fprintf(stdout, "POP3 authentication successful\n");
    } else {
        fprintf(stderr, "POP3 authentication failed\n");
    }

    sprintf(command, "QUIT\r\n");
    sendPOP3Command(sockfd, command);

    close(sockfd);
    return 0;
}