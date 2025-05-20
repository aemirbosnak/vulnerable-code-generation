//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 25
#define MAX_MESSAGE_LENGTH 512

struct email {
    char *from;
    char *to;
    char *subject;
    char *message;
};

int main(void) {
    int sock, client_sock;
    struct email email;
    char buffer[1024];

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    // Bind the socket to the address and port
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

    // Accept an incoming connection
    client_sock = accept(sock, NULL, NULL);
    if (client_sock < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    printf("Connection accepted from client...\n");

    // Read the email message from the client
    while (fgets(buffer, 1024, stdin) != NULL) {
        // Parse the email message
        char *message = strtok(buffer, "\r\n");
        email.from = strtok(NULL, "<");
        email.to = strtok(NULL, "<");
        email.subject = strtok(NULL, " ");
        email.message = message;

        // Send the email message to the next server
        if (send(client_sock, email.message, strlen(email.message), 0) < 0) {
            perror("send failed");
            exit(EXIT_FAILURE);
        }

        // Print the email message
        printf("Received email from %s to %s with subject %s and message %s\n",
               email.from, email.to, email.subject, email.message);
    }

    // Close the socket
    close(client_sock);

    return 0;
}