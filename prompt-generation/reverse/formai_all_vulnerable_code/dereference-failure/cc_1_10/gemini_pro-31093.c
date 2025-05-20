//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: cheerful
// Let's set the stage for a whimsical chat adventure!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Let's establish our communication portal!
#define PORT 8080

// Define our chatty characters:
typedef struct {
    char name[20];
    char message[100];
} Chatter;

// Server-side magic:
void server(int argc, char *argv[]) {
    // Prepare our communication portal:
    int server_fd, conn_fd;
    socklen_t addrlen;
    struct sockaddr_in server_addr, client_addr;

    // Open the portal:
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Socket creation failed!");
        exit(EXIT_FAILURE);
    }

    // Set up our communication address:
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the address to the portal:
    if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed!");
        exit(EXIT_FAILURE);
    }

    // Open for business:
    if (listen(server_fd, 5) < 0) {
        perror("Listen failed!");
        exit(EXIT_FAILURE);
    }

    // Ready to welcome a chatty friend:
    printf("Awaiting a chatty companion...\n");

    // Let the conversation begin:
    while (1) {
        // Greet the new friend:
        addrlen = sizeof(client_addr);
        conn_fd = accept(server_fd, (struct sockaddr *) &client_addr, &addrlen);
        if (conn_fd < 0) {
            perror("Accept failed!");
            exit(EXIT_FAILURE);
        }

        // Get ready to receive messages:
        Chatter chatter;

        // Keep the conversation flowing:
        while (recv(conn_fd, &chatter, sizeof(chatter), 0) > 0) {
            // Display the chatty message:
            printf("%s: %s\n", chatter.name, chatter.message);

            // Send a cheerful response:
            strcpy(chatter.message, "Glad to chat with you too!");
            send(conn_fd, &chatter, sizeof(chatter), 0);
        }

        // Say goodbye to the departing friend:
        close(conn_fd);
    }

    // Close the communication portal:
    close(server_fd);
}

// Client-side charm:
void client(int argc, char *argv[]) {
    // Knock on the server's door:
    int client_fd;
    socklen_t addrlen;
    struct sockaddr_in server_addr;

    // Open the communication channel:
    client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd < 0) {
        perror("Socket creation failed!");
        exit(EXIT_FAILURE);
    }

    // Set up the server's address:
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(PORT);

    // Knock on the door:
    addrlen = sizeof(server_addr);
    if (connect(client_fd, (struct sockaddr *) &server_addr, addrlen) < 0) {
        perror("Connection failed!");
        exit(EXIT_FAILURE);
    }

    // Introduce yourself:
    Chatter chatter;
    printf("Enter your chatty name: ");
    scanf("%s", chatter.name);

    // Chat away!
    while (1) {
        // Send a cheerful message:
        printf("Send a message: ");
        scanf(" %[^\n]%*c", chatter.message);
        send(client_fd, &chatter, sizeof(chatter), 0);

        // Listen for a response:
        recv(client_fd, &chatter, sizeof(chatter), 0);
        printf("%s: %s\n", chatter.name, chatter.message);
    }

    // Say goodbye:
    close(client_fd);
}

int main(int argc, char *argv[]) {
    // Choose your chatty role:
    if (argc < 2) {
        printf("Usage: %s [server/client] [server IP (for client only)]\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Let's start the chatty adventure:
    if (strcmp(argv[1], "server") == 0) {
        server(argc, argv);
    } else if (strcmp(argv[1], "client") == 0) {
        client(argc, argv);
    } else {
        printf("Invalid role! Choose 'server' or 'client'.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}