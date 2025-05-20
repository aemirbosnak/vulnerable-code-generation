//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAXBUF 1024

// Function to connect to FTP server
int connect_to_ftp_server(char *ip, int port, char *username, char *password) {
    char buffer[MAXBUF];
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connection failed.\n");
        return -1;
    }

    if (recv(sockfd, buffer, MAXBUF, 0) < 0) {
        printf("Error receiving message from FTP server.\n");
        return -1;
    }

    sprintf(buffer, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);
    if (recv(sockfd, buffer, MAXBUF, 0) < 0) {
        printf("Error receiving message from FTP server.\n");
        return -1;
    }

    sprintf(buffer, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);
    if (recv(sockfd, buffer, MAXBUF, 0) < 0) {
        printf("Error receiving message from FTP server.\n");
        return -1;
    }

    return sockfd;
}

// Function to download a file from the FTP server
void download_file(int sockfd, char *filename) {
    char buffer[MAXBUF];
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error creating file for download.\n");
        return;
    }

    sprintf(buffer, "RETR %s\r\n", filename);
    send(sockfd, buffer, strlen(buffer), 0);
    if (recv(sockfd, buffer, MAXBUF, 0) < 0) {
        printf("Error receiving message from FTP server.\n");
        return;
    }

    while (1) {
        int n = recv(sockfd, buffer, MAXBUF, 0);
        if (n <= 0) {
            break;
        }
        fwrite(buffer, sizeof(char), n, fp);
    }

    printf("File downloaded successfully.\n");
    fclose(fp);
}

int main() {
    char ftp_ip[MAXBUF], ftp_username[MAXBUF], ftp_password[MAXBUF], filename[MAXBUF];
    int ftp_port;

    printf("Enter FTP server IP: ");
    scanf("%s", ftp_ip);

    printf("Enter FTP server port number: ");
    scanf("%d", &ftp_port);

    printf("Enter FTP server username: ");
    scanf("%s", ftp_username);

    printf("Enter FTP server password: ");
    scanf("%s", ftp_password);

    int sockfd = connect_to_ftp_server(ftp_ip, ftp_port, ftp_username, ftp_password);

    if (sockfd < 0) {
        printf("Connection to FTP server failed.\n");
        return -1;
    }

    printf("Enter filename to download: ");
    scanf("%s", filename);

    download_file(sockfd, filename);

    close(sockfd);

    return 0;
}