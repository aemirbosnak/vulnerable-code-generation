//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: portable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <openssl/ssl.h>

// Function to create a SMTP client
void smtp_client(char* hostname, int port) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Create an address structure
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        perror("ERROR converting hostname to address");
        exit(1);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // SSL connection
    SSL* ssl = SSL_new(TLSv1_2_client_method());
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) < 0) {
        perror("ERROR connecting SSL");
        exit(1);
    }

    // Send a simple SMTP command
    char command[128] = "HELO localhost";
    int cmd_len = strlen(command);
    if (SSL_write(ssl, command, cmd_len) <= 0) {
        perror("ERROR sending command");
        exit(1);
    }
    char response[128];
    if (SSL_read(ssl, response, 128) <= 0) {
        perror("ERROR reading response");
        exit(1);
    }
    printf("%s\n", response);

    // Close the socket
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sockfd);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }
    smtp_client(argv[1], atoi(argv[2]));
    return 0;
}