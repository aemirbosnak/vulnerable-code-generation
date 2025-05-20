//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <arpa/nameser.h>

#define PORT 25
#define HOST "smtp.gmail.com"

struct email {
    char *from;
    char *to;
    char *subject;
    char *message;
};

int main() {
    struct email email;
    int sock;
    char buffer[1024];

    // Create email structure
    email.from = "john@example.com";
    email.to = "jane@example.com";
    email.subject = "Hello from C!";
    email.message = "This is the first email sent from C!";

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Set up socket address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, HOST, &server_addr.sin_addr);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(1);
    }

    // Send email
    send(sock, email.message, strlen(email.message), 0);

    // Receive email
    char *message = malloc(1024);
    recv(sock, message, 1024, 0);

    // Print received email
    printf("Received email: %s\n", message);

    // Close socket
    close(sock);

    return 0;
}