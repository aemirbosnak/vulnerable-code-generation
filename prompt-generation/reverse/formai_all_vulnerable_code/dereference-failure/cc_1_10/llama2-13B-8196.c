//LLAMA2-13B DATASET v1.0 Category: Weather simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define PORT 8080

// Structure to represent a weather station
struct weather_station {
    int id;
    float temperature;
    float humidity;
    float wind_speed;
};

// Function to create a new weather station
struct weather_station *new_weather_station(int id, float temperature, float humidity, float wind_speed) {
    struct weather_station *station = malloc(sizeof(struct weather_station));
    station->id = id;
    station->temperature = temperature;
    station->humidity = humidity;
    station->wind_speed = wind_speed;
    return station;
}

// Function to send data from one weather station to another
void send_data(int sock, struct weather_station *station) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "%d %f %f %f", station->id, station->temperature, station->humidity, station->wind_speed);
    send(sock, buffer, strlen(buffer), 0);
}

// Function to receive data from another weather station
struct weather_station *receive_data(int sock) {
    char buffer[BUFFER_SIZE];
    int len = recv(sock, buffer, BUFFER_SIZE, 0);
    if (len > 0) {
        // Parse the received data
        int id, temperature, humidity, wind_speed;
        sscanf(buffer, "%d %f %f %f", &id, &temperature, &humidity, &wind_speed);
        struct weather_station *station = malloc(sizeof(struct weather_station));
        station->id = id;
        station->temperature = temperature;
        station->humidity = humidity;
        station->wind_speed = wind_speed;
        return station;
    }
    return NULL;
}

int main() {
    int sock1, sock2;
    struct weather_station *station1, *station2;

    // Create a socket
    sock1 = socket(AF_INET, SOCK_STREAM, 0);
    if (sock1 < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set address and port number for the first weather station
    struct sockaddr_in address1 = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    // Bind the socket to the address and port
    if (bind(sock1, (struct sockaddr *)&address1, sizeof(address1)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sock1, 5) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept an incoming connection
    sock2 = accept(sock1, NULL, NULL);
    if (sock2 < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    // Create a new weather station
    station1 = new_weather_station(1, 20, 60, 5);

    // Send data from station1 to station2
    send_data(sock2, station1);

    // Receive data from station2
    station2 = receive_data(sock2);
    if (station2 != NULL) {
        printf("Station 1 received data from Station 2: id=%d, temperature=%f, humidity=%f, wind_speed=%f\n",
               station2->id, station2->temperature, station2->humidity, station2->wind_speed);
    } else {
        printf("No data received from Station 2\n");
    }

    // Close the sockets
    close(sock1);
    close(sock2);

    return 0;
}