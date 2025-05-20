//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUF_SIZE 10240

int main(int argc, char const *argv[]) {
    char *response;
    char command[MAX_BUF_SIZE] = { 0 };
    int sock;
    struct sockaddr_in server_address;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        return EXIT_FAILURE;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("YOUR_IMAP_SERVER_ADDRESS");
    server_address.sin_port = htons(993);

    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        return EXIT_FAILURE;
    }

    printf("Connected to IMAP server successfully\n");

    // Receive server response
    response = (char *)malloc(MAX_BUF_SIZE);
    memset(response, 0, MAX_BUF_SIZE);
    recv(sock, response, MAX_BUF_SIZE, 0);
    printf("%s\n", response);

    // Send login command
    sprintf(command, "%s%s%s", "A001 LOGIN ", "YOUR_EMAIL_ADDRESS YOUR_PASSWORD", "\r\n");
    send(sock, command, strlen(command), 0);

    // Receive server response
    memset(response, 0, MAX_BUF_SIZE);
    recv(sock, response, MAX_BUF_SIZE, 0);
    printf("%s\n", response);

    // Send list command
    sprintf(command, "%s%s", "A002 LIST \"\" \"*\"", "\r\n");
    send(sock, command, strlen(command), 0);
    
    // Receive server response
    memset(response, 0, MAX_BUF_SIZE);
    recv(sock, response, MAX_BUF_SIZE, 0);
    printf("%s\n", response);

    // Send logout command
    sprintf(command, "%s", "A003 LOGOUT\r\n");
    send(sock, command, strlen(command), 0);

    // Receive server response
    memset(response, 0, MAX_BUF_SIZE);
    recv(sock, response, MAX_BUF_SIZE, 0);
    printf("%s\n", response);

    // Close socket
    close(sock);

    return EXIT_SUCCESS;
}