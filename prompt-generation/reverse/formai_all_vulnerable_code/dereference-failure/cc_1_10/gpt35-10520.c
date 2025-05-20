//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define POP3_PORT 110

int create_socket(const char* hostname) {
    struct sockaddr_in server;
    struct hostent* host;

    if ((host = gethostbyname(hostname)) == NULL) {
        perror("gethostbyname");
        return -1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    bzero((char*)&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(POP3_PORT);
    memcpy(&server.sin_addr, host->h_addr_list[0], host->h_length);

    if (connect(sockfd, (struct sockaddr*)&server, sizeof(server)) == -1) {
        perror("connect");
        return -1;
    }

    return sockfd;
}

int send_command(int sockfd, const char* cmd) {
    printf("%s\n", cmd);
    write(sockfd, cmd, strlen(cmd));
    return 0;
}

int main(int argc, const char** argv) {
    if (argc < 3) {
        printf("Usage: %s <host> <user> <pass>\n", argv[0]);
        return 1;
    }

    const char* hostname = argv[1];
    const char* username = argv[2];
    const char* password = argc > 3 ? argv[3] : "";

    int sockfd = create_socket(hostname);
    if (sockfd == -1) {
        return 1;
    }

    char buf[2048];
    int len = read(sockfd, buf, sizeof(buf));
    if (len <= 0) {
        perror("read");
        return 1;
    }
    buf[len] = '\0';
    printf("%s", buf);

    send_command(sockfd, "USER ");
    send_command(sockfd, username);
    send_command(sockfd, "\r\n");

    len = read(sockfd, buf, sizeof(buf));
    if (len <= 0) {
        perror("read");
        return 1;
    }
    buf[len] = '\0';
    printf("%s", buf);

    send_command(sockfd, "PASS ");
    send_command(sockfd, password);
    send_command(sockfd, "\r\n");

    len = read(sockfd, buf, sizeof(buf));
    if (len <= 0) {
        perror("read");
        return 1;
    }
    buf[len] = '\0';
    printf("%s", buf);

    send_command(sockfd, "STAT\r\n");

    len = read(sockfd, buf, sizeof(buf));
    if (len <= 0) {
        perror("read");
        return 1;
    }
    buf[len] = '\0';
    printf("%s", buf);

    send_command(sockfd, "QUIT\r\n");

    len = read(sockfd, buf, sizeof(buf));
    if (len <= 0) {
        perror("read");
        return 1;
    }
    buf[len] = '\0';
    printf("%s", buf);

    close(sockfd);

    return 0;
}