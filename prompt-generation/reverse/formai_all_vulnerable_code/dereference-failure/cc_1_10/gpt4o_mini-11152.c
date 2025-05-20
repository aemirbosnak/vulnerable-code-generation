//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT 21

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int create_connection(const char *hostname, int port) {
    struct sockaddr_in server_addr;
    struct hostent *server;

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR: No such host\n");
        return -1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
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

void send_command(int sockfd, const char *cmd) {
    write(sockfd, cmd, strlen(cmd));
    write(sockfd, "\r\n", 2);
}

void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n;
    while ((n = read(sockfd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
        if (buffer[3] == ' ') // Check for response ending
            break;
    }
}

void authenticate(int sockfd, const char *username, const char *password) {
    char cmd[BUFFER_SIZE];

    snprintf(cmd, BUFFER_SIZE, "USER %s", username);
    send_command(sockfd, cmd);
    read_response(sockfd);

    snprintf(cmd, BUFFER_SIZE, "PASS %s", password);
    send_command(sockfd, cmd);
    read_response(sockfd);
}

void list_files(int sockfd) {
    char cmd[BUFFER_SIZE];

    send_command(sockfd, "PASV");
    read_response(sockfd);

    // Starting passive mode to receive the data connection port
    char buffer[BUFFER_SIZE];
    int n = read(sockfd, buffer, sizeof(buffer) - 1);
    buffer[n] = '\0';
    
    int p1, p2;
    sscanf(strrchr(buffer, '('), "(%*d,%*d,%*d,%*d,%d,%d)", &p1, &p2);
    int data_port = p1 * 256 + p2;
    
    // Create data connection
    int data_sockfd = create_connection("127.0.0.1", data_port);
    if (data_sockfd < 0) return;

    send_command(sockfd, "LIST");
    read_response(sockfd);

    // Read file data from data connection
    memset(buffer, 0, sizeof(buffer));
    while ((n = read(data_sockfd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(data_sockfd);
    read_response(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    // Create connection
    int sockfd = create_connection(hostname, PORT);
    if (sockfd < 0) return EXIT_FAILURE;

    read_response(sockfd);
    
    // Authenticate user
    authenticate(sockfd, username, password);
    
    // List files
    list_files(sockfd);

    // Clean up
    close(sockfd);
    return EXIT_SUCCESS;
}