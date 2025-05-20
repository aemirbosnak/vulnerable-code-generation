//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

// A gentle whisper of love for our connection configuration
void init_connection(const char *server, int port, int *sock) {
    struct sockaddr_in server_addr;
    struct hostent *host;

    // Seeking out our beloved server
    host = gethostbyname(server);
    if (host == NULL) {
        fprintf(stderr, "Could not find host %s\n", server);
        exit(1);
    }

    // Bringing our hearts together
    *sock = socket(AF_INET, SOCK_STREAM, 0);
    if (*sock < 0) {
        perror("Unable to create socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    // Embracing the connection
    if (connect(*sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Unable to connect");
        exit(1);
    }
    printf("Connected to the server, a sweet beginning!\n");
}

// A poetic invitation to log in to our IMAP love story
void login(int sock, const char *username, const char *password) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "A001 LOGIN \"%s\" \"%s\"\r\n", username, password);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);
}

// Our hearts entwined as we fetch beautiful messages
void fetch_messages(int sock) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "A002 SELECT INBOX\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // The sweet moments of fetching
    snprintf(buffer, sizeof(buffer), "A003 FETCH 1:* (RFC822)\r\n");
    send(sock, buffer, strlen(buffer), 0);
    while (recv(sock, buffer, sizeof(buffer)-1, 0) > 0) {
        printf("%s", buffer);
        if (strstr(buffer, "A003 OK")) {
            break; // Bidding farewell to this part
        }
    }
}

// An enchanting farewell to the server
void logout(int sock) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "A004 LOGOUT\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);
    close(sock);
}

int main() {
    int sock;
    const char *server = "imap.example.com"; // Your IMAP server
    const char *username = "your_email@example.com"; // Your email
    const char *password = "your_password"; // Your password

    // A passionate rendezvous with the server
    init_connection(server, 993, &sock); // Connection on SSL port
    login(sock, username, password); 
    fetch_messages(sock); 
    logout(sock); 

    return 0;
}