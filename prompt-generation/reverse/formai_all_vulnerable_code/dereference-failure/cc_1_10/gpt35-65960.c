//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

// function to establish connection with POP3 server
int connect_to_server(const char* server, int port) {
    int sock_fd;
    struct hostent *server_info;
    struct sockaddr_in server_addr;

    // create socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Error creating socket");
        return -1;
    }

    // get server info
    server_info = gethostbyname(server);
    if (server_info == NULL) {
        fprintf(stderr, "Error getting host info\n");
        return -1;
    }

    // set up server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr.s_addr, server_info->h_addr, server_info->h_length);

    // connect to server
    if (connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        return -1;
    }

    return sock_fd;
}

int main(int argc, char* argv[]) {
    int sock_fd, n;
    char buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];
    char response[BUFFER_SIZE];

    if (argc != 3) {
        fprintf(stderr, "Usage: pop3client <server> <port>\n");
        exit(1);
    }

    // connect to POP3 server
    sock_fd = connect_to_server(argv[1], atoi(argv[2]));
    if (sock_fd < 0) {
        fprintf(stderr, "Error connecting to server\n");
        exit(1);
    }

    // receive initial response
    bzero(buffer, BUFFER_SIZE);
    n = recv(sock_fd, buffer, BUFFER_SIZE-1, 0);
    if (n < 0) {
        perror("Error receiving initial response");
        exit(1);
    }
    printf("%s", buffer);

    // send username
    printf("Username: ");
    fgets(command, BUFFER_SIZE, stdin);
    snprintf(buffer, BUFFER_SIZE, "USER %s", command);
    n = send(sock_fd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error sending username");
        exit(1);
    }

    // receive response to username
    bzero(buffer, BUFFER_SIZE);
    n = recv(sock_fd, buffer, BUFFER_SIZE-1, 0);
    if (n < 0) {
        perror("Error receiving response to username");
        exit(1);
    }
    printf("%s", buffer);

    // send password
    printf("Password: ");
    fgets(command, BUFFER_SIZE, stdin);
    snprintf(buffer, BUFFER_SIZE, "PASS %s", command);
    n = send(sock_fd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error sending password");
        exit(1);
    }

    // receive response to password
    bzero(buffer, BUFFER_SIZE);
    n = recv(sock_fd, buffer, BUFFER_SIZE-1, 0);
    if (n < 0) {
        perror("Error receiving response to password");
        exit(1);
    }
    printf("%s", buffer);

    // list messages
    snprintf(buffer, BUFFER_SIZE, "LIST");
    n = send(sock_fd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error sending LIST command");
        exit(1);
    }

    // receive list of messages
    printf("Messages:\n");
    while(1) {
        bzero(buffer, BUFFER_SIZE);
        n = recv(sock_fd, buffer, BUFFER_SIZE-1, 0);
        if (n < 0) {
            perror("Error receiving message list");
            exit(1);
        }
        if (strcmp(buffer, ".\r\n") == 0) {
            break;
        }
        printf("%s", buffer);
    }

    // quit
    snprintf(buffer, BUFFER_SIZE, "QUIT");
    n = send(sock_fd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error sending QUIT command");
        exit(1);
    }

    // receive response to quit
    bzero(buffer, BUFFER_SIZE);
    n = recv(sock_fd, buffer, BUFFER_SIZE-1, 0);
    if (n < 0) {
        perror("Error receiving response to QUIT");
        exit(1);
    }
    printf("%s", buffer);

    // close socket
    close(sock_fd);

    return 0;
}