//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 25
#define MAX_MESSAGE_LENGTH 512

struct email {
    char *from;
    char *to;
    char *subject;
    char *message;
};

int main() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Set up the server address
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    // Bind the socket to the address and port
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sock, 5) < 0) {
        perror("Listening failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", PORT);

    // Accept an incoming connection
    int client_sock = accept(sock, NULL, NULL);
    if (client_sock < 0) {
        perror("Accept failed");
        exit(1);
    }

    printf("Connection accepted from client...\n");

    // Read the email message from the client
    char message[MAX_MESSAGE_LENGTH];
    read(client_sock, message, sizeof(message));

    // Print the email message
    printf("Received email message from client:\n%s\n", message);

    // Create a new email structure to hold the message
    struct email email;
    email.from = "grateful@example.com";
    email.to = "lucky@example.com";
    email.subject = "Thank you for connecting!";
    email.message = message;

    // Send the email back to the client
    char send_message[MAX_MESSAGE_LENGTH];
    sprintf(send_message, "Thank you for your email! %s", message);
    write(client_sock, send_message, strlen(send_message));

    // Close the client socket
    close(client_sock);

    // Print a grateful message
    printf("Thank you for using our email client! Have a great day!\n");

    return 0;
}