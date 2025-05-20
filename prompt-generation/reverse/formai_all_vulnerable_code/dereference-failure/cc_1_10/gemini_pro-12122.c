//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>

// Let's fetch some tasty mail!
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <server-address> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Hooray, a socket to chat with the mail server!
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    // Setting up the server's address like a charming snail mail address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        return EXIT_FAILURE;
    }

    char buffer[1024];

    // Let's say hello and hope for the best!
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);
    
    // Tell the server we're ready for our mail, like a friendly neighbor asking for a cup of sugar
    send(sockfd, "USER your-username@example.com\r\n", strlen("USER your-username@example.com\r\n"), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // We're not shy, ask for our password like a curious cat
    send(sockfd, "PASS your-password\r\n", strlen("PASS your-password\r\n"), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Excitedly check our mailbox for any mail like kids running to the mail slot
    send(sockfd, "LIST\r\n", strlen("LIST\r\n"), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Let's grab the first email eagerly like a child unwrapping a present
    send(sockfd, "RETR 1\r\n", strlen("RETR 1\r\n"), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);

    // Politely tell the server we've had our fun and are leaving like a considerate guest
    send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Time to leave the mailbox like a secret agent disappearing into the shadows
    close(sockfd);

    return EXIT_SUCCESS;
}