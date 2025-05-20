//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BACKLOG 10

void *thread(void *vargp);

int main(int argc, char **argv)
{
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    int opt = 1;
    int addrlen = sizeof(struct sockaddr_in);

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(listenfd, BACKLOG) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    puts("Server is running...");

    while (1)
    {
        if ((connfd = accept(listenfd, (struct sockaddr *)&cliaddr, (socklen_t*)&addrlen)) < 0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, thread, (void*)connfd);
        pthread_detach(thread_id);
    }

    return 0;
}

void *thread(void *vargp)
{
    int connfd = *(int*)vargp;

    char buffer[4096];
    bzero(buffer, sizeof(buffer));

    while (fgets(buffer, sizeof(buffer), stdin)!= NULL)
    {
        send(connfd, buffer, strlen(buffer), 0);
    }

    close(connfd);

    return NULL;
}