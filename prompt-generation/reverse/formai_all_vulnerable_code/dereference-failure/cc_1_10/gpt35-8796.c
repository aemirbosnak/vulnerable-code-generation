//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// Function to handle errors
void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[4096];
    char username[100], password[100];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    // Set up server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    portno = atoi(argv[2]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(portno);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    // Receive greeting message
    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0)
        error("ERROR reading from socket");

    // Print greeting message
    printf("%s", buffer);

    // Send username
    memset(username, 0, sizeof(username));
    printf("Enter Username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;
    n = write(sockfd, username, strlen(username));
    if (n < 0)
        error("ERROR writing to socket");

    // Receive password prompt
    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0)
        error("ERROR reading from socket");

    // Print password prompt
    printf("%s", buffer);

    // Send password
    memset(password, 0, sizeof(password));
    printf("Enter Password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;
    n = write(sockfd, password, strlen(password));
    if (n < 0)
        error("ERROR writing to socket");

    // Receive response to login
    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0)
        error("ERROR reading from socket");

    // Print response to login
    printf("%s", buffer);

    // Send command to list messages
    n = write(sockfd, "LIST\r\n", strlen("LIST\r\n"));
    if (n < 0)
        error("ERROR writing to socket");

    // Receive response to list messages
    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0)
        error("ERROR reading from socket");

    // Print response to list messages
    printf("%s", buffer);

    // Close socket
    close(sockfd);

    return 0;
}