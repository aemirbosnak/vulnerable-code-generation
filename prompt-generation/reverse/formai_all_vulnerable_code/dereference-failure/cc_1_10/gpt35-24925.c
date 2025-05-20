//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXLINE 1024
#define MAXBUF 8096

void puzzle(char* buf) {
    char tmp[MAXBUF];

    int i = 0;
    while (buf[i] != '\n') {
        if (buf[i] == 'G' && 
            buf[i+1] == 'E' && 
            buf[i+2] == 'T' && 
            buf[i+3] == ' ') {
            int j = 0;
            i += 4;
            while (buf[i] != ' ') {
                tmp[j++] = buf[i++];
            }
            tmp[j] = '\0';
            strcat(buf, tmp);
            strcat(buf, "\n");
            break;
        }
        i++;
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(0);
    }

    int listenfd = 0, connfd = 0;
    struct sockaddr_in serv_addr;

    char buff[MAXLINE];
    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(buff, '0', sizeof(buff));

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    listen(listenfd, 10);

    while (1) {
        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);

        read(connfd, buff, sizeof(buff)-1);
        printf("%s", buff);

        puzzle(buff);

        write(connfd, buff, strlen(buff));

        close(connfd);
        memset(buff, '0', sizeof(buff));
    }
    return 0;
}