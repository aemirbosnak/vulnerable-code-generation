//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 110 // Default POP3 port
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    // Check if the user provided an email address and a password
    if (argc != 3) {
        printf("Please provide an email address and a password.\n");
        return -1;
    }

    // Set up the socket
    struct hostent *server_info;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE + 1];
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        printf("Error: Unable to create socket.\n");
        return -1;
    }
    server_info = gethostbyname("pop.gmail.com");
    if (server_info == NULL) {
        printf("Error: Unable to resolve server.\n");
        return -1;
    }
    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    bcopy((char *)server_info->h_addr_list[0], (char *)&server_address.sin_addr.s_addr, server_info->h_length);

    // Connect to the server
    if (connect(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Error: Unable to connect to server.\n");
        return -1;
    }

    // Log in with the user's email and password
    sprintf(buffer, "USER %s\r\n", argv[1]);
    send(socket_fd, buffer, strlen(buffer), 0);
    bzero(buffer, BUFFER_SIZE);
    recv(socket_fd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);
    sprintf(buffer, "PASS %s\r\n", argv[2]);
    send(socket_fd, buffer, strlen(buffer), 0);
    bzero(buffer, BUFFER_SIZE);
    recv(socket_fd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // List all the messages in the mailbox
    sprintf(buffer, "LIST\r\n");
    send(socket_fd, buffer, strlen(buffer), 0);
    bzero(buffer, BUFFER_SIZE);
    recv(socket_fd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);
    while (1) {
        bzero(buffer, BUFFER_SIZE);
        recv(socket_fd, buffer, BUFFER_SIZE, 0);
        if (strcmp(buffer, ".\r\n") == 0) {
            break;
        }
        printf("%s", buffer);
    }

    // Log out and close the socket
    sprintf(buffer, "QUIT\r\n");
    send(socket_fd, buffer, strlen(buffer), 0);
    bzero(buffer, BUFFER_SIZE);
    recv(socket_fd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);
    close(socket_fd);

    return 0;
}