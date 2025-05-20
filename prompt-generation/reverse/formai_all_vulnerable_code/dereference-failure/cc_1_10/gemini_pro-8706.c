//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

// Hooray! IMAP magic begins here!
int main(int argc, char **argv) {
    // Let's set sail for the IMAP server!
    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Establishing a connection with the IMAP server
    printf("Excitedly connecting to %s:%d!\n", hostname, port);
    struct hostent *server = gethostbyname(hostname);
    struct sockaddr_in server_addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(port);
    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // We're ready to send commands! Let's greet the server with a smile:
    char buffer[1024];
    recv(sockfd, buffer, 1024, 0);
    printf("The server says: %s", buffer);

    // Now, let's login like rockstars
    sprintf(buffer, "LOGIN %s %s\r\n", argv[3], argv[4]);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, 1024, 0);
    printf("Server response: %s", buffer);

    // Time to select a mailbox and get those precious emails!
    sprintf(buffer, "SELECT INBOX\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, 1024, 0);
    printf("And the server tells us: %s", buffer);

    // Hold your breath! We're about to discover our email count:
    sprintf(buffer, "FETCH 1:* (RFC822)\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Oh wow! Let's dive into the emails:
    int email_count = 0;
    char *start = strstr(buffer, "RFC822");
    while (start) {
        email_count++;
        start = strstr(start + 1, "RFC822");
    }

    printf("Wow, you have %d emails waiting!\n", email_count);

    // Finally, let's say goodbye with a graceful touch:
    sprintf(buffer, "LOGOUT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    shutdown(sockfd, SHUT_RDWR);

    return 0;
}