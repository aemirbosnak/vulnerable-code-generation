//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXLINE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}
 
int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buffer[MAXLINE];
    
    // user-configurable variables
    char username[50] = "example_user";
    char password[50] = "example_password";
    char server_address[50] = "mail.example.com";
    int port_number = 110;
 
    // Create a TCP socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        error("ERROR in creating socket");
 
    // Set the server address and port
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port_number);
    
    if (inet_pton(AF_INET, server_address, &servaddr.sin_addr) <= 0)
        error("ERROR in inet_pton");
 
    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0)
        error("ERROR in connect");
 
    // Receive the server hello message
    bzero(buffer, MAXLINE);
    n = read(sockfd, buffer, MAXLINE);
    if (n < 0)
        error("ERROR in read");
    printf("%s", buffer);
 
    // Send the username to the server
    char user_message[MAXLINE];
    sprintf(user_message, "USER %s\r\n", username);
    n = write(sockfd, user_message, strlen(user_message));
    if (n < 0)
        error("ERROR in write");
    
    // Receive the response from the server
    bzero(buffer, MAXLINE);
    n = read(sockfd, buffer, MAXLINE);
    if (n < 0)
        error("ERROR in read");
    printf("%s", buffer);
    
    // Send the password to the server
    char pass_message[MAXLINE];
    sprintf(pass_message, "PASS %s\r\n", password);
    n = write(sockfd, pass_message, strlen(pass_message));
    if (n < 0)
        error("ERROR in write");
    
    // Receive the response from the server
    bzero(buffer, MAXLINE);
    n = read(sockfd, buffer, MAXLINE);
    if (n < 0)
        error("ERROR in read");
    printf("%s", buffer);
    
    // Send the quit message to the server
    char quit_message[] = "QUIT\r\n";
    n = write(sockfd, quit_message, strlen(quit_message));
    if (n < 0)
        error("ERROR in write");
 
    close(sockfd);
    return 0;
}