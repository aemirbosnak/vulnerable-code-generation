//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SMTP_PORT 25

void send_command(int sock, char *command, char *arg) {
    char buffer[256];
    sprintf(buffer, "%s %s\r\n", command, arg);
    send(sock, buffer, strlen(buffer), 0);
}

int main(int argc, char *argv[]) {
    if(argc != 3) {
        fprintf(stderr, "Usage: %s <host> <from_email>\n", argv[0]);
        exit(1);
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        perror("Failed to create socket");
        exit(1);
    }

    struct hostent *he = gethostbyname(argv[1]);
    if(he == NULL) {
        fprintf(stderr, "Failed to resolve hostname\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr = *((struct in_addr*)he->h_addr);

    if(connect(sock, (const struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Failed to connect to server");
        exit(1);
    }

    char buffer[256];
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    send_command(sock, "EHLO", argv[2]);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    send_command(sock, "MAIL FROM:", argv[2]);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    char to_email[256];
    printf("To: ");
    fgets(to_email, sizeof(to_email), stdin);
    send_command(sock, "RCPT TO:", to_email);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    send_command(sock, "DATA", "");
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    send_command(sock, "Subject:", "");
    char message[1024];
    printf("Enter your message (press CTRL+D to end):\n");
    ssize_t message_len = fread(message, sizeof(char), sizeof(message), stdin);
    send(sock, message, message_len, 0);

    send_command(sock, ".", "");
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    send_command(sock, "QUIT", "");
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    close(sock);
    return 0;
}