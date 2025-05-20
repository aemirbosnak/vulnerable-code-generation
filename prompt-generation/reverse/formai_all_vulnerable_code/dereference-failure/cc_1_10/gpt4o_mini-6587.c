//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define POP3_PORT 110
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int sockfd, const char *cmd, char *response, size_t size) {
    send(sockfd, cmd, strlen(cmd), 0);
    send(sockfd, "\r\n", 2, 0);
    
    recv(sockfd, response, size, 0);
    printf("Server Response: %s\n", response);
}

void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    while ((bytes_read = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    struct sockaddr_in server_address;
    struct hostent *host;

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("ERROR opening socket");

    // Get host by name
    host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    // Fill server_address struct
    bzero((char *)&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *)host->h_addr, (char *)&server_address.sin_addr.s_addr, host->h_length);
    server_address.sin_port = htons(POP3_PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        error("ERROR connecting");
    }

    char response[BUFFER_SIZE];
    
    // Read server greeting
    read_response(sockfd);
    
    // Send USER command
    snprintf(response, sizeof(response), "USER %s", username);
    send_command(sockfd, response, response, sizeof(response));
    
    // Send PASS command
    snprintf(response, sizeof(response), "PASS %s", password);
    send_command(sockfd, response, response, sizeof(response));

    // Send STAT command to get message stats
    send_command(sockfd, "STAT", response, sizeof(response));

    // Send LIST command to get list of messages
    send_command(sockfd, "LIST", response, sizeof(response));

    // Send RETR command to retrieve the first message (1)
    snprintf(response, sizeof(response), "RETR 1");
    send_command(sockfd, response, response, sizeof(response));
    
    // Send QUIT command to close connection
    send_command(sockfd, "QUIT", response, sizeof(response));

    // Close socket
    close(sockfd);

    return 0;
}