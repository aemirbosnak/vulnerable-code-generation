//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_DEVICES 10

struct device {
    char name[32];
    bool state;
    int socket;
};

struct device devices[MAX_DEVICES];
int num_devices = 0;

void add_device(char *name, bool state, int socket) {
    if (num_devices == MAX_DEVICES) {
        fprintf(stderr, "Error: maximum number of devices reached\n");
        return;
    }

    strcpy(devices[num_devices].name, name);
    devices[num_devices].state = state;
    devices[num_devices].socket = socket;
    num_devices++;
}

void remove_device(char *name) {
    int i;

    for (i = 0; i < num_devices; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            break;
        }
    }

    if (i == num_devices) {
        fprintf(stderr, "Error: device not found\n");
        return;
    }

    for (; i < num_devices - 1; i++) {
        devices[i] = devices[i + 1];
    }

    num_devices--;
}

void toggle_device(char *name) {
    int i;

    for (i = 0; i < num_devices; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            break;
        }
    }

    if (i == num_devices) {
        fprintf(stderr, "Error: device not found\n");
        return;
    }

    devices[i].state = !devices[i].state;
}

void send_command(char *name, char *command) {
    int i;

    for (i = 0; i < num_devices; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            break;
        }
    }

    if (i == num_devices) {
        fprintf(stderr, "Error: device not found\n");
        return;
    }

    send(devices[i].socket, command, strlen(command), 0);
}

void receive_messages() {
    fd_set readfds;
    int maxfd;
    int i;
    char buffer[1024];
    int nbytes;

    while (1) {
        FD_ZERO(&readfds);
        maxfd = 0;

        for (i = 0; i < num_devices; i++) {
            FD_SET(devices[i].socket, &readfds);
            if (devices[i].socket > maxfd) {
                maxfd = devices[i].socket;
            }
        }

        select(maxfd + 1, &readfds, NULL, NULL, NULL);

        for (i = 0; i < num_devices; i++) {
            if (FD_ISSET(devices[i].socket, &readfds)) {
                nbytes = recv(devices[i].socket, buffer, sizeof(buffer), 0);
                if (nbytes > 0) {
                    printf("Received message from %s: %s\n", devices[i].name, buffer);
                } else {
                    fprintf(stderr, "Error: device %s closed connection\n", devices[i].name);
                    remove_device(devices[i].name);
                }
            }
        }
    }
}

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in servaddr;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error: could not create socket");
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(atoi(argv[1]));

    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("Error: could not bind socket");
        return 1;
    }

    if (listen(sockfd, 5) == -1) {
        perror("Error: could not listen on socket");
        return 1;
    }

    add_device("light1", false, -1);
    add_device("light2", false, -1);
    add_device("fan", false, -1);

    receive_messages();

    return 0;
}