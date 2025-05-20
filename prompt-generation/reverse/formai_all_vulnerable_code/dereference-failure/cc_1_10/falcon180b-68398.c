//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <netdb.h>

#define SERVER_PORT 110
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, bytes_read;
    char buffer[BUFFER_SIZE];
    char hostname[1024];
    struct hostent *host;
    struct sockaddr_in server_addr;

    // Get the hostname from the command line argument
    strcpy(hostname, argv[1]);

    // Get the server address
    host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error: could not resolve hostname.\n");
        exit(1);
    }

    // Create a socket
    sockfd = socket(PF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "Error: could not create socket.\n");
        exit(1);
    }

    // Set the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error: could not connect to server.\n");
        exit(1);
    }

    // Authenticate with the server
    char user[1024];
    char pass[1024];
    printf("Enter username: ");
    fgets(user, sizeof(user), stdin);
    printf("Enter password: ");
    fgets(pass, sizeof(pass), stdin);

    char auth_buffer[1024];
    snprintf(auth_buffer, sizeof(auth_buffer), "USER %s\r\n", user);
    send(sockfd, auth_buffer, strlen(auth_buffer), 0);

    char password_buffer[1024];
    snprintf(password_buffer, sizeof(password_buffer), "PASS %s\r\n", pass);
    send(sockfd, password_buffer, strlen(password_buffer), 0);

    // Retrieve messages from the server
    while (1) {
        bytes_read = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_read == 0) {
            fprintf(stderr, "Error: connection closed by server.\n");
            exit(1);
        }

        buffer[bytes_read] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}