//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

void handle(int status) {
    if(status < 0) {
        perror("Error occurred while communicating with server.");
        exit(1);
    }
}

void put_file(int sockfd, char *filename) {
    FILE *fp;
    char buffer[1024];
    int bytes_sent, bytes_read;

    fp = fopen(filename, "r");
    if(fp == NULL) {
        perror("Error: ");
        exit(1);
    }

    bzero(buffer, 1024);
    bytes_read = fread(buffer, sizeof(char), 1024, fp);
    while(bytes_read > 0) {
        bytes_sent = send(sockfd, buffer, bytes_read, 0);
        handle(bytes_sent);
        bzero(buffer, 1024);
        bytes_read = fread(buffer, sizeof(char), 1024, fp);
    }

    fclose(fp);

    printf("File sent to server.\n");
}

void get_file(int sockfd, char *filename) {
    FILE *fp;
    char buffer[1024];
    int bytes_received;

    fp = fopen(filename, "w");
    if(fp == NULL) {
        perror("Error: ");
        exit(1);
    }

    bzero(buffer, 1024);
    bytes_received = recv(sockfd, buffer, 1024, 0);
    while(bytes_received > 0) {
        fwrite(buffer, sizeof(char), bytes_received, fp);
        bzero(buffer, 1024);
        bytes_received = recv(sockfd, buffer, 1024, 0);
    }

    fclose(fp);

    printf("File received from server.\n");
}

int main(int argc, char **argv) {
    char *hostname, *portnumber, *command, *filename, buffer[1024];
    struct sockaddr_in server_addr;
    int sockfd, bytes_received;

    if(argc != 4) {
        printf("Usage: ./ftpclient <hostname> <portnumber> <command>\n");
        printf("Commands: put <filename>, get <filename>\n");
        exit(1);
    }

    hostname = argv[1];
    portnumber = argv[2];
    command = argv[3];

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Error: ");
        exit(1);
    }

    // set up server address
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(portnumber));
    inet_aton(hostname, &server_addr.sin_addr);

    // connect to server
    if(connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error: ");
        exit(1);
    }

    // send command
    bzero(buffer, 1024);
    strcpy(buffer, command);
    send(sockfd, buffer, strlen(buffer), 0);

    // handle command
    if(strcmp(command, "put") == 0) {
        filename = argv[4];
        put_file(sockfd, filename);
    } else if(strcmp(command, "get") == 0) {
        filename = argv[4];
        get_file(sockfd, filename);
    } else {
        printf("Invalid command.\n");
    }

    // close the socket
    close(sockfd);

    return 0;
}