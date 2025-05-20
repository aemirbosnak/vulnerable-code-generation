//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: innovative
// Welcome to the Cyber Bistro, where your appetite for knowledge shall be sated!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

// The Bistro's secret ingredients:
#define PORT 8080
#define BUFFER_SIZE 1024

// Our array of mouthwatering dishes:
typedef struct {
    char* name;
    char* recipe;
} Dish;

Dish menu[] = {
    { "HTML & CSS", "In a bowl, combine equal parts HTML and CSS. Bake at 375°F for 15 minutes, or until golden brown." },
    { "JavaScript", "In a large skillet, heat some butter and add JavaScript. Cook over medium heat until browned. Serve with a side of debugging." },
    { "Python", "In a slow cooker, combine Python with a splash of open source. Cook on low for several hours, or until tender." },
    { "Java", "In a coffee maker, brew Java with a touch of caffeine. Serve with a side of espresso shots." }
};

int main() {
    // Open the Bistro's doors:
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        fprintf(stderr, "Kitchen's closed, come back later!\n");
        return -1;
    }

    // Set the Bistro's address:
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Bind the Bistro to its address:
    int bind_result = bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    if (bind_result == -1) {
        fprintf(stderr, "Reservations are full, try again tomorrow!\n");
        return -1;
    }

    // Prepare the Bistro for guests:
    int listen_result = listen(server_socket, 5);
    if (listen_result == -1) {
        fprintf(stderr, "Waiting list is too long, come back another time!\n");
        return -1;
    }

    // Welcome guests and serve them our exquisite dishes:
    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_len);
        if (client_socket == -1) {
            fprintf(stderr, "Table's not ready yet, please wait!\n");
            continue;
        }

        // Take the guest's order:
        char request[BUFFER_SIZE];
        int recv_result = recv(client_socket, request, BUFFER_SIZE, 0);
        if (recv_result == -1) {
            fprintf(stderr, "Order not received, please try again!\n");
            continue;
        }

        // Parse the guest's order:
        char* dish_name = strtok(request, " ");
        char* http_version = strtok(NULL, " ");

        // Find the guest's desired dish:
        Dish* dish = NULL;
        for (int i = 0; i < 4; i++) {
            if (strcmp(menu[i].name, dish_name) == 0) {
                dish = &menu[i];
                break;
            }
        }

        // Prepare the guest's dish:
        char response[BUFFER_SIZE];
        sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\n%s", dish->recipe);

        // Serve the guest their dish:
        int send_result = send(client_socket, response, strlen(response), 0);
        if (send_result == -1) {
            fprintf(stderr, "Dish not delivered, please try again!\n");
        }

        // Close the guest's table:
        close(client_socket);
    }

    // Close the Bistro for the night:
    close(server_socket);

    return 0;
}