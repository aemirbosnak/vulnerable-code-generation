//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main() {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char buffer[256];

    /* Create a socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    /* Get the port number from the user */
    printf("Enter the port number: ");
    scanf("%d", &portno);

    /* Get the IP address of the server */
    struct hostent *server;
    server = gethostbyname("localhost");
    if (server == NULL) {
        perror("Error getting host by name");
        exit(1);
    }

    /* Fill in the server address */
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);

    /* Connect to the server */
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    /* Send a message to the server */
    strcpy(buffer, "Hello, world!");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message to server");
        exit(1);
    }

    /* Receive a message from the server */
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("Error receiving message from server");
        exit(1);
    }

    /* Print the message from the server */
    printf("Message from server: %s\n", buffer);

    /* Close the socket */
    close(sockfd);

    return 0;
}