//GEMINI-pro DATASET v1.0 Category: Weather simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/select.h>
#include <signal.h>

#define UNIX_SOCK_PATH "/tmp/weather_sock"

typedef struct {
    double temperature;
    double humidity;
    double wind_speed;
    double wind_direction;
    time_t timestamp;
} weather_data;

static volatile int should_stop = 0;

static void sigint_handler(int sig) {
    should_stop = 1;
}

int main(int argc, char **argv) {
    int sockfd, clientfd;
    struct sockaddr_un addr;
    fd_set rfds;
    struct timeval timeout = {0, 0};
    weather_data data;

    // Create UNIX socket
    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set socket address
    memset(&addr, 0, sizeof(addr));
    addr.sun_family = AF_UNIX;
    strcpy(addr.sun_path, UNIX_SOCK_PATH);

    // Bind socket to address
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Listen for connections
    if (listen(sockfd, 5) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Set up signal handler for SIGINT
    signal(SIGINT, &sigint_handler);

    // Main loop
    while (!should_stop) {
        // Set up select()
        FD_ZERO(&rfds);
        FD_SET(sockfd, &rfds);

        // Wait for input
        if (select(sockfd + 1, &rfds, NULL, NULL, &timeout) == -1) {
            perror("select");
            continue;
        }

        // Check for client connection
        if (FD_ISSET(sockfd, &rfds)) {
            clientfd = accept(sockfd, NULL, NULL);
            if (clientfd == -1) {
                perror("accept");
                continue;
            }

            // Generate weather data
            data.temperature = rand() % 30 + 10;
            data.humidity = rand() % 100;
            data.wind_speed = rand() % 10 + 1;
            data.wind_direction = rand() % 360;
            data.timestamp = time(NULL);

            // Send weather data to client
            if (send(clientfd, &data, sizeof(data), 0) == -1) {
                perror("send");
                close(clientfd);
                continue;
            }

            // Close client connection
            close(clientfd);
        }
    }

    // Close server socket
    close(sockfd);

    return EXIT_SUCCESS;
}