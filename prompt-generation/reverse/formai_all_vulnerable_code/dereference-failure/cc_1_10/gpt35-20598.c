//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct IMAPConnection {
    char *hostname;
    char *username;
    char *password;
    int sockfd;
} IMAPConnection;

/**
 * Connects to the IMAP server and logs in.
 */
int connect_and_login(IMAPConnection *imap_conn) {
    // Resolve the hostname to an IP address
    struct hostent *server = gethostbyname(imap_conn->hostname);
    if (server == NULL) {
        fprintf(stderr, "Error: Could not resolve hostname\n");
        return -1;
    }

    // Create a socket
    imap_conn->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (imap_conn->sockfd < 0) {
        fprintf(stderr, "Error: Could not create socket\n");
        return -1;
    }

    // Create a socket address and connect to the server
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = *(long *) (server->h_addr);
    serv_addr.sin_port = htons(143);
    if (connect(imap_conn->sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error: Could not connect to server\n");
        return -1;
    }

    // Read the greeting from the server
    char buffer[BUFFER_SIZE];
    ssize_t n = read(imap_conn->sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        fprintf(stderr, "Error: Could not read from socket\n");
        return -1;
    }
    buffer[n] = '\0';

    // Send the login command to the server
    char *login_command = malloc(BUFFER_SIZE);
    snprintf(login_command, BUFFER_SIZE, "LOGIN %s %s\r\n", imap_conn->username, imap_conn->password);
    n = write(imap_conn->sockfd, login_command, strlen(login_command));
    if (n < 0) {
        fprintf(stderr, "Error: Could not write to socket\n");
        return -1;
    }

    // Read the login response from the server
    n = read(imap_conn->sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        fprintf(stderr, "Error: Could not read from socket\n");
        return -1;
    }
    buffer[n] = '\0';

    return 0;
}

// Sample usage of the IMAP client module
int main() {
    IMAPConnection *imap_conn = malloc(sizeof(IMAPConnection));
    imap_conn->hostname = strdup("mail.example.com");
    imap_conn->username = strdup("username");
    imap_conn->password = strdup("password");

    int ret = connect_and_login(imap_conn);

    if (ret == 0) {
        printf("Successfully logged in to %s\n", imap_conn->hostname);
    }

    close(imap_conn->sockfd);

    free(imap_conn->hostname);
    free(imap_conn->username);
    free(imap_conn->password);
    free(imap_conn);

    return 0;
}