//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>

#define BUF_SIZE 1024

struct server_info {
    char ip_addr[25];
    int port;
};

int connect_to_server(struct server_info server) {
    int sock_fd;
    struct sockaddr_in server_addr;

    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server.port);
    if (inet_pton(AF_INET, server.ip_addr, &server_addr.sin_addr) <= 0) {
        perror("invalid address or address not supported");
        exit(EXIT_FAILURE);
    }

    if (connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    return sock_fd;
}

char *trim(char *str) {
    char *end;
    while (isspace((unsigned char)*str)) str++;
    if (*str == 0) return str;
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    *(end + 1) = 0;
    return str;
}

int receive_data(int sock_fd, char *recv_data_buf) {
    int num_bytes;
    if ((num_bytes = recv(sock_fd, recv_data_buf, BUF_SIZE, 0)) == -1) {
        perror("data receive failed");
        exit(EXIT_FAILURE);
    }
    return num_bytes;
}

void check_response_code(char *response, char *expected_code) {
    if (strncmp(response, expected_code, strlen(expected_code)) != 0)
        printf("\nError: Bad response from server. Response was %s\n", response);
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s POP3_SERVER_IP POP3_SERVER_PORT USERNAME\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct server_info server;
    strncpy(server.ip_addr, argv[1], sizeof(server.ip_addr));
    server.port = atoi(argv[2]);
    char *username = argv[3];

    int sock_fd = connect_to_server(server);

    char recv_buf[BUF_SIZE];
    memset(recv_buf, 0, BUF_SIZE);
    receive_data(sock_fd, recv_buf);
    check_response_code(recv_buf, "+OK");

    char user_buf[BUF_SIZE];
    memset(user_buf, 0, BUF_SIZE);
    sprintf(user_buf, "USER %s\r\n", username);
    send(sock_fd, user_buf, strlen(user_buf), 0);

    memset(recv_buf, 0, BUF_SIZE);
    receive_data(sock_fd, recv_buf);
    check_response_code(recv_buf, "+OK");

    char pass_buf[BUF_SIZE];
    memset(pass_buf, 0, BUF_SIZE);

    printf("Enter password: ");
    fgets(pass_buf, BUF_SIZE, stdin);
    trim(pass_buf);

    char pass_cmd_buf[BUF_SIZE];
    memset(pass_cmd_buf, 0, BUF_SIZE);
    sprintf(pass_cmd_buf, "PASS %s\r\n", pass_buf);
    send(sock_fd, pass_cmd_buf, strlen(pass_cmd_buf), 0);

    memset(recv_buf, 0, BUF_SIZE);
    receive_data(sock_fd, recv_buf);
    check_response_code(recv_buf, "+OK");

    send(sock_fd, "STAT\r\n", strlen("STAT\r\n"), 0);

    memset(recv_buf, 0, BUF_SIZE);
    receive_data(sock_fd, recv_buf);
    check_response_code(recv_buf, "+OK");

    char *num_messages_str = strtok(recv_buf, " ");
    num_messages_str = strtok(NULL, " ");
    int num_messages = atoi(num_messages_str);

    printf("You have %d messages.\n", num_messages);

    for (int i = 1; i <= num_messages; i++) {
        char list_cmd_buf[BUF_SIZE];
        memset(list_cmd_buf, 0, BUF_SIZE);
        sprintf(list_cmd_buf, "LIST %d\r\n", i);
        send(sock_fd, list_cmd_buf, strlen(list_cmd_buf), 0);

        memset(recv_buf, 0, BUF_SIZE);
        receive_data(sock_fd, recv_buf);
        check_response_code(recv_buf, "+OK");

        char *msg_info = strtok(recv_buf, " ");
        char *msg_size_str = strtok(NULL, " ");
        int msg_size = atoi(msg_size_str);

        printf("Message %d size: %d\n", i, msg_size);

        char retr_cmd_buf[BUF_SIZE];
        memset(retr_cmd_buf, 0, BUF_SIZE);
        sprintf(retr_cmd_buf, "RETR %d\r\n", i);
        send(sock_fd, retr_cmd_buf, strlen(retr_cmd_buf), 0);

        memset(recv_buf, 0, BUF_SIZE);

        int recv_total = 0;
        while (1) {
            int num_bytes = receive_data(sock_fd, recv_buf);
            recv_total += num_bytes;
            if (strncmp(recv_buf + num_bytes - 5, "\r\n.\r\n", 5) == 0) {
                break;
            }
            memset(recv_buf, 0, BUF_SIZE);
        }

        printf("Message %d:\n%s\n", i, recv_buf);
    }

    send(sock_fd, "QUIT\r\n", strlen("QUIT\r\n"), 0);

    memset(recv_buf, 0, BUF_SIZE);
    receive_data(sock_fd, recv_buf);
    check_response_code(recv_buf, "+OK");

    close(sock_fd);

    return 0;
}