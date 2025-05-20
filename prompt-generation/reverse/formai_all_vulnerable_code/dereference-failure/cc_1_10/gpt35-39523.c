//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

// Function to handle any errors
void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {

    // Checking if we have enough arguments
    if (argc < 4) {
        fprintf(stderr,"Usage: %s hostname port_number message\n", argv[0]);
        exit(1);
    }

    // Setting up the socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    // Setting up the address struct
    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // Connecting to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    // Preparing the message
    char message[1024];
    memset(message, 0, 1024);
    sprintf(message, "MAIL FROM:<%s>\r\n", argv[3]);

    // Sending the message
    if (send(sockfd,message,strlen(message), 0) < 0)
        error("ERROR sending message");

    // Receiving the response from the server
    char buffer[1024];
    memset(buffer, 0, 1024);
    int n = recv(sockfd, buffer, 1024, 0);
    if (n < 0)
        error("ERROR receiving message");

    // Closing the socket
    close(sockfd);

    return 0;
}