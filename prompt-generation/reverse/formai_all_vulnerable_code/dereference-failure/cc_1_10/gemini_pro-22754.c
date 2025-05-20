//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define MAX_ROOMS 100

struct room {
    int room_number;
    int capacity;
    int price;
    int availability;
};

struct client {
    int client_id;
    int socket_fd;
    char name[100];
    char address[100];
    char phone[100];
    char email[100];
    int check_in_date;
    int check_out_date;
    int room_number;
};

struct hotel {
    struct room rooms[MAX_ROOMS];
    struct client clients[MAX_CLIENTS];
    int num_rooms;
    int num_clients;
};

struct hotel my_hotel;

void init_hotel() {
    my_hotel.num_rooms = 0;
    my_hotel.num_clients = 0;
}

void add_room(int room_number, int capacity, int price) {
    my_hotel.rooms[my_hotel.num_rooms].room_number = room_number;
    my_hotel.rooms[my_hotel.num_rooms].capacity = capacity;
    my_hotel.rooms[my_hotel.num_rooms].price = price;
    my_hotel.rooms[my_hotel.num_rooms].availability = 1;
    my_hotel.num_rooms++;
}

void add_client(int client_id, int socket_fd, char *name, char *address, char *phone, char *email, int check_in_date, int check_out_date, int room_number) {
    my_hotel.clients[my_hotel.num_clients].client_id = client_id;
    my_hotel.clients[my_hotel.num_clients].socket_fd = socket_fd;
    strcpy(my_hotel.clients[my_hotel.num_clients].name, name);
    strcpy(my_hotel.clients[my_hotel.num_clients].address, address);
    strcpy(my_hotel.clients[my_hotel.num_clients].phone, phone);
    strcpy(my_hotel.clients[my_hotel.num_clients].email, email);
    my_hotel.clients[my_hotel.num_clients].check_in_date = check_in_date;
    my_hotel.clients[my_hotel.num_clients].check_out_date = check_out_date;
    my_hotel.clients[my_hotel.num_clients].room_number = room_number;
    my_hotel.num_clients++;
}

void *client_handler(void *arg) {
    int client_id = *(int *)arg;
    int socket_fd = my_hotel.clients[client_id].socket_fd;

    while (1) {
        char buffer[1024];
        int n = read(socket_fd, buffer, sizeof(buffer));
        if (n == 0) {
            break;
        }

        // Parse the command
        char *command = strtok(buffer, " ");
        if (strcmp(command, "book") == 0) {
            // Parse the arguments
            int room_number = atoi(strtok(NULL, " "));
            int check_in_date = atoi(strtok(NULL, " "));
            int check_out_date = atoi(strtok(NULL, " "));

            // Check if the room is available
            int available = 0;
            for (int i = 0; i < my_hotel.num_rooms; i++) {
                if (my_hotel.rooms[i].room_number == room_number && my_hotel.rooms[i].availability == 1) {
                    available = 1;
                    break;
                }
            }

            // Send the response to the client
            if (available == 1) {
                char response[] = "OK";
                write(socket_fd, response, strlen(response));
            } else {
                char response[] = "Not available";
                write(socket_fd, response, strlen(response));
            }
        } else if (strcmp(command, "cancel") == 0) {
            // Parse the arguments
            int room_number = atoi(strtok(NULL, " "));

            // Check if the room is booked by the client
            int booked = 0;
            for (int i = 0; i < my_hotel.num_clients; i++) {
                if (my_hotel.clients[i].client_id == client_id && my_hotel.clients[i].room_number == room_number) {
                    booked = 1;
                    break;
                }
            }

            // Send the response to the client
            if (booked == 1) {
                char response[] = "OK";
                write(socket_fd, response, strlen(response));
            } else {
                char response[] = "Not booked";
                write(socket_fd, response, strlen(response));
            }
        } else if (strcmp(command, "quit") == 0) {
            break;
        }
    }

    // Close the client socket
    close(socket_fd);

    return NULL;
}

int main() {
    init_hotel();

    // Add some rooms to the hotel
    add_room(1, 2, 100);
    add_room(2, 3, 150);
    add_room(3, 4, 200);

    // Start the server
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    if (listen(server_fd, 5) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    while (1) {
        // Accept a new client connection
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_fd == -1) {
            perror("accept");
            continue;
        }

        // Create a new thread to handle the client
        pthread_t client_thread;
        int *client_id = malloc(sizeof(int));
        *client_id = my_hotel.num_clients;
        pthread_create(&client_thread, NULL, client_handler, client_id);
        pthread_detach(client_thread);
    }

    // Close the server socket
    close(server_fd);

    return EXIT_SUCCESS;
}