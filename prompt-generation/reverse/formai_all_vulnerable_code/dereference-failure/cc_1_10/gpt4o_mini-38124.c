//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <ctype.h>

#define PORT 8080
#define BUF_SIZE 1024

// Server Code 
void server() {
    int sfd, cfd;
    struct sockaddr_in addr;
    char buffer[BUF_SIZE];
    
    // Create socket
    if ((sfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) perror("Socket failed");
    
    // Set up server address
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);
    
    // Bind
    if (bind(sfd, (struct sockaddr*)&addr, sizeof(addr)) < 0) perror("Bind failed");
    
    // Listen
    listen(sfd, 3);
    
    // Accept client connection
    if ((cfd = accept(sfd, NULL, NULL)) < 0) perror("Accept failed");
    
    // Receive and respond
    while (1) {
        memset(buffer, 0, BUF_SIZE);
        int n = read(cfd, buffer, BUF_SIZE);
        if (n <= 0) break; // Exit on error or client disconnect
        for (int i = 0; buffer[i]; i++) buffer[i] = toupper(buffer[i]);
        write(cfd, buffer, strlen(buffer));
    }
    
    close(cfd);
    close(sfd);
}

// Client Code 
void client() {
    int sock;
    struct sockaddr_in addr;
    char buffer[BUF_SIZE];
    
    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) perror("Socket failed");
    
    // Set up server address
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);
    
    // Connect to server
    if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) perror("Connection failed");
    
    // Send data
    printf("Enter text: ");
    fgets(buffer, BUF_SIZE, stdin);
    write(sock, buffer, strlen(buffer));
    
    // Receive response
    memset(buffer, 0, BUF_SIZE);
    read(sock, buffer, BUF_SIZE);
    printf("Server Response: %s\n", buffer);
    
    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <server|client>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    if (strcmp(argv[1], "server") == 0) {
        server();
    } else if (strcmp(argv[1], "client") == 0) {
        client();
    } else {
        fprintf(stderr, "Invalid argument. Use 'server' or 'client'.\n");
    }
    
    return EXIT_SUCCESS;
}