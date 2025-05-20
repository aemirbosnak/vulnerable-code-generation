//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define SMTP_PORT 25

int main(int argc, char* argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[1024];

    // Check if the command line arguments are correct
    if(argc != 4) {
        printf("Usage: %s <server_addr> <from_email> <to_email>\n", argv[0]);
        exit(1);
    }

    // Get the server IP address from hostname
    struct hostent* server = gethostbyname(argv[1]);
    if(server == NULL) {
        printf("Error: could not resolve hostname %s\n", argv[1]);
        exit(1);
    }

    // Create a socket for SMTP communication
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        printf("Error: could not create socket\n");
        exit(1);
    }

    // Connect to the SMTP server
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SMTP_PORT);
    servaddr.sin_addr = *((struct in_addr*)server->h_addr_list[0]);

    if(connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        printf("Error: could not connect to server\n");
        exit(1);
    }

    // Read server greeting message
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);  
    printf("%s", buffer);

    // Say hello to the server
    sprintf(buffer, "HELO %s\r\n", argv[1]);
    send(sockfd, buffer, strlen(buffer), 0);  
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);  
    printf("%s", buffer);

    // Send mail from
    sprintf(buffer, "MAIL FROM:<%s>\r\n", argv[2]);
    send(sockfd, buffer, strlen(buffer), 0);  
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);  
    printf("%s", buffer);

    // Send mail to
    sprintf(buffer, "RCPT TO:<%s>\r\n", argv[3]);
    send(sockfd, buffer, strlen(buffer), 0);  
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);  
    printf("%s", buffer);

    // Start message data
    send(sockfd, "DATA\r\n", sizeof("DATA\r\n"), 0);  
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);  
    printf("%s", buffer);

    // Send mail header
    sprintf(buffer, "From: <%s>\r\n", argv[2]);
    send(sockfd, buffer, strlen(buffer), 0);  
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "To: <%s>\r\n", argv[3]);
    send(sockfd, buffer, strlen(buffer), 0);  
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "Subject: Testing SMTP client\r\n");
    send(sockfd, buffer, strlen(buffer), 0);  
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "\r\n");
    send(sockfd, buffer, strlen(buffer), 0);  
    memset(buffer, 0, sizeof(buffer));

    // Send mail body
    sprintf(buffer, "This is a test message sent from a C SMTP client\n");
    send(sockfd, buffer, strlen(buffer), 0);  
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, ".\r\n");
    send(sockfd, buffer, strlen(buffer), 0);  
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);  
    printf("%s", buffer);

    // Quit session
    send(sockfd, "QUIT\r\n", sizeof("QUIT\r\n"), 0);  
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);  
    printf("%s", buffer);

    // Close socket
    close(sockfd);

    return 0;
}