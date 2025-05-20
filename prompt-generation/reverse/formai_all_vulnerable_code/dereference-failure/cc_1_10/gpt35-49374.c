//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: systematic
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFSIZE 1024
#define TIMEOUT 30

// Function declarations
int create_socket(char *server, int port);
int send_command(SSL *ssl, char *command);
int read_response(SSL *ssl, char *response, int size);
void parse_response(char *response);

int main(void) {
    char server[100];
    char username[100];
    char password[100];
    int port = 993;
    SSL_CTX *ctx;
    SSL *ssl;
    int sockfd;
    char command[BUFSIZE];
    char response[BUFSIZE];

    // Get server information
    printf("Enter the IMAP server: ");
    fgets(server, sizeof(server), stdin);
    server[strlen(server) - 1] = '\0';

    // Get login information
    printf("Enter your username: ");
    fgets(username, sizeof(username), stdin);
    username[strlen(username) - 1] = '\0';

    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);
    password[strlen(password) - 1] = '\0';

    // Create SSL socket
    sockfd = create_socket(server, port);
    SSL_load_error_strings();
    SSL_library_init();
    ctx = SSL_CTX_new(TLSv1_2_client_method());
    if (ctx == NULL) {
        printf("Error creating SSL context.\n");
        exit(EXIT_FAILURE);
    }
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) != 1) {
        printf("Error connecting to server.\n");
        exit(EXIT_FAILURE);
    }

    // Log in to IMAP server
    read_response(ssl, response, BUFSIZE);
    if (strncmp(response, "* OK", 4) != 0) {
        printf("Error connecting to server.\n");
        exit(EXIT_FAILURE);
    }
    sprintf(command, "LOGIN %s %s", username, password);
    send_command(ssl, command);
    read_response(ssl, response, BUFSIZE);
    if (strncmp(response, "* OK", 4) != 0) {
        printf("Error logging in.\n");
        exit(EXIT_FAILURE);
    }

    // Select mailbox
    send_command(ssl, "SELECT INBOX");
    read_response(ssl, response, BUFSIZE);
    if (strncmp(response, "* OK", 4) != 0) {
        printf("Error selecting mailbox.\n");
        exit(EXIT_FAILURE);
    }

    // Get mailbox status
    send_command(ssl, "STATUS INBOX (MESSAGES UNSEEN)");
    read_response(ssl, response, BUFSIZE);
    if (strncmp(response, "* STATUS", 8) != 0) {
        printf("Error getting mailbox status.\n");
        exit(EXIT_FAILURE);
    }
    parse_response(response);

    // Log out and close connection
    send_command(ssl, "LOGOUT");
    SSL_shutdown(ssl);
    close(sockfd);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    return 0;
}

/**
 * Creates and connects a TCP socket to the given server and port.
 *
 * @param server the server to connect to
 * @param port the port to connect to
 *
 * @return the socket file descriptor
 */
int create_socket(char *server, int port) {
    int sockfd;
    struct hostent *he;
    struct sockaddr_in addr;

    if ((he = gethostbyname(server)) == NULL) {
        printf("Error resolving hostname.\n");
        exit(EXIT_FAILURE);
    }
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    memcpy(&addr.sin_addr, he->h_addr, he->h_length);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket.\n");
        exit(EXIT_FAILURE);
    }
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        printf("Error connecting to server.\n");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

/**
 * Sends a command to the server using the given SSL socket.
 *
 * @param ssl the SSL socket to use for communication
 * @param command the command to send
 *
 * @return 0 on success, -1 on failure
 */
int send_command(SSL *ssl, char *command) {
    char buf[BUFSIZE];
    int len;

    sprintf(buf, "%s\r\n", command);
    len = SSL_write(ssl, buf, strlen(buf));
    if (len <= 0) {
        printf("Error sending command.\n");
        return -1;
    }
    return 0;
}

/**
 * Reads a response from the server using the given SSL socket.
 *
 * @param ssl the SSL socket to use for communication
 * @param response the buffer to store the response in
 * @param size the size of the buffer
 *
 * @return the number of bytes read, -1 on failure
 */
int read_response(SSL *ssl, char *response, int size) {
    int len;
    fd_set fds;
    struct timeval tv;

    FD_ZERO(&fds);
    FD_SET(SSL_get_fd(ssl), &fds);
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    if (select(SSL_get_fd(ssl) + 1, &fds, NULL, NULL, &tv) <= 0) {
        printf("Error reading response.\n");
        return -1;
    }
    len = SSL_read(ssl, response, size - 1);
    if (len <= 0) {
        printf("Error reading response.\n");
        return -1;
    }
    response[len] = '\0';
    return len;
}

/**
 * Parses a status response from the server and prints the number of messages and
 * number of unseen messages in the mailbox.
 *
 * @param response the response to parse
 */
void parse_response(char *response) {
    char *p;
    int messages = 0, unseen = 0;

    p = strstr(response, "MESSAGES");
    if (p != NULL) {
        sscanf(p, "MESSAGES %d", &messages);
    }
    p = strstr(response, "UNSEEN");
    if (p != NULL) {
        sscanf(p, "UNSEEN %d", &unseen);
    }
    printf("Mailbox contains %d messages. %d messages are unseen.\n", messages, unseen);
}