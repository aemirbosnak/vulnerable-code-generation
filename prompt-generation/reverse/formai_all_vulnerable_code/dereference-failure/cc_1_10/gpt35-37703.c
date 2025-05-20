//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 8080

int main(int argc, char *argv[]) {

    struct sockaddr_in server;
    int socket_desc, client_sock, read_size;
    char client_message[2000];

    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        perror("Could not create socket");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    if (bind(socket_desc, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("Bind failed");
        return 1;
    }

    listen(socket_desc, 3);

    puts("Waiting for incoming connections...");
    int c = sizeof(struct sockaddr_in);
    while ((client_sock = accept(socket_desc, (struct sockaddr *) &server, (socklen_t*) &c))) {
        puts("Connection accepted");

        // Receive a message from client
        while ((read_size = recv(client_sock, client_message, 2000, 0)) > 0) {
            // Command parsing
            char* command;
            char* arg;

            command = strtok(client_message, " ");
            arg = strtok(NULL, " ");

            if (strcmp(command, "echo") == 0) {
                char echo_msg[2000] = "Echoing: ";
                strcat(echo_msg, arg);
                send(client_sock, echo_msg, strlen(echo_msg), 0);
            } else {
                char error_msg[] = "Invalid command";
                send(client_sock, error_msg, strlen(error_msg), 0);
            }
        }

        // Client disconnected
        puts("Client disconnected");
        fflush(stdout);
    }

    if (client_sock < 0) {
        perror("Accept failed");
        return 1;
    }

    return 0;
}