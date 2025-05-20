//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Surprise! Here's a whooping POP3 client in C!

int main(int argc, char *argv[]) {
    // Let's check our arguments, shall we?
    if (argc != 4) {
        printf("Oops! You're missing some arguments.\n");
        printf("Usage: %s <server> <port> <username>\n", argv[0]);
        return 1;
    }

    // Get our server address and port
    char *server = argv[1];
    int port = atoi(argv[2]);

    // Create a socket, it's how we talk to the POP3 server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Whoa, socket creation failed!\n");
        return 1;
    }

    // Set up the server address and port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(server);

    // Connect to the server, let's get chatty!
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Ouch! Connection failed.\n");
        return 1;
    }

    // Authorization time! Let's log in
    char buffer[512];
    recv(sockfd, buffer, 512, 0);
    printf("%s", buffer);

    // Send our username, it's the first step to login paradise
    snprintf(buffer, 512, "USER %s\r\n", argv[3]);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, 512, 0);
    printf("%s", buffer);

    // Now, let's get that sweet password
    snprintf(buffer, 512, "PASS %s\r\n", "my-super-secret-password");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, 512, 0);
    printf("%s", buffer);

    // Time to list our emails, let's see what we've got
    snprintf(buffer, 512, "LIST\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, 512, 0);
    printf("%s", buffer);

    // Let's grab an email, shall we?
    snprintf(buffer, 512, "RETR 1\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, 512, 0);
    printf("%s", buffer);

    // Don't forget to say goodbye, it's polite!
    snprintf(buffer, 512, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, 512, 0);
    printf("%s", buffer);

    // Close the socket, we're done here
    close(sockfd);

    return 0;
}