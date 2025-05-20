//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define FTP_PORT 21

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int sockfd, const char *command) {
    write(sockfd, command, strlen(command));
    write(sockfd, "\r\n", 2);
}

void read_response(int sockfd) {
    char response[BUFFER_SIZE];
    int n = read(sockfd, response, sizeof(response) - 1);
    response[n] = '\0';
    printf("%s", response);
}

void login(int sockfd, const char *user, const char *pass) {
    char command[BUFFER_SIZE];

    sprintf(command, "USER %s", user);
    send_command(sockfd, command);
    read_response(sockfd);

    sprintf(command, "PASS %s", pass);
    send_command(sockfd, command);
    read_response(sockfd);
}

void download_file(int sockfd, const char *filename) {
    char command[BUFFER_SIZE];
    FILE *fp;

    sprintf(command, "RETR %s", filename);
    send_command(sockfd, command);
    read_response(sockfd);

    fp = fopen(filename, "wb");
    if (fp == NULL) {
        error("Error opening file for writing");
    }

    char buffer[BUFFER_SIZE];
    int n;
    while ((n = read(sockfd, buffer, sizeof(buffer))) > 0) {
        fwrite(buffer, sizeof(char), n, fp);
    }

    fclose(fp);
    printf("Downloaded file: %s\n", filename);
}

void upload_file(int sockfd, const char *filename) {
    char command[BUFFER_SIZE];
    FILE *fp;

    sprintf(command, "STOR %s", filename);
    send_command(sockfd, command);
    read_response(sockfd);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        error("Error opening file for reading");
    }

    char buffer[BUFFER_SIZE];
    int n;
    while ((n = fread(buffer, sizeof(char), sizeof(buffer), fp)) > 0) {
        write(sockfd, buffer, n);
    }

    fclose(fp);
    printf("Uploaded file: %s\n", filename);
}

int main(int argc, char *argv[]) {
    const char *hostname = "ftp.example.com"; // Change to your FTP server
    const char *username = "your_username";    // Change to your FTP username
    const char *password = "your_password";    // Change to your FTP password

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <download/upload> <filename>\n", argv[0]);
        exit(1);
    }

    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;

    host = gethostbyname(hostname);
    if (host == NULL) {
        error("ERROR, no such host\n");
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)host->h_addr, (char *)&server_addr.sin_addr.s_addr, host->h_length);
    server_addr.sin_port = htons(FTP_PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting");
    }

    read_response(sockfd);

    login(sockfd, username, password);

    if (strcmp(argv[1], "download") == 0) {
        download_file(sockfd, argv[2]);
    } else if (strcmp(argv[1], "upload") == 0) {
        upload_file(sockfd, argv[2]);
    } else {
        fprintf(stderr, "Invalid operation. Use 'download' or 'upload'.\n");
        exit(1);
    }

    send_command(sockfd, "QUIT");
    read_response(sockfd);
    close(sockfd);

    return 0;
}