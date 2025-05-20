//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 21

int sockfd, datafd;

void error(char *msg) {
    perror(msg);
    exit(1);
}

void send_command(char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
}

char *recv_response() {
    char *response = malloc(1024);
    int len = recv(sockfd, response, 1024, 0);
    response[len] = '\0';
    return response;
}

void login(char *username, char *password) {
    send_command("USER ");
    send_command(username);
    send_command("\r\n");
    char *response = recv_response();
    if (strncmp(response, "331", 3) == 0) {
        send_command("PASS ");
        send_command(password);
        send_command("\r\n");
        response = recv_response();
        if (strncmp(response, "230", 3) == 0) {
            printf("Logged in successfully.\n");
        } else {
            printf("Login failed.\n");
            exit(1);
        }
    } else {
        printf("Login failed.\n");
        exit(1);
    }
}

void list_files() {
    send_command("LIST\r\n");
    char *response = recv_response();
    while (strncmp(response, "226", 3) != 0) {
        printf("%s", response);
        response = recv_response();
    }
}

void download_file(char *filename) {
    send_command("RETR ");
    send_command(filename);
    send_command("\r\n");
    char *response = recv_response();
    if (strncmp(response, "150", 3) == 0) {
        int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1) {
            error("open");
        }
        char *buffer = malloc(1024);
        int len;
        while ((len = recv(sockfd, buffer, 1024, 0)) > 0) {
            write(fd, buffer, len);
        }
        close(fd);
        printf("File downloaded successfully.\n");
    } else {
        printf("File download failed.\n");
    }
}

void upload_file(char *filename) {
    send_command("STOR ");
    send_command(filename);
    send_command("\r\n");
    char *response = recv_response();
    if (strncmp(response, "150", 3) == 0) {
        int fd = open(filename, O_RDONLY);
        if (fd == -1) {
            error("open");
        }
        char *buffer = malloc(1024);
        int len;
        while ((len = read(fd, buffer, 1024)) > 0) {
            send(sockfd, buffer, len, 0);
        }
        close(fd);
        printf("File uploaded successfully.\n");
    } else {
        printf("File upload failed.\n");
    }
}

void disconnect() {
    send_command("QUIT\r\n");
    char *response = recv_response();
    if (strncmp(response, "221", 3) == 0) {
        printf("Disconnected successfully.\n");
    } else {
        printf("Disconnect failed.\n");
    }
}

int main() {
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error("socket");
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error("connect");
    }

    char *response = recv_response();
    printf("%s", response);

    login("user", "password");

    list_files();

    download_file("file.txt");

    upload_file("file.txt");

    disconnect();

    close(sockfd);

    return 0;
}