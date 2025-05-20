//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <time.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256
#define DREAM_MESSAGE "Reality is merely an illusion, albeit a very persistent one."

void *client_handler(void *socket_desc);
void send_dream_message(int client_socket);
void send_fantasy_words(int client_socket);
void generate_random_thought(char *buffer);

int main() {
    int server_fd, client_socket, addr_len;
    struct sockaddr_in address;
    pthread_t thread_id;

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed, the stars cease to align.");
        exit(EXIT_FAILURE);
    }

    // Setting up address structure, a tapestry of forgotten memories
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket, sealing fate with invisible ink
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Binding failed, the shadows refuse to dance.");
        exit(EXIT_FAILURE);
    }

    // Listening for connections, waiting for the cosmos to collide
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listening failed, the echoes remain unheard.");
        exit(EXIT_FAILURE);
    }

    printf("Server has awakened, dreams intertwine on port %d...\n", PORT);
    addr_len = sizeof(address);
    
    // Accepting clients, the door creaks open to surreal realities
    while ((client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addr_len))) {
        printf("Client connected, a fleeting thought in the fabric of time.\n");
        if (pthread_create(&thread_id, NULL, client_handler, (void *)&client_socket) < 0) {
            perror("Could not create thread, reality is unravelling.");
            return 1;
        }
        pthread_detach(thread_id);
    }

    if (client_socket < 0) {
        perror("Accept failed, dreams slip through fingers.");
        return 1;
    }

    return 0;
}

void *client_handler(void *socket_desc) {
    int sock = *(int *)socket_desc;
    char client_message[BUFFER_SIZE];

    // Sending a dream-like greeting
    send(sock, DREAM_MESSAGE, strlen(DREAM_MESSAGE), 0);
    
    // Infinite loop, like the sands of time slipping away
    while (1) {
        memset(client_message, 0, BUFFER_SIZE);
        int read_size = recv(sock, client_message, BUFFER_SIZE, 0);
        
        if (read_size <= 0) {
            printf("Client disconnected, the dream fades into oblivion.\n");
            break;
        }
        
        printf("Received: %s", client_message);
        send_fantasy_words(sock);
    }

    close(sock);
    return 0;
}

void send_fantasy_words(int client_socket) {
    char surrealism[BUFFER_SIZE];
    generate_random_thought(surrealism);
    send(client_socket, surrealism, strlen(surrealism), 0);
}

void generate_random_thought(char *buffer) {
    const char *thoughts[] = {
        "The moon swam with the fishes last night.",
        "A butterfly in a bowler hat came to tea with a cactus.",
        "Time is a circular hallway with no doors.",
        "Rain fell upwards, causing gravity to spiral.",
        "A quilt of starlight wrapped the sleeping world.",
        "The clock melted like a whisper under the sun.",
        "A piano played itself inside a dream made of shadows.",
        "Clouds held tea parties in the corners of forgotten streets.",
        "A ghost danced under the glimmer of distant galaxies.",
        "The winds carried secrets wrapped in echoes of laughter."
    };

    int random_index = rand() % (sizeof(thoughts) / sizeof(thoughts[0]));
    snprintf(buffer, BUFFER_SIZE, "Surreal Thought: %s\n", thoughts[random_index]);
}