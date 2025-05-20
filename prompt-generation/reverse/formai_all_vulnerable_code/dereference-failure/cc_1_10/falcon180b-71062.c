//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_REQUEST_SIZE 1024
#define ROOT_DIR "./www/"

typedef struct {
    int sockfd;
    char ip[16];
    char request[MAX_REQUEST_SIZE];
} client_t;

void *handle_client(void *arg) {
    client_t *client = (client_t *) arg;
    char response[2048];
    FILE *fp;
    char filename[1024];

    strcpy(filename, ROOT_DIR);
    strcat(filename, client->request);
    if ((fp = fopen(filename, "r")) == NULL) {
        sprintf(response, "HTTP/1.0 404 Not Found\r\nContent-Length: %d\r\n\r\n404 Not Found", strlen("404 Not Found"));
        send(client->sockfd, response, strlen(response), 0);
        close(client->sockfd);
        free(client);
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    rewind(fp);

    char *file_content = (char *) malloc(file_size + 1);
    fread(file_content, file_size, 1, fp);
    fclose(fp);

    sprintf(response, "HTTP/1.0 200 OK\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n%s", file_size, file_content);
    send(client->sockfd, response, strlen(response), 0);

    close(client->sockfd);
    free(client);
    free(file_content);
    return NULL;
}

void accept_client(int listen_sockfd) {
    int client_sockfd;
    struct sockaddr_in client_addr;
    socklen_t addr_size = sizeof(client_addr);

    while ((client_sockfd = accept(listen_sockfd, (struct sockaddr *) &client_addr, &addr_size)) > 0) {
        client_t *client = (client_t *) malloc(sizeof(client_t));
        strcpy(client->ip, inet_ntoa(client_addr.sin_addr));
        recv(client_sockfd, client->request, MAX_REQUEST_SIZE, 0);

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) client);
        pthread_detach(thread_id);
    }
}

int main() {
    int listen_sockfd;
    struct sockaddr_in server_addr;

    listen_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(listen_sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(listen_sockfd, 5) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server started on port %d\n", PORT);

    accept_client(listen_sockfd);

    return 0;
}