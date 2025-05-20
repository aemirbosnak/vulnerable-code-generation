//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Constants
#define FTP_PORT 21
#define MAX_BUFFER_SIZE 1024

// Function prototypes
int connect_to_server(const char *hostname, int port);
int send_command(int sockfd, const char *command);
int receive_response(int sockfd, char *buffer, size_t size);
int disconnect_from_server(int sockfd);

int main(int argc, char **argv) {
    // Check if the user has provided the hostname
    if (argc < 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Connect to the server
    int sockfd = connect_to_server(argv[1], FTP_PORT);
    if (sockfd == -1) {
        perror("connect_to_server");
        return EXIT_FAILURE;
    }

    // Send the USER command
    if (send_command(sockfd, "USER anonymous") == -1) {
        perror("send_command");
        disconnect_from_server(sockfd);
        return EXIT_FAILURE;
    }

    // Receive the response from the server
    char buffer[MAX_BUFFER_SIZE];
    if (receive_response(sockfd, buffer, MAX_BUFFER_SIZE) == -1) {
        perror("receive_response");
        disconnect_from_server(sockfd);
        return EXIT_FAILURE;
    }

    // Check if the server accepted the USER command
    if (strncmp(buffer, "331", 3) != 0) {
        printf("Error: Server did not accept the USER command.\n");
        disconnect_from_server(sockfd);
        return EXIT_FAILURE;
    }

    // Send the PASS command
    if (send_command(sockfd, "PASS guest@example.com") == -1) {
        perror("send_command");
        disconnect_from_server(sockfd);
        return EXIT_FAILURE;
    }

    // Receive the response from the server
    if (receive_response(sockfd, buffer, MAX_BUFFER_SIZE) == -1) {
        perror("receive_response");
        disconnect_from_server(sockfd);
        return EXIT_FAILURE;
    }

    // Check if the server accepted the PASS command
    if (strncmp(buffer, "230", 3) != 0) {
        printf("Error: Server did not accept the PASS command.\n");
        disconnect_from_server(sockfd);
        return EXIT_FAILURE;
    }

    // Send the LIST command
    if (send_command(sockfd, "LIST") == -1) {
        perror("send_command");
        disconnect_from_server(sockfd);
        return EXIT_FAILURE;
    }

    // Receive the response from the server
    while (receive_response(sockfd, buffer, MAX_BUFFER_SIZE) != -1) {
        // Print the response to the console
        printf("%s", buffer);
    }

    // Disconnect from the server
    if (disconnect_from_server(sockfd) == -1) {
        perror("disconnect_from_server");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int connect_to_server(const char *hostname, int port) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        return -1;
    }

    // Resolve the hostname
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        close(sockfd);
        return -1;
    }

    // Create a sockaddr_in structure
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr = *(struct in_addr *)host->h_addr;

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        close(sockfd);
        return -1;
    }

    return sockfd;
}

int send_command(int sockfd, const char *command) {
    // Send the command to the server
    if (send(sockfd, command, strlen(command), 0) == -1) {
        return -1;
    }

    // Send a newline character
    if (send(sockfd, "\r\n", 2, 0) == -1) {
        return -1;
    }

    return 0;
}

int receive_response(int sockfd, char *buffer, size_t size) {
    // Receive the response from the server
    int bytes_received = recv(sockfd, buffer, size, 0);
    if (bytes_received == -1) {
        return -1;
    }

    // Null-terminate the buffer
    buffer[bytes_received] = '\0';

    return bytes_received;
}

int disconnect_from_server(int sockfd) {
    // Close the socket
    if (close(sockfd) == -1) {
        return -1;
    }

    return 0;
}