//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>

// A universe where sockets whisper secrets of the void
#define PORT 8080
#define BUFFER_SIZE 256

void existentialThoughts(char *buffer) {
    // Pondering existence in the context of the infinite
    snprintf(buffer, BUFFER_SIZE, "What is data without interpretation?");
}

// Dancing between the realms of server and client
void surrealServer() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // The melancholy breath of creation
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed, the void speaks!");
        exit(EXIT_FAILURE);
    }

    // Setting parameters for the dance floor of despair
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the ethereal threads of fate
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Binding failed, a cruel twist of fate!");
        exit(EXIT_FAILURE);
    }
    listen(server_fd, 3);

    // Waiting for souls to connect
    while ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))) {
        existentialThoughts(buffer);
        send(new_socket, buffer, strlen(buffer), 0);
        printf("Sent to the wandering soul: %s\n", buffer);
        close(new_socket);
    }

    // The curtain falls, and the abyss calls
    if (new_socket < 0) {
        perror("Accept failed, echoes linger in the dark.");
        exit(EXIT_FAILURE);
    }

    close(server_fd);
}

// A journey through the veil of dreams to the garden of the strange
void surrealClient() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    // Whispers from the cosmos guide my hand towards connection
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error, the stars align unfavorably.\n");
        return;
    }
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    // Converting the heartbeat of the universe to numerical form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address, a mirage in the desert of perception.\n");
        return;
    }

    // Embracing connection like a lost lover
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed, life escapes through my fingertips.\n");
        return;
    }

    // Receiving the cosmic thought
    read(sock, buffer, BUFFER_SIZE);
    printf("Received wisdom from the infinite: %s\n", buffer);

    close(sock);
}

int main(int argc, char const *argv[]) {
    // A choice: the path of light or shadow
    if (argc > 1 && strcmp(argv[1], "server") == 0) {
        surrealServer();
    } else {
        // The client’s move, echoing across dimensions
        sleep(1);  // Delay for the server to be ready
        surrealClient();
    }

    return 0;
}