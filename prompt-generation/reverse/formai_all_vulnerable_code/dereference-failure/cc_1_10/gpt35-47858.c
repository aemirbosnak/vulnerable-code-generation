//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_COMMAND_SIZE 100
#define MAX_RESPONSE_SIZE 500

// Function Declarations
void readResponse(int sockfd, char* response);
void ftpCommand(int sockfd, char* command, char* response);
void connectToServer(int* sockfd, char* serverAddr, uint16_t serverPort, char* response);

int main(int argc, char *argv[]) {
    int sockfd; // Socket file descriptor
    char serverAddr[MAX_COMMAND_SIZE], response[MAX_RESPONSE_SIZE], command[MAX_COMMAND_SIZE];
    uint16_t serverPort;

    // Get server address and port number from command line arguments
    if (argc == 3) {
        strcpy(serverAddr, argv[1]);
        serverPort = atoi(argv[2]);
    } else {
        printf("Usage: %s <Server Address> <Server Port>\n", argv[0]);
        exit(0);
    }

    // Connect to server
    connectToServer(&sockfd, serverAddr, serverPort, response);

    // Login to the server
    ftpCommand(sockfd, "USER anonymous\r\n", response);
    ftpCommand(sockfd, "PASS guest@\r\n", response);

    // Get list of files on server
    ftpCommand(sockfd, "LIST\r\n", response);
    printf("Response from server:\n%s", response);

    // Download a file from server
    printf("Enter name of file to download: ");
    scanf("%s", command);
    sprintf(command, "RETR %s\r\n", command);
    ftpCommand(sockfd, command, response);

    // Close connection to server
    ftpCommand(sockfd, "QUIT\r\n", response);
    close(sockfd);

    return 0;
}

void readResponse(int sockfd, char* response) {
    memset(response, 0, MAX_RESPONSE_SIZE);
    int nbytes = 0;
    while ((nbytes = read(sockfd, response, MAX_RESPONSE_SIZE - 1)) > 0) {
        response[nbytes] = '\0';
        printf("%s", response);
        if (response[nbytes - 1] == '\n') {
            break;
        } else {
            memset(response, 0, MAX_RESPONSE_SIZE);
        }
    }
}

void ftpCommand(int sockfd, char* command, char* response) {
    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, MAX_BUFFER_SIZE);
    strcpy(buffer, command);
    write(sockfd, buffer, strlen(buffer));
    readResponse(sockfd, response);
}

void connectToServer(int* sockfd, char* serverAddr, uint16_t serverPort, char* response) {
    // Create socket
    if ((*sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set server address and port
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(serverAddr);
    servaddr.sin_port = htons(serverPort);

    // Connect to server
    if (connect(*sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Get welcome message from server
    readResponse(*sockfd, response);
}