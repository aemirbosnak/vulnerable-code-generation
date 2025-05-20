//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

void error_handling(char *message);

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in serv_addr;
    char buf[BUF_SIZE];
    int str_len, recv_len, recv_cnt;

    if(argc != 3) {
        printf("Usage: %s <ip> <port>\n", argv[0]);
        exit(1);
    }
   
    // create socket
    sock = socket(PF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        error_handling("socket() error");
    }

    // initialize server address structure
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    // connect to server
    if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        error_handling("connect() error");
    }

    // receive welcome message from the server
    str_len = read(sock, buf, BUF_SIZE);
    if(str_len == -1) {
        error_handling("read() error");
    }
    printf("Message from server: %s", buf);

    while(1) {
        printf("Enter command: ");
        fgets(buf, BUF_SIZE, stdin);
        if(!strcmp(buf, "quit\n")) {
            break;
        }

        // send command to the server
        write(sock, buf, strlen(buf));

        // receive response from the server
        memset(buf, 0, BUF_SIZE);
        recv_len = 0;
        while(recv_len < BUF_SIZE) {
            recv_cnt = read(sock, &buf[recv_len], BUF_SIZE-recv_len);
            if(recv_cnt == -1) {
                error_handling("read() error");
            }
            recv_len += recv_cnt;
        }
        printf("Response from server: %s", buf);
    }

    close(sock);

    return 0;
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}