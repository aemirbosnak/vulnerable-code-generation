//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define POP3_PORT 110 // Default POP3 port

// Function to handle errors
void handle_error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    
    if(argc != 3) {
        printf("Usage: %s [host address] [username]\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    // Initialize socket file descriptors and other variables
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024];
    char user[100];
    char pass[100];
    char cmd[100];
    
    // Get server IP address
    server = gethostbyname(argv[1]);
    if(server == NULL) handle_error("Error: no such host");
    
    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) handle_error("Error: could not create socket");
    
    // Configure socket settings
    memset(&serv_addr, 0, sizeof(serv_addr));   // Clear out structure
    serv_addr.sin_family = AF_INET;             // IPv4
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length); // Set IP address
    serv_addr.sin_port = htons(POP3_PORT);       // Set port number
    
    // Connect to POP3 server
    if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) handle_error("Error: could not connect to host");
    
    // Receive welcome message
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if(n < 0) handle_error("Error: could not read from socket");
    printf("%s", buffer);
    
    // Send username
    sprintf(user, "USER %s\r\n", argv[2]);
    if(send(sockfd, user, strlen(user), 0) < 0) handle_error("Error: could not write to socket");
    
    // Receive response to username
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if(n < 0) handle_error("Error: could not read from socket");
    printf("%s", buffer);
    
    // Enter password
    printf("Enter password: ");
    fgets(pass, sizeof(pass), stdin);
    pass[strlen(pass)-1] = '\0';
    
    // Send password
    sprintf(cmd, "PASS %s\r\n", pass);
    if(send(sockfd, cmd, strlen(cmd), 0) < 0) handle_error("Error: could not write to socket");
    
    // Receive response to password
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if(n < 0) handle_error("Error: could not read from socket");
    printf("%s", buffer);
    
    // Send quit command
    if(send(sockfd, "QUIT\r\n", 6, 0) < 0) handle_error("Error: could not write to socket");
    
    // Receive response to quit command
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if(n < 0) handle_error("Error: could not read from socket");
    printf("%s", buffer);
    
    // Close socket
    close(sockfd);
    
    return EXIT_SUCCESS;
}