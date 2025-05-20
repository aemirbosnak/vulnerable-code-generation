//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define the maximum number of lights that can be controlled
#define MAX_LIGHTS 10

// Define the possible states of a light
typedef enum {
    OFF,
    ON,
    DIMMED
} light_state;

// Define the structure of a light
typedef struct {
    int id;
    char *name;
    light_state state;
} light;

// Define the structure of a smart home
typedef struct {
    int num_lights;
    light lights[MAX_LIGHTS];
} smart_home;

// Create a new smart home
smart_home *create_smart_home() {
    smart_home *home = malloc(sizeof(smart_home));
    home->num_lights = 0;
    return home;
}

// Add a new light to a smart home
void add_light(smart_home *home, int id, char *name) {
    if (home->num_lights < MAX_LIGHTS) {
        home->lights[home->num_lights].id = id;
        home->lights[home->num_lights].name = strdup(name);
        home->lights[home->num_lights].state = OFF;
        home->num_lights++;
    }
}

// Turn on a light in a smart home
void turn_on_light(smart_home *home, int id) {
    for (int i = 0; i < home->num_lights; i++) {
        if (home->lights[i].id == id) {
            home->lights[i].state = ON;
            break;
        }
    }
}

// Turn off a light in a smart home
void turn_off_light(smart_home *home, int id) {
    for (int i = 0; i < home->num_lights; i++) {
        if (home->lights[i].id == id) {
            home->lights[i].state = OFF;
            break;
        }
    }
}

// Dim a light in a smart home
void dim_light(smart_home *home, int id) {
    for (int i = 0; i < home->num_lights; i++) {
        if (home->lights[i].id == id) {
            home->lights[i].state = DIMMED;
            break;
        }
    }
}

// Print the state of all lights in a smart home
void print_lights(smart_home *home) {
    for (int i = 0; i < home->num_lights; i++) {
        printf("Light %d (%s): ", home->lights[i].id, home->lights[i].name);
        switch (home->lights[i].state) {
            case OFF:
                printf("OFF\n");
                break;
            case ON:
                printf("ON\n");
                break;
            case DIMMED:
                printf("DIMMED\n");
                break;
        }
    }
}

// Create a server socket that listens for commands from a client
int create_server_socket(int port) {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(server_socket, 5) == -1) {
        perror("listen");
        exit(1);
    }

    return server_socket;
}

// Accept a connection from a client and create a new client socket
int accept_client_connection(int server_socket) {
    int client_socket = accept(server_socket, NULL, NULL);
    if (client_socket == -1) {
        perror("accept");
        exit(1);
    }

    return client_socket;
}

// Read a command from a client socket
char *read_command(int client_socket) {
    char *buffer = malloc(1024);
    int n = read(client_socket, buffer, 1023);
    if (n == -1) {
        perror("read");
        exit(1);
    }

    buffer[n] = '\0';
    return buffer;
}

// Parse a command from a client socket
void parse_command(smart_home *home, char *command) {
    char *action = strtok(command, " ");
    char *light_id = strtok(NULL, " ");

    if (strcmp(action, "turn_on") == 0) {
        turn_on_light(home, atoi(light_id));
    } else if (strcmp(action, "turn_off") == 0) {
        turn_off_light(home, atoi(light_id));
    } else if (strcmp(action, "dim") == 0) {
        dim_light(home, atoi(light_id));
    } else {
        printf("Unknown command: %s\n", command);
    }
}

int main() {
    // Create a new smart home
    smart_home *home = create_smart_home();

    // Add some lights to the smart home
    add_light(home, 1, "Living Room Light");
    add_light(home, 2, "Kitchen Light");
    add_light(home, 3, "Bedroom Light");

    // Create a server socket that listens for commands from a client
    int server_socket = create_server_socket(5555);

    while (1) {
        // Accept a connection from a client
        int client_socket = accept_client_connection(server_socket);

        // Read a command from the client
        char *command = read_command(client_socket);

        // Parse the command
        parse_command(home, command);

        // Print the state of all lights in the smart home
        print_lights(home);

        // Close the client socket
        close(client_socket);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}