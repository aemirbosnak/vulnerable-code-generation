//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_PORT 110
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void pop3_authenticate(int sock, const char *username, const char *password) {
    char buffer[BUFFER_SIZE];

    // Send USER command
    snprintf(buffer, sizeof(buffer), "USER %s\r\n", username);
    write(sock, buffer, strlen(buffer));
    read(sock, buffer, sizeof(buffer) - 1);
    printf("%s", buffer);

    // Send PASS command
    snprintf(buffer, sizeof(buffer), "PASS %s\r\n", password);
    write(sock, buffer, strlen(buffer));
    read(sock, buffer, sizeof(buffer) - 1);
    printf("%s", buffer);
}

void pop3_list_messages(int sock) {
    char buffer[BUFFER_SIZE];
    
    // Send LIST command
    snprintf(buffer, sizeof(buffer), "LIST\r\n");
    write(sock, buffer, strlen(buffer));
    read(sock, buffer, sizeof(buffer) - 1);
    printf("%s", buffer);
}

void pop3_retrieve_message(int sock, int msg_number) {
    char buffer[BUFFER_SIZE];

    // Send RETR command
    snprintf(buffer, sizeof(buffer), "RETR %d\r\n", msg_number);
    write(sock, buffer, strlen(buffer));
    read(sock, buffer, sizeof(buffer) - 1);
    printf("Message %d:\n%s", msg_number, buffer);
}

void pop3_quit(int sock) {
    char buffer[BUFFER_SIZE];

    // Send QUIT command
    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    write(sock, buffer, strlen(buffer));
    read(sock, buffer, sizeof(buffer) - 1);
    printf("%s", buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server> <username> <password>\n", argv[0]);
        exit(1);
    }
  
    const char *server = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];
    
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        error("ERROR opening socket");
    }

    // Setup server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, server, &server_addr.sin_addr) <= 0) {
        error("ERROR invalid server address");
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting");
    }

    // Read server greeting
    read(sock, buffer, sizeof(buffer) - 1);
    printf("%s", buffer); 

    pop3_authenticate(sock, username, password);
    pop3_list_messages(sock);

    // Let's assume we want to fetch the first message
    pop3_retrieve_message(sock, 1);
    
    pop3_quit(sock);
    
    // Close socket
    close(sock);
    return 0;
}