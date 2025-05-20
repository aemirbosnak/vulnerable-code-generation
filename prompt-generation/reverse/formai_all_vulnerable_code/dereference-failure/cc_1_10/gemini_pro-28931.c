//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: lively
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

// A lively greeting for our chat server!
void greet_server() {
    printf("Welcome to the Chat Palace!\n");
    printf("Grab a seat, make some friends, and let the conversation flow!\n\n");
}

// A server that's always listening, like a good friend :)
int main(int argc, char *argv[]) {
    // Let's get our server up and running!
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed.");
        exit(EXIT_FAILURE);
    }

    // Now let's give our server a place to listen for chatters
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[1]));
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Bind our server to that special place
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Bind failed.");
        exit(EXIT_FAILURE);
    }

    // Time to listen for incoming chatters
    if (listen(server_socket, 5) == -1) {
        perror("Listen failed.");
        exit(EXIT_FAILURE);
    }

    greet_server();

    // Our server is ready to chat! Let's keep it going until we're told to stop.
    while (1) {
        // Waiting for a new chatter to join the party
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
        if (client_socket == -1) {
            perror("Accept failed.");
            continue;
        }

        // Fork a new process to handle this chatter
        int pid = fork();
        if (pid == -1) {
            perror("Fork failed.");
            close(client_socket);
            continue;
        }

        // Child process: chat away!
        if (pid == 0) {
            close(server_socket);

            // Let's welcome our new friend!
            char welcome_message[] = "Welcome to the Chat Palace! Feel free to chat away!\n";
            send(client_socket, welcome_message, strlen(welcome_message), 0);

            // Time to chat!
            char buffer[1024];
            while (1) {
                // Waiting for our friend to say something
                memset(buffer, 0, sizeof(buffer));
                int recv_size = recv(client_socket, buffer, sizeof(buffer), 0);
                if (recv_size == -1) {
                    perror("Receive failed.");
                    break;
                } else if (recv_size == 0) {
                    // Our friend has left the chat
                    printf("Client disconnected.\n");
                    break;
                }

                // Echo back what our friend said
                send(client_socket, buffer, recv_size, 0);
            }

            // Time to say goodbye to our friend
            char goodbye_message[] = "Thanks for chatting! Come visit us again soon!\n";
            send(client_socket, goodbye_message, strlen(goodbye_message), 0);

            // All done chatting, let's close the connection
            close(client_socket);
            exit(EXIT_SUCCESS);
        }

        // Parent process: back to waiting for more chatters
        close(client_socket);
    }

    // Our server has served its purpose. Time to say farewell.
    close(server_socket);
    return EXIT_SUCCESS;
}