//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024
#define FTP_PORT 21

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void ftp_authenticate(int sockfd, const char *username, const char *password) {
    char buffer[BUF_SIZE];

    // Read the server's welcome message
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Send USER command
    snprintf(buffer, sizeof(buffer), "USER %s\r\n", username);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Send PASS command
    snprintf(buffer, sizeof(buffer), "PASS %s\r\n", password);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);
}

void ftp_list_files(int sockfd) {
    char buffer[BUF_SIZE];

    // Send the LIST command
    snprintf(buffer, sizeof(buffer), "PASV\r\n");
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Extract the IP and Port from the PASV response
    int p1, p2;
    char ip_str[16];
    sscanf(buffer, "227 Entering Passive Mode (%[^)])", ip_str);
    sscanf(strrchr(ip_str, ',') + 1, "%d,%d", &p1, &p2);
    char *token = strtok(ip_str, ",");
    char ip[16] = {0};
    int i = 0;
    while (token) {
        if (i < 4) {
            strncat(ip, token, strlen(token));
            if (i < 3) strcat(ip, ".");
        }
        token = strtok(NULL, ",");
        i++;
    }
    int data_port = p1 * 256 + p2;

    // Create a new socket for data transfer
    int data_sock;
    struct sockaddr_in data_addr;
    if ((data_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        die("Data socket creation failed");
    }

    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(data_port);
    inet_pton(AF_INET, ip, &data_addr.sin_addr);

    if (connect(data_sock, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        die("Data connection failed");
    }

    // Send the RETR command and receive files
    snprintf(buffer, sizeof(buffer), "LIST\r\n");
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Read the file list from the data connection
    while (read(data_sock, buffer, sizeof(buffer)) > 0) {
        printf("%s", buffer);
    }

    close(data_sock);
}

int main() {
    char server[100], username[50], password[50];

    printf("Welcome to the FTP Client! \n");
    printf("Please enter the FTP server address: ");
    scanf("%s", server);
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    // Create FTP connection
    int sockfd;
    struct sockaddr_in server_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        die("Socket creation failed");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(FTP_PORT);
    struct hostent *host_info = gethostbyname(server);
    if (host_info == NULL) {
        fprintf(stderr, "Failed to resolve host %s\n", server);
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    memcpy(&server_addr.sin_addr.s_addr, host_info->h_addr, host_info->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        die("Connection to the FTP server failed");
    }

    // Authenticate to the FTP server
    ftp_authenticate(sockfd, username, password);

    // List files in the current directory
    ftp_list_files(sockfd);

    // Close the main socket
    close(sockfd);
    printf("Goodbye from the FTP Client!\n");
    return 0;
}