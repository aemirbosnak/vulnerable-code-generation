//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 25
#define MAX_MSG_LEN 1024

int main(int argc, char *argv[]) {
    struct sockaddr_in serverAddr;
    struct hostent *serverHost;
    struct sockaddr_in clientAddr;
    int clientSock;
    int sendResult;
    char message[MAX_MSG_LEN] = "Hello, world!\n";

    printf("SMTP client started.\n");

    // Resolve server hostname
    serverHost = gethostbyname("smtp.example.com");
    if (serverHost == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    // Create socket
    clientSock = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSock < 0) {
        perror("socket");
        exit(1);
    }

    // Create server address
    bzero((char *)&serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    bcopy((char *)serverHost->h_addr,
          (char *)&serverAddr.sin_addr.s_addr,
          serverHost->h_length);
    serverAddr.sin_port = htons(PORT);

    // Connect to server
    if (connect(clientSock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send message
    sendResult = send(clientSock, message, strlen(message), 0);
    if (sendResult < 0) {
        perror("send");
        exit(1);
    }

    // Close connection
    close(clientSock);

    printf("SMTP client finished.\n");
    return 0;
}