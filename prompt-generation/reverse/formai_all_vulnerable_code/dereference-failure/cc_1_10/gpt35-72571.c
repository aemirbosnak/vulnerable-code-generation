//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define FTPPORT 21

char user[50] = "";
char pass[50] = "";
char host[50] = "";
char path[256] = "";

int socket_create(const char *host, int port){
    int sockfd;
    struct sockaddr_in addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(host);

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    return sockfd;  
}

int send_recv(int sockfd, char *send_data, int send_len, char *recv_data, int recv_len) {
    if (send(sockfd, send_data, send_len, 0) == -1){
        perror("send");
        exit(EXIT_FAILURE);
    }

    memset(recv_data, 0, recv_len);
    if (recv(sockfd, recv_data, recv_len, 0) == -1){
        perror("recv");
        exit(EXIT_FAILURE);
    }

    printf(">> %s", recv_data);

    return 0;
}

void login(int sockfd) {
    char buffer[1024];
    memset(buffer, 0, 1024);

    sprintf(buffer, "USER %s\r\n", user);
    send_recv(sockfd, buffer, strlen(buffer), buffer, sizeof(buffer));

    sprintf(buffer, "PASS %s\r\n", pass);
    send_recv(sockfd, buffer, strlen(buffer), buffer, sizeof(buffer));
}

void download_file(int sockfd, char *filename) {
    char buffer[1024];
    sprintf(buffer, "RETR %s\r\n", filename);

    send(sockfd, buffer, strlen(buffer), 0);

    FILE * fp = fopen(filename, "w");

    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int bytes_recv = 1;

    while (bytes_recv > 0) {
        char file_data[1024];
        memset(file_data, 0, sizeof(file_data));
        bytes_recv = recv(sockfd, file_data, sizeof(file_data), 0);

        if (bytes_recv == -1) {
            perror("recv");
            exit(EXIT_FAILURE);
        }

        fwrite(file_data, 1, bytes_recv, fp);
    }

    fclose(fp);
}

void upload_file(int sockfd, char *filename) {
    char buffer[1024];
    sprintf(buffer, "STOR %s\r\n", filename);

    send(sockfd, buffer, strlen(buffer), 0);

    FILE * fp = fopen(filename, "r");

    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int bytes_read = 1;

    while (bytes_read > 0) {
        char file_data[1024];
        memset(file_data, 0, sizeof(file_data));
        bytes_read = fread(file_data, 1, sizeof(file_data), fp);

        if (bytes_read == -1) {
            perror("Error reading file");
            exit(EXIT_FAILURE);
        }

        if (bytes_read == 0) {
            break;
        }

        if (send(sockfd, file_data, bytes_read, 0) == -1) {
            perror("send");
            exit(EXIT_FAILURE);
        }
    }

    fclose(fp);
}

int main(int argc, char *argv[]){
    int sockfd;
    char buffer[1024];

    if (argc != 2) {
        printf("usage: %s <ip address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    strcpy(host, argv[1]);

    sockfd = socket_create(host, FTPPORT);

    printf("Type in your username: ");
    fgets(user, sizeof(user), stdin);
    user[strlen(user) - 1] = '\0';

    printf("Type in your password: ");
    fgets(pass, sizeof(pass), stdin);
    pass[strlen(pass) - 1] = '\0';

    login(sockfd);

    printf("Type in the filename you want to download: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strlen(buffer) - 1] = '\0';

    download_file(sockfd, buffer);

    printf("Type in the filename you want to upload: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strlen(buffer) - 1] = '\0';

    upload_file(sockfd, buffer);

    close(sockfd);

    return 0;
}