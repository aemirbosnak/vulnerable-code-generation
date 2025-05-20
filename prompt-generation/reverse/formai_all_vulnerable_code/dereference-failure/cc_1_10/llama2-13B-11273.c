//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct phone_book {
    char name[50];
    char number[20];
};

int main(void) {
    struct phone_book *pb;
    int sock, client_sock;
    socklen_t client_len = sizeof(struct sockaddr_in);
    struct sockaddr_in client_addr, server_addr;
    char buffer[256];

    // Create a phone book
    pb = malloc(sizeof(struct phone_book));
    pb->name[0] = '\0';
    pb->number[0] = '\0';

    // Create a server socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set address and port number for the server
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the server socket to the address and port
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept an incoming connection
        if ((client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Read name and number from the client
        printf("Please enter name and number: ");
        fgets(buffer, 256, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        strcpy(pb->name, buffer);
        strcpy(pb->number, buffer);

        // Send the name and number back to the client
        send(client_sock, pb->name, strlen(pb->name), 0);
        send(client_sock, pb->number, strlen(pb->number), 0);

        // Close the client socket
        close(client_sock);
    }

    return 0;
}