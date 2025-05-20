//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/wait.h>

#define PORT 25
#define HOST "smtp.gmail.com"

typedef struct {
    char *email;
    char *password;
} user_info_t;

user_info_t users[] = {
    {"john", "doe"},
    {"jane", "smith"},
    {"bob", "jones"}
};

int main() {
    int sock, port, i;
    struct sockaddr_in server;
    char buffer[256];

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(HOST);
    server.sin_port = htons(PORT);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connect failed");
        exit(EXIT_FAILURE);
    }

    // Loop through the users and send their emails
    for (i = 0; i < sizeof(users) / sizeof(users[0]); i++) {
        // Get the current user's email and password
        char *email = users[i].email;
        char *password = users[i].password;

        // Build the email message
        sprintf(buffer, "Hello %s!", email);

        // Send the email
        send(sock, buffer, strlen(buffer), 0);

        // Receive the response
        recv(sock, buffer, 256, 0);

        // Print the response
        printf("Server responded with: %s\n", buffer);
    }

    // Close the socket
    close(sock);

    return 0;
}