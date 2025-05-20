//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define BUF_SIZE 1024

/* Function declarations */
void error(char *msg);
void ftp_connect(char *server, char *port);
void ftp_login(char *username, char *password);
void ftp_quit();
void ftp_get(char *filename);

/* Global variables */
int sockfd;

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr,"Usage: %s server port username password\n", argv[0]);
        exit(1);
    }

    char *server = argv[1];
    char *port = argv[2];
    char *username = argv[3];
    char *password = argv[4];

    ftp_connect(server, port);
    ftp_login(username, password);
    ftp_get("survival_guide.txt");
    ftp_quit();

    close(sockfd);
    return 0;
}

void ftp_connect(char *server, char *port) {
    struct addrinfo hints;
    struct addrinfo *result, *p;
    int status;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo(server, port, &hints, &result)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(1);
    }

    for (p = result; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket error");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            perror("connect error");
            close(sockfd);
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Unable to connect to server\n");
        exit(1);
    }

    freeaddrinfo(result);
}

void ftp_login(char *username, char *password) {
    char buffer[BUF_SIZE];
    int bytes_read;

    memset(buffer, 0, sizeof(buffer));
    bytes_read = read(sockfd, buffer, sizeof(buffer));
    if (bytes_read == -1) {
        perror("read error");
        ftp_quit();
        exit(1);
    }

    printf("%s\n", buffer);

    sprintf(buffer, "USER %s\r\n", username);
    if (write(sockfd, buffer, strlen(buffer)) == -1) {
        perror("write error");
        ftp_quit();
        exit(1);
    }

    memset(buffer, 0, sizeof(buffer));
    bytes_read = read(sockfd, buffer, sizeof(buffer));
    if (bytes_read == -1) {
        perror("read error");
        ftp_quit();
        exit(1);
    }

    printf("%s\n", buffer);

    sprintf(buffer, "PASS %s\r\n", password);
    if (write(sockfd, buffer, strlen(buffer)) == -1) {
        perror("write error");
        ftp_quit();
        exit(1);
    }

    memset(buffer, 0, sizeof(buffer));
    bytes_read = read(sockfd, buffer, sizeof(buffer));
    if (bytes_read == -1) {
        perror("read error");
        ftp_quit();
        exit(1);
    }

    printf("%s\n", buffer);
}

void ftp_quit() {
    char buffer[BUF_SIZE];
    int bytes_read;

    sprintf(buffer, "QUIT\r\n");
    if (write(sockfd, buffer, strlen(buffer)) == -1) {
        perror("write error");
        exit(1);
    }

    memset(buffer, 0, sizeof(buffer));
    bytes_read = read(sockfd, buffer, sizeof(buffer));
    if (bytes_read == -1) {
        perror("read error");
        exit(1);
    }

    printf("%s\n", buffer);
}

void ftp_get(char *filename) {
    char buffer[BUF_SIZE];
    int bytes_read, file_size;

    /* Send PASV command */
    sprintf(buffer, "PASV\r\n");
    if (write(sockfd, buffer, strlen(buffer)) == -1) {
        perror("write error");
        ftp_quit();
        exit(1);
    }

    /* Get passive mode port */
    memset(buffer, 0, sizeof(buffer));
    bytes_read = read(sockfd, buffer, sizeof(buffer));
    if (bytes_read == -1) {
        perror("read error");
        ftp_quit();
        exit(1);
    }

    printf("%s\n", buffer);

    char *port_str = strstr(buffer, "(") + 1;
    char *saveptr;
    char *token;

    token = strtok_r(port_str, ",", &saveptr);
    int port_num = atoi(token) * 256;
    token = strtok_r(NULL, ",", &saveptr);
    port_num += atoi(token);

    /* Open data connection */
    struct sockaddr_in serv_addr;
    int sockfd_data;

    sockfd_data = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd_data == -1) {
        perror("socket error");
        ftp_quit();
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port_num);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) == -1) {
        perror("inet_pton error");
        ftp_quit();
        exit(1);
    }

    if (connect(sockfd_data, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect error");
        ftp_quit();
        exit(1);
    }

    /* Send RETR command */
    sprintf(buffer, "RETR %s\r\n", filename);
    if (write(sockfd, buffer, strlen(buffer)) == -1) {
        perror("write error");
        ftp_quit();
        exit(1);
    }

    /* Get file size */
    memset(buffer, 0, sizeof(buffer));
    bytes_read = read(sockfd, buffer, sizeof(buffer));
    if (bytes_read == -1) {
        perror("read error");
        ftp_quit();
        exit(1);
    }

    printf("%s\n", buffer);

    if (strncmp(buffer, "550", 3) == 0) {
        printf("File not found: %s\n", filename);
        ftp_quit();
        exit(1);
    }

    if (strncmp(buffer, "150", 3) == 0) {
        sscanf(buffer, "%*s %*d (%d", &file_size);
    }

    /* Receive file */
    FILE *fp;
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("file open error");
        ftp_quit();
        exit(1);
    }

    int bytes_written;
    int total_bytes_written = 0;
    while (1) {
        bytes_read = read(sockfd_data, buffer, sizeof(buffer));
        if (bytes_read == -1) {
            perror("read error");
            ftp_quit();
            exit(1);
        }

        if (bytes_read == 0) {
            break;
        }

        bytes_written = fwrite(buffer, 1, bytes_read, fp);
        if (bytes_written == -1) {
            perror("write error");
            ftp_quit();
            exit(1);
        }

        total_bytes_written += bytes_written;
    }

    fclose(fp);
    close(sockfd_data);

    memset(buffer, 0, sizeof(buffer));
    bytes_read = read(sockfd, buffer, sizeof(buffer));
    if (bytes_read == -1) {
        perror("read error");
        ftp_quit();
        exit(1);
    }

    printf("%s\n", buffer);
}

void error(char *msg) {
    perror(msg);
    exit(1);
}