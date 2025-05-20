//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024
#define FTP_PORT 21

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int connect_to_server(const char *hostname) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;

    host = gethostbyname(hostname);
    if (host == NULL) {
        error("Error: No such host");
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)host->h_addr, (char *)&server_addr.sin_addr.s_addr, host->h_length);
    server_addr.sin_port = htons(FTP_PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Error connecting to server");
    }

    return sockfd;
}

void send_command(int sockfd, const char *cmd) {
    char buffer[BUFFER_SIZE];
    write(sockfd, cmd, strlen(cmd));
    write(sockfd, "\r\n", 2);
    bzero(buffer, BUFFER_SIZE);
    read(sockfd, buffer, BUFFER_SIZE - 1);
    printf("%s", buffer);
}

void login(int sockfd, const char *username, const char *password) {
    char cmd[BUFFER_SIZE];
    sprintf(cmd, "USER %s", username);
    send_command(sockfd, cmd);
    sprintf(cmd, "PASS %s", password);
    send_command(sockfd, cmd);
}

void list_files(int sockfd) {
    send_command(sockfd, "PASV"); // Switch to passive mode

    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);
    read(sockfd, buffer, BUFFER_SIZE - 1);
    printf("%s", buffer);
    
    // Extract the IP and port for data connection
    int p1, p2, port1, port2;
    sscanf(buffer, "%*d %*d %*d %*d %*d %d,%d", &port1, &port2);
    int data_port = (port1 * 256) + port2;

    // Create data socket
    int data_sock;
    struct sockaddr_in data_addr;
    data_sock = socket(AF_INET, SOCK_STREAM, 0);
    bzero((char *)&data_addr, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(data_port);
    data_addr.sin_addr.s_addr = inet_addr(buffer);

    if (connect(data_sock, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        error("Error connecting to data socket");
    }

    // Send LIST command to retrieve file list
    send_command(sockfd, "LIST");

    // Read file list from data connection
    bzero(buffer, BUFFER_SIZE);
    while (read(data_sock, buffer, BUFFER_SIZE - 1) > 0) {
        printf("%s", buffer);
        bzero(buffer, BUFFER_SIZE);
    }

    close(data_sock);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int ftp_sock = connect_to_server(hostname);
    login(ftp_sock, username, password);
    list_files(ftp_sock);

    close(ftp_sock);
    return 0;
}