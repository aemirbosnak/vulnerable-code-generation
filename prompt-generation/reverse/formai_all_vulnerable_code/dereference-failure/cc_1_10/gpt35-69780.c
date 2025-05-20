//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAXLINE 1024

void error(char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    exit(1);
}

void ftp_connect(int sockfd) {
    
    char buf[MAXLINE];
    recv(sockfd, buf, MAXLINE, 0);
    
    printf("%s", buf);
    
    char username[MAXLINE];
    char password[MAXLINE];
    
    printf("Username: ");
    fgets(username, MAXLINE, stdin);
    username[strlen(username) - 1] = '\0';
    
    send(sockfd, username, strlen(username), 0);
    recv(sockfd, buf, MAXLINE, 0);
    printf("%s", buf);
    
    printf("Password: ");
    fgets(password, MAXLINE, stdin);
    password[strlen(password) - 1] = '\0';
    
    send(sockfd, password, strlen(password), 0);
    recv(sockfd, buf, MAXLINE, 0);
    printf("%s", buf);
}

void ftp_list(int sockfd) {
    
    char buf[MAXLINE];
    send(sockfd, "LIST", 4, 0);
    recv(sockfd, buf, MAXLINE, 0);
    
    if (buf[0] == '-') {
        printf("Error: %s", buf);
        return;
    }
    
    printf("%s", buf);
    
    while (recv(sockfd, buf, MAXLINE, 0) > 0) {
        printf("%s", buf);
    }
}

int ftp_pasv(int sockfd) {
    
    char buf[MAXLINE];
    send(sockfd, "PASV", 4, 0);
    recv(sockfd, buf, MAXLINE, 0);
    
    if (buf[0] == '-') {
        printf("Error: %s", buf);
        return -1;
    }
    
    char *p = strchr(buf, '(');
    if (!p) {
        printf("Error: Invalid response\n");
        return -1;
    }
    
    p++;
    int a, b, c, d, e, f;
    sscanf(p, "%d,%d,%d,%d,%d,%d)", &a, &b, &c, &d, &e, &f);
    
    char ip[MAXLINE];
    snprintf(ip, MAXLINE, "%d.%d.%d.%d", a, b, c, d);
    
    int port = e * 256 + f;
    
    return ftp_create(ip, port);
}

int ftp_create(char *ip, int port) {
    
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket.\n");
    }
    
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    
    if (inet_pton(AF_INET, ip, &servaddr.sin_addr) <= 0) {
        error("Error converting IP address.\n");
    }
    
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        error("Error connecting to server.\n");
    }
    
    return sockfd;
}

void ftp_download(int sockfd, char *filename) {
    
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        error("Error opening file.\n");
    }
    
    char buf[MAXLINE];
    send(sockfd, "TYPE I", 6, 0);
    recv(sockfd, buf, MAXLINE, 0);
    
    if (buf[0] == '-') {
        printf("Error: %s", buf);
        return;
    }
    
    int datasockfd = ftp_pasv(sockfd);
    
    if (datasockfd < 0) {
        return;
    }
    
    send(sockfd, "RETR ", 5, 0);
    send(sockfd, filename, strlen(filename), 0);
    send(sockfd, "\r\n", 2, 0);
    recv(sockfd, buf, MAXLINE, 0);
    
    if (buf[0] == '-') {
        printf("Error: %s", buf);
        return;
    }
    
    while (recv(datasockfd, buf, MAXLINE, 0) > 0) {
        write(fd, buf, strlen(buf));
    }
    
    close(datasockfd);
    close(fd);
}

void ftp_quit(int sockfd) {
    
    char buf[MAXLINE];
    send(sockfd, "QUIT", 4, 0);
    recv(sockfd, buf, MAXLINE, 0);
    printf("%s", buf);
}

int main(int argc, char **argv) {
    
    if (argc != 3) {
        error("Usage: ftpclient hostname portnumber\n");
    }
    
    char *hostname = argv[1];
    int portnumber = atoi(argv[2]);
    
    int sockfd = ftp_create(hostname, portnumber);
    ftp_connect(sockfd);
    
    char input[MAXLINE];
    
    while (1) {
        
        printf("ftp> ");
        fgets(input, MAXLINE, stdin);
        input[strlen(input) - 1] = '\0';
        
        if (strcmp(input, "quit") == 0) {
            ftp_quit(sockfd);
            break;
        }
        else if (strcmp(input, "ls") == 0) {
            ftp_list(sockfd);
        }
        else if (strncmp(input, "get ", 4) == 0) {
            char *filename = input + 4;
            ftp_download(sockfd, filename);
        }
        else {
            printf("Error: Invalid command.\n");
        }
    }
    
    close(sockfd);
    return 0;
}