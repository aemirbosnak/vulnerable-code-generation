//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: curious
// Welcome to "The Curious Case of the Chatty Echoes," where a curious client and a quirky server embark on an adventure in the realm of communication.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

// The curious client, ever eager to explore the unknown, sets off on its journey.
int client_main(int argc, char *argv[]) {

    // First, it establishes a connection with the quirky server that resides at a distant shore.
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        puts("Alas, the client's attempt to connect failed.");
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2])); // The port, like a secret password, opens the door to communication.
    if (inet_aton(argv[1], &server_address.sin_addr) == 0) { // Converting IP address to network format, like translating a secret code.
        puts("The client's journey was hindered by an invalid IP.");
        return EXIT_FAILURE;
    }

    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        puts("The client's connection attempt stumbled.");
        return EXIT_FAILURE;
    }

    // The client, filled with anticipation, prepares to send its message to the server.
    char message[1024];
    printf("Unveil your message, curious client: ");
    fgets(message, sizeof(message), stdin); // The client's message, like a whisper carried by the wind.

    // With a swift motion, the client sends its message to the server, eager to hear the echo.
    if (send(client_socket, message, strlen(message), 0) == -1) {
        puts("The client's message failed to reach the server.");
        return EXIT_FAILURE;
    }

    // The client waits patiently for the server's echo, like a child awaiting a parent's response.
    char server_response[1024];
    if (recv(client_socket, server_response, sizeof(server_response), 0) == -1) {
        puts("The client's ears failed to catch the server's echo.");
        return EXIT_FAILURE;
    }

    // The moment of truth arrives as the client beholds the server's response.
    printf("Hark! The server's echo: %s", server_response); // The server's echo, like a mirror reflecting the client's words.

    // The client, its purpose fulfilled, bids farewell to the server.
    close(client_socket);

    return EXIT_SUCCESS;
}

// The quirky server, always ready for a chat, awaits the client's arrival.
int server_main(int argc, char *argv[]) {

    // The server establishes a listening point, like a lighthouse beckoning ships to its harbor.
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        puts("Alas, the server's listening point could not be established.");
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[1]));
    server_address.sin_addr.s_addr = INADDR_ANY; // The server opens its doors to all who seek its wisdom.

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        puts("The server's listening point could not be bound.");
        return EXIT_FAILURE;
    }

    if (listen(server_socket, 5) == -1) { // The server prepares to listen, like a patient teacher awaiting students.
        puts("The server's ears failed to open.");
        return EXIT_FAILURE;
    }

    struct sockaddr_in client_address;
    socklen_t client_address_size = sizeof(client_address);
    int client_socket;

    while (1) { // The server enters an endless loop, always ready for a new connection, like an eternal guardian.

        // A client approaches! The server welcomes it with open arms.
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_size);
        if (client_socket == -1) {
            puts("The server's attempt to welcome the client failed.");
            continue;
        }

        // The client whispers its message to the server, like a secret shared between friends.
        char client_message[1024];
        if (recv(client_socket, client_message, sizeof(client_message), 0) == -1) {
            puts("The server failed to hear the client's whisper.");
            close(client_socket);
            continue;
        }

        // The server, like a wise mentor, echoes the client's message back to it.
        if (send(client_socket, client_message, strlen(client_message), 0) == -1) {
            puts("The server's echo failed to reach the client.");
            close(client_socket);
            continue;
        }

        // The server bids farewell to the client, its purpose fulfilled.
        close(client_socket);
    }

    close(server_socket);

    return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) {

    // The curious client and the quirky server come together, their fates intertwined.
    if (argc < 3) {
        puts("Please provide the server's IP address and port number.");
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "-c") == 0) { // The client's journey begins.
        return client_main(argc, argv);
    } else if (strcmp(argv[1], "-s") == 0) { // The server's adventure unfolds.
        return server_main(argc, argv);
    } else {
        puts("Invalid option. Please specify '-c' for client or '-s' for server.");
        return EXIT_FAILURE;
    }
}