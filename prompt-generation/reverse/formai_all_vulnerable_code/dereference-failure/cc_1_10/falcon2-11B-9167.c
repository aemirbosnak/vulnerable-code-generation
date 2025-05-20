//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

int main(int argc, char *argv[])
{
    // IMAP server host and port
    char *host = "imap.example.com";
    int port = 143;

    // Server login
    char *username = "user";
    char *password = "password";

    // Socket descriptor
    int socket_fd;

    // Create socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("Error creating socket");
        return 1;
    }

    // Connect to server
    struct hostent *host_info = gethostbyname(host);
    if (host_info == NULL) {
        fprintf(stderr, "Error: host not found\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy((char *)&server_addr.sin_addr.s_addr, (char *)host_info->h_addr, host_info->h_length);

    int result = connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (result < 0) {
        perror("Error connecting to server");
        return 1;
    }

    // Login to server
    char buffer[BUFSIZE];
    snprintf(buffer, BUFSIZE, "LOGIN %s %s\r\n", username, password);
    int num_bytes_read = write(socket_fd, buffer, strlen(buffer));
    if (num_bytes_read < 0) {
        perror("Error writing to socket");
        return 1;
    }

    // Get list of mailboxes
    char command[BUFSIZE];
    snprintf(command, BUFSIZE, "LIST \"*\"\r\n");
    num_bytes_read = write(socket_fd, command, strlen(command));
    if (num_bytes_read < 0) {
        perror("Error writing to socket");
        return 1;
    }

    // Read and display mailbox list
    char *line = NULL;
    size_t len = 0;
    ssize_t bytes_read;
    while ((bytes_read = read(socket_fd, &line, BUFSIZE)) > 0) {
        len += bytes_read;
        printf("%s", line);
        if (strstr(line, "OK LIST completed\r\n")!= NULL) {
            break;
        }
        line[len] = '\0';
    }

    // Close socket
    close(socket_fd);
    return 0;
}