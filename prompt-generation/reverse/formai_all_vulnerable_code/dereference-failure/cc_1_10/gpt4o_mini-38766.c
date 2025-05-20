//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define SERVER_PORT 993  // IMAP over SSL
#define BUFFER_SIZE 1024

void die(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void send_command(int socket, const char *command) {
    if (send(socket, command, strlen(command), 0) == -1) {
        die("send");
    }
}

void receive_response(int socket, char *buffer, int size) {
    int bytes_received = recv(socket, buffer, size - 1, 0);
    if (bytes_received < 0) {
        die("recv");
    }
    buffer[bytes_received] = '\0';  // Null-terminate the string
}

void login(int socket, const char *username, const char *password) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "a001 LOGIN %s %s\r\n", username, password);
    send_command(socket, buffer);
    
    receive_response(socket, buffer, sizeof(buffer));
    printf("Login Response: %s\n", buffer);
}

void list_mailboxes(int socket) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "a002 LIST \"\" \"*\"\r\n");
    send_command(socket, buffer);
    
    while (1) {
        receive_response(socket, buffer, sizeof(buffer));
        printf("List Response: %s\n", buffer);
        
        if (strstr(buffer, "OK") != NULL) {
            break;  // Exit loop if OK is found
        }
    }
}

void fetch_email(int socket, const char *mailbox) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "a003 SELECT %s\r\n", mailbox);
    send_command(socket, buffer);
    
    receive_response(socket, buffer, sizeof(buffer));
    printf("Select Mailbox Response: %s\n", buffer);

    snprintf(buffer, sizeof(buffer), "a004 FETCH 1 BODY[]\r\n");
    send_command(socket, buffer);
    
    while (1) {
        receive_response(socket, buffer, sizeof(buffer));
        printf("Fetch Response: %s\n", buffer);
        
        if (strstr(buffer, "OK") != NULL) {
            break;  // Exit loop if OK is found
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];
    int socket_fd;
    struct sockaddr_in server_addr;
    
    // Create socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        die("socket");
    }

    // Resolve the server address
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        die("gethostbyname");
    }

    // Set up server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    
    // Connect to server
    if (connect(socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        die("connect");
    }
    
    printf("Connected to IMAP server: %s\n", hostname);
    
    // Login to the server
    login(socket_fd, username, password);
    
    // List mailboxes
    list_mailboxes(socket_fd);
    
    // Fetch email from the inbox
    fetch_email(socket_fd, "INBOX");
    
    // Close the connection
    close(socket_fd);
    return 0;
}