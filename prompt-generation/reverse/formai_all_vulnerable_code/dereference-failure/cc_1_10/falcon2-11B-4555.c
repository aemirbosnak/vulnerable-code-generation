//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

// Function to print usage of the program
void print_usage()
{
    printf("Usage: client <host> <port>\n");
    exit(1);
}

// Function to create a socket and connect to a server
int connect_to_server(char *host, int port)
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(host);

    int connect_status = connect(sockfd, (struct sockaddr *)&server, sizeof(server));
    if (connect_status == -1)
    {
        perror("connect");
        exit(1);
    }

    return sockfd;
}

// Function to send a message to the server
void send_message(int sockfd, char *message)
{
    int num_sent = send(sockfd, message, strlen(message), 0);
    if (num_sent == -1)
    {
        perror("send");
        exit(1);
    }
}

// Function to receive a message from the server
char *receive_message(int sockfd)
{
    char buffer[1024];
    int num_received = recv(sockfd, buffer, sizeof(buffer), 0);
    if (num_received == -1)
    {
        perror("recv");
        exit(1);
    }

    return buffer;
}

// Function to close the socket
void close_socket(int sockfd)
{
    close(sockfd);
}

int main(int argc, char *argv[])
{
    if (argc!= 3)
    {
        print_usage();
    }

    int sockfd = connect_to_server(argv[1], atoi(argv[2]));
    if (sockfd == -1)
    {
        perror("connect to server");
        exit(1);
    }

    char *message = "Hello, server!\n";
    send_message(sockfd, message);

    char *response = receive_message(sockfd);
    printf("Received: %s\n", response);

    close_socket(sockfd);

    return 0;
}