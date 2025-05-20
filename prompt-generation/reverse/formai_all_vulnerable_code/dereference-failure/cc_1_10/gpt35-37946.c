//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

#define PORT 8080

typedef struct node
{
    struct sockaddr_in address;
    struct node *next;
} node_t;

typedef struct
{
    node_t *head;
    pthread_mutex_t mutex;
} list_t;

list_t *list;

void list_init()
{
    list = (list_t*) malloc(sizeof(list_t));
    list->head = NULL;
    pthread_mutex_init(&list->mutex, NULL);
}

void list_add(struct sockaddr_in address)
{
    node_t *new_node = (node_t*) malloc(sizeof(node_t));
    new_node->address = address;
    new_node->next = list->head;
    list->head = new_node;
}

void list_remove(struct sockaddr_in address)
{
    pthread_mutex_lock(&list->mutex);

    node_t *current_node = list->head;
    node_t *prev_node = NULL;

    while (current_node != NULL && memcmp(&current_node->address, &address, sizeof(struct sockaddr_in)) != 0)
    {
        prev_node = current_node;
        current_node = current_node->next;
    }

    if (current_node != NULL)
    {
        if (prev_node == NULL)
        {
            list->head = current_node->next;
        }
        else
        {
            prev_node->next = current_node->next;
        }

        free(current_node);
    }

    pthread_mutex_unlock(&list->mutex);
}

void* server_thread(void* arg)
{
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    memset(&address, 0, sizeof(address));

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr*)&address, sizeof(address));

    listen(server_fd, 10);

    while (1)
    {
        int client_fd = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);

        pthread_mutex_lock(&list->mutex);
        list_add(address);
        pthread_mutex_unlock(&list->mutex);

        close(client_fd);
    }
}

void* client_thread(void* arg)
{
    struct hostent *host = (struct hostent*) arg;
    struct sockaddr_in address;

    memcpy(&address.sin_addr, host->h_addr_list[0], sizeof(address.sin_addr));
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);

    int client_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (connect(client_fd, (struct sockaddr*)&address, sizeof(address)) == 0)
    {
        printf("Online: %s\n", host->h_name);
    }
    else
    {
        list_remove(address);
        printf("Offline: %s\n", host->h_name);
    }

    close(client_fd);
}

int main(int argc, char** argv)
{
    int i;

    if (argc < 2)
    {
        printf("Usage: %s [hostname1] [hostname2] ...\n", argv[0]);
        exit(1);
    }

    list_init();

    pthread_t server_thread_id;
    pthread_create(&server_thread_id, NULL, server_thread, NULL);

    for (i = 1; i < argc; i++)
    {
        struct hostent *host = gethostbyname(argv[i]);
        pthread_t client_thread_id;
        pthread_create(&client_thread_id, NULL, client_thread, (void*) host);
    }

    pthread_join(server_thread_id, NULL);

    return 0;
}