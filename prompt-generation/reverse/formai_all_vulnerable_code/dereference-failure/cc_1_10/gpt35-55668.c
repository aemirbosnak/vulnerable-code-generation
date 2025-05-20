//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char *hostname = "pop.gmail.com";
    int port = 995;

    // Get the IP address of the server
    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Error: No such host %s\n", hostname);
        exit(1);
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: Could not create socket\n");
        exit(1);
    }

    // Connect to the server
    struct sockaddr_in serv_addr;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error: Could not connect to server\n");
        exit(1);
    }

    // Send the POP3 username and password
    char buffer[256];
    bzero(buffer, 256);
    sprintf(buffer, "USER %s\r\n", "your_username");
    send(sockfd, buffer, strlen(buffer), 0);

    bzero(buffer, 256);
    sprintf(buffer, "PASS %s\r\n", "your_password");
    send(sockfd, buffer, strlen(buffer), 0);

    // Check if the username and password are accepted
    bzero(buffer, 256);
    recv(sockfd, buffer, 255, 0);
    if (strcasestr(buffer, "+OK") == NULL) {
        fprintf(stderr, "Error: Could not log in\n");
        exit(1);
    }

    // Send the POP3 LIST command to get the list of messages
    bzero(buffer, 256);
    sprintf(buffer, "LIST\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive the list of messages
    bzero(buffer, 256);
    recv(sockfd, buffer, 255, 0);

    // Parse the list of messages
    char *token = strtok(buffer, "\r\n");
    while (token != NULL) {
        if (strcasestr(token, "+OK") == NULL) {
            printf("%s\n", token);
        }
        token = strtok(NULL, "\r\n");
    }

    // Send the POP3 RETR command to get the first message
    bzero(buffer, 256);
    sprintf(buffer, "RETR 1\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive the first message
    bzero(buffer, 256);
    recv(sockfd, buffer, 255, 0);

    // Print the first message
    printf("%s\n", buffer);

    // Send the POP3 QUIT command to disconnect from the server
    bzero(buffer, 256);
    sprintf(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Close the socket
    close(sockfd);

    return 0;
}