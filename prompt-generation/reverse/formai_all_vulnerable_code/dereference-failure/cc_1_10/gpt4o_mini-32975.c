//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024
#define DEFAULT_PORT 21

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int create_socket(const char *hostname, int port) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Error: No such host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    memset((char *)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy((char *)&server_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    server_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting");
    }

    return sockfd;
}

void send_command(int sockfd, const char *command) {
    write(sockfd, command, strlen(command));
    write(sockfd, "\r\n", 2);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n;

    while ((n = read(sockfd, buffer, BUFFER_SIZE - 1)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
        if (buffer[0] == '2') break; // Assuming a command completion response
    }
}

void login(int sockfd, const char *user, const char *pass) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "USER %s", user);
    send_command(sockfd, command);
    receive_response(sockfd);

    snprintf(command, sizeof(command), "PASS %s", pass);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void list_files(int sockfd) {
    char command[BUFFER_SIZE];

    send_command(sockfd, "PASV");
    receive_response(sockfd); // Get passive mode response

    // Assuming you have parsed the port from PASS command response and setup a data connection

    send_command(sockfd, "LIST");
    receive_response(sockfd); // Fetch and print the list of files
}

void close_connection(int sockfd) {
    send_command(sockfd, "QUIT");
    receive_response(sockfd);
    close(sockfd);
}

int main(int argc, char *argv[]) {
    int sockfd;
    char *hostname, *username, *password;

    if (argc < 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    hostname = argv[1];
    username = argv[2];
    password = argv[3];

    sockfd = create_socket(hostname, DEFAULT_PORT);
    receive_response(sockfd); // Initial server greeting

    login(sockfd, username, password); // Log in

    list_files(sockfd); // List files

    close_connection(sockfd); // Clean up

    return 0;
}