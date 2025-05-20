//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

// Function to parse server response
void parseResponse(char *response) {
    // code for parsing response
    printf("Parsing Server Response...\n");
}

int main(int argc, char *argv[]) {
    if(argc < 3) { // check for minimum arguments
        printf("Usage: %s <server> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int clientSocket;
    struct sockaddr_in serverAddr;
    struct hostent *server;

    // create socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(clientSocket == -1) {
        perror("Error creating socket");
        exit(errno);
    }

    int serverPort = atoi(argv[2]);
    server = gethostbyname(argv[1]);

    // fill server address structure
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(serverPort);
    memcpy(&serverAddr.sin_addr, server->h_addr, server->h_length);

    // connect to server
    if(connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("Error connecting to server");
        exit(errno);
    }

    printf("Connected to server.\n");

    // send login request
    char *login = "LOGIN username password\n";
    if(send(clientSocket, login, strlen(login), 0) == -1) {
        perror("Error sending login request");
        exit(errno);
    }

    printf("Login request sent to server.\n");

    char response[2048];
    int bytesReceived;
    while(1) {
        //receive server response
        bytesReceived = recv(clientSocket, response, 2048, 0);
        if(bytesReceived == -1) {
            perror("Error receiving server response");
            exit(errno);
        } else if(bytesReceived == 0) {
            printf("Server closed the connection.\n");
            break;
        }

        //parse server response
        parseResponse(response);
    }

    // close socket
    close(clientSocket);
    printf("Connection closed.\n");

    return 0;
}