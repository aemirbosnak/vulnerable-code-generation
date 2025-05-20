//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAXLINE 1024
#define ENCODING_SHIFT 3  // For simple Caesar cipher

// Function prototypes
void encodeMessage(char *message, char *encoded);
void decodeMessage(char *encoded, char *decoded);
void startServer();
void startClient();

// Function to encode the message using Caesar cipher
void encodeMessage(char *message, char *encoded) {
    while (*message) {
        if (*message >= 'A' && *message <= 'Z') {
            *encoded = ((*message - 'A' + ENCODING_SHIFT) % 26) + 'A';
        } else if (*message >= 'a' && *message <= 'z') {
            *encoded = ((*message - 'a' + ENCODING_SHIFT) % 26) + 'a';
        } else {
            *encoded = *message; // Copy unchanged if not an alphabet
        }
        message++;
        encoded++;
    }
    *encoded = '\0'; // Null-terminate the string
}

// Function to decode the message using Caesar cipher
void decodeMessage(char *encoded, char *decoded) {
    while (*encoded) {
        if (*encoded >= 'A' && *encoded <= 'Z') {
            *decoded = ((*encoded - 'A' - ENCODING_SHIFT + 26) % 26) + 'A';
        } else if (*encoded >= 'a' && *encoded <= 'z') {
            *decoded = ((*encoded - 'a' - ENCODING_SHIFT + 26) % 26) + 'a';
        } else {
            *decoded = *encoded; // Copy unchanged if not an alphabet
        }
        encoded++;
        decoded++;
    }
    *decoded = '\0'; // Null-terminate the string
}

// Server code
void startServer() {
    int sockfd, new_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    char buffer[MAXLINE];
    char decoded[MAXLINE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(sockfd, 10);
    
    printf("Server listening on port %d...\n", PORT);
    addr_size = sizeof(client_addr);
    new_sock = accept(sockfd, (struct sockaddr *) &client_addr, &addr_size);
    
    while (1) {
        int n = recv(new_sock, buffer, MAXLINE, 0);
        if (n <= 0) break;
        buffer[n] = '\0'; // Null-terminate the received string
        decodeMessage(buffer, decoded);
        printf("Server received (decoded): %s\n", decoded);
        send(new_sock, "Message Received", strlen("Message Received"), 0);
    }

    close(new_sock);
    close(sockfd);
}

// Client code
void startClient() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[MAXLINE];
    char encoded[MAXLINE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    
    while (1) {
        printf("Enter a message to send (or 'exit' to quit): ");
        fgets(buffer, MAXLINE, stdin);
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline character

        if (strcmp(buffer, "exit") == 0) break;

        encodeMessage(buffer, encoded);
        send(sockfd, encoded, strlen(encoded), 0);
        
        recv(sockfd, buffer, MAXLINE, 0);
        printf("Server reply: %s\n", buffer);
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <server|client>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "server") == 0) {
        startServer();
    } else if (strcmp(argv[1], "client") == 0) {
        startClient();
    } else {
        fprintf(stderr, "Invalid argument. Use 'server' or 'client'\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}