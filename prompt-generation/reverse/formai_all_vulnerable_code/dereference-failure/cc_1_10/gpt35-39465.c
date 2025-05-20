//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define MAX_COMMAND_SIZE 1024
#define MAX_RESPONSE_SIZE 1024

/* Function to display FTP server response */
void display_response(char *response) {
    printf("%s\n", response);
}

/* Function to send command to FTP server */
void send_command(int sockfd, char *command) {
    char response[MAX_RESPONSE_SIZE];
    memset(response, 0, sizeof(response));

    if (send(sockfd, command, strlen(command), 0) < 0) {
        perror("send");
        exit(1);
    }

    if (recv(sockfd, response, MAX_RESPONSE_SIZE, 0) < 0) {
        perror("recv");
        exit(1);
    }

    display_response(response);
}

/* Function to download file from FTP server */
void download_file(int sockfd, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    char response[MAX_RESPONSE_SIZE];
    memset(response, 0, sizeof(response));

    if (send(sockfd, "RETR ", strlen("RETR "), 0) < 0) {
        perror("send");
        exit(1);
    }

    if (send(sockfd, filename, strlen(filename), 0) < 0) {
        perror("send");
        exit(1);
    }

    if (recv(sockfd, response, MAX_RESPONSE_SIZE, 0) < 0) {
        perror("recv");
        exit(1);
    }

    if (strncmp(response, "550", 3) == 0) {
        printf("File not found\n");
        exit(1);
    }

    printf("Downloading...\n");

    char buffer[BUFFER_SIZE];
    size_t nbytes;
    while ((nbytes = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, 1, nbytes, fp);
    }

    printf("Download complete\n");
    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: ./ftp_client <hostname> <port> <username>\n");
        exit(1);
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);
    char *username = argv[3];

    /* Create socket */
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    /* Connect to server */
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, hostname, &serv_addr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    printf("Connected to %s:%d\n", hostname, port);

    /* Receive and display server response */
    char response[MAX_RESPONSE_SIZE];
    memset(response, 0, sizeof(response));

    if (recv(sockfd, response, MAX_RESPONSE_SIZE, 0) < 0) {
        perror("recv");
        exit(1);
    }

    display_response(response);

    /* Send username */
    char command[MAX_COMMAND_SIZE];
    printf("Enter password: ");
    char *password = getpass("");

    sprintf(command, "USER %s\n", username);
    send_command(sockfd, command);

    /* Send password */
    sprintf(command, "PASS %s\n", password);
    send_command(sockfd, command);

    /* Send PASV command */
    send_command(sockfd, "PASV\n");

    /* Parse PASV response */
    int h1, h2, h3, h4, p1, p2;

    if (sscanf(response, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)", &h1, &h2, &h3, &h4, &p1, &p2) < 0) {
        perror("sscanf");
        exit(1);
    }

    /* Calculate data port */
    int data_port = p1 * 256 + p2;

    /* Create data socket */
    int data_sockfd;
    if ((data_sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    /* Connect to data port */
    serv_addr.sin_port = htons(data_port);

    if (connect(data_sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    /* Send LIST command */
    send_command(sockfd, "LIST\n");

    /* Receive directory listing */
    printf("Retrieving directory listing...\n");

    char buffer[BUFFER_SIZE];
    size_t nbytes;
    while ((nbytes = recv(data_sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, 1, nbytes, stdout);
    }

    /* Close data socket */
    close(data_sockfd);

    /* Prompt user for file to download */
    printf("Enter filename to download: ");
    char filename[MAX_COMMAND_SIZE];
    memset(filename, 0, sizeof(filename));
    fgets(filename, MAX_COMMAND_SIZE, stdin);

    /* Remove newline character */
    size_t len = strlen(filename);
    if (len > 0 && filename[len-1] == '\n') {
        filename[len-1] = '\0';
    }

    /* Download file */
    download_file(sockfd, filename);

    /* Send QUIT command */
    send_command(sockfd, "QUIT\n");

    /* Close socket */
    close(sockfd);

    return 0;
}