//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024

char user_input[BUFFER_SIZE];
char email[BUFFER_SIZE];
char password[BUFFER_SIZE];

int sockfd;
SSL* ssl;

void handle_error(const char* msg) 
{
    perror(msg);
    exit(1);
}

int create_socket(char* hostname) 
{
    struct addrinfo hints, *result;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
  
    int rc = getaddrinfo(hostname, "993", &hints, &result);
    if (rc != 0) 
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rc));
        exit(1);
    }
  
    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) 
    {
        handle_error("socket");
    }

    if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) 
    {
        handle_error("connect");
    }

    freeaddrinfo(result);
  
    return sockfd;
}

SSL* create_ssl(int sockfd) 
{
    SSL_library_init();
    SSL_CTX* ssl_ctx = SSL_CTX_new(TLS_client_method());
    SSL* ssl = SSL_new(ssl_ctx);
    SSL_set_fd(ssl, sockfd);
  
    if (SSL_connect(ssl) == -1) 
    {
        ERR_print_errors_fp(stderr);
        exit(1);
    }
  
    return ssl;
}

void receive_response() 
{
    char buffer[BUFFER_SIZE];

    memset(buffer, 0, BUFFER_SIZE);

    int bytes = SSL_read(ssl, buffer, BUFFER_SIZE);
    if (bytes == -1) 
    {
        ERR_print_errors_fp(stderr);
        exit(1);
    }

    printf("%s", buffer);
}

void send_command(char* command) 
{
    int bytes = SSL_write(ssl, command, strlen(command));
    if (bytes == -1) 
    {
        ERR_print_errors_fp(stderr);
        exit(1);
    }
}

void login() 
{
    sprintf(user_input, "LOGIN %s %s\n", email, password);
    send_command(user_input);
    receive_response();
}

void select_mailbox() 
{
    send_command("SELECT INBOX\n");
    receive_response();
}

void search_unread_email() 
{
    send_command("SEARCH UNSEEN\n");
    receive_response();
}

void logout() 
{
    send_command("LOGOUT\n");
    receive_response();
}

int main() 
{
    printf("Enter Email: ");
    fgets(email, BUFFER_SIZE, stdin);
    email[strcspn(email, "\n")] = 0;

    printf("Enter Password: ");
    fgets(password, BUFFER_SIZE, stdin);
    password[strcspn(password, "\n")] = 0;
  
    sockfd = create_socket("imap.gmail.com");
    ssl = create_ssl(sockfd);
  
    receive_response();
    login();
    select_mailbox();
    search_unread_email();
    logout();
  
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sockfd);
    SSL_CTX_free(SSL_CTX_new(TLS_client_method()));

    return 0;
}