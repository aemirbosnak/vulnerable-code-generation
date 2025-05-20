//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main()
{
    // Define the socket variables
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Get the port number from the user
    printf("Enter the port number: ");
    scanf("%d", &portno);

    // Create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Get the hostname from the user
    printf("Enter the hostname: ");
    char hostname[1024];
    scanf("%s", hostname);

    // Get the server's IP address
    server = gethostbyname(hostname);
    if (server == NULL) {
        perror("ERROR resolving hostname");
        exit(1);
    }

    // Fill in the server's address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting to server");
        exit(1);
    }

    // Send a message to the server
    char message[] = "Hello, world!";
    int n = write(sockfd, message, strlen(message));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Receive a message from the server
    char buffer[1024];
    n = read(sockfd, buffer, 1024);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    // Print the message from the server
    printf("Received from server: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}