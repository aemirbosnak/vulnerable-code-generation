//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>

#define PORT 21
#define MAX_LINE 1024
#define SERVER_FILE "server_file"

struct addrinfo hints;
struct addrinfo *servinfo;
int sockfd;
char send_buffer[MAX_LINE];
char recv_buffer[MAX_LINE];

void send_command(char *command) {
    strcpy(send_buffer, command);
    strcat(send_buffer, "\r\n");
    send(sockfd, send_buffer, strlen(send_buffer), 0);
}

void receive_response() {
    memset(recv_buffer, 0, sizeof(recv_buffer));
    int bytes_received = recv(sockfd, recv_buffer, sizeof(recv_buffer), 0);
    if (bytes_received <= 0) {
        printf("Server disconnected.\n");
        close(sockfd);
        exit(0);
    }
    printf("%s", recv_buffer);
}

int main() {
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    getaddrinfo("localhost", "21", &hints, &servinfo);

    sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    if (sockfd == -1) {
        printf("Socket creation failed.\n");
        exit(0);
    }

    printf("Connected to server.\n");

    send_command("USER anonymous");
    receive_response();

    send_command("PASS anonymous");
    receive_response();

    send_command("TYPE I");
    receive_response();

    send_command("PORT 127,0,0,1,0,0");
    receive_response();

    FILE *fp;
    fp = fopen(SERVER_FILE, "wb");
    if (fp == NULL) {
        printf("File creation failed.\n");
        exit(0);
    }

    send_command("RETR server_file");
    receive_response();

    int bytes_received;
    char buffer[MAX_LINE];
    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        fwrite(buffer, 1, bytes_received, fp);
    }

    fclose(fp);
    printf("File received successfully.\n");

    close(sockfd);
    return 0;
}