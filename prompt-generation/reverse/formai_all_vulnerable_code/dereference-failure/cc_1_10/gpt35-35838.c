//FormAI DATASET v1.0 Category: Socket programming ; Style: statistical
/*
 * Statistical Example Program Using Sockets
 * Calculates mean, median, mode, and standard deviation of a set of numbers received via socket
 * 
 * Author: [Your Name]
 * Date: [Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000

void error(char *message);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int server_socket;
    struct sockaddr_in server_address;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        error("Error creating socket");
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[1]));
    server_address.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        error("Error binding socket");
    }

    listen(server_socket, 3);

    while (1) {
        int client_socket;
        struct sockaddr_in client_address;
        socklen_t client_address_length = sizeof(client_address);

        client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_length);

        if (client_socket < 0) {
            error("Error accepting client connection");
        }

        char buffer[MAX_SIZE];
        int n = read(client_socket, buffer, MAX_SIZE);
        buffer[n] = '\0';

        char *token, *rest;
        double numbers[MAX_SIZE];
        int i = 0;
        rest = buffer;

        while ((token = strtok_r(rest, " ", &rest))) {
            numbers[i++] = atof(token);
        }

        double mean = 0.0;
        for (int j = 0; j < i; j++) {
            mean += numbers[j];
        }
        mean /= i;

        double median = 0.0;
        if (i % 2 == 0) {
            median = (numbers[i/2 - 1] + numbers[i/2]) / 2.0;
        } else {
            median = numbers[i/2];
        }

        double mode = 0.0, max_count = 0.0;
        for (int j = 0; j < i; j++) {
            double count = 0.0;
            for (int k = 0; k < i; k++) {
                if (numbers[k] == numbers[j]) {
                    count++;
                }
            }
            if (count > max_count) {
                max_count = count;
                mode = numbers[j];
            }
        }

        double variance = 0.0;
        for (int j = 0; j < i; j++) {
            variance += pow(numbers[j] - mean, 2);
        }
        variance /= i;

        double std_dev = sqrt(variance);

        char result[MAX_SIZE];
        snprintf(result, MAX_SIZE, "Mean: %.2lf\nMedian: %.2lf\nMode: %.2lf\nStandard Deviation: %.2lf\n", mean, median, mode, std_dev);
        write(client_socket, result, strlen(result));

        close(client_socket);
    }

    close(server_socket);
    return 0;
}

void error(char *message) {
    printf("%s\n", message);
    exit(1);
}