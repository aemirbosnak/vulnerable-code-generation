//FormAI DATASET v1.0 Category: Socket programming ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sock, port, shape;
    struct sockaddr_in server;
    char message[100], server_reply[200];

    // Shape shifting based on number of command line arguments
    if (argc >= 4) {
        port = atoi(argv[1]);
        shape = atoi(argv[2]);
        strcpy(message, argv[3]);
    } else if (argc == 3) {
        port = atoi(argv[1]);
        shape = atoi(argv[2]);
        printf("Enter message: ");
        fgets(message, 100, stdin);
        message[strcspn(message, "\n")] = '\0'; // Remove trailing newline character
    } else {
        printf("Usage: %s <port> <shape> <message>\n", argv[0]);
        printf("Shapes:\n  1 - square\n  2 - circle\n  3 - triangle\n");
        return 1;
    }

    // Shape shifting based on user input
    switch (shape) {
        case 1:
            sprintf(message, "SQUARE|%s", message);
            break;
        case 2:
            sprintf(message, "CIRCLE|%s", message);
            break;
        case 3:
            sprintf(message, "TRIANGLE|%s", message);
            break;
        default:
            printf("Invalid shape.\n");
            return 1;
    }

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket.\n");
        return 1;
    }

    // Prepare server address structure
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    // Connect to remote server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Could not connect to server.\n");
        return 1;
    }

    // Send data to server
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("Send failed.\n");
        return 1;
    }

    // Receive from server
    if (recv(sock, server_reply, 200, 0) < 0) {
        printf("Receive failed.\n");
        return 1;
    }

    printf("Server reply: %s\n", server_reply);

    // Close socket
    close(sock);

    return 0;
}