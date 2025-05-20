//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_MSG_SIZE 2048
#define DEFAULT_PORT "21"

char* read_reply(int sock_fd) {
    char buffer[MAX_MSG_SIZE];
    memset(buffer, 0, sizeof(buffer));
    if (recv(sock_fd, buffer, MAX_MSG_SIZE, 0) < 0) {
        printf("Failed to read reply from server.\n");
        exit(1);
    }
    return strdup(buffer);
}

void send_command(int sock_fd, char* message) {
    if (send(sock_fd, message, strlen(message), 0) < 0) {
        printf("Failed to send command to server.\n");
        exit(1);
    }
}

void ftp_get(int sock_fd, char* filename) {
    send_command(sock_fd, "PASV\n");
    char* reply = read_reply(sock_fd);
    printf("%s", reply);

    int h1,h2,h3,h4,p1,p2;
    if (sscanf(reply, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d).\n", &h1,&h2,&h3,&h4,&p1,&p2) != 6) {
        printf("Failed to parse IP and port from server's response.\n");
        exit(1);
    }
    int data_port = p1 << 8 | p2;
   
    struct sockaddr_in data_addr;
    memset(&data_addr, 0, sizeof(struct sockaddr_in));
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(data_port);
    data_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int data_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sock_fd < 0) {
        printf("Failed to create data socket.\n");
        exit(1);
    }

    if (connect(data_sock_fd, (struct sockaddr*)&data_addr, sizeof(struct sockaddr_in)) < 0) {
        printf("Failed to connect to data socket.\n");
        exit(1);
    }

    char cmd[256];
    sprintf(cmd, "RETR %s\n", filename);
    send_command(sock_fd, cmd);
    reply = read_reply(sock_fd);
    printf("%s", reply);
   
    int bytes_received = 0;
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Failed to open local file for writing.\n");
        exit(1);
    }

    char buffer[MAX_MSG_SIZE];
    while ((bytes_received = recv(data_sock_fd, buffer, MAX_MSG_SIZE, 0)) > 0) {
        fwrite(buffer, 1, bytes_received, file);
    }

    fclose(file);
    close(data_sock_fd);
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: %s <host> <user> <pass>\n", argv[0]);
        exit(1);
    }

    struct hostent* host = gethostbyname(argv[1]);
    if (!host) {
        printf("Failed to lookup hostname.\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(DEFAULT_PORT));
    server_addr.sin_addr = *((struct in_addr*)host->h_addr);

    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        printf("Failed to create socket.\n");
        exit(1);
    }

    if (connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(struct sockaddr_in)) < 0) {
        printf("Failed to connect to server.\n");
        exit(1);
    }

    char* reply = read_reply(sock_fd);
    printf("%s", reply);

    char user_message[256];
    sprintf(user_message, "USER %s\n", argv[2]);
    send_command(sock_fd, user_message);
    reply = read_reply(sock_fd);
    printf("%s", reply);

    char pass_message[256];
    sprintf(pass_message, "PASS %s\n", argv[3]);
    send_command(sock_fd, pass_message);
    reply = read_reply(sock_fd);
    printf("%s", reply);

    ftp_get(sock_fd, "filename.txt");

    close(sock_fd);
    return 0;
}