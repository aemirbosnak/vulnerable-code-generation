//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

int num_clients = 0;
pthread_t *clients;
pthread_mutex_t clients_mutex;

void *client_handler(void *client_data) {
    int *id = (int *)client_data;
    int index = *id;
    char message[256];
    int msg_len = 0;

    while (1) {
        pthread_mutex_lock(&clients_mutex);
        printf("Message from client %d: ", index);
        scanf("%s", message);
        pthread_mutex_unlock(&clients_mutex);
        printf("%s\n", message);
        msg_len = strlen(message);
        pthread_mutex_lock(&clients_mutex);
        char *reply = (char *)malloc(msg_len + 1);
        memset(reply, 0, msg_len + 1);
        sprintf(reply, "Thank you for your message client %d!\n", index);
        pthread_mutex_unlock(&clients_mutex);
        pthread_mutex_lock(&clients_mutex);
        clients[index] = reply;
        pthread_mutex_unlock(&clients_mutex);
    }
}

int main() {
    pthread_t client1, client2, client3;
    int id1 = 1, id2 = 2, id3 = 3;
    clients = (pthread_t *)malloc(3 * sizeof(pthread_t));

    pthread_mutex_init(&clients_mutex, NULL);

    pthread_create(&client1, NULL, client_handler, &id1);
    pthread_create(&client2, NULL, client_handler, &id2);
    pthread_create(&client3, NULL, client_handler, &id3);

    pthread_join(client1, NULL);
    pthread_join(client2, NULL);
    pthread_join(client3, NULL);

    pthread_mutex_destroy(&clients_mutex);
    return 0;
}