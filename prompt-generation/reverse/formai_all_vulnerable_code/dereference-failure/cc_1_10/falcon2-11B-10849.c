//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>
#include <errno.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT "21"
#define MAX_LINE 1024
#define TIMEOUT 10

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    if(argc!= 3)
    {
        printf("Usage: %s <username> <password>\n", argv[0]);
        return 1;
    }

    char username[256], password[256];
    strcpy(username, argv[1]);
    strcpy(password, argv[2]);

    // Create socket
    int sockfd, n;
    struct sockaddr_in server;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
        error("ERROR opening socket");

    // Set up connection parameters
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(SERVER_PORT));
    server.sin_addr.s_addr = inet_addr(SERVER_IP);

    // Connect to the server
    if(connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0)
        error("ERROR connecting");

    // Send username and password
    char command[MAX_LINE];
    sprintf(command, "USER %s\r\n", username);
    write(sockfd, command, strlen(command));
    if(read(sockfd, command, MAX_LINE) < 0)
        error("ERROR reading from server");

    // Send password
    sprintf(command, "PASS %s\r\n", password);
    write(sockfd, command, strlen(command));
    if(read(sockfd, command, MAX_LINE) < 0)
        error("ERROR reading from server");

    // Enter FTP command loop
    while(1)
    {
        printf("ftp> ");
        fflush(stdout);
        if(read(sockfd, command, MAX_LINE) < 0)
            error("ERROR reading from server");
        if(strstr(command, "QUIT")!= NULL)
            break;

        // Process command
        printf("%s\n", command);
        fflush(stdout);
        if(write(sockfd, command, strlen(command)) < 0)
            error("ERROR writing to server");
        if(read(sockfd, command, MAX_LINE) < 0)
            error("ERROR reading from server");
    }

    close(sockfd);
    return 0;
}