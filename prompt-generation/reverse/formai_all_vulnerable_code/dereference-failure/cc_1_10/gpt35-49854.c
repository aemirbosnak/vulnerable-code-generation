//FormAI DATASET v1.0 Category: Client Server Application ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

void error(char *message) {
    perror(message);
    exit(1);
}

// Decrypt the message using a shift key
void decrypt(char *message, int key) {
    int i;
    for (i = 0; message[i] != '\0'; ++i) {
        char c = message[i];
        if (c >= 'a' && c <= 'z') {
            c = 'a' + ((c - 'a' - key + 26) % 26);
            message[i] = c;
        }
        else if (c >= 'A' && c <= 'Z') {
            c = 'A' + ((c - 'A' - key + 26) % 26);
            message[i] = c;
        }
    }
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, n;
    socklen_t cli_len;
    struct sockaddr_in serv_addr, cli_addr;

    char buffer[BUFFER_SIZE];
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    // Bind socket to address
    memset(&serv_addr, 0, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    // Listen for connections
    listen(sockfd, 5);
    cli_len = sizeof(cli_addr);

    // Accept connection and read from socket
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &cli_len);
    if (newsockfd < 0)
        error("ERROR on accept");

    printf("Connection established\n");
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        n = read(newsockfd, buffer, BUFFER_SIZE - 1);
        if (n < 0)
            error("ERROR reading from socket");

        printf("Encrypted Message received: %s\n", buffer);

        // Decrypt the message
        decrypt(buffer, 3);
        printf("Decrypted Message: %s\n", buffer);

        // Send the decrypted message
        n = write(newsockfd, buffer, strlen(buffer));
        if (n < 0)
            error("ERROR writing to socket");
    }

    // Close sockets
    close(newsockfd);
    close(sockfd);

    return 0;
}