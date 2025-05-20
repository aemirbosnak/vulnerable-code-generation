//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define MAXSIZE 1000

int main(int argc, char* argv[]) {

    // Check if user has provided all required arguments
    if (argc < 3) {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        return 0;
    }

    // Create socket
    int sock = 0;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Failed to create socket.\n");
        return 1;
    }

    // Create address struct for IMAP server
    struct sockaddr_in imap_addr;
    memset(&imap_addr, 0, sizeof(imap_addr));
    imap_addr.sin_family = AF_INET;
    imap_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &imap_addr.sin_addr) != 1) {
        printf("Invalid address: %s\n", argv[1]);
        return 1;
    }

    // Connect to IMAP server
    if (connect(sock, (struct sockaddr*) &imap_addr, sizeof(imap_addr)) != 0) {
        printf("Failed to connect to IMAP server.\n");
        return 1;
    }

    // Receive server greeting
    char server_response[MAXSIZE];
    int bytes_received = recv(sock, server_response, MAXSIZE, 0);
    if (bytes_received <= 0) {
        printf("Failed to receive server greeting.\n");
        return 1;
    }
    server_response[bytes_received] = '\0';
    printf("Server says: %s", server_response);

    // Send login command to server
    char username[MAXSIZE], password[MAXSIZE];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    char login_command[MAXSIZE];
    sprintf(login_command, "LOGIN %s %s\r\n", username, password);
    send(sock, login_command, strlen(login_command), 0);

    // Receive login response
    bytes_received = recv(sock, server_response, MAXSIZE, 0);
    if (bytes_received <= 0) {
        printf("Failed to receive login response.\n");
        return 1;
    }
    server_response[bytes_received] = '\0';
    printf("Server says: %s", server_response);

    // Send select command to server
    char select_command[MAXSIZE];
    sprintf(select_command, "SELECT INBOX\r\n");
    send(sock, select_command, strlen(select_command), 0);

    // Receive select response
    bytes_received = recv(sock, server_response, MAXSIZE, 0);
    if (bytes_received <= 0) {
        printf("Failed to receive select response.\n");
        return 1;
    }
    server_response[bytes_received] = '\0';
    printf("Server says: %s", server_response);

    // Send fetch command to server
    char fetch_command[MAXSIZE];
    sprintf(fetch_command, "FETCH 1:* FULL\r\n");
    send(sock, fetch_command, strlen(fetch_command), 0);

    // Receive fetch response
    bytes_received = recv(sock, server_response, MAXSIZE, 0);
    if (bytes_received <= 0) {
        printf("Failed to receive fetch response.\n");
        return 1;
    }
    server_response[bytes_received] = '\0';
    printf("Server says: %s", server_response);

    // Close socket
    close(sock);

    return 0;
}