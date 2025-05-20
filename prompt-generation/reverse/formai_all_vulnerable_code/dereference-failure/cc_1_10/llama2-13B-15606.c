//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_CLIENT_LEN 1024
#define MAX_SERVER_LEN 1024
#define PORT 8080

struct node {
    int id;
    char name[MAX_CLIENT_LEN];
    char type[MAX_CLIENT_LEN];
    int weight;
    struct node *next;
};

int main(int argc, char *argv[]) {
    int sock, cli_sock;
    struct sockaddr_in server, client;
    struct node *head, *tail;
    char buffer[256];

    // Create the server socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind the server socket to the address and port
    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // Create a new client socket
    cli_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (cli_sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Connect the client socket to the server
    if (connect(cli_sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connecting failed");
        exit(EXIT_FAILURE);
    }

    // Create a new node for the client
    head = tail = (struct node *)malloc(sizeof(struct node));
    head->id = cli_sock;
    strcpy(head->name, "Client");
    strcpy(head->type, "User");
    head->weight = 1;
    head->next = NULL;

    // Send the client's information to the server
    send(cli_sock, head, sizeof(struct node), 0);

    // Receive the server's response
    recv(sock, buffer, 256, 0);

    // Print the received message
    printf("Server response: %s\n", buffer);

    // Close the sockets
    close(sock);
    close(cli_sock);

    return 0;
}