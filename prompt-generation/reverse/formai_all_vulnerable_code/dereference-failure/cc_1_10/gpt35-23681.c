//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define MAX_BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server> <port> <username>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Set up SSL
    SSL_library_init();
    SSL_CTX *ctx = SSL_CTX_new(TLSv1_2_client_method());
    
    // Load certificates
    SSL_CTX_load_verify_locations(ctx, NULL, "/etc/ssl/certs");
    
    // Set up socket
    struct addrinfo hints;
    struct addrinfo *result, *rp;
    int status, sockfd;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    status = getaddrinfo(argv[1], argv[2], &hints, &result);
    if (status != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }
    for (rp = result; rp != NULL; rp = rp->ai_next) {
        sockfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (sockfd == -1) continue;
        if (connect(sockfd, rp->ai_addr, rp->ai_addrlen) != -1) break;
        close(sockfd);
    }
    if (rp == NULL) {
        fprintf(stderr, "Could not connect to server\n");
        exit(EXIT_FAILURE);
    }

    // Set up SSL connection
    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) == -1) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
    
    // Send authentication command
    char auth_command[MAX_BUFFER_SIZE];
    snprintf(auth_command, MAX_BUFFER_SIZE, "USER %s\r\n", argv[3]);
    SSL_write(ssl, auth_command, strlen(auth_command));
    char buffer[MAX_BUFFER_SIZE];
    SSL_read(ssl, buffer, MAX_BUFFER_SIZE);
    // TODO: Check for authentication success
    
    // Send password command
    char password[MAX_BUFFER_SIZE];
    printf("Enter password: ");
    fgets(password, MAX_BUFFER_SIZE, stdin);
    password[strcspn(password, "\r\n")] = 0;
    snprintf(auth_command, MAX_BUFFER_SIZE, "PASS %s\r\n", password);
    SSL_write(ssl, auth_command, strlen(auth_command));
    SSL_read(ssl, buffer, MAX_BUFFER_SIZE);
    // TODO: Check for authentication success
    
    // Get mailbox status
    SSL_write(ssl, "STAT\r\n", strlen("STAT\r\n"));
    SSL_read(ssl, buffer, MAX_BUFFER_SIZE);
    // TODO: Parse and display mailbox status
    
    // Retrieve a message
    char retrieve_command[MAX_BUFFER_SIZE];
    int message_number;
    printf("Enter message number to retrieve: ");
    scanf("%d", &message_number);
    snprintf(retrieve_command, MAX_BUFFER_SIZE, "RETR %d\r\n", message_number);
    SSL_write(ssl, retrieve_command, strlen(retrieve_command));
    SSL_read(ssl, buffer, MAX_BUFFER_SIZE);
    // TODO: Parse and display the message
    
    // Clean up
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sockfd);
    SSL_CTX_free(ctx);
    return 0;
}