//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define IMAP_PORT 993 // IMAP SSL port
#define BUFFER_SIZE 1024 // Size of buffer for receiving messages

int main(int argc, char *argv[]) {
    
    /* Check command line arguments */
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_address> <username>\n", argv[0]);
        exit(1);
    }
    
    /* Get server address */
    struct hostent *server;
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host '%s'\n", argv[1]);
        exit(1);
    }
    
    /* Create socket */
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        exit(1);
    }
    
    /* Specify server address and port */
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(IMAP_PORT);
    
    /* Connect to server */
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }
    
    /* Receive banner message */
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);
    
    /* Authenticate with server */
    char command[BUFFER_SIZE];
    snprintf(command, BUFFER_SIZE, "a001 LOGIN %s\n", argv[2]);
    send(sock, command, strlen(command), 0);
    memset(buffer, 0, BUFFER_SIZE);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);
    
    /* List mailboxes */
    snprintf(command, BUFFER_SIZE, "a002 LIST \"\" *\n");
    send(sock, command, strlen(command), 0);
    memset(buffer, 0, BUFFER_SIZE);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);
    
    /* Logout and close connection */
    snprintf(command, BUFFER_SIZE, "a003 LOGOUT\n");
    send(sock, command, strlen(command), 0);
    memset(buffer, 0, BUFFER_SIZE);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);
    close(sock);
    
    return 0;
}