//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>

#define MAX_LINE 1024
#define POP3_PORT 110

typedef enum { DISCONNECTED, CONNECTING, CONNECTED } POP3_STATUS;

unsigned char buffer[MAX_LINE];
POP3_STATUS status = DISCONNECTED;

int pop3_connect(const char* host, const char* user, const char* pass);
int pop3_execute(int sockfd, const char* cmd, unsigned char* res, size_t size);
void pop3_parse(unsigned char* data);

int main(int argc, char* argv[]) {
    const char* host = "mail.example.com";
    const char* user = "example@example.com";
    const char* pass = "password";

    int sockfd = pop3_connect(host, user, pass);
    if (sockfd < 0) {
        fprintf(stderr, "Failed to connect to POP3 server!\n");
        exit(EXIT_FAILURE);
    }

    while (status == CONNECTED) {
        printf("> ");
        fgets((char*)buffer, MAX_LINE, stdin);
        buffer[strcspn((const char*)buffer, "\n")] = '\0';

        if (strlen((const char*)buffer) == 0)
            continue;

        if (strcmp((const char*)buffer, "QUIT") == 0) {
            pop3_execute(sockfd, "QUIT\r\n", buffer, MAX_LINE);
            pop3_parse(buffer);
            status = DISCONNECTED;
            break;
        }

        pop3_execute(sockfd, (const char*)buffer, buffer, MAX_LINE);
        pop3_parse(buffer);
    }

    close(sockfd);

    exit(EXIT_SUCCESS);
}

int pop3_connect(const char* host, const char* user, const char* pass) {
    int sockfd;
    struct hostent* h;
    struct sockaddr_in saddr;
    char buf[MAX_LINE];

    if ((h = gethostbyname(host)) == NULL) {
        perror("gethostbyname()");
        return -1;
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket()");
        return -1;
    }

    memset(&saddr, 0, sizeof(struct sockaddr_in));
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(POP3_PORT);
    saddr.sin_addr = *((struct in_addr*)h->h_addr);

    if (connect(sockfd, (struct sockaddr*)&saddr, sizeof(saddr)) < 0) {
        perror("connect()");
        return -1;
    }

    if (fcntl(sockfd, F_SETFL, O_NONBLOCK) < 0) {
        perror("fcntl()");
        return -1;
    }

    pop3_execute(sockfd, "USER ", buffer, MAX_LINE);
    sprintf(buf, "%s\r\n", user);
    pop3_execute(sockfd, buf, buffer, MAX_LINE);
    pop3_parse(buffer);

    pop3_execute(sockfd, "PASS ", buffer, MAX_LINE);
    sprintf(buf, "%s\r\n", pass);
    pop3_execute(sockfd, buf, buffer, MAX_LINE);
    pop3_parse(buffer);

    status = CONNECTED;

    return sockfd;
}

int pop3_execute(int sockfd, const char* cmd, unsigned char* res, size_t size) {
    int len;

    if ((len = send(sockfd, cmd, strlen(cmd), 0)) < 0) {
        perror("send()");
        return -1;
    }

    if (recv(sockfd, res, size, 0) < 0) {
        perror("recv()");
        return -1;
    }

    return 0;
}

void pop3_parse(unsigned char* data) {
    char *ptr, *status;

    if ((ptr = strstr((const char*)data, "+OK")) != NULL) {
        status = "OK";
    } else if ((ptr = strstr((const char*)data, "-ERR")) != NULL) {
        status = "ERROR";
    } else {
        status = "UNKNOWN";
    }

    printf("%s: %s\n", status, ptr);
}