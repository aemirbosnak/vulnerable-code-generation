//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

int send_email(const char* hostname, int port, const char* username, const char* password) {
    struct hostent* he = gethostbyname(hostname);
    struct sockaddr_in serv_addr;
    int sockfd;

    // Initialize server address structure
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char*)he->h_addr, (char*)&serv_addr.sin_addr.s_addr, he->h_length);
    serv_addr.sin_port = htons(port);

    // Connect to the server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return -1;
    }

    // Send email
    char msg[1024];
    strcpy(msg, "HELO world\r\n");
    if (send(sockfd, msg, strlen(msg), 0) < 0) {
        perror("send");
        return -1;
    }

    strcpy(msg, "MAIL FROM: <");
    strcat(msg, username);
    strcat(msg, ">\r\n");
    if (send(sockfd, msg, strlen(msg), 0) < 0) {
        perror("send");
        return -1;
    }

    strcpy(msg, "RCPT TO: <");
    strcat(msg, username);
    strcat(msg, ">\r\n");
    if (send(sockfd, msg, strlen(msg), 0) < 0) {
        perror("send");
        return -1;
    }

    strcpy(msg, "DATA\r\n");
    if (send(sockfd, msg, strlen(msg), 0) < 0) {
        perror("send");
        return -1;
    }

    strcpy(msg, "From: ");
    strcat(msg, username);
    strcat(msg, "\r\n");
    if (send(sockfd, msg, strlen(msg), 0) < 0) {
        perror("send");
        return -1;
    }

    strcpy(msg, "To: ");
    strcat(msg, username);
    strcat(msg, "\r\n");
    if (send(sockfd, msg, strlen(msg), 0) < 0) {
        perror("send");
        return -1;
    }

    strcpy(msg, "Subject: Hello\r\n");
    if (send(sockfd, msg, strlen(msg), 0) < 0) {
        perror("send");
        return -1;
    }

    strcpy(msg, "\r\n");
    if (send(sockfd, msg, strlen(msg), 0) < 0) {
        perror("send");
        return -1;
    }

    strcpy(msg, "QUIT\r\n");
    if (send(sockfd, msg, strlen(msg), 0) < 0) {
        perror("send");
        return -1;
    }

    // Close the socket
    close(sockfd);

    return 0;
}

int pop3_send_email(const char* hostname, int port, const char* username, const char* password) {
    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, &send_email, (void*)hostname);
    pthread_attr_destroy(&attr);
    pthread_join(tid, NULL);

    return 0;
}

int main() {
    const char* hostname = "pop3.example.com";
    int port = 110;
    const char* username = "user";
    const char* password = "password";

    pop3_send_email(hostname, port, username, password);

    return 0;
}