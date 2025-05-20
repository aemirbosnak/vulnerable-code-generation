//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<math.h>

#define BYTES 1024

int main(int argc, char *argv[])
{
    // Checking for minimum arguments
    if(argc < 3)
    {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Initializing socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1)
    {
        printf("ERROR: Unable to create socket.\n");
        exit(EXIT_FAILURE);
    }

    // Filling the server address structure
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    // Connecting to the server
    if(connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
    {
        printf("ERROR: Unable to connect to server.\n");
        exit(EXIT_FAILURE);
    }

    printf("Connected to the server.\n");

    // Receiving message from server
    char buffer[BYTES];
    printf("Enter the mathematical expression: ");
    fgets(buffer, BYTES, stdin);
    send(sockfd, buffer, strlen(buffer), 0);
    printf("Expression sent to server successfully.\n");
    memset(buffer, 0, BYTES);
    int bytes_received = recv(sockfd, buffer, BYTES, 0);
    if(bytes_received == -1)
    {
        printf("ERROR: Unable to receive message from server.\n");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_received] = '\0';
    printf("Server's response: %s\n", buffer);

    // Closing the socket
    close(sockfd);

    return 0;
}