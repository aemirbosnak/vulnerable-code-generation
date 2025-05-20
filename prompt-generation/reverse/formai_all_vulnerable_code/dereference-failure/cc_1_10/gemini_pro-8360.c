//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFF_SIZE (1024)

typedef enum {
    FTP_CMD_CONNECT,
    FTP_CMD_USER,
    FTP_CMD_PASS,
    FTP_CMD_CWD,
    FTP_CMD_LIST,
    FTP_CMD_RETR,
    FTP_CMD_QUIT,
    FTP_CMD_INVALID
} FTPCommand;

typedef struct {
    char *cmd;
    FTPCommand type;
} FTPCommandMap;

static FTPCommandMap ftp_commands[] = {
    {"CONNECT", FTP_CMD_CONNECT},
    {"USER", FTP_CMD_USER},
    {"PASS", FTP_CMD_PASS},
    {"CWD", FTP_CMD_CWD},
    {"LIST", FTP_CMD_LIST},
    {"RETR", FTP_CMD_RETR},
    {"QUIT", FTP_CMD_QUIT}
};

static int ftp_connect(const char *ip, unsigned short port)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return -1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        close(sock);
        return -1;
    }

    return sock;
}

static int ftp_send_command(int sock, const char *cmd)
{
    int len = strlen(cmd);
    if (send(sock, cmd, len, 0) != len) {
        perror("send");
        return -1;
    }

    return 0;
}

static int ftp_receive_response(int sock)
{
    char buff[BUFF_SIZE];
    memset(buff, 0, sizeof(buff));

    if (recv(sock, buff, BUFF_SIZE-1, 0) <= 0) {
        perror("recv");
        return -1;
    }

    printf("%s", buff);

    return 0;
}

static int ftp_process_command(int sock, const char *cmd)
{
    FTPCommand type = FTP_CMD_INVALID;
    for (size_t i = 0; i < sizeof(ftp_commands)/sizeof(ftp_commands[0]); i++) {
        if (strcmp(cmd, ftp_commands[i].cmd) == 0) {
            type = ftp_commands[i].type;
            break;
        }
    }

    switch (type) {
        case FTP_CMD_CONNECT:
            return ftp_connect(strtok(NULL, " "), (unsigned short)atoi(strtok(NULL, " ")));
        case FTP_CMD_USER:
            return ftp_send_command(sock, strcat(strdup(cmd), "\r\n"));
        case FTP_CMD_PASS:
            return ftp_send_command(sock, strcat(strdup(cmd), "\r\n"));
        case FTP_CMD_CWD:
            return ftp_send_command(sock, strcat(strdup(cmd), "\r\n"));
        case FTP_CMD_LIST:
            return ftp_send_command(sock, strcat(strdup(cmd), "\r\n"));
        case FTP_CMD_RETR:
            return ftp_send_command(sock, strcat(strdup(cmd), "\r\n"));
        case FTP_CMD_QUIT:
            return ftp_send_command(sock, strdup(cmd));
        default:
            return -1;
    }
}

static int ftp_loop(int sock)
{
    char buff[BUFF_SIZE];
    memset(buff, 0, sizeof(buff));

    while (1) {
        printf("> ");
        fgets(buff, sizeof(buff), stdin);

        if (ftp_process_command(sock, buff) == -1) {
            fprintf(stderr, "Invalid command\n");
            continue;
        }

        ftp_receive_response(sock);

        if (strcmp(buff, "QUIT") == 0) {
            break;
        }
    }

    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int sock = ftp_connect(argv[1], (unsigned short)atoi(argv[2]));
    if (sock == -1) {
        return EXIT_FAILURE;
    }

    ftp_loop(sock);

    close(sock);

    return EXIT_SUCCESS;
}