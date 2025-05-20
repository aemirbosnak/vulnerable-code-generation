//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function to connect to the POP3 server
int connectToServer(char* hostname, int port) {
    int sockfd;
    struct hostent* h;
    struct sockaddr_in server_addr;

    // Get host information
    if ((h = gethostbyname(hostname)) == NULL) {
        perror("Error: invalid hostname");
        return -1;
    }

    // Set up socket address information
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, h->h_addr, h->h_length);

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error: could not create sockfd");
        return -1;
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error: could not connect to server");
        return -1;
    }

    return sockfd;
}

// Function to authenticate with the server
int authenticate(int sockfd, char* username, char* password) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    // Read greeting message from server
    bytes_read = read(sockfd, buffer, BUFFER_SIZE);
    buffer[bytes_read] = '\0';
    printf("%s", buffer);

    // Send username
    sprintf(buffer, "USER %s\r\n", username);
    if (write(sockfd, buffer, strlen(buffer)) == -1) {
        perror("Error: could not send username");
        return -1;
    }

    // Read response
    bytes_read = read(sockfd, buffer, BUFFER_SIZE);
    buffer[bytes_read] = '\0';
    printf("%s", buffer);

    // Send password
    sprintf(buffer, "PASS %s\r\n", password);
    if (write(sockfd, buffer, strlen(buffer)) == -1) {
        perror("Error: could not send password");
        return -1;
    }

    // Read response
    bytes_read = read(sockfd, buffer, BUFFER_SIZE);
    buffer[bytes_read] = '\0';
    printf("%s", buffer);

    return 0;
}

int main(int argc, char* argv[]) {
    char* hostname;
    int port;
    char* username;
    char* password;

    // Get command line arguments
    if (argc != 5) {
        printf("Usage: %s <hostname> <port> <username> <password>\n", argv[0]);
        return 1;
    }
    hostname = argv[1];
    port = atoi(argv[2]);
    username = argv[3];
    password = argv[4];

    // Connect to server
    int sockfd = connectToServer(hostname, port);
    if (sockfd == -1) {
        return 1;
    }

    // Authenticate with server
    if (authenticate(sockfd, username, password) == -1) {
        return 1;
    }

    // Disconnect from server
    if (write(sockfd, "QUIT\r\n", 6) == -1) {
        perror("Error: could not send QUIT command");
        return 1;
    }
    close(sockfd);

    return 0;
}