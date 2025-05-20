//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFSIZE 1024
#define HOSTNAME "imap.gmail.com"
#define PORT "993"

SSL_CTX *InitCTX(void)
{
    SSL_CTX *ctx;

    SSL_library_init();
    ctx = SSL_CTX_new(SSLv23_client_method());

    if (ctx == NULL)
    {
        ERR_print_errors_fp(stderr);
        abort();
    }

    return ctx;
}

int main(int argc, char *argv[])
{
    SSL_CTX *ctx;
    SSL *ssl;
    struct hostent *host;
    struct sockaddr_in serverAddr;
    char buffer[BUFSIZE];
    int sockfd, nbytes;
    char user[100], password[100], cmd[100], response[BUFSIZE], *p;

    // Get username and password from the user
    printf("Username: ");
    fgets(user, sizeof(user), stdin);
    printf("Password: ");
    fgets(password, sizeof(password), stdin);

    // Remove newline character from the end of the strings
    user[strcspn(user, "\n")] = 0;
    password[strcspn(password, "\n")] = 0;

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Get the IP address of the server
    host = gethostbyname(HOSTNAME);

    // Set up the server address structure
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    memcpy(&serverAddr.sin_addr.s_addr, host->h_addr, host->h_length);
    serverAddr.sin_port = htons(atoi(PORT));

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
    {
        perror("connect");
        exit(1);
    }

    // Initialize SSL
    ctx = InitCTX();
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);

    // Connect to the server using SSL
    if (SSL_connect(ssl) == -1)
    {
        ERR_print_errors_fp(stderr);
        exit(1);
    }

    // Read the welcome message from the server
    nbytes = SSL_read(ssl, buffer, sizeof(buffer));
    printf("%s", buffer);

    // Send the user's username to the server
    sprintf(cmd, "A001 LOGIN %s %s\r\n", user, password);
    SSL_write(ssl, cmd, strlen(cmd));
    nbytes = SSL_read(ssl, response, sizeof(response));
    printf("%s", response);

    // Send the LIST command to the server
    sprintf(cmd, "A002 LIST \"\" *\r\n");
    SSL_write(ssl, cmd, strlen(cmd));
    nbytes = SSL_read(ssl, response, sizeof(response));
    printf("%s", response);

    // Send the LOGOUT command to the server
    SSL_write(ssl, "A003 LOGOUT\r\n", strlen("A003 LOGOUT\r\n"));
    nbytes = SSL_read(ssl, response, sizeof(response));
    printf("%s", response);

    // Free SSL context and close the socket
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);

    return 0;
}