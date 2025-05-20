//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

// The Baker Street Irregulars, our trusted network helpers
struct addrinfo hints, *res;

// A fine cup of tea, to keep us sharp
int sockfd;

// A telegram to dispatch
char *message;

// Our journey begins
int main(int argc, char *argv[]) {
    // Check if we have a destination and a message
    printf("My esteemed client, I trust you have a destination and a message for me to convey?\n");
    if (argc != 3) {
        printf("Alas, I cannot proceed without a proper destination and message. Farewell.\n");
        return 1;
    }

    // Prepare our network inquiries
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    if (getaddrinfo(argv[1], "25", &hints, &res) != 0) {
        printf("Watson, it appears the network is shrouded in mystery. Cannot find the destination.\n");
        return 1;
    }

    // Establish our connection
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0) {
        printf("My dear Watson, it seems our connection attempt has hit a snag. Farewell.\n");
        return 1;
    }

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) < 0) {
        printf("Hmm, the network seems to be playing tricks on us. Cannot connect to the destination.\n");
        return 1;
    }

    // Begin our exchange
    printf("We are now connected. Shall we send our message?\n");
    message = argv[2];

    // Craft our initial greetings
    if (send(sockfd, "HELO sherlock.net\r\n", strlen("HELO sherlock.net\r\n"), 0) < 0) {
        printf("Alas, my attempt to greet the server has failed. Farewell.\n");
        return 1;
    }

    // Expect a response
    char buffer[1024];
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        printf("Watson, it appears the server is not responding. Farewell.\n");
        return 1;
    }

    // Parse the server's response
    char *status = strtok(buffer, " ");
    if (strcmp(status, "250") != 0) {
        printf("Hmm, the server does not seem to welcome our presence. Farewell.\n");
        return 1;
    }

    // Send our message
    if (send(sockfd, "MAIL FROM:<sherlock@sherlock.net>\r\n", strlen("MAIL FROM:<sherlock@sherlock.net>\r\n"), 0) < 0) {
        printf("Watson, it appears I am unable to send the message. Farewell.\n");
        return 1;
    }

    // Expect a response
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        printf("Watson, it appears the server is not responding. Farewell.\n");
        return 1;
    }

    // Parse the server's response
    status = strtok(buffer, " ");
    if (strcmp(status, "250") != 0) {
        printf("Hmm, the server does not seem to accept our message. Farewell.\n");
        return 1;
    }

    // Send the recipient
    if (send(sockfd, "RCPT TO:<john.watson@sherlock.net>\r\n", strlen("RCPT TO:<john.watson@sherlock.net>\r\n"), 0) < 0) {
        printf("Watson, it appears I am unable to send the recipient. Farewell.\n");
        return 1;
    }

    // Expect a response
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        printf("Watson, it appears the server is not responding. Farewell.\n");
        return 1;
    }

    // Parse the server's response
    status = strtok(buffer, " ");
    if (strcmp(status, "250") != 0) {
        printf("Hmm, the server does not seem to accept the recipient. Farewell.\n");
        return 1;
    }

    // Begin sending the message
    if (send(sockfd, "DATA\r\n", strlen("DATA\r\n"), 0) < 0) {
        printf("Watson, it appears I am unable to send the data. Farewell.\n");
        return 1;
    }

    // Expect a response
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        printf("Watson, it appears the server is not responding. Farewell.\n");
        return 1;
    }

    // Parse the server's response
    status = strtok(buffer, " ");
    if (strcmp(status, "354") != 0) {
        printf("Hmm, the server does not seem to be ready for the data. Farewell.\n");
        return 1;
    }

    // Send the message
    if (send(sockfd, message, strlen(message), 0) < 0) {
        printf("Watson, it appears I am unable to send the message. Farewell.\n");
        return 1;
    }

    // End the message
    if (send(sockfd, "\r\n.\r\n", strlen("\r\n.\r\n"), 0) < 0) {
        printf("Watson, it appears I am unable to end the message. Farewell.\n");
        return 1;
    }

    // Expect a response
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        printf("Watson, it appears the server is not responding. Farewell.\n");
        return 1;
    }

    // Parse the server's response
    status = strtok(buffer, " ");
    if (strcmp(status, "250") != 0) {
        printf("Hmm, the server does not seem to have accepted the message. Farewell.\n");
        return 1;
    }

    // Send our farewell
    if (send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0) < 0) {
        printf("Watson, it appears I am unable to send the farewell. Farewell.\n");
        return 1;
    }

    // Close our connection
    close(sockfd);

    // Our mission is complete
    printf("My esteemed client, your message has been dispatched. Farewell.\n");
    return 0;
}