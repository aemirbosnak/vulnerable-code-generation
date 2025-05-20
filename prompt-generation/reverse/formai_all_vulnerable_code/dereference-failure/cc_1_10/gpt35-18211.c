//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define SERVER "127.0.0.1"
#define PORT 21

void cyberpunk_authenticate(int sock_fd, char *username, char *password) {
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    recv(sock_fd, buffer, 1024, 0);
    printf("FTP Server Response: %s\n", buffer);
    char* user_command = malloc(strlen(username) + 6);
    sprintf(user_command, "USER %s\r\n", username);
    printf("Client Request: %s", user_command);
    send(sock_fd, user_command, strlen(user_command), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(sock_fd, buffer, 1024, 0);
    printf("FTP Server Response: %s\n", buffer);
    char* pass_command = malloc(strlen(password) + 6);
    sprintf(pass_command, "PASS %s\r\n", password);
    printf("Client Request: %s", pass_command);
    send(sock_fd, pass_command, strlen(pass_command), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(sock_fd, buffer, 1024, 0);
    printf("FTP Server Response: %s\n", buffer);
    free(user_command);
    free(pass_command);
}

void cyberpunk_download(int sock_fd, char *filename) {
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    char* retr_command = malloc(strlen(filename) + 6);
    sprintf(retr_command, "RETR %s\r\n", filename);
    printf("Client Request: %s", retr_command);
    send(sock_fd, retr_command, strlen(retr_command), 0);
    recv(sock_fd, buffer, 1024, 0);
    printf("FTP Server Response: %s\n", buffer);
    FILE *file = fopen(filename, "w");
    while(recv(sock_fd, buffer, 1024, 0) > 0) {
        fprintf(file, "%s", buffer);
        memset(buffer, 0, sizeof(buffer));
    }
    fclose(file);
    free(retr_command);
}

void cyberpunk_upload(int sock_fd, char *filename) {
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    char* stor_command = malloc(strlen(filename) + 6);
    sprintf(stor_command, "STOR %s\r\n", filename);
    printf("Client Request: %s", stor_command);
    send(sock_fd, stor_command, strlen(stor_command), 0);
    FILE *file = fopen(filename, "r");
    while(fgets(buffer, 1024, file) != NULL) {
        send(sock_fd, buffer, strlen(buffer), 0);
        memset(buffer, 0, sizeof(buffer));
    }
    fclose(file);
    recv(sock_fd, buffer, 1024, 0);
    printf("FTP Server Response: %s\n", buffer);
    free(stor_command);
}

void cyberpunk_disconnect(int sock_fd) {
    char* quit_command = "QUIT\r\n";
    printf("Client Request: %s", quit_command);
    send(sock_fd, quit_command, strlen(quit_command), 0);
    close(sock_fd);
}

int main() {
    int sock_fd;
    struct sockaddr_in server_addr;
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);
    connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    char username[256];
    char password[256];
    printf("Enter FTP Username: ");
    scanf("%s", username);
    printf("Enter FTP Password: ");
    scanf("%s", password);
    cyberpunk_authenticate(sock_fd, username, password);
    char filename[256];
    printf("Enter filename to download/upload: ");
    scanf("%s", filename);
    char download_or_upload;
    printf("Do you want to download or upload? (d/u): ");
    scanf(" %c", &download_or_upload);
    if(download_or_upload == 'd') {
        cyberpunk_download(sock_fd, filename);
    } else if (download_or_upload == 'u') {
        cyberpunk_upload(sock_fd, filename);
    } else {
        printf("Invalid Input!");
    }
    cyberpunk_disconnect(sock_fd);
    return 0;
}