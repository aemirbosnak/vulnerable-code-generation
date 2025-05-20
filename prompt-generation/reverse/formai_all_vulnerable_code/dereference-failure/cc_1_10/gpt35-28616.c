//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 993
#define MAX_SIZE 1024

// Function to connect to IMAP server
int connect_server(char *ip_address)
{
    int sock_fd;
    struct sockaddr_in server_addr;

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, ip_address, &server_addr.sin_addr) <= 0) {
        printf("Invalid IP address\n");
        exit(1);
    }

    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server: %s\n", strerror(errno));
        exit(1);
    }

    return sock_fd;
}

// Function to authenticate with IMAP server
void authenticate(int sock_fd, char *username, char *password)
{
    char buffer[MAX_SIZE];
    int num_bytes;

    // Login to the server
    sprintf(buffer, "login %s %s\n", username, password);
    send(sock_fd, buffer, strlen(buffer), 0);

    // Wait for server response
    num_bytes = recv(sock_fd, buffer, MAX_SIZE, 0);
    buffer[num_bytes] = '\0';

    // Check if authentication was successful
    if (strstr(buffer, "OK") == NULL) {
        printf("Authentication failed: %s\n", buffer);
        exit(1);
    }

    printf("Authentication successful: %s\n", buffer);
}

// Function to fetch inbox messages from the server
void fetch_inbox_messages(int sock_fd)
{
    char buffer[MAX_SIZE];
    int num_bytes;

    // Select the inbox folder
    sprintf(buffer, "select inbox\n");
    send(sock_fd, buffer, strlen(buffer), 0);

    // Wait for server response
    num_bytes = recv(sock_fd, buffer, MAX_SIZE, 0);
    buffer[num_bytes] = '\0';

    // Check if folder selection was successful
    if (strstr(buffer, "OK") == NULL) {
        printf("Error selecting inbox folder: %s\n", buffer);
        exit(1);
    }

    // Fetch message count
    sprintf(buffer, "status inbox (messages)\n");
    send(sock_fd, buffer, strlen(buffer), 0);

    // Wait for server response
    num_bytes = recv(sock_fd, buffer, MAX_SIZE, 0);
    buffer[num_bytes] = '\0';

    // Parse message count
    char *token = strtok(buffer, " ");
    while (token != NULL) {
        if (isdigit(*token)) {
            printf("Number of messages in inbox: %s\n", token);
            break;
        }
        token = strtok(NULL, " ");
    }

    // Fetch message list
    sprintf(buffer, "fetch 1:* (body[])\n");
    send(sock_fd, buffer, strlen(buffer), 0);

    // Wait for server response
    num_bytes = recv(sock_fd, buffer, MAX_SIZE, 0);
    buffer[num_bytes] = '\0';

    printf("Inbox messages:\n%s\n", buffer);
}

int main()
{
    char ip_address[] = "127.0.0.1";
    char username[] = "testuser";
    char password[] = "testpassword";

    int sock_fd = connect_server(ip_address);
    authenticate(sock_fd, username, password);
    fetch_inbox_messages(sock_fd);

    return 0;
}