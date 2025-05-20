//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Sherlock Holmes
// The Case of the Missing Emails - An IMAP Client Sherlock HolmesStyle
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024
#define USERNAME "sherlock@bakerstreet.com"
#define PASSWORD "elementarymydear"

// Function to create a SSL/TLS socket connection
SSL_CTX* create_ssl_context() {
    SSL_library_init();
    SSL_load_error_strings();
    SSL_METHOD *method;
    SSL_CTX *ctx;
    method = TLSv1_2_client_method();
    ctx = SSL_CTX_new(method);
    if (ctx == NULL) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
    return ctx;
}

// Function to connect to the IMAP server and return the SSL socket
SSL* connect_to_server(char* server, char* port, SSL_CTX *ctx) {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server_info;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }
    server_info = gethostbyname(server);
    if (server_info == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(port));
    memcpy(&serv_addr.sin_addr.s_addr, server_info->h_addr, server_info->h_length);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) <0){
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }
    SSL* ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
    return ssl;
}

int main(int argc, char *argv[]){
    printf("Welcome to Sherlock Holmes IMAP Client");
    SSL_CTX *sslContext = create_ssl_context();

    char* server = "imap.gmail.com"; // IMAP server address
    char* port = "993"; // IMAP server port
    SSL* sslSocket = connect_to_server(server, port, sslContext);
  
    // Step 1: Authenticate User
    char buffer[BUFFER_SIZE] = "";
    SSL_read(sslSocket, buffer, BUFFER_SIZE);
    printf("%s", buffer);
    memset(buffer, 0, BUFFER_SIZE);
    SSL_write(sslSocket,"1 LOGIN " USERNAME " " PASSWORD "\r\n",strlen("1 LOGIN " USERNAME " " PASSWORD "\r\n"));

    SSL_read(sslSocket, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // Step 2: List Mailboxes
    memset(buffer, 0, BUFFER_SIZE);
    SSL_write(sslSocket,"2 LIST \"\" *\r\n",strlen("2 LIST \"\" *\r\n"));

    SSL_read(sslSocket, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // Step 3: Select Inbox
    memset(buffer, 0, BUFFER_SIZE);
    SSL_write(sslSocket,"3 SELECT INBOX\r\n",strlen("3 SELECT INBOX\r\n"));

    SSL_read(sslSocket, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // Step 4: Fetch Emails
    memset(buffer, 0, BUFFER_SIZE);
    SSL_write(sslSocket,"4 FETCH 1:* (BODY[TEXT])\r\n",strlen("4 FETCH 1:* (BODY[TEXT])\r\n"));

    SSL_read(sslSocket, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    SSL_shutdown(sslSocket);
    SSL_free(sslSocket);
    SSL_CTX_free(sslContext);
    return 0;
}