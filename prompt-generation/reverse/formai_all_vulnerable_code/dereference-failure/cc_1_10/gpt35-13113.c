//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER "pop.gmail.com"
#define PORT 995
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    
    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error: Failed to open socket\n");
        exit(1);
    }
    
    // Get server info
    server = gethostbyname(SERVER);
    if (server == NULL) {
        perror("Error: Failed to get server info\n");
        exit(1);
    }
    
    // Setup server address
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy(server->h_addr, (char *) &server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(PORT);
    
    // Connect to server
    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error: Failed to connect to server\n");
        exit(1);
    }
    
    // Receive greeting message and print to console
    bzero(buffer, BUFFER_SIZE);
    printf("Receiving greeting\n");
    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error: Failed to receive greeting\n");
        exit(1);
    }
    printf("%s", buffer);
    
    // Send user and password
    printf("Sending user and password\n");
    send(sock, "USER myemail@gmail.com\r\n", strlen("USER myemail@gmail.com\r\n"), 0);
    bzero(buffer, BUFFER_SIZE);
    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error: Failed to receive response from server\n");
        exit(1);
    }
    printf("%s", buffer);
    send(sock, "PASS mypassword\r\n", strlen("PASS mypassword\r\n"), 0);
    bzero(buffer, BUFFER_SIZE);
    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error: Failed to receive response from server\n");
        exit(1);
    }
    printf("%s", buffer);
    
    // Send list command to get number of emails in mailbox
    printf("Sending list command\n");
    send(sock, "LIST\r\n", strlen("LIST\r\n"), 0);
    bzero(buffer, BUFFER_SIZE);
    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error: Failed to receive response from server\n");
        exit(1);
    }
    printf("%s", buffer);
    
    // Send quit command and close socket
    printf("Sending quit command and closing socket\n");
    send(sock, "QUIT\r\n", strlen("QUIT\r\n"), 0);
    close(sock);
    
    return 0;
}