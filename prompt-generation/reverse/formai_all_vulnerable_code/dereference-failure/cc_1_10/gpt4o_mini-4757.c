//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SERVER_PORT 21
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    send(sockfd, "\r\n", 2, 0);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;
    
    bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        error("Error receiving data from server");
    }
    
    buffer[bytes_received] = '\0';
    printf("Server response: %s", buffer);
}

void authenticate(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "USER %s", username);
    send_command(sockfd, command);
    receive_response(sockfd);
    
    snprintf(command, sizeof(command), "PASS %s", password);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void list_files(int sockfd) {
    char command[BUFFER_SIZE];
    char data_cmd[BUFFER_SIZE];
    int data_sockfd;
    struct sockaddr_in data_addr;
    socklen_t addr_size = sizeof(data_addr);
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Create a socket for data connection
    data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sockfd < 0) {
        error("Error creating data socket");
    }

    // Prepare to listen for incoming data connection
    memset(&data_addr, 0, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    data_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    data_addr.sin_port = htons(0);

    if (bind(data_sockfd, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        error("Error binding data socket");
    }

    listen(data_sockfd, 1);
    // Notify server to use this data connection
    snprintf(data_cmd, sizeof(data_cmd), "PASV");
    send_command(sockfd, data_cmd);
    receive_response(sockfd);
    
    // Extract port number from server's response
    // Assume response format is (227 Entering Passive Mode (h1,h2,h3,h4,p1,p2))
    char *token = strtok(buffer, ",");
    for (int i = 0; i < 5 && token != NULL; i++) {
        token = strtok(NULL, ",");
    }
    
    int p1 = atoi(token);
    int p2 = atoi(strtok(NULL, ")"));
    int port = (p1 << 8) + p2;

    data_addr.sin_port = htons(port);
    
    // Accepting incoming data connection
    if (connect(data_sockfd, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        error("Error connecting data socket");
    }

    snprintf(command, sizeof(command), "LIST");
    send_command(sockfd, command);
    receive_response(sockfd);
    
    // Read list of files from the data connection
    bytes_received = recv(data_sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        error("Error receiving file list");
    }
    buffer[bytes_received] = '\0';
    printf("List of files:\n%s\n", buffer);

    close(data_sockfd);
}

void ftp_client(const char *server_ip, const char *username, const char *password) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error creating socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        error("Invalid server IP address");
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection to server failed");
    }

    receive_response(sockfd);
    authenticate(sockfd, username, password);
    list_files(sockfd);
    
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server_ip> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ftp_client(argv[1], argv[2], argv[3]);
    return 0;
}