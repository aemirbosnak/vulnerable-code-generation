//LLAMA2-13B DATASET v1.0 Category: Weather simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10

struct weather_data {
    float temperature;
    float humidity;
    float wind_speed;
};

struct client_data {
    int sock;
    struct weather_data data;
};

void handle_client(int sock) {
    struct weather_data data;
    recv(sock, (void *)&data, sizeof(data), 0);
    printf("Client %d: Temperature: %f, Humidity: %f, Wind Speed: %f\n", sock, data.temperature, data.humidity, data.wind_speed);
    send(sock, "Weather data received!", 13, 0);
}

void *server_thread(void *arg) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(sock, MAX_CLIENTS);

    while (1) {
        int client_sock = accept(sock, NULL, NULL);
        struct client_data *client_data = malloc(sizeof(struct client_data));
        client_data->sock = client_sock;
        client_data->data.temperature = 22.0f;
        client_data->data.humidity = 60.0f;
        client_data->data.wind_speed = 5.0f;

        pthread_t thread;
        pthread_create(&thread, NULL, handle_client, client_data);

        printf("New client connected: %d\n", client_sock);
    }

    return NULL;
}

int main() {
    pthread_t server_thread_id;
    pthread_create(&server_thread_id, NULL, server_thread, NULL);

    printf("Server started on port %d\n", PORT);

    return 0;
}