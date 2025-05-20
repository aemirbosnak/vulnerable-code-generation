//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: Romeo and Juliet
// Romeo and Juliet Client-Server Application
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

// Quotes to be shared between server and client
const char *quotes[] = {
    "But, soft! What light through yonder window breaks?",
    "My bounty is as boundless as the sea,",
    "For I ne'er saw true beauty till this night.",
    "With love's light, think about it, my dear!",
    "These violent delights have violent ends.",
    "Good night, good night! Parting is such sweet sorrow.",
    "O, I am fortune's fool!",
    "Thus with a kiss, I die."
};

// Server function
void start_server(int port) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("The Server: Ready to receive the request of love...\n");

    // Accepting a client
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    int quote_index = 0;
    while (quote_index < sizeof(quotes) / sizeof(quotes[0])) {
        send(new_socket, quotes[quote_index], strlen(quotes[quote_index]), 0);
        printf("The Server: Sent quote %d - \"%s\"\n", quote_index + 1, quotes[quote_index]);
        quote_index++;
        sleep(1);
    }

    close(new_socket);
    close(server_fd);
}

// Client function
void start_client(const char *ip_address, int port) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    // Creating socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, ip_address, &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address or Address not supported \n");
        return;
    }

    // Connecting to server
    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return;
    }

    printf("The Client: Yearning for words of love...\n");

    // Receiving quotes
    while (1) {
        int valread = read(sock, buffer, 1024);
        if (valread <= 0) {
            break; // Server has closed the connection
        }
        printf("The Client: Received Quote - \"%s\"\n", buffer);
        memset(buffer, 0, sizeof(buffer));  // Clear the buffer
    }

    close(sock);
}

// Entry point: Choose between server and client
int main(int argc, char const *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <server|client> <port> [<ip_address>]\n", argv[0]);
        return EXIT_FAILURE;
    }

    int port = atoi(argv[2]);

    if (strcmp(argv[1], "server") == 0) {
        start_server(port);
    } else if (strcmp(argv[1], "client") == 0) {
        if (argc < 4) {
            fprintf(stderr, "Client mode requires <ip_address>.\n");
            return EXIT_FAILURE;
        }
        start_client(argv[3], port);
    } else {
        fprintf(stderr, "Unknown mode. Use 'server' or 'client'.\n");
        return EXIT_FAILURE;
    }

    return 0;
}