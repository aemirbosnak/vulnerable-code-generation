//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <netdb.h>

#define MAX_BUFFER 1024
#define SERVER_PORT 993
#define IMAP_SERVER "imap.example.com"

// Function declarations
void error(const char *msg);
void connect_to_server(int *sock, struct sockaddr_in *server_address);
void send_command(int sock, const char *cmd);
void receive_response(int sock);
void list_mailboxes(int sock);
void get_subject_lines(int sock);

int main() {
    int sock;
    struct sockaddr_in server_address;

    // Connect to the IMAP server
    connect_to_server(&sock, &server_address);
    
    // Authenticate user
    send_command(sock, "a1 LOGIN username password");
    receive_response(sock);

    // List mailboxes
    list_mailboxes(sock);
    
    // Get subject lines from the inbox
    get_subject_lines(sock);

    // Clean up and close the socket
    close(sock);
    return 0;
}

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void connect_to_server(int *sock, struct sockaddr_in *server_address) {
    struct hostent *server;

    *sock = socket(AF_INET, SOCK_STREAM, 0);
    if (*sock < 0) 
        error("ERROR opening socket");

    server = gethostbyname(IMAP_SERVER);
    if (server == NULL) 
        error("ERROR, no such host");

    memset((char *)server_address, 0, sizeof(*server_address));
    server_address->sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_address->sin_addr.s_addr, server->h_length);
    server_address->sin_port = htons(SERVER_PORT);
    
    if (connect(*sock, (struct sockaddr *)server_address, sizeof(*server_address)) < 0)
        error("ERROR connecting");

    receive_response(*sock); // Initial Response from the server
}

void send_command(int sock, const char *cmd) {
    printf("Sending command: %s\n", cmd);
    write(sock, cmd, strlen(cmd)); 
    write(sock, "\r\n", 2); // IMAP command should end with CRLF
}

void receive_response(int sock) {
    char buffer[MAX_BUFFER];
    memset(buffer, 0, MAX_BUFFER);
    read(sock, buffer, MAX_BUFFER-1);
    printf("Server Response: %s\n", buffer);
}

void list_mailboxes(int sock) {
    printf("Listing Mailboxes:\n");
    send_command(sock, "a2 LIST \"\" *");
    receive_response(sock);
}

void get_subject_lines(int sock) {
    printf("Fetching Subject Lines from Inbox:\n");
    send_command(sock, "a3 SELECT INBOX");
    receive_response(sock);

    // Fetch the messages
    send_command(sock, "a4 FETCH 1:* (ENVELOPE)");
    receive_response(sock);
}

// Note: For a full implementation, you would need to handle SSL/TLS connections too which is 
// essential for secure communication with an IMAP server. Use OpenSSL for proper connection security.