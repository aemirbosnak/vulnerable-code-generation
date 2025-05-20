//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

// UDP Echo Server
void start_udp_server() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len;
    char buffer[BUFFER_SIZE];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
        error("Socket creation failed");

    // Set server address and port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // Listen on all interfaces
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the address and port
    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        error("Bind failed");

    printf("UDP Echo Server is running on port %d...\n", PORT);

    while (1) {
        addr_len = sizeof(client_addr);
        int n = recvfrom(sockfd, buffer, BUFFER_SIZE, MSG_WAITALL, (struct sockaddr *)&client_addr, &addr_len);
        buffer[n] = '\0'; // Null-terminate the received string

        printf("Received message: %s\n", buffer);

        // Echo the message back to the client
        sendto(sockfd, buffer, n, MSG_CONFIRM, (const struct sockaddr *)&client_addr, addr_len);
        printf("Echoed message back to client.\n");
    }

    close(sockfd);
}

// UDP Client
void start_udp_client(const char *message) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
        error("Socket creation failed");

    memset(&server_addr, 0, sizeof(server_addr));

    // Set server address and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost

    // Send the message to the server
    sendto(sockfd, message, strlen(message), MSG_CONFIRM, (const struct sockaddr *)&server_addr, sizeof(server_addr));
    printf("Message sent to server: %s\n", message);

    // Receive the echoed message
    socklen_t addr_len = sizeof(server_addr);
    int n = recvfrom(sockfd, buffer, BUFFER_SIZE, MSG_WAITALL, (struct sockaddr *)&server_addr, &addr_len);
    buffer[n] = '\0'; // Null-terminate the received string

    printf("Echoed message received: %s\n", buffer);

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <message_to_send>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Start the server in a separate thread/process
    if (fork() == 0) {
        start_udp_server();
        exit(0);
    }

    // Pause for the server to initialize
    sleep(1);

    // Start the client to send a message
    start_udp_client(argv[1]);

    return 0;
}