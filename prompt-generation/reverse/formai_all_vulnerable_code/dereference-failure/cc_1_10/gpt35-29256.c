//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#define PORT 25

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_address;
    struct hostent *server;
    char buffer[1024];

    printf("Initializing SMTP Client...\n");
    printf("Enter hostname: ");
    scanf("%s", buffer);
    server = gethostbyname(buffer);
    if (server == NULL) {
        printf("Could not find the server.\n");
        return -1;
    }

    // Create the socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Could not create the socket.\n");
        return -1;
    }

    // Set server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    bcopy((char *)server->h_addr, (char *)&server_address.sin_addr.s_addr, server->h_length);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Could not connect to the server.\n");
        return -1;
    }

    // Receive welcome message
    recv(sock, buffer, 1024, 0);
    printf("%s", buffer);

    // Send HELO command
    sprintf(buffer, "HELO %s\r\n", buffer);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, 1024, 0);
    printf("%s", buffer);

    // Send MAIL FROM command
    printf("Enter your email address: ");
    scanf("%s", buffer);
    sprintf(buffer, "MAIL FROM:<%s>\r\n", buffer);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, 1024, 0);
    printf("%s", buffer);

    // Send RCPT TO command
    printf("Enter recipient email address: ");
    scanf("%s", buffer);
    sprintf(buffer, "RCPT TO:<%s>\r\n", buffer);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, 1024, 0);
    printf("%s", buffer);

    // Send DATA command
    sprintf(buffer, "DATA\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, 1024, 0);
    printf("%s", buffer);

    // Send email body
    printf("Enter email body and end with a single dot '.' on a new line: \n");
    while (fgets(buffer, 1024, stdin)) {
        send(sock, buffer, strlen(buffer), 0);
        if (buffer[0] == '.' && buffer[1] == '\n') {
            break;
        }
    }
    sprintf(buffer, "\r\n.\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, 1024, 0);
    printf("%s", buffer);

    // Send QUIT command
    sprintf(buffer, "QUIT\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, 1024, 0);
    printf("%s", buffer);

    printf("Email sent successfully.\n");

    // Close the socket
    close(sock);

    return 0;
}