//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

#define BUFFER_SIZE 4096
#define DATA_PORT 20

#define error(a) {perror(a); exit(1);}
#define client_details "192.168.0.100" // Enter your client details here
#define USER "USERNAME_GOES_HERE" // Enter your username here
#define PASS "PASSWORD_GOES_HERE" // Enter your password here

// Connect to FTP Server
int connect_to_server(char *server_ip) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error creating socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(21);
    inet_aton(server_ip, &server_addr.sin_addr);
    memset(&(server_addr.sin_zero), '\0', 8);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(struct sockaddr)) < 0) {
        error("Error connecting to server");
    }

    char buffer[BUFFER_SIZE];
    int n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (n < 0) {
        error("Error receiving data from server");
    }

    printf("%s", buffer);
    return sockfd;
}

// Login to FTP Server
void login_to_server(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n;

    // username prompt
    char username[BUFFER_SIZE];
    printf("Username: ");
    fgets(username, BUFFER_SIZE, stdin);
    username[strcspn(username, "\n")] = 0;

    char *command = malloc(sizeof(char) * BUFFER_SIZE);
    snprintf(command, BUFFER_SIZE, "USER %s\r\n", USER);
    n = send(sockfd, command, strlen(command), 0);
    if (n < 0) {
        error("Error sending data to server");
    }

    n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (n < 0) {
        error("Error receiving data from server");
    }

    printf("%s", buffer);

    // password prompt
    char *password = getpass("Password: ");

    memset(command, 0, strlen(command));
    snprintf(command, BUFFER_SIZE, "PASS %s\r\n", PASS);
    n = send(sockfd, command, strlen(command), 0);
    if (n < 0) {
        error("Error sending data to server");
    }

    n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (n < 0) {
        error("Error receiving data from server");
    }

    printf("%s", buffer);
}

// Retrieve Data
int retrieve_data(int sockfd, char *filename) {
    char buffer[BUFFER_SIZE];
    struct sockaddr_in data_addr, connect_addr;
    socklen_t connect_addr_len = sizeof(connect_addr);
    int data_sockfd, n, filefd;
    off_t offset = 0;

    memset(&data_addr, 0, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(DATA_PORT);

    data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sockfd < 0) {
        error("Error creating socket");
    }

    if (connect(data_sockfd, (struct sockaddr *) &data_addr, sizeof(data_addr)) < 0) {
        error("Error connecting data socket");
    }

    char *command = malloc(sizeof(char) * BUFFER_SIZE);
    snprintf(command, BUFFER_SIZE, "RETR %s\r\n", filename);
    n = send(sockfd, command, strlen(command), 0);
    if (n < 0) {
        error("Error sending data to server");
    }

    n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (n < 0) {
        error("Error receiving data from server");
    }

    if (strstr(buffer, "550")) {
        printf("File not found.\n");
        return -1;
    }

    char *mode = "wb";
    filefd = open(filename, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH); // Open the file you are retrieving in binary mode
    if (filefd == -1) {
        error("Error opening file");
    }

    while ((n = recv(data_sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        if (write(filefd, buffer, n) != n) {
            error("Error writing to file");
        }
    }

    if (n < 0) {
        error("Error receiving data from server");
    }

    close(filefd);
    close(data_sockfd);

    return 0;
}

int main() {
    char *server_ip = malloc(sizeof(char) * BUFFER_SIZE);
    strcpy(server_ip, client_details);
    int sockfd, n;

    sockfd = connect_to_server(server_ip);

    login_to_server(sockfd);

    char *filename = malloc(sizeof(char) * BUFFER_SIZE);
    printf("Enter filename to retrieve: ");
    scanf("%s", filename);

    retrieve_data(sockfd, filename);

    close(sockfd);
    return 0;
}