//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<semaphore.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define MAX 100
#define WAIT_DIE 5

int g_socket = -1;
int g_sem = 0;

void *thread_fun(void *arg) {
    char *message = (char *) arg;
    int n = send(g_socket, message, strlen(message), 0);
    if (n <= 0) {
        printf("Send failed\n");
    }
    close(g_socket);
    pthread_exit(0);
}

int connect_server() {
    struct sockaddr_in server_addr;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Socket create error: %s\n", strerror(errno));
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Connect error: %s\n", strerror(errno));
        close(sock);
        return -1;
    }

    return sock;
}

int main() {
    pthread_t thread_id;
    char message[MAX];

    g_socket = connect_server();
    if (g_socket == -1) {
        return -1;
    }

    while (TRUE) {
        memset(message, 0, sizeof(message));
        printf("Romeo: ");
        fgets(message, MAX, stdin);

        pthread_create(&thread_id, NULL, thread_fun, (void *) message);
        sem_wait(&g_sem);
    }

    close(g_socket);
    return 0;
}