//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int create_connection(char *hostname, int port) {
    struct sockaddr_in server_addr;
    struct hostent *host;

    host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error: No such host\n");
        exit(EXIT_FAILURE);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)host->h_addr, (char *)&server_addr.sin_addr.s_addr, host->h_length);
    server_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error("Error connecting");
    }

    return sockfd;
}

void send_command(int sockfd, const char *command) {
    if (send(sockfd, command, strlen(command), 0) < 0) {
        error("Error sending command");
    }
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n;

    bzero(buffer, BUFFER_SIZE);
    n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (n < 0) {
        error("Error receiving response");
    }
    
    printf("%s", buffer);
}

bool login_to_ftp(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    // Sending USER command
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(sockfd, command);
    receive_response(sockfd);

    // Sending PASS command
    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(sockfd, command);
    receive_response(sockfd);

    return true;
}

void list_files(int sockfd) {
    char command[BUFFER_SIZE];

    // Sending PASV command
    send_command(sockfd, "PASV\r\n");
    receive_response(sockfd);

    // Sample response: 227 Entering Passive Mode (127,0,0,1,196,191)
    int p1, p2;
    sscanf(strstr(command, "(") + 1, "%*d,%*d,%*d,%*d,%d,%d", &p1, &p2);
    int data_port = (p1 << 8) + p2;

    // Creating data connection
    int data_sockfd = create_connection("127.0.0.1", data_port);

    // Send LIST command
    send_command(sockfd, "LIST\r\n");
    receive_response(sockfd);

    // Close data connection
    close(data_sockfd);
}

void ftp_client(char *hostname, char *username, char *password) {
    // Create Control Connection
    int control_sockfd = create_connection(hostname, 21);
    receive_response(control_sockfd);

    // Login to FTP
    if (!login_to_ftp(control_sockfd, username, password)) {
        printf("Login failed.\n");
    } else {
        printf("Login successful.\n");
        list_files(control_sockfd);
    }

    // Send QUIT command
    send_command(control_sockfd, "QUIT\r\n");
    receive_response(control_sockfd);
    
    // Close control connection
    close(control_sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *hostname = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    ftp_client(hostname, username, password);

    return 0;
}