//FormAI DATASET v1.0 Category: Networking ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {

    if (argc != 4) {
        printf("Usage: %s <server_ip> <port_number> <funny_message>\n", argv[0]);
        return 1;
    }

    // Step 1: Create the socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error: Could not create socket. Are you out of sockets?\n");
        return 1;
    }

    // Step 2: Prepare the socket connection parameters
    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));

    // Step 3: Connect to the server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Error: Could not connect to server. Is it down or is your network down?\n");
        return 1;
    }

    // Step 4: Send the message to the server
    char *message = argv[3];
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("Error: Could not send message to server. Is your message too funny for the server?\n");
        return 1;
    }

    // Step 5: Receive the response from the server
    char server_reply[2000];
    if (recv(sock, server_reply, 2000, 0) < 0) {
        printf("Error: Could not receive message from server. Did the server get mad at your funny message?\n");
        return 1;
    }

    // Step 6: Print the server's response
    printf("Server: %s\n", server_reply);

    return 0;
}