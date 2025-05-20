//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define DEFAULT_PORT 21

//Function to initialize a socket connection
int initSocketConnection(char *serverName) {
    int sockFd;
    struct sockaddr_in serverAddr;
    struct hostent *server;

    //Create socket
    sockFd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockFd < 0) {
        printf("Error creating socket!\n");
        exit(1);
    }

    //Get server details
    server = gethostbyname(serverName);
    if (server == NULL) {
        printf("Error: no such host!\n");
        exit(1);
    }

    //Create server address structure
    bzero((char *) &serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serverAddr.sin_addr.s_addr,
         server->h_length);
    serverAddr.sin_port = htons(DEFAULT_PORT);

    //Connect to server
    if (connect(sockFd,(struct sockaddr *) &serverAddr,sizeof(serverAddr)) < 0) {
        printf("Error connecting to server!\n");
        exit(1);
    }

    return sockFd;
}

//Function to send a command to the server
void sendCommand(int sockFd, char *cmd) {
    char buffer[256];
    bzero(buffer,256);
    strcpy(buffer, cmd);

    //Send command to server
    int n = write(sockFd, buffer, strlen(buffer));
    if (n < 0) {
        printf("Error writing to socket!\n");
        exit(1);
    }
}

//Function to receive response from the server
void receiveResponse(int sockFd, char *response) {
    char buffer[256];
    bzero(buffer,256);

    //Receive response from server
    int n = read(sockFd, buffer, 255);
    if (n < 0) {
        printf("Error reading from socket!\n");
        exit(1);
    }
    strcpy(response, buffer);
}

int main(int argc, char *argv[]) {
    int sockFd;
    char serverName[256];
    char response[256];

    //Get server name from user
    printf("Enter server name: ");
    scanf("%s", serverName);

    //Initialize socket connection
    sockFd = initSocketConnection(serverName);

    //Send login details to server
    char userCmd[256];
    printf("Username: ");
    scanf("%s", userCmd);
    sendCommand(sockFd, userCmd);
    receiveResponse(sockFd, response);
    printf("%s\n", response);

    char passCmd[256];
    printf("Password: ");
    scanf("%s", passCmd);
    sendCommand(sockFd, passCmd);
    receiveResponse(sockFd, response);
    printf("%s\n", response);

    //Send list files command and receive response
    sendCommand(sockFd, "LIST\r\n");
    receiveResponse(sockFd, response);
    printf("%s\n", response);

    //Close socket connection
    close(sockFd);

    return 0;
}