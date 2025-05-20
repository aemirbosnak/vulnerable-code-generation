//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

// A tale of love, of passion, of messages missed,
// An IMAP client, brings forth this twist.
// With functions and structures, we craft our desire,
// Let us build a connection, that burns like fire.

#define IMAP_PORT 143
#define BUFFER_SIZE 1024

typedef struct {
    int sockfd;
    char buffer[BUFFER_SIZE];
} IMAPClient;

// In the midst of connection, our hearts entwined,
// We shall find our passion in messages unsigned.

void display_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

// To create a client, fill our hearts, oh sweet embrace!
IMAPClient *create_client(const char *hostname) {
    IMAPClient *client = (IMAPClient *)malloc(sizeof(IMAPClient));
    struct sockaddr_in server_addr;
    struct hostent *host_info;

    if ((host_info = gethostbyname(hostname)) == NULL) {
        display_error("Could not resolve host");
    }

    client->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->sockfd < 0) {
        display_error("Socket creation failed");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    memcpy(&server_addr.sin_addr, host_info->h_addr, host_info->h_length);

    if (connect(client->sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        display_error("Connection to server failed");
    }

    return client;
}

// To send our heart's desires to the server's ear,
void send_command(IMAPClient *client, const char *command) {
    if (send(client->sockfd, command, strlen(command), 0) < 0) {
        display_error("Sending command failed");
    }
}

// The response from the server, like love letters read,
int receive_response(IMAPClient *client) {
    int bytes_received = recv(client->sockfd, client->buffer, BUFFER_SIZE - 1, 0);
    
    if (bytes_received < 0) {
        display_error("Receiving response failed");
    }
    
    client->buffer[bytes_received] = '\0';
    printf("Server: %s\n", client->buffer);
    return bytes_received;
}

// A login, the entrance to our love's sweet domain,
void login_to_server(IMAPClient *client, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    sprintf(command, "a001 LOGIN %s %s\r\n", username, password);
    send_command(client, command);
    receive_response(client);
}

// To fetch our messages, like roses in bloom,
void fetch_emails(IMAPClient *client) {
    send_command(client, "a002 SELECT INBOX\r\n");
    receive_response(client);
    send_command(client, "a003 FETCH 1:* BODY[HEADER]\r\n");
    receive_response(client);
}

// With care we close our client and bid farewell,
void close_client(IMAPClient *client) {
    send_command(client, "a004 LOGOUT\r\n");
    receive_response(client);
    close(client->sockfd);
    free(client);
}

// A gentle main function, where our story shall unfold,
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // As we commence, let the story begin,
    IMAPClient *client = create_client(argv[1]);
    printf("Connection to the IMAP server established!\n");

    // With a heart full of hope, we take our stance,
    login_to_server(client, argv[2], argv[3]);
    
    // Fetching the emails, a dance of delight,
    fetch_emails(client);
    
    // Thus, with love and code, our tale concludes,
    close_client(client);

    // Let not silence linger, nor darkness prevail,
    printf("Farewell to love, and code without fail!\n");
    return EXIT_SUCCESS;
}