//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// Function to connect to the server
int connect_to_server(const char *server_name, const char *port)
{
    struct addrinfo hints, *res;
    int sockfd;

    // Clear hints and set relevant values
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    // Get address information for the server
    if (getaddrinfo(server_name, port, &hints, &res) != 0) {
        printf("Error: Could not resolve server %s\n", server_name);
        return -1;
    }

    // Attempt to connect to the server
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0) {
        printf("Error: Could not create socket\n");
        return -1;
    }

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) < 0) {
        printf("Error: Could not connect to server %s\n", server_name);
        return -1;
    }

    printf("Connection established with server %s\n", server_name);
    return sockfd;
}

// Function to send an email
void send_email(int sockfd, const char *from, const char *to, const char *msg)
{
    char buffer[1024] = {0};

    // Wait for server greeting
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);

    // Send EHLO and wait for response
    sprintf(buffer, "EHLO %s\r\n", from);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);

    // Send MAIL FROM and wait for response
    sprintf(buffer, "MAIL FROM: <%s>\r\n", from);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);

    // Send RCPT TO and wait for response
    sprintf(buffer, "RCPT TO: <%s>\r\n", to);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);

    // Send DATA and wait for response
    sprintf(buffer, "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);

    // Send message content
    sprintf(buffer, "%s\r\n.\r\n", msg);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);

    // Send QUIT command and wait for response
    sprintf(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);
}

int main(int argc, char *argv[])
{
    int sockfd;

    // Make sure the user passed in enough arguments
    if (argc < 5) {
        printf("Usage: %s server_name server_port from to message\n", argv[0]);
        return -1;
    }

    // Connect to the server
    sockfd = connect_to_server(argv[1], argv[2]);
    if (sockfd < 0) {
        return -1;
    }

    // Send the email
    send_email(sockfd, argv[3], argv[4], argv[5]);

    // Clean up and exit
    close(sockfd);
    return 0;
}