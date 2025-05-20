//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: distributed
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT 1234

// Function declarations
void handle_client(int sockfd);
void handle_server(int sockfd);

// Main function
int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in serv_addr;
    int opt = 1;
    char buffer[1024];

    if (argc!= 2) {
        printf("Usage: %s <server|client>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "server") == 0) {
        handle_server(sockfd);
    } else if (strcmp(argv[1], "client") == 0) {
        handle_client(sockfd);
    } else {
        printf("Invalid option!\n");
        return 1;
    }

    return 0;
}

// Function to handle client requests
void handle_client(int sockfd)
{
    char message[1024];
    int n;

    while (1) {
        printf("Enter a message to send to server: ");
        fgets(message, sizeof(message), stdin);
        if (message[strlen(message) - 1] == '\n') {
            message[strlen(message) - 1] = '\0';
        }
        n = send(sockfd, message, strlen(message), 0);
        if (n == -1) {
            perror("send");
            break;
        }
        printf("Message sent successfully!\n");
    }

    close(sockfd);
    return;
}

// Function to handle server requests
void handle_server(int sockfd)
{
    char buffer[1024];
    int n;

    bzero(buffer, sizeof(buffer));

    while (1) {
        n = recv(sockfd, buffer, sizeof(buffer), 0);
        if (n == -1) {
            perror("recv");
            break;
        }
        printf("Received message: %s\n", buffer);
    }

    close(sockfd);
    return;
}