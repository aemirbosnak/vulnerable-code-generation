//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <server> <from> <to> [cc] [bcc]\n", argv[0]);
        return 1;
    }

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    // Get server IP address
    struct hostent *he = gethostbyname(argv[1]);
    if (he == NULL) {
        printf("Unknown host: %s\n", argv[1]);
        return 1;
    }

    // Connect to server
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr = *((struct in_addr *)he->h_addr);
    server.sin_port = htons(25);
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        return 1;
    }

    // Receive welcome message
    char buffer[MAX_BUFFER_SIZE] = {0};
    recv(sock, buffer, MAX_BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send HELO command
    char *helo = "HELO smtpClient\r\n";
    send(sock, helo, strlen(helo), 0);
    recv(sock, buffer, MAX_BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send MAIL FROM command
    char mail_from[MAX_BUFFER_SIZE];
    sprintf(mail_from, "MAIL FROM: <%s>\r\n", argv[2]);
    send(sock, mail_from, strlen(mail_from), 0);
    recv(sock, buffer, MAX_BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send RCPT TO command(s)
    char rcpt_to[MAX_BUFFER_SIZE];
    sprintf(rcpt_to, "RCPT TO: <%s>\r\n", argv[3]);
    send(sock, rcpt_to, strlen(rcpt_to), 0);
    recv(sock, buffer, MAX_BUFFER_SIZE, 0);
    printf("%s", buffer);

    if (argc > 4) {
        char cc[MAX_BUFFER_SIZE];
        sprintf(cc, "RCPT TO: <%s>\r\n", argv[4]);
        send(sock, cc, strlen(cc), 0);
        recv(sock, buffer, MAX_BUFFER_SIZE, 0);
        printf("%s", buffer);
    }

    if (argc > 5) {
        char bcc[MAX_BUFFER_SIZE];
        sprintf(bcc, "RCPT TO: <%s>\r\n", argv[5]);
        send(sock, bcc, strlen(bcc), 0);
        recv(sock, buffer, MAX_BUFFER_SIZE, 0);
        printf("%s", buffer);
    }

    // Send DATA command
    char *data = "DATA\r\n";
    send(sock, data, strlen(data), 0);
    recv(sock, buffer, MAX_BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send email body
    char body[MAX_BUFFER_SIZE];
    printf("Enter email body: ");
    fgets(body, MAX_BUFFER_SIZE, stdin);
    send(sock, body, strlen(body), 0);

    // End email transmission
    char *end = "\r\n.\r\n";
    send(sock, end, strlen(end), 0);
    recv(sock, buffer, MAX_BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send QUIT command
    char *quit = "QUIT\r\n";
    send(sock, quit, strlen(quit), 0);
    recv(sock, buffer, MAX_BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Close socket
    close(sock);

    return 0;
}