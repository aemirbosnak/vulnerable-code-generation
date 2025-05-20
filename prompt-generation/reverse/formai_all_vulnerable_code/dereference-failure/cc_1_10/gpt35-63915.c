//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    // Check if the right number of arguments was passed
    if (argc < 3) {
        printf("Usage: ./smtp-client <server> <recipient> [<sender>]\n");
        exit(1);
    }

    char* server = argv[1];
    char* recipient = argv[2];
    char* sender;
    
    // Set a default sender if none was provided
    if (argc < 4) {
        sender = "user@example.com";
    }
    else {
        sender = argv[3];
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Get the server hostname
    struct hostent* serverinfo = gethostbyname(server);
    if (serverinfo == NULL) {
        printf("Error getting server hostname\n");
        exit(1);
    }

    // Create a socket address structure
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(SMTP_PORT);
    memcpy(&addr.sin_addr, serverinfo->h_addr, serverinfo->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Read the initial server greeting
    char buffer[BUFFER_SIZE];
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    
    // Send the helo command
    char helo[BUFFER_SIZE];
    sprintf(helo, "HELO %s\r\n", server);
    send(sockfd, helo, strlen(helo), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    
    // Send the mail from command
    char mail_from[BUFFER_SIZE];
    sprintf(mail_from, "MAIL FROM:<%s>\r\n", sender);
    send(sockfd, mail_from, strlen(mail_from), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    
    // Send the rcpt to command
    char rcpt_to[BUFFER_SIZE];
    sprintf(rcpt_to, "RCPT TO:<%s>\r\n", recipient);
    send(sockfd, rcpt_to, strlen(rcpt_to), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    
    // Send the data command
    char data[] = "DATA\r\n";
    send(sockfd, data, strlen(data), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    // Send the email body
    char body[BUFFER_SIZE];
    printf("Enter email message:\n");
    fgets(body, BUFFER_SIZE, stdin);
    send(sockfd, body, strlen(body), 0);

    // Send the end of data command
    char eod[] = "\r\n.\r\n";
    send(sockfd, eod, strlen(eod), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    // Send the quit command
    char quit[] = "QUIT\r\n";
    send(sockfd, quit, strlen(quit), 0);

    // Close the socket
    close(sockfd);

    return 0;
}