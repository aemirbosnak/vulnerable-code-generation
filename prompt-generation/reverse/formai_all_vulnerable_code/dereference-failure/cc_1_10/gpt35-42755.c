//FormAI DATASET v1.0 Category: Networking ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFF_SIZE 1024

void sendMessage(int sock, char *message) {
    int len = strlen(message);
    send(sock, message, len, 0);
    printf("Sent message to the server: %s\n", message);
}

int receiveMessage(int sock, char *buffer) {
    int recv_size = recv(sock, buffer, BUFF_SIZE, 0);
    buffer[recv_size] = '\0';
    printf("Received message from server: %s\n", buffer);
    return recv_size > 0;
}

int main() {
    int sock;
    struct sockaddr_in server;
    char server_reply[BUFF_SIZE];
    char message[BUFF_SIZE];

    //Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Oh no! Could not create socket :(\n");
        exit(1);
    }

    printf("Socket created successfully! Let's communicate with a server.\n");

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);

    //Connect to remote server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Uh oh, connection failed :(.\n");
        exit(1);
    }

    printf("Connected successfully to the server, ready to chat! Type 'bye' to quit.\n");

    while (1) {
        printf("Enter your message: ");
        fgets(message, BUFF_SIZE, stdin);
        message[strcspn(message, "\n")] = '\0';
        sendMessage(sock, message);

        if (strcmp(message, "bye") == 0) {
            printf("Goodbye, it's been fun! :)\n");
            break;
        }

        if (!receiveMessage(sock, server_reply)) {
            printf("Uh oh, there was an error receiving message from server. \n");
            exit(1);
        }

        if (strcmp(server_reply, "bye") == 0) {
            printf("Server has decided to leave. Goodbye! :(\n");
            break;
        }
    }

    close(sock);
    return 0;
}