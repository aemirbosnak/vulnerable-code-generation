//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>

#define MAX_BUF_SIZE 1024
#define POP3_PORT 110

void trim(char * buffer) {
    // Remove leading and trailing whitespaces from a string
    char * end = buffer + strlen(buffer) - 1;
    while (*end == '\r' || *end == '\n') {
        *end-- = '\0';
    }
    while (*buffer == ' ' || *buffer == '\t') {
        ++buffer;
    }
}

int main(int argc, char * argv[]) {
    // Parse command line arguments
    char * server_url = argv[1];
    char * user = argv[2];
    char * password = argv[3];

    // Convert server URL to IP address
    struct hostent * server = gethostbyname(server_url);
    if (server == NULL) {
        printf("[%d] Could not resolve server URL: %s\n", errno, server_url);
        exit(errno);
    }

    // Open socket to POP3 server
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("[%d] Could not create socket\n", errno);
        exit(errno);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr = *((struct in_addr *) server->h_addr);

    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("[%d] Could not connect to server\n", errno);
        exit(errno);
    }

    char buffer[MAX_BUF_SIZE];
    ssize_t count;

    // Read welcome message from server
    count = recv(sock, buffer, MAX_BUF_SIZE, 0);
    buffer[count] = '\0';
    printf("%s", buffer);

    // Send user name to server
    sprintf(buffer, "USER %s\r\n", user);
    send(sock, buffer, strlen(buffer), 0);

    // Read server response to user name
    count = recv(sock, buffer, MAX_BUF_SIZE, 0);
    buffer[count] = '\0';
    printf("%s", buffer);

    // Send password to server
    sprintf(buffer, "PASS %s\r\n", password);
    send(sock, buffer, strlen(buffer), 0);

    // Read server response to password
    count = recv(sock, buffer, MAX_BUF_SIZE, 0);
    buffer[count] = '\0';
    printf("%s", buffer);

    // Send command to list all emails
    sprintf(buffer, "LIST\r\n");
    send(sock, buffer, strlen(buffer), 0);

    // Read server response to list command
    count = recv(sock, buffer, MAX_BUF_SIZE, 0);
    buffer[count] = '\0';
    printf("%s", buffer);

    // Extract email IDs from server response
    char * token = strtok(buffer, " \r\n");
    token = strtok(NULL, " \r\n");
    while (token != NULL) {
        // Send command to fetch email with given ID
        sprintf(buffer, "RETR %s\r\n", token);
        send(sock, buffer, strlen(buffer), 0);

        // Read server response to fetch command
        count = recv(sock, buffer, MAX_BUF_SIZE, 0);
        buffer[count] = '\0';

        // Print email content header
        printf("Email ID: %s\n", token);
        printf("------------------------\n");

        // Print email content body
        char * start = strstr(buffer, "\r\n\r\n") + 4;
        trim(start);
        printf("%s\n", start);

        // Move to next email ID
        token = strtok(NULL, " \r\n");
    }

    // Send command to quit POP3 session
    sprintf(buffer, "QUIT\r\n");
    send(sock, buffer, strlen(buffer), 0);

    // Read server response to quit command
    count = recv(sock, buffer, MAX_BUF_SIZE, 0);
    buffer[count] = '\0';
    printf("%s", buffer);

    // Close socket and exit program successfully
    close(sock);
    return 0;
}