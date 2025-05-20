//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    char *host = "mail.example.com";
    char *username = "exampleuser";
    char *password = "password123";

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Failed to create socket\n");
        return 1;
    }

    // Resolve IP address of mail server
    struct hostent *server = gethostbyname(host);
    if (server == NULL) {
        printf("Error: Failed to resolve IP address of mail server\n");
        return 1;
    }

    // Connect to mail server
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    memcpy(&server_address.sin_addr.s_addr, server->h_addr, server->h_length);
    server_address.sin_port = htons(993); // IMAP server port
    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error: Failed to connect to mail server\n");
        return 1;
    }

    // Read server greeting
    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, MAX_BUFFER_SIZE);
    read(sockfd, buffer, MAX_BUFFER_SIZE);
    printf("Server greeting: %s", buffer);

    // Send login command
    memset(buffer, 0, MAX_BUFFER_SIZE);
    sprintf(buffer, "LOGIN %s %s\r\n", username, password);
    write(sockfd, buffer, strlen(buffer));

    // Read server response
    memset(buffer, 0, MAX_BUFFER_SIZE);
    read(sockfd, buffer, MAX_BUFFER_SIZE);
    printf("Server response: %s", buffer);

    // Send select command
    memset(buffer, 0, MAX_BUFFER_SIZE);
    sprintf(buffer, "SELECT INBOX\r\n");
    write(sockfd, buffer, strlen(buffer));

    // Read server response
    memset(buffer, 0, MAX_BUFFER_SIZE);
    read(sockfd, buffer, MAX_BUFFER_SIZE);
    printf("Server response: %s", buffer);

    // Send fetch command
    memset(buffer, 0, MAX_BUFFER_SIZE);
    sprintf(buffer, "FETCH 1 BODY[HEADER]\r\n");
    write(sockfd, buffer, strlen(buffer));

    // Read server response
    memset(buffer, 0, MAX_BUFFER_SIZE);
    read(sockfd, buffer, MAX_BUFFER_SIZE);
    printf("Server response: %s", buffer);

    // Logout and close socket
    memset(buffer, 0, MAX_BUFFER_SIZE);
    sprintf(buffer, "LOGOUT\r\n");
    write(sockfd, buffer, strlen(buffer));
    close(sockfd);

    return 0;
}