//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: active
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

int main(int argc, char *argv[]) {
    struct email email;
    int sock;
    char buffer[1024];

    if (argc != 4) {
        printf("Usage: %s <from> <to> <subject> <message>\n", argv[0]);
        return 1;
    }

    email.from = argv[1];
    email.to = argv[2];
    email.subject = argv[3];
    email.message = argv[4];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        return 1;
    }

    // Set up the server address
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = inet_addr("127.0.0.1") // Replace with your own IP address
    };

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        return 1;
    }

    // Send the email
    send(sock, email.message, strlen(email.message), 0);

    // Receive the response
    recv(sock, buffer, 1024, 0);

    // Print the response
    printf("%s\n", buffer);

    // Close the socket
    close(sock);

    return 0;
}