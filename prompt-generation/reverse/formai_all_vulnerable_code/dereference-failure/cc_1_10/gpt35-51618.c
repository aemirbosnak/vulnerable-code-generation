//FormAI DATASET v1.0 Category: Chat server ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_BUF_SIZE 1024

struct client_info {
    int sockfd;
    struct sockaddr_in client_addr;
};

int num_clients = 0;
struct client_info clients[MAX_THREADS];

void *handle_client(void *args) {
    int sockfd = (*(struct client_info*)args).sockfd;
    char buf[MAX_BUF_SIZE];
    int num_bytes;

    while (1) {
        num_bytes = recv(sockfd, buf, MAX_BUF_SIZE-1, 0);
        if (num_bytes <= 0) {
            break;
        }
        buf[num_bytes] = '\0';
        printf("Received from client %s: %s\n", inet_ntoa((*(struct client_info*)args).client_addr.sin_addr), buf);
        send(sockfd, buf, num_bytes, 0);
    }
    printf("Client %s disconnected.\n", inet_ntoa((*(struct client_info*)args).client_addr.sin_addr));
    close(sockfd);
    num_clients--;
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int sockfd, new_sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    pthread_t threads[MAX_THREADS];
    int i, err;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket error");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
        perror("bind error");
        exit(1);
    }

    if (listen(sockfd, MAX_THREADS) == -1 ) {
        perror("listen error");
        exit(1);
    }

    while(1) {
        if(num_clients == MAX_THREADS) {
            printf("Maximum clients reached, refusing connection.\n");
            continue;
        }
        if ((new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &addr_len)) == -1) {
            perror("accept error");
            continue;
        }
        printf("Client %s connected.\n", inet_ntoa(client_addr.sin_addr));
        clients[num_clients].sockfd = new_sockfd;
        clients[num_clients].client_addr = client_addr;
        num_clients++;
        err = pthread_create(&threads[num_clients-1], NULL, handle_client, &clients[num_clients-1]);
        if (err) {
            printf("Thread creation error %d.\n", err);
            exit(1);
        }
    }

    close(sockfd);
    return 0;
}