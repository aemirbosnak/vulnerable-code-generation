//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

int main(int argc, char *argv[]) {
    SSL *ssl;
    SSL_CTX *ctx;
    int sock;
    struct hostent *host;
    struct sockaddr_in server;

    // Initialize SSL context
    ctx = SSL_CTX_new(SSLv23_client_method());

    // Load certificates
    SSL_CTX_set_default_verify_paths(ctx);

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    // Resolve server address
    host = gethostbyname("imap.gmail.com");

    // Set server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(993);
    memcpy(&server.sin_addr, host->h_addr, host->h_length);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Create SSL connection
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);

    // Establish SSL connection
    if (SSL_connect(ssl) <= 0) {
        printf("Error establishing SSL connection\n");
        exit(1);
    }

    // Authenticate with server
    char username[100] = "username";
    char password[100] = "password";
    char *auth_string = (char *)malloc(strlen(username) + strlen(password) + 2);
    strcpy(auth_string, username);
    strcat(auth_string, " ");
    strcat(auth_string, password);
    send(sock, auth_string, strlen(auth_string), 0);

    // Send commands to server
    char *commands[] = {"CAPABILITY", "SELECT Inbox", "FETCH 1:* (BODY.PEEK[])", NULL};
    for (int i = 0; commands[i]!= NULL; i++) {
        send(sock, commands[i], strlen(commands[i]), 0);
    }

    // Receive responses from server
    char buffer[1024];
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int bytes = recv(sock, buffer, sizeof(buffer), 0);
        if (bytes <= 0) {
            break;
        }
        printf("%s\n", buffer);
    }

    // Close SSL connection
    SSL_shutdown(ssl);
    SSL_free(ssl);

    // Close socket
    close(sock);

    return 0;
}