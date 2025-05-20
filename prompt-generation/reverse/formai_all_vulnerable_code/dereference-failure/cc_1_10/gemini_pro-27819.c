//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: immersive
// Embark on an Immersive TCP/IP Odyssey

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

// Embark as the Mighty Server
void serverVoyage() {
    // Forge your Destiny
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;

    // Cast your Net
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set Sail to a Known Port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    // Bind to the Port, Establishing your Presence
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Raise your Anchor, Ready to Receive
    if (listen(server_fd, 5) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Await a Distant Call
    while (1) {
        client_addr_len = sizeof(client_addr);
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_fd == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Handle Communication with the Voyager
        char buffer[1024];
        memset(buffer, 0, sizeof(buffer));
        recv(client_fd, buffer, 1024, 0);
        printf("Received Message: %s\n", buffer);
        send(client_fd, "Greetings from the Server!", 27, 0);

        // Part Ways Once More
        close(client_fd);
    }
}

// Set Forth as the Adventurous Client
void clientExpedition() {
    // Chart your Course
    int client_fd;
    struct sockaddr_in server_addr;
    struct hostent *host;

    // Acquire your Destination
    host = gethostbyname("127.0.0.1");
    if (!host) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    // Embark on your Journey
    client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set Sail for the Distant Port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr_list[0], host->h_length);
    server_addr.sin_port = htons(8080);

    // Make Contact with the Server
    if (connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send your Message
    char buffer[] = "Ahoy! Greetings from the Client!";
    if (send(client_fd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive a Reply from the Server
    memset(buffer, 0, sizeof(buffer));
    recv(client_fd, buffer, 1024, 0);
    printf("Received Message: %s\n", buffer);

    // End your Excursion
    close(client_fd);
}

// Embark on your Odyssey
int main() {
    int choice;
    printf("Embark on a TCP/IP Odyssey:\n");
    printf("1. Server\n");
    printf("2. Client\n");
    scanf("%d", &choice);

    // Choose your Destiny
    switch (choice) {
        case 1:
            serverVoyage();
            break;
        case 2:
            clientExpedition();
            break;
        default:
            printf("Invalid Choice\n");
    }

    return 0;
}