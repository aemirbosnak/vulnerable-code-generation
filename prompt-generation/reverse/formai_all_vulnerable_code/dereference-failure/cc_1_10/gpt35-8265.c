//FormAI DATASET v1.0 Category: Networking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sock, n, c, port;
    struct sockaddr_in server;
    char message[1000], server_reply[2000];

    // Check if the user entered the port number as command line argument
    if (argc == 2) {
        port = atoi(argv[1]);
    } else {
        // If not, prompt the user to enter the port number
        printf("Please enter the port number: ");
        scanf("%d", &port);
    }

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
    }

    // Set up address structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(port);

    // Connect to remote server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connection failed");
        return 1;
    }

    printf("Connected to server on port %d\n", port);

    // Keep communicating with server
    while (1) {
        printf("Enter message to send: ");
        fgets(message, sizeof(message), stdin);

        // Remove newline character
        c = strlen(message) - 1;
        if (message[c] == '\n') {
            message[c] = '\0';
        }

        // Send message to server
        if (send(sock, message, strlen(message), 0) < 0) {
            perror("Send failed");
            return 1;
        }

        // Receive reply from server
        memset(server_reply, 0, sizeof(server_reply));
        n = recv(sock, server_reply, sizeof(server_reply), 0);
        if (n < 0) {
            perror("Receive failed");
            return 1;
        }

        printf("Server reply: %s\n", server_reply);
    }

    close(sock);
    return 0;
}