//FormAI DATASET v1.0 Category: Email Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER 2048
#define SERVER_NAME "mail.server.com"
#define SERVER_PORT 25

int main()
{
    int sock; 
    struct sockaddr_in server_addr;
    struct hostent *he;
    char buffer[MAX_BUFFER];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Error creating socket");
        exit(1);
    }

    // Get server IP address from hostname
    if ((he = gethostbyname(SERVER_NAME)) == NULL) {
        perror("Error resolving hostname");
        exit(1);
    }

    // Set server address and port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr = *((struct in_addr *)he->h_addr);
    server_addr.sin_port = htons(SERVER_PORT);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting to server");
        exit(1);
    }

    // Receive server greetings
    memset(buffer, 0, sizeof(buffer));
    recv(sock, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    // Send EHLO command to server
    sprintf(buffer, "EHLO %s\r\n", inet_ntoa(*((struct in_addr *)he->h_addr)));
    send(sock, buffer, strlen(buffer), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(sock, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    // Send MAIL FROM command to server
    sprintf(buffer, "MAIL FROM:<awesome.email@example.com>\r\n");
    send(sock, buffer, strlen(buffer), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(sock, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    // Send RCPT TO command to server
    sprintf(buffer, "RCPT TO:<recipient.email@example.com>\r\n");
    send(sock, buffer, strlen(buffer), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(sock, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    // Send DATA command to server
    sprintf(buffer, "DATA\r\n");
    send(sock, buffer, strlen(buffer), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(sock, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    // Send email body to server
    sprintf(buffer, "Subject: Test email\r\n\r\nThis is a test email sent from my C email client.\r\n.\r\n");
    send(sock, buffer, strlen(buffer), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(sock, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    // Send QUIT command to server
    sprintf(buffer, "QUIT\r\n");
    send(sock, buffer, strlen(buffer), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(sock, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    // Close socket
    close(sock);

    return 0;
}