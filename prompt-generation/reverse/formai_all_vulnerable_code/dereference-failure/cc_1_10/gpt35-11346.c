//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define MAX_LEN 1024

void send_cmd(int sock, char* cmd) {
    char buf[MAX_LEN];
    strcpy(buf, cmd);
    strcat(buf, "\r\n");
    send(sock, buf, strlen(buf), 0);
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: %s <server_ip> <server_port> <sender_email>\n", argv[0]);
        exit(1);
    }

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock < 0) {
        perror("socket failed");
        exit(1);
    }

    // Connect to server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    // Receive greeting message from server
    char buf[MAX_LEN];
    recv(sock, buf, MAX_LEN-1, 0);
    printf("%s\n", buf);

    // Send HELO command
    send_cmd(sock, "HELO myclient");

    // Send MAIL FROM command
    char mail_from[MAX_LEN];
    sprintf(mail_from, "MAIL FROM:<%s>", argv[3]);
    send_cmd(sock, mail_from);

    // Send RCPT TO command
    char rcpt_to[MAX_LEN];
    printf("Enter recipient email: ");
    fflush(stdout);
    fgets(rcpt_to, MAX_LEN, stdin);
    rcpt_to[strlen(rcpt_to)-1] = '\0'; // remove newline character

    char rcpt_cmd[MAX_LEN];
    sprintf(rcpt_cmd, "RCPT TO:<%s>", rcpt_to);
    send_cmd(sock, rcpt_cmd);

    // Send DATA command
    send_cmd(sock, "DATA");

    // Send email body
    char subject[MAX_LEN];
    char body[MAX_LEN];
    printf("Enter subject: ");
    fflush(stdout);
    fgets(subject, MAX_LEN, stdin);
    printf("Enter email body (end with \\n.\\n): ");
    fflush(stdout);
    fgets(body, MAX_LEN, stdin);

    char email[MAX_LEN];
    sprintf(email, "Subject: %s\nFrom: %s\nTo: %s\n\n%s", subject, argv[3], rcpt_to, body);

    send(sock, email, strlen(email), 0);
    send(sock, ".\r\n", strlen(".\r\n"), 0);

    // Send QUIT command
    send_cmd(sock, "QUIT");

    // Close socket
    close(sock);

    return 0;
}