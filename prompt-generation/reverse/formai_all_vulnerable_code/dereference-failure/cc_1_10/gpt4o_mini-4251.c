//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_RESPONSE_SIZE 1024

// Function declarations
void connect_to_pop3_server(const char *server, int port);
void authenticate(const char *username, const char *password);
void list_messages();
void cleanup();

int sockfd; // Socket file descriptor for the connection

// The main function serves as the entrance to our transformative journey.
int main(int argc, char *argv[]) {
    // Initial checks for inputs
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <POP3 Server> <Username> <Password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *pop3_server = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    connect_to_pop3_server(pop3_server, 110);
    authenticate(username, password);
    list_messages();
    cleanup();

    return 0; // Exit gracefully
}

// This function transforms our intent as we connect to a server
void connect_to_pop3_server(const char *server, int port) {
    struct sockaddr_in server_address;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Set up server address structure
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    inet_pton(AF_INET, server, &server_address.sin_addr);

    // Connecting to the server
    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Unable to connect to the POP3 server");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Connected to POP3 server %s\n", server);
}

// Authentication metamorphosis takes place here
void authenticate(const char *username, const char *password) {
    char command[MAX_RESPONSE_SIZE];
    char response[MAX_RESPONSE_SIZE];

    // Read server's greeting
    read(sockfd, response, sizeof(response));
    printf("%s", response); // Print server's greeting

    // Send USER command
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    write(sockfd, command, strlen(command));
    read(sockfd, response, sizeof(response));
    printf("%s", response);

    // Send PASS command
    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    write(sockfd, command, strlen(command));
    read(sockfd, response, sizeof(response));
    printf("%s", response);
}

// List messages metamorphoses into a new form
void list_messages() {
    char command[MAX_RESPONSE_SIZE];
    char response[MAX_RESPONSE_SIZE];

    // Send LIST command to server
    snprintf(command, sizeof(command), "LIST\r\n");
    write(sockfd, command, strlen(command));
    read(sockfd, response, sizeof(response));
    printf("%s", response); // Output the list of messages

    if (strncmp(response, "+OK", 3) == 0) {
        printf("Messages list retrieved successfully.\n");
    } else {
        printf("Failed to retrieve message list.\n");
    }
}

// As we exit, we clean up the formed shapes
void cleanup() {
    // Sending QUIT command
    char *command = "QUIT\r\n";
    write(sockfd, command, strlen(command));
    close(sockfd);
    printf("Disconnected from the server. Cleanup complete.\n");
}