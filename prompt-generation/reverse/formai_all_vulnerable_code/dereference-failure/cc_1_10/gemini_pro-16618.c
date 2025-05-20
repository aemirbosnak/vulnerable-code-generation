//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

// A lively POP3 client that fetches emails with vigor!

// Colors for vibrant output
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"

int main(int argc, char *argv[]) {
    // Let's get the server's address
    if (argc < 3) {
        printf(RED "Usage: %s <server> <port>\n", argv[0]);
        return 1;
    }

    // Connect to the POP3 server with enthusiasm
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Couldn't create socket");
        return 2;
    }
    
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Couldn't connect to server");
        return 3;
    }
    
    // Say hello to the server with style
    char buffer[1024];
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf(GREEN "%s", buffer);
    
    // Authorize the mighty client
    char user[256], pass[256];
    printf(YELLOW "Enter username: ");
    scanf("%s", user);
    sprintf(buffer, "USER %s\r\n", user);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);
    
    printf(YELLOW "Enter password: ");
    scanf("%s", pass);
    sprintf(buffer, "PASS %s\r\n", pass);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);
    
    // Retrieve the list of emails with panache
    send(sockfd, "LIST\r\n", 6, 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf(GREEN "Email list:\n%s", buffer);
    
    // Retrieve an email with style
    int email_num;
    printf(YELLOW "Enter email number to retrieve: ");
    scanf("%d", &email_num);
    sprintf(buffer, "RETR %d\r\n", email_num);
    send(sockfd, buffer, strlen(buffer), 0);
    
    recv(sockfd, buffer, sizeof(buffer), 0);
    
    // Display headers with flair
    char header_buffer[1024];
    while (strcmp(buffer, "\r\n.\r\n") != 0) {
        strcpy(header_buffer, buffer);
        recv(sockfd, buffer, sizeof(buffer), 0);
        printf("%s", header_buffer);
    }
    
    // Display email body with passion
    printf(GREEN "Email body:\n");
    while (recv(sockfd, buffer, sizeof(buffer), 0) > 0) {
        printf("%s", buffer);
    }
    
    // Close the connection with a smile
    close(sockfd);
    printf(RED "Connection closed. Goodbye!\n");
    
    return 0;
}