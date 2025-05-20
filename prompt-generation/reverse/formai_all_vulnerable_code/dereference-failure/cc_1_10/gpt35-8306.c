//FormAI DATASET v1.0 Category: Networking ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 100

int main(int argc, char *argv[]) {

    // Check for IP address and port number arguments
    if(argc != 3) {
        printf("Usage: %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    int sock = socket(PF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    // Start up a connection to the server
    if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        printf("connect() error!\n");
        exit(1);
    }
    else {
        printf("Connected to server.\n");
    }

    fd_set rd, rd_temp;
    FD_ZERO(&rd);
    FD_SET(sock, &rd);
    FD_SET(STDIN_FILENO, &rd);
    rd_temp = rd;

    // Loop for sending and receiving messages
    while(1) {
        int ret = select(sock+1, &rd_temp, NULL, NULL, NULL);
        if(ret <= 0) continue;
        else if(FD_ISSET(STDIN_FILENO, &rd_temp)) {
            char buf[BUF_SIZE] = {0};
            fgets(buf, BUF_SIZE, stdin);
            if(!strcmp(buf, "exit\n")) {
                printf("Disconnected from server.\n");
                break;
            }
            write(sock, buf, strlen(buf));
            memset(buf, 0, BUF_SIZE);
            printf("Sent message to server.\n");
        }
        else if(FD_ISSET(sock, &rd_temp)) {
            char buf[BUF_SIZE] = {0};
            read(sock, buf, BUF_SIZE-1);
            if(!strcmp(buf, "exit\n")) {
                printf("Server has disconnected.\n");
                break;
            }
            printf("Received message from server: %s", buf);
            memset(buf, 0, BUF_SIZE);
        }
        rd_temp = rd;
    }

    close(sock);
    return 0;
}