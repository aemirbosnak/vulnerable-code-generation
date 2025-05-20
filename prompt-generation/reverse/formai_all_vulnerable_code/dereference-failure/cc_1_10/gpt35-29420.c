//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024
#define POP3_PORT "110"

void cyberConnect(int);

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("USAGE: %s <server_address> <username>\n", argv[0]);
        exit(1);
    }

    struct hostent *server = gethostbyname(argv[1]);

    if (server == NULL)
    {
        printf("ERROR: Could not resolve server address.\n");
        exit(2);
    }

    int socketFd = socket(AF_INET, SOCK_STREAM, 0);

    if (socketFd < 0)
    {
        printf("ERROR: Could not open socket.\n");
        exit(3);
    }

    int portNo = atoi(POP3_PORT);

    struct sockaddr_in serverAddress;
    memset((char *) &serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    memcpy((char *)&serverAddress.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    serverAddress.sin_port = htons(portNo);

    if (connect(socketFd, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) < 0)
    {
        printf("ERROR: Could not connect to server.\n");
        exit(4);
    }

    cyberConnect(socketFd);

    close(socketFd);

    return 0;
}

void cyberConnect(int socketFd)
{
    char buffer[BUFFER_SIZE];
    int n, i;

    // Clear the buffer
    memset(buffer, 0, BUFFER_SIZE);

    n = read(socketFd, buffer, BUFFER_SIZE - 1);

    if (n < 0)
    {
        printf("ERROR: Could not read from socket.\n");
        exit(5);
    }

    printf("%s", buffer);

    // Send the username to the server
    char username[BUFFER_SIZE];
    printf("Enter username: ");
    fgets(username, BUFFER_SIZE, stdin);
    strcat(username, "\r\n");
    n = write(socketFd, username, strlen(username));

    if (n < 0)
    {
        printf("ERROR: Could not write to socket.\n");
        exit(6);
    }

    // Clear the buffer
    memset(buffer, 0, BUFFER_SIZE);

    n = read(socketFd, buffer, BUFFER_SIZE - 1);

    if (n < 0)
    {
        printf("ERROR: Could not read from socket.\n");
        exit(7);
    }

    printf("%s", buffer);

    // Send the password to the server
    char password[BUFFER_SIZE];
    printf("Enter password: ");
    fgets(password, BUFFER_SIZE, stdin);
    strcat(password, "\r\n");
    n = write(socketFd, password, strlen(password));

    if (n < 0)
    {
        printf("ERROR: Could not write to socket.\n");
        exit(8);
    }

    // Clear the buffer
    memset(buffer, 0, BUFFER_SIZE);

    n = read(socketFd, buffer, BUFFER_SIZE - 1);

    if (n < 0)
    {
        printf("ERROR: Could not read from socket.\n");
        exit(9);
    }

    printf("%s", buffer);

    // List emails
    n = write(socketFd, "LIST\r\n", strlen("LIST\r\n"));

    if (n < 0)
    {
        printf("ERROR: Could not write to socket.\n");
        exit(10);
    }

    memset(buffer, 0, BUFFER_SIZE);

    n = read(socketFd, buffer, BUFFER_SIZE - 1);

    if (n < 0)
    {
        printf("ERROR: Could not read from socket.\n");
        exit(11);
    }

    printf("%s", buffer);

    i = 1;
    while(i) {
        char command[BUFFER_SIZE];
        printf("Enter email number (Enter 0 to exit): ");
        fgets(command, BUFFER_SIZE, stdin);

        if (strcmp(command, "0\r\n") == 0) {
            i = 0;
            continue;
        }

        strcat(command, "\r\n");

        n = write(socketFd, command, strlen(command));

        if (n < 0)
        {
            printf("ERROR: Could not write to socket.\n");
            exit(12);
        }

        memset(buffer, 0, BUFFER_SIZE);

        n = read(socketFd, buffer, BUFFER_SIZE - 1);

        if (n < 0)
        {
            printf("ERROR: Could not read from socket.\n");
            exit(13);
        }

        printf("%s", buffer);
    }

    // Quit
    n = write(socketFd, "QUIT\r\n", strlen("QUIT\r\n"));

    if (n < 0)
    {
        printf("ERROR: Could not write to socket.\n");
        exit(14);
    }

    memset(buffer, 0, BUFFER_SIZE);

    n = read(socketFd, buffer, BUFFER_SIZE - 1);

    if (n < 0)
    {
        printf("ERROR: Could not read from socket.\n");
        exit(15);
    }

    printf("%s", buffer);
}