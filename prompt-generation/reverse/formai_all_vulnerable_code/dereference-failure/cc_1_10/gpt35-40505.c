//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int socketFd, port;
    struct hostent *server;
    struct sockaddr_in serverAddress;
    char buffer[BUFFER_SIZE], fileName[BUFFER_SIZE];
    FILE *filePtr;

    if(argc < 4)
    {
        fprintf(stderr, "Usage: %s serverIp port fileName\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    port = atoi(argv[2]); //Get port number

    socketFd = socket(AF_INET, SOCK_STREAM, 0); //Create socket
    if(socketFd < 0)
    {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(argv[1]); //Get server address
    if(server == NULL)
    {
        fprintf(stderr, "Failed to get server address\n");
        exit(EXIT_FAILURE);
    }

    memset((char *)&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
        (char *)&serverAddress.sin_addr.s_addr, server->h_length);
    serverAddress.sin_port = htons(port);

    if(connect(socketFd, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0) //Connect to server
    {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }

    strcpy(fileName, argv[3]); //Store requested file name

    send(socketFd, fileName, sizeof(fileName), 0); //Send file name to server

    recv(socketFd, buffer, BUFFER_SIZE, 0); //Receive response from server
    if(strcmp(buffer, "File not found") == 0)
    {
        fprintf(stderr, "Could not find file on server\n");
        close(socketFd);
        exit(EXIT_FAILURE);
    }
    else if(strcmp(buffer, "Error") == 0)
    {
        fprintf(stderr, "An error occurred on the server\n");
        close(socketFd);
        exit(EXIT_FAILURE);
    }

    filePtr = fopen(fileName, "wb"); //Open file for writing
    if(filePtr == NULL)
    {
        perror("Failed to create file");
        close(socketFd);
        exit(EXIT_FAILURE);
    }

    while(recv(socketFd, buffer, BUFFER_SIZE, 0) > 0) //Receive file data from server
    {
        fwrite(buffer, 1, BUFFER_SIZE, filePtr);
    }

    fclose(filePtr); //Close file
    close(socketFd); //Close socket

    printf("File transfer successful!\n");

    return 0;
}