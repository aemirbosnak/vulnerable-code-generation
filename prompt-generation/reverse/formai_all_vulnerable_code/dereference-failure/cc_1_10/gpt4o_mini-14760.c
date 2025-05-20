//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

// Function to establish a connection to the FTP server
int connect_to_server(const char *hostname, int port) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;

    if ((host = gethostbyname(hostname)) == NULL) {
        die("gethostbyname error");
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        die("socket error");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        die("connect error");
    }

    return sockfd;
}

// Function for sending and receiving data from the FTP server
void send_command(int sockfd, const char *cmd, char *response) {
    send(sockfd, cmd, strlen(cmd), 0);
    send(sockfd, "\r\n", 2, 0);
    recv(sockfd, response, BUFFER_SIZE, 0);
}

// Function to login to the FTP server
void ftp_login(int sockfd, const char *username, const char *password) {
    char response[BUFFER_SIZE];
    char command[512];

    send_command(sockfd, "USER", response);
    printf("Server: %s", response);

    send_command(sockfd, username, response);
    printf("Server: %s", response);

    send_command(sockfd, "PASS", response);
    printf("Server: %s", response);

    send_command(sockfd, password, response);
    printf("Server: %s", response);
}

// Function to list files in the current directory on the FTP server
void list_files(int sockfd) {
    char response[BUFFER_SIZE];

    send_command(sockfd, "LIST", response);
    printf("Server: %s", response);
}

// Function to download a file from the FTP server
void download_file(int sockfd, const char *filename) {
    char command[512];
    char response[BUFFER_SIZE];
    int filefd;

    snprintf(command, sizeof(command), "RETR %s", filename);
    send_command(sockfd, command, response);
    printf("Server: %s", response);

    if ((filefd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR)) < 0) {
        die("open error");
    }

    while (1) {
        int bytes_received = recv(sockfd, response, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        write(filefd, response, bytes_received);
    }

    close(filefd);
    printf("Downloaded %s\n", filename);
}

// Function to upload a file to the FTP server
void upload_file(int sockfd, const char *filename) {
    char command[512];
    char response[BUFFER_SIZE];
    int filefd;

    snprintf(command, sizeof(command), "STOR %s", filename);
    send_command(sockfd, command, response);
    printf("Server: %s", response);

    if ((filefd = open(filename, O_RDONLY)) < 0) {
        die("open error");
    }

    while (1) {
        int bytes_read = read(filefd, response, BUFFER_SIZE);
        if (bytes_read <= 0) {
            break;
        }
        send(sockfd, response, bytes_read, 0);
    }

    close(filefd);
    printf("Uploaded %s\n", filename);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd = connect_to_server(hostname, 21);
    printf("Connected to %s\n", hostname);

    ftp_login(sockfd, username, password);
    list_files(sockfd);

    // Example file download; you can change the filename
    download_file(sockfd, "example.txt");

    // Example file upload; you can change the filename
    upload_file(sockfd, "upload_example.txt");

    close(sockfd);
    return 0;
}