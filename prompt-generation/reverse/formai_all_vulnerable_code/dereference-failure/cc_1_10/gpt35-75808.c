//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_SIZE 1024 // maximum size of message buffer

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Usage: %s <server-address> <port-number>\n", argv[0]);
        exit(1);
    }

    // Creating socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        printf("Error creating socket\n");
        exit(1);
    }

    // Setting up server address and port number
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_aton(argv[1], &server_addr.sin_addr);

    // Connecting to server
    if(connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
    {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Receiving server response
    char buffer[MAX_SIZE];
    memset(buffer, 0, MAX_SIZE);
    read(sockfd, buffer, MAX_SIZE);
    printf("%s\n", buffer);

    // Sending user credentials
    char user[MAX_SIZE], pass[MAX_SIZE];
    printf("Username: ");
    fgets(user, MAX_SIZE, stdin);
    printf("Password: ");
    fgets(pass, MAX_SIZE, stdin);
    char credentials[MAX_SIZE];
    sprintf(credentials, "USER %sPASS %s", user, pass);
    send(sockfd, credentials, strlen(credentials), 0);

    // Receiving login response from server
    memset(buffer, 0, MAX_SIZE);
    read(sockfd, buffer, MAX_SIZE);
    printf("%s\n", buffer);

    // Sending command to list emails
    send(sockfd, "LIST\r\n", strlen("LIST\r\n"), 0);

    // Receiving email list from server
    memset(buffer, 0, MAX_SIZE);
    read(sockfd, buffer, MAX_SIZE);
    printf("%s\n", buffer);

    // Sending command to retrieve email
    char retrieve[MAX_SIZE];
    printf("Enter email number to retrieve: ");
    fgets(retrieve, MAX_SIZE, stdin);
    char retrieve_command[MAX_SIZE];
    sprintf(retrieve_command, "RETR %s", retrieve);
    send(sockfd, retrieve_command, strlen(retrieve_command), 0);

    // Receiving email from server
    memset(buffer, 0, MAX_SIZE);
    read(sockfd, buffer, MAX_SIZE);
    printf("%s\n", buffer);

    // Closing socket
    close(sockfd);

    return 0;
}