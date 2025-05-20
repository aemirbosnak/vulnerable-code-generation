//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUF_SIZE 1024

void die(const char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        die("Usage:./smtp_client <server_ip> <sender_email> <receiver_email>");
    }

    char* server_ip = argv[1];
    char* sender_email = argv[2];
    char* receiver_email = argv[3];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        die("socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(25);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        die("connect");
    }

    char* message = "From: ";
    strcat(message, sender_email);
    strcat(message, "\r\n");
    strcat(message, "To: ");
    strcat(message, receiver_email);
    strcat(message, "\r\n");
    strcat(message, "Subject: Test email\r\n\r\n");
    strcat(message, "This is a test email sent from a SMTP client.\r\n");

    send(sock, message, strlen(message), 0);

    char buf[BUF_SIZE];
    while (recv(sock, buf, BUF_SIZE, 0) > 0) {
        printf("Received: %s", buf);
    }

    close(sock);

    return 0;
}