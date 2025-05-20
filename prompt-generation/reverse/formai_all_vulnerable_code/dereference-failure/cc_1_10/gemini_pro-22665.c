//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: curious
// Let's shine a light on your smart home!

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

// Some curious constants
#define SMART_HOME_PORT 1337
#define SMART_HOME_IP "127.0.0.1"
#define MAX_LIGHTS 100

// Our curious light structure
typedef struct Light {
    char name[20];
    int state; // 0 for off, 1 for on
} Light;

// An array of our curious lights
Light lights[MAX_LIGHTS];

// A curious function to handle incoming connections
void *handle_connection(void *arg) {
    int client_sock = *(int *)arg;
    free(arg);
    
    // Receive the command
    char command[100];
    recv(client_sock, command, 100, 0);
    
    // Parse the command
    char *pch = strtok(command, " ");
    char *light_name = pch;
    pch = strtok(NULL, " ");
    char *state = pch;
    
    // Find the light
    int i;
    for (i = 0; i < MAX_LIGHTS; i++) {
        if (strcmp(lights[i].name, light_name) == 0) {
            break;
        }
    }
    
    // If the light was found, change its state
    if (i < MAX_LIGHTS) {
        lights[i].state = atoi(state);
    }
    
    // Send a response
    send(client_sock, "OK", 2, 0);
    
    // Close the connection
    close(client_sock);
    
    return NULL;
}

int main() {
    // Create a curious socket
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    
    // Bind the socket to a curious port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMART_HOME_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SMART_HOME_IP);
    bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    
    // Listen for curious connections
    listen(server_sock, 100);
    
    // Handle curious connections in a curious manner
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_len);
        
        // Create a curious thread to handle the connection
        pthread_t thread;
        int *arg = malloc(sizeof(int));
        *arg = client_sock;
        pthread_create(&thread, NULL, handle_connection, arg);
    }
    
    // Close the curious socket
    close(server_sock);
    
    return 0;
}