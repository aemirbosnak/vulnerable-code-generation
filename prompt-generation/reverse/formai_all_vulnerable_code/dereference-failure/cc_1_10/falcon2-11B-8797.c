//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

#define MAX_MESSAGE_SIZE 1024
#define MAX_SERVER_NAME 256

int main(int argc, char *argv[])
{
    // Check command line arguments
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <server_ip> <message>\n", argv[0]);
        exit(1);
    }

    // Convert server IP address to dotted decimal notation
    char *server_ip = argv[1];
    struct hostent *server_info = gethostbyname(server_ip);
    if (server_info == NULL) {
        fprintf(stderr, "Error: Invalid server IP address.\n");
        exit(1);
    }

    // Create a TCP socket
    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    // Connect to the server
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *)server_info->h_addr, (char *)&server_address.sin_addr.s_addr, server_info->h_length);
    server_address.sin_port = htons(8080);
    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Send a message to the server
    char message[MAX_MESSAGE_SIZE];
    printf("Enter a message to send to the server: ");
    scanf("%s", message);
    if (send(sockfd, message, strlen(message), 0) < 0) {
        perror("Error sending message");
        exit(1);
    }

    // Receive a response from the server
    char response[MAX_MESSAGE_SIZE];
    if (recv(sockfd, response, MAX_MESSAGE_SIZE, 0) < 0) {
        perror("Error receiving response");
        exit(1);
    }
    printf("Response from server: %s\n", response);

    // Close the socket
    close(sockfd);

    return 0;
}