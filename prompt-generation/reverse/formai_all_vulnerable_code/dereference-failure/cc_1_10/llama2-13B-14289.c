//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_MESSAGE_SIZE 512
#define MAX_EMAIL_ADDRESS_SIZE 64

typedef struct {
    char *email_address;
    char *message;
} email_t;

int main() {
    int sock, port;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    port = 1025; // random port chosen by the curious programmer
    printf("Listening on port %d...\n", port);

    while (1) {
        email_t email;
        printf("Enter email address: ");
        fgets(email.email_address, MAX_EMAIL_ADDRESS_SIZE, stdin);
        printf("Enter message: ");
        fgets(email.message, MAX_MESSAGE_SIZE, stdin);

        // Send email over the network
        struct sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            perror("Connection failed");
            exit(EXIT_FAILURE);
        }

        send(sock, email.message, strlen(email.message), 0);

        // Receive email from the network
        char buffer[1024];
        recv(sock, buffer, 1024, 0);

        // Print received email
        printf("Received email from %s:\n%s\n", email.email_address, buffer);

        // Exit if no more emails to send
        if (email.message == NULL) {
            break;
        }
    }

    close(sock);
    return 0;
}