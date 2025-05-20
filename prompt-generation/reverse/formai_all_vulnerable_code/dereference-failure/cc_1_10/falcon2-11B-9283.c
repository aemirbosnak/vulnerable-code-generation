//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
    // Check for correct usage
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    // Get the hostname from command line argument
    char* hostname = argv[1];
    
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    
    // Resolve the hostname
    struct hostent* server = gethostbyname(hostname);
    if (server == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }
    
    // Create a connected socket
    struct sockaddr_in serv_addr;
    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char*)server->h_addr, (char*)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(25); // Use SMTP port
    
    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }
    
    // Send the email
    char buffer[256];
    sprintf(buffer, "To: recipient@example.com\r\nFrom: sender@example.com\r\nSubject: Test Email\r\n\r\nThis is a test email.\r\n\r\n");
    write(sockfd, buffer, strlen(buffer));
    
    // Receive the response
    char response[256];
    read(sockfd, response, sizeof(response));
    printf("Response: %s\n", response);
    
    // Close the socket
    close(sockfd);
    
    return 0;
}