//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT 21
#define MAX 4096

void handle_error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void read_reply(int sockfd, char *buffer) {
    memset(buffer, 0, MAX);
    if (recv(sockfd, buffer, MAX, 0) < 0) {
        handle_error("Error while reading server response");
    }
}

void send_cmd(int sockfd, char *cmd) {
    char buffer[MAX];
    memset(buffer, 0, MAX);
    sprintf(buffer, "%s\r\n", cmd);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        handle_error("Error while sending command");
    }
}

void print_reply(char *buffer) {
    printf("%s", buffer);
}

int main() {
    char buffer[MAX];
    char *hostname = "ftp.server.com"; // Your FTP server address
    struct sockaddr_in server_addr;
    int sockfd;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) { handle_error("Error while socket creation"); }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, hostname, &(server_addr.sin_addr));

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Error while connecting");
    }

    read_reply(sockfd, buffer);
    print_reply(buffer);

    // Send Login credentials
    char *username = "yourusername", *password = "yourpassword";
    send_cmd(sockfd, "USER "); send_cmd(sockfd, username);
    read_reply(sockfd, buffer);
    print_reply(buffer);

    send_cmd(sockfd, "PASS "); send_cmd(sockfd, password);
    read_reply(sockfd, buffer);
    print_reply(buffer);

    // Set binary mode
    send_cmd(sockfd, "TYPE I");
    read_reply(sockfd, buffer);
    print_reply(buffer);

    // Get file size
    char *filename = "example_text.txt";
    send_cmd(sockfd, "SIZE "); send_cmd(sockfd, filename);
    read_reply(sockfd, buffer);
    print_reply(buffer);

    // Download file
    send_cmd(sockfd, "RETR "); send_cmd(sockfd, filename);
    read_reply(sockfd, buffer);

    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        handle_error("Error while file creation");
    }

    int size, count = 0;
    while ((size = recv(sockfd, buffer, MAX, 0)) > 0) {
        fwrite(buffer, size, 1, file);
        if (++count % 50 == 0) {
            printf(".");
        }
    }
    printf("\nFile transfer completed successfully.\n");

    send_cmd(sockfd, "QUIT");

    fclose(file);
    close(sockfd);

    return 0;
}