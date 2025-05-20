//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/time.h>
#include <time.h>
#include <netinet/tcp.h>
#include <pthread.h>

#define MAX_SIZE 1024
#define PORT 110
#define HOST "pop.gmail.com"

typedef struct {
    char *mail_from;
    char *mail_to;
    char *subject;
    char *content;
    char *username;
    char *password;
} Email;

void *send_mail(void *ptr) {
    Email *email = (Email *) ptr;
    char buffer[MAX_SIZE];
    int sockfd;
    int ret;

    struct hostent *server;
    struct sockaddr_in address;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server = gethostbyname(HOST);

    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    address.sin_addr = *(struct in_addr *)server->h_addr;

    ret = connect(sockfd, (struct sockaddr *)&address, sizeof(address));

    if (ret < 0) {
        perror("connect");
        exit(1);
    }

    printf("Connected to POP3 server\n");

    ret = send(sockfd, "USER ", strlen("USER "), 0);

    if (ret < 0) {
        perror("send");
        exit(1);
    }

    ret = send(sockfd, email->username, strlen(email->username), 0);

    if (ret < 0) {
        perror("send");
        exit(1);
    }

    ret = send(sockfd, "PASS ", strlen("PASS "), 0);

    if (ret < 0) {
        perror("send");
        exit(1);
    }

    ret = send(sockfd, email->password, strlen(email->password), 0);

    if (ret < 0) {
        perror("send");
        exit(1);
    }

    ret = send(sockfd, "QUIT", strlen("QUIT"), 0);

    if (ret < 0) {
        perror("send");
        exit(1);
    }

    close(sockfd);
}

int main() {
    Email email;

    strcpy(email.mail_from, "sender@gmail.com");
    strcpy(email.mail_to, "recipient@gmail.com");
    strcpy(email.subject, "Subject");
    strcpy(email.content, "Message");

    strcpy(email.username, "username");
    strcpy(email.password, "password");

    pthread_t thread;

    pthread_create(&thread, NULL, send_mail, (void *)&email);

    pthread_join(thread, NULL);

    return 0;
}