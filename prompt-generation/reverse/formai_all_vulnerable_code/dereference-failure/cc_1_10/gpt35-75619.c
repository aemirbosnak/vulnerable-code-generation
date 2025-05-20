//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>

// Define constants
#define BUF_SIZE 1024
#define POP3_PORT 110

// Function to receive response from server
void recv_response(int sockfd, char *buf)
{
    int len = read(sockfd, buf, BUF_SIZE);
    buf[len] = '\0';
    printf("\nServer: %s\n", buf);
}

// Function to send command to server
void send_command(int sockfd, char *cmd)
{
    int len = strlen(cmd);
    write(sockfd, cmd, len);
    printf("\nClient: %s\n", cmd);
}

int main(int argc, char *argv[])
{
    // Check if user has provided server IP address
    if(argc < 2)
    {
        printf("Please provide server IP address\n");
        return 1;
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) 
    {
        printf("Error creating socket\n");
        return 1;
    }

    // Set server address and port number
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(POP3_PORT);

    // Connect to server
    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Error connecting to server\n");
        return 1;
    }
    printf("Connected to server\n");

    char buf[BUF_SIZE];
    recv_response(sockfd, buf);

    // Send USER command
    send_command(sockfd, "USER username\n");
    recv_response(sockfd, buf);

    // Send PASS command
    send_command(sockfd, "PASS password\n");
    recv_response(sockfd, buf);

    // Send LIST command
    send_command(sockfd, "LIST\n");
    recv_response(sockfd, buf);

    // Close socket
    close(sockfd);
    printf("Disconnected from server\n");

    return 0;
}