//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>

#define PORT 993

void readResponse(int s) {
    char buffer[4096];
    ssize_t n;

    while ((n = recv(s, buffer, sizeof(buffer), 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }
}

void sendMessage(int s, const char *msg) {
    ssize_t n = send(s, msg, strlen(msg), 0);
    if (n < 0) {
        perror("Failed to send message");
        exit(1);
    }
}

void login(int s, const char *username, const char *password) {
    char buffer[4096];

    sprintf(buffer, ". login %s %s\n", username, password);
    sendMessage(s, buffer);
    readResponse(s);
}

void selectMailbox(int s, const char *mailbox) {
    char buffer[4096];

    sprintf(buffer, ". select %s\n", mailbox);
    sendMessage(s, buffer);
    readResponse(s);
}

void fetchMessage(int s, int message) {
    char buffer[4096];

    sprintf(buffer, ". fetch %d body[header.fields (subject from)]\n", message);
    sendMessage(s, buffer);
    readResponse(s);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    int s;
    struct hostent *h;
    struct sockaddr_in addr;

    h = gethostbyname(argv[1]);
    if (h == NULL) {
        perror("Failed to find hostname");
        exit(1);
    }

    s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (s < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr = *(struct in_addr *)h->h_addr;

    if (connect(s, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Failed to connect to server");
        exit(1);
    }

    readResponse(s);

    login(s, argv[2], argv[3]);

    selectMailbox(s, "INBOX");

    fetchMessage(s, 1);

    sendMessage(s, ". logout\n");

    readResponse(s);

    close(s);

    return 0;
}