//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define BUFSIZE 1024

void *ftp_client_thread(void *arg);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "usage: %s <server_ip> <server_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *server_ip = argv[1];
    int server_port = atoi(argv[2]);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(server_port);

    pthread_t tid;
    pthread_create(&tid, NULL, ftp_client_thread, &server_addr);
    pthread_join(tid, NULL);

    return 0;
}

void *ftp_client_thread(void *arg) {
    struct sockaddr_in server_addr = *(struct sockaddr_in *)arg;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket error");
        exit(EXIT_FAILURE);
    }
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect error");
        exit(EXIT_FAILURE);
    }
    printf("Connected to FTP server successfully!\n");

    char buf[BUFSIZE];
    while (1) {
        printf("ftp> ");
        fgets(buf, BUFSIZE, stdin);
        if (strlen(buf) > 0) {
            buf[strlen(buf) - 1] = '\0'; // remove trailing newline
        }
        if (strcmp(buf, "quit") == 0) {
            break;
        }
        send(sockfd, buf, strlen(buf), 0);
        memset(buf, 0, BUFSIZE);
        if (recv(sockfd, buf, BUFSIZE, 0) < 0) {
            printf("ERROR: Server disconnected.\n");
            break;
        }
        printf("%s\n", buf);
    }

    close(sockfd);
    pthread_exit(NULL);
}