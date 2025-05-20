//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/crypto.h>
#include <openssl/x509.h>

typedef struct {
    char *buf;
    unsigned long bufsize;
    int pos;
} IMAPResponse;

/* Function to create the IMAP socket */
int create_imap_socket(char *server_addr, char *port) {
    char err_buf[512];
    struct addrinfo hints, *res = NULL;
    int sock;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if (getaddrinfo(server_addr, port, &hints, &res) != 0) {
        sprintf(err_buf, "Error: Cannot resolve %s:%s\n", server_addr, port);
        perror(err_buf);
        return -1;
    }

    if ((sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) == -1) {
        perror("Error: Creating IMAP Socket\n");
        return -1;
    }

    if (connect(sock, res->ai_addr, res->ai_addrlen) == -1) {
        perror("Error: Connecting to IMAP Server\n");
        return -1;
    }

    return sock;
}

/* Function to read the response from IMAP */
IMAPResponse read_imap_response(int sock) {
    IMAPResponse resp;
    resp.bufsize = 1024;
    resp.pos = 0;
    resp.buf = (char *)malloc(resp.bufsize);
    memset(resp.buf, 0, resp.bufsize);

    int read_size;
    char buf[512];

    while (1) {
        read_size = recv(sock, buf, 512, 0);

        if (read_size == -1) {
            perror("Error: Reading IMAP Response\n");
            return resp;
        }

        if (read_size == 0) break;

        while ((resp.pos + read_size) > resp.bufsize) {
            resp.bufsize *= 2;
            resp.buf = (char *)realloc(resp.buf, resp.bufsize);
        }

        strncpy((resp.buf + resp.pos), buf, read_size);
        resp.pos += read_size;

        if (buf[read_size - 1] == '\n') break;
    }

    resp.buf = (char *)realloc(resp.buf, (resp.pos + 1));
    strncpy((resp.buf + resp.pos), "\0", 1);

    return resp;
}

/* Function to send command to the IMAP server */
void send_imap_command(int sock, char *command) {
    char buf[1024];
    sprintf(buf, "%s\r\n", command);
    if (send(sock, buf, strlen(buf), 0) == -1) {
        perror("Error: Sending IMAP Command\n");
        exit(1);
    }
    return;
}

/* Function to login to the IMAP server */
void imap_login(int sock, char *username, char *password) {
    IMAPResponse resp;
    char buf[1024];

    send_imap_command(sock, "LOGIN");
    resp = read_imap_response(sock);

    if (strstr(resp.buf, "* BAD")) {
        sprintf(buf, "Error: IMAP authentication failed. Reason: %s", resp.buf);
        perror(buf);
        exit(1);
    }

    char *token, *ptr, *tag;

    token = strtok(resp.buf, " ");
    ptr = strstr(resp.buf, token);

    if (ptr) tag = strdup(ptr);

    send_imap_command(sock, tag);

    memset(buf, 0, sizeof(char) * 1024);
    sprintf(buf, "\"%s\"", username);
    send_imap_command(sock, buf);

    memset(buf, 0, sizeof(char) * 1024);
    sprintf(buf, "\"%s\"", password);
    send_imap_command(sock, buf);

    resp = read_imap_response(sock);

    if (strstr(resp.buf, "OK")) {
        printf("Success: IMAP login successful.\n");
    } else {
        sprintf(buf, "Error: IMAP authentication failed. Reason: %s", resp.buf);
        perror(buf);
        exit(1);
    }

    return;
}

/* Function to logout from the IMAP server */
void imap_logout(int sock) {
    IMAPResponse resp;

    send_imap_command(sock, "LOGOUT");

    resp = read_imap_response(sock);

    if (strstr(resp.buf, "OK")) {
        printf("Success: IMAP Logout successful.\n");
    } else {
        printf("Error: IMAP Logout failed. Reason: %s", resp.buf);
    }

    return;
}

/* Asynchronous code for IMAP client */
int main(int argc, char **argv) {
    char *server_addr = "imap.gmail.com";
    char *port = "993";
    char *username = "example@gmail.com";
    char *password = "examplepassword";

    int imap_sock = create_imap_socket(server_addr, port);

    if (imap_sock == -1) {
        printf("Error: Creating IMAP socket. Exiting.\n");
        exit(1);
    }

    imap_login(imap_sock, username, password);

    // Perform some IMAP operations in an asynchronous manner

    // Logout and exit
    imap_logout(imap_sock);
    close(imap_sock);

    return 0;
}