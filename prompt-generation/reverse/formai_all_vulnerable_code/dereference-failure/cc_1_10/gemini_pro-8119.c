//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: multiplayer
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 10

struct client_info {
    int sockfd;
    struct sockaddr_in addr;
};

struct file_info {
    char filename[256];
    int filesize;
    char filedata[1024];
};

void *client_handler(void *arg) {
    struct client_info *client = (struct client_info *)arg;
    int sockfd = client->sockfd;
    while (1) {
        struct file_info file;
        int n = read(sockfd, &file, sizeof(file));
        if (n <= 0) {
            if (n == 0) {
                printf("Client %d disconnected\n", client->addr.sin_addr.s_addr);
            } else {
                perror("read");
            }
            close(sockfd);
            free(client);
            return NULL;
        }
        printf("Received file %s from client %d\n", file.filename, client->addr.sin_addr.s_addr);
        int fd = open(file.filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd < 0) {
            perror("open");
            continue;
        }
        int nwritten = 0;
        while (nwritten < file.filesize) {
            n = write(fd, file.filedata + nwritten, file.filesize - nwritten);
            if (n < 0) {
                perror("write");
                close(fd);
                continue;
            }
            nwritten += n;
        }
        close(fd);
    }
    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    int ret = bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if (ret < 0) {
        perror("bind");
        exit(1);
    }

    ret = listen(sockfd, MAX_CLIENTS);
    if (ret < 0) {
        perror("listen");
        exit(1);
    }

    pthread_t threads[MAX_CLIENTS];
    int i = 0;
    while (1) {
        struct client_info *client = malloc(sizeof(struct client_info));
        socklen_t len = sizeof(client->addr);
        client->sockfd = accept(sockfd, (struct sockaddr *)&client->addr, &len);
        if (client->sockfd < 0) {
            perror("accept");
            continue;
        }
        printf("Client %d connected\n", client->addr.sin_addr.s_addr);
        pthread_create(&threads[i++], NULL, client_handler, client);
    }

    close(sockfd);
    for (i = 0; i < MAX_CLIENTS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}