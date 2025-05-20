//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <smtp_server> <from_email> <to_email>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *smtp_server = argv[1];
    char *from_email = argv[2];
    char *to_email = argv[3];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(smtp_server);
    server.sin_family = AF_INET;
    server.sin_port = htons(25);

    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];

    read(sock, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    sprintf(buffer, "HELO %s\r\n", smtp_server);
    write(sock, buffer, strlen(buffer));
    read(sock, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    sprintf(buffer, "MAIL FROM:<%s>\r\n", from_email);
    write(sock, buffer, strlen(buffer));
    read(sock, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    sprintf(buffer, "RCPT TO:<%s>\r\n", to_email);
    write(sock, buffer, strlen(buffer));
    read(sock, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    sprintf(buffer, "DATA\r\n");
    write(sock, buffer, strlen(buffer));
    read(sock, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    sprintf(buffer, "Subject: Test E-mail\r\n\r\nThis is a test message sent from my SMTP client!\r\n.\r\n");
    write(sock, buffer, strlen(buffer));
    read(sock, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    sprintf(buffer, "QUIT\r\n");
    write(sock, buffer, strlen(buffer));
    read(sock, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    close(sock);

    return 0;
}