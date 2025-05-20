//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
  
#define PORT 587 // default SMTP port
  
void send_email(const char* to, const char* from, const char* subject, const char* body) {
    int sockfd;
    struct sockaddr_in servaddr;
    struct hostent *host;
  
    // Get SMTP server IP address
    host = gethostbyname("smtp.server.com");
  
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
  
    // Configure server information
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    bcopy(host->h_addr, (char *)&servaddr.sin_addr.s_addr, host->h_length);
  
    // Connect to server
    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
  
    char buffer[1024];
    int n;
  
    // Validate connection
    n = read(sockfd, buffer, sizeof(buffer));
    buffer[n] = '\0';
    printf("%s", buffer);
    if (buffer[0] != '2') {
        printf("Error: could not connect to SMTP server\n");
        exit(1);
    }
  
    // Send HELO email command
    snprintf(buffer, sizeof(buffer), "EHLO localhost\r\n");
    write(sockfd, buffer, strlen(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    buffer[n] = '\0';
    if (buffer[0] != '2') {
        printf("Error: SMTP server rejected HELO command\n");
        exit(1);
    }
  
    // Send FROM email command
    snprintf(buffer, sizeof(buffer), "MAIL FROM: <%s>\r\n", from);
    write(sockfd, buffer, strlen(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    buffer[n] = '\0';
    if (buffer[0] != '2') {
        printf("Error: SMTP server rejected FROM command\n");
        exit(1);
    }
  
    // Send TO email command
    snprintf(buffer, sizeof(buffer), "RCPT TO: <%s>\r\n", to);
    write(sockfd, buffer, strlen(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    buffer[n] = '\0';
    if (buffer[0] != '2') {
        printf("Error: SMTP server rejected TO command\n");
        exit(1);
    }
  
    // Send data command
    snprintf(buffer, sizeof(buffer), "DATA\r\n");
    write(sockfd, buffer, strlen(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    buffer[n] = '\0';
    if (buffer[0] != '3') {
        printf("Error: SMTP server rejected DATA command\n");
        exit(1);
    }
  
    // Send email headers
    snprintf(buffer, sizeof(buffer), "From: <%s>\r\n", from);
    write(sockfd, buffer, strlen(buffer));
    snprintf(buffer, sizeof(buffer), "To: <%s>\r\n", to);
    write(sockfd, buffer, strlen(buffer));
    snprintf(buffer, sizeof(buffer), "Subject: %s\r\n", subject);
    write(sockfd, buffer, strlen(buffer));
  
    // Send email body
    write(sockfd, body, strlen(body));
  
    // Send termination sequence
    snprintf(buffer, sizeof(buffer), "\r\n.\r\n");
    write(sockfd, buffer, strlen(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    buffer[n] = '\0';
    if (buffer[0] != '2') {
        printf("Error: SMTP server rejected email\n");
        exit(1);
    }
  
    // Send quit command
    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    write(sockfd, buffer, strlen(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    buffer[n] = '\0';
    if (buffer[0] != '2') {
        printf("Error: could not quit SMTP server\n");
        exit(1);
    }
  
    // Close connection
    close(sockfd);
}
  
int main() {
    char to[] = "john.doe@example.com";
    char from[] = "jane.doe@example.com";
    char subject[] = "Test email";
    char body[] = "This is a test email sent from my SMTP client program.";
  
    send_email(to, from, subject, body);
  
    return 0;
}