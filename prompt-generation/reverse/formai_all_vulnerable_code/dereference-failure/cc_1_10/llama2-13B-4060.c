//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080

struct email {
    char *from;
    char *to;
    char *subject;
    char *body;
};

int main(int argc, char *argv[]) {
    int sock, port;
    struct email email;

    // Check if the user has provided a hostname and port number
    if (argc != 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        return 1;
    }

    // Set the address and port number
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        return 1;
    }

    // Read the email message from the standard input
    printf("Enter email message (subject <subject>, from <from>, to <to>, body <body>): ");
    fgets(email.subject, 100, stdin);
    fgets(email.from, 100, stdin);
    fgets(email.to, 100, stdin);
    fgets(email.body, 100, stdin);

    // Send the email message to the server
    send(sock, email.subject, strlen(email.subject), 0);
    send(sock, email.from, strlen(email.from), 0);
    send(sock, email.to, strlen(email.to), 0);
    send(sock, email.body, strlen(email.body), 0);

    // Close the socket
    close(sock);

    return 0;
}