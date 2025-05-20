//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>

#define POP3_PORT 110

// Send a command to the server and receive the response
char* send_command(int sockfd, char* command)
{
    // Send the command
    if (send(sockfd, command, strlen(command), 0) == -1)
    {
        perror("send");
        exit(1);
    }

    // Receive the response
    char* response = malloc(1024);
    if (recv(sockfd, response, 1023, 0) == -1)
    {
        perror("recv");
        exit(1);
    }

    // Null-terminate the response
    response[strlen(response)] = '\0';

    return response;
}

int main(int argc, char* argv[])
{
    // Check the number of arguments
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <hostname> <username>\n", argv[0]);
        exit(1);
    }

    // Get the hostname and username
    char* hostname = argv[1];
    char* username = argv[2];

    // Resolve the hostname
    struct hostent* host = gethostbyname(hostname);
    if (host == NULL)
    {
        perror("gethostbyname");
        exit(1);
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket");
        exit(1);
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("connect");
        exit(1);
    }

    // Send the USER command
    char* response = send_command(sockfd, "USER ");
    printf("%s\n", response);

    // Send the PASS command
    response = send_command(sockfd, "PASS ");
    printf("%s\n", response);

    // Send the LIST command
    response = send_command(sockfd, "LIST\n");
    printf("%s\n", response);

    // Send the RETR command
    response = send_command(sockfd, "RETR 1\n");
    printf("%s\n", response);

    // Send the QUIT command
    response = send_command(sockfd, "QUIT\n");
    printf("%s\n", response);

    // Close the socket
    close(sockfd);

    return 0;
}