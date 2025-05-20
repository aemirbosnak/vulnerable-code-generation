//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Romeo and Juliet
/* As the sun rises on fair Verona,
   A POP3 client is born anew.
   Our hero, Romeo, seeks to retrieve
   His missive from fair Juliet,
   But alas, he is but a lowly C programmer.
   Shall he be swayed by the siren call of Python?
   Nay! He shall code his own solution!

   Behold, dear reader, the tale of Romeo and his POP3 client. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    // First, let us set the stage.
    char *server_name = "pop.gmail.com";
    char *username = "romeo@gmail.com";
    char *password = "juli3t4ever";

    // Now, let us resolve the server name to an IP address.
    struct hostent *server = gethostbyname(server_name);

    // If we could not resolve the address, let us exit our play.
    if (server == NULL) {
        fprintf(stderr, "Could not resolve server %s\n", server_name);
        return 1;
    }

    // Now, let us create a socket to the server.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // If we could not create a socket, we shall end our play.
    if (sockfd < 0) {
        fprintf(stderr, "Could not create socket to server\n");
        return 1;
    }

    // Let us set up our server address and port.
    struct sockaddr_in serv_addr;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr,
          (char *) &serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(995);

    // Now, let us connect to the server.
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Could not connect to server\n");
        return 1;
    }

    // Let us read the response from the server.
    char buffer[BUFFER_SIZE];
    ssize_t n = read(sockfd, buffer, BUFFER_SIZE - 1);

    // If we received an error from the server, we shall end our play.
    if (strncmp(buffer, "+OK", 3) != 0) {
        fprintf(stderr, "Server error: %s\n", buffer);
        return 1;
    }

    // Now, let us log in to the server.
    snprintf(buffer, BUFFER_SIZE, "USER %s\r\n", username);
    write(sockfd, buffer, strlen(buffer));
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (strncmp(buffer, "+OK", 3) != 0) {
        fprintf(stderr, "Server error: %s\n", buffer);
        return 1;
    }

    snprintf(buffer, BUFFER_SIZE, "PASS %s\r\n", password);
    write(sockfd, buffer, strlen(buffer));
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (strncmp(buffer, "+OK", 3) != 0) {
        fprintf(stderr, "Server error: %s\n", buffer);
        return 1;
    }

    // We are now logged in. Let us fetch our messages.
    snprintf(buffer, BUFFER_SIZE, "LIST\r\n");
    write(sockfd, buffer, strlen(buffer));
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (strncmp(buffer, "+OK", 3) != 0) {
        fprintf(stderr, "Server error: %s\n", buffer);
        return 1;
    }

    // Let us print the message count and size.
    printf("Message count:\n");
    printf("%s\n", buffer);
    memset(buffer, 0, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    printf("%s\n", buffer);

    // Now, let us fetch the first message.
    snprintf(buffer, BUFFER_SIZE, "RETR 1\r\n");
    write(sockfd, buffer, strlen(buffer));
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (strncmp(buffer, "+OK", 3) != 0) {
        fprintf(stderr, "Server error: %s\n", buffer);
        return 1;
    }

    // Let us print the message.
    printf("Message:\n");
    while ((n = read(sockfd, buffer, BUFFER_SIZE - 1)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    // Let us say farewell to our server.
    snprintf(buffer, BUFFER_SIZE, "QUIT\r\n");
    write(sockfd, buffer, strlen(buffer));
    n = read(sockfd, buffer, BUFFER_SIZE - 1);

    // And thus, our play has reached its end.
    return 0;
}