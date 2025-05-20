//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

void error_handling(char *message);
void ftp_handling(int sock);

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;

    if (argc != 3) {
        printf("Usage: %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error_handling("socket() error");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        error_handling("connect() error");
    }

    ftp_handling(sock);
    close(sock);
    return 0;
}

void error_handling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

void read_file(int sock, char *filename) {
    FILE *fp;
    char buf[BUF_SIZE];

    fp = fopen(filename, "w");
    if (!fp) {
        error_handling("fopen() error");
    }

    while (1) {
        int n = read(sock, buf, BUF_SIZE);
        if (n < 0) {
            error_handling("read() error");
        } else if (n == 0) {
            break;
        }

        if (fwrite(buf, 1, n, fp) != n) {
            error_handling("fwrite() error");
        }
    }

    fclose(fp);
}

void write_file(int sock, char *filename) {
    FILE *fp;
    char buf[BUF_SIZE];
    int n;

    fp = fopen(filename, "r");
    if (!fp) {
        error_handling("fopen() error");
    }

    while ((n = fread(buf, 1, BUF_SIZE, fp)) > 0) {
        if (write(sock, buf, n) != n) {
            error_handling("write() error");
        }
    }

    fclose(fp);
}

void ftp_handling(int sock) {
    char buf[BUF_SIZE];

    while (1) {
        printf("ftp> ");
        fgets(buf, BUF_SIZE, stdin);

        if (send(sock, buf, strlen(buf), 0) == -1) {
            error_handling("send() error");
        }

        if (strncmp(buf, "get", 3) == 0) {
            char filename[BUF_SIZE];
            sscanf(buf+4, "%s", filename);
            read_file(sock, filename);
        } else if (strncmp(buf, "put", 3) == 0) {
            char filename[BUF_SIZE];
            sscanf(buf+4, "%s", filename);
            write_file(sock, filename);
        } else if (strncmp(buf, "quit", 4) == 0) {
            break;
        }

        int n = read(sock, buf, BUF_SIZE);
        if (n < 0) {
            error_handling("read() error");
        } else if (n == 0) {
            break;
        }

        buf[n] = '\0';
        printf("%s", buf);
    }
}