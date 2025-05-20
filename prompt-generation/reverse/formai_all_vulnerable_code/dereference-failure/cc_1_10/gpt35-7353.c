//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

void  error(const char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char const *argv[]) {
	// Variables to hold login credentials and server details
    char* username = "imapuser";
    char* password = "imappassword";
    char* server = "mail.example.com";
    int port = 993;

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("ERROR opening socket");

    // Connect to server
    struct hostent* h = gethostbyname(server);
    if (h == NULL) error("ERROR, no such host");
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)h->h_addr_list[0], (char *)&serv_addr.sin_addr.s_addr, h->h_length);
    serv_addr.sin_port = htons(port);
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) error("ERROR connecting");

    // Initialize OpenSSL
    SSL_library_init();
    SSL_CTX *ssl_ctx = SSL_CTX_new(TLSv1_2_client_method());
    if (ssl_ctx == NULL) error("ERROR creating SSL context");

    // Set up SSL object for socket
    SSL *ssl = SSL_new(ssl_ctx);
    SSL_set_fd(ssl, sockfd);

    // Connect SSL object to socket
    if (SSL_connect(ssl) < 1) error("ERROR connecting SSL");

    // Send login credentials
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    snprintf(buffer, sizeof(buffer), "1 LOGIN %s %s\r\n", username, password);
    SSL_write(ssl, buffer, strlen(buffer));

    // Receive server response
    memset(buffer, 0, sizeof(buffer));
    SSL_read(ssl, buffer, sizeof(buffer));
    printf("%s", buffer);

    // Send command to select mailbox
    memset(buffer, 0, sizeof(buffer));
    snprintf(buffer, sizeof(buffer), "2 SELECT Inbox\r\n");
    SSL_write(ssl, buffer, strlen(buffer));

    // Receive server response
    memset(buffer, 0, sizeof(buffer));
    SSL_read(ssl, buffer, sizeof(buffer));
    printf("%s", buffer);

    // Send command to fetch latest email
    memset(buffer, 0, sizeof(buffer));
    snprintf(buffer, sizeof(buffer), "3 FETCH 1 BODY[TEXT]\r\n");
    SSL_write(ssl, buffer, strlen(buffer));

    // Receive server response
    memset(buffer, 0, sizeof(buffer));
    SSL_read(ssl, buffer, sizeof(buffer));
    printf("%s", buffer);

    // Close connection
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ssl_ctx);
    close(sockfd);

    return 0;
}