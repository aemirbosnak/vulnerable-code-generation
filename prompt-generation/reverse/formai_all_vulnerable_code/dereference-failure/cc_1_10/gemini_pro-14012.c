//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>

// Palette of vibrant hues,
// To paint the canvas of our tune.
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

// A symphony of threads, a chorus of notes,
// Woven together, a song that floats.
#define MAX_THREADS  5
#define BUFFER_SIZE 1024

// The maestro's baton, conducting the show,
// A socket handle, where data shall flow.
int server_fd;

// A tapestry of threads, each playing its part,
// Awaiting the maestro's signal to start.
pthread_t threads[MAX_THREADS];

// The stage is set, the curtain about to rise,
// A function to handle each thread's surprise.
void* handle_thread(void* arg) {
    int client_fd = (int)arg;
    char buffer[BUFFER_SIZE];

    // A loop that dances, a rhythm that flows,
    // Reading and writing, as the data shows.
    while (1) {
        int bytes_received = recv(client_fd, buffer, BUFFER_SIZE, 0);
        if (bytes_received > 0) {
            printf(GREEN "[Thread %ld] Received: " RESET "%s\n", pthread_self(), buffer);

            // A touch of color, a dash of hue,
            // Adding flair to the message we construe.
            int color_index = rand() % 6;
            char color_code[10];
            switch (color_index) {
                case 0: strcpy(color_code, RED); break;
                case 1: strcpy(color_code, GREEN); break;
                case 2: strcpy(color_code, YELLOW); break;
                case 3: strcpy(color_code, BLUE); break;
                case 4: strcpy(color_code, MAGENTA); break;
                case 5: strcpy(color_code, CYAN); break;
            }

            // A whisper transformed, a message reborn,
            // Echoing in hues, a poetic adorn.
            sprintf(buffer, "%s[Thread %ld] %s", color_code, pthread_self(), buffer);
            send(client_fd, buffer, strlen(buffer), 0);
        } else if (bytes_received == 0) {
            printf(YELLOW "[Thread %ld] Client disconnected\n" RESET, pthread_self());
            close(client_fd);
            break;
        } else {
            perror("recv");
            close(client_fd);
            break;
        }
    }

    return NULL;
}

// The grand symphony, a masterpiece to behold,
// Where threads dance, and melodies unfold.
int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // A socket blooms, a gateway to the unknown,
    // Where connections weave, a tapestry grown.
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // A touch of magic, a dash of grace,
    // The socket's address, a welcoming space.
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // The socket unfurls, ready to embrace,
    // Binding to an address, a digital space.
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        close(server_fd);
        return EXIT_FAILURE;
    }

    // A symphony's soul, a heartbeat's call,
    // The socket listens, awaiting a thrall.
    if (listen(server_fd, 5) == -1) {
        perror("listen");
        close(server_fd);
        return EXIT_FAILURE;
    }

    printf(BLUE "[Server] Listening on port %s\n" RESET, argv[1]);

    // A maestro's baton, a thread's embrace,
    // Threads awaken, ready for the chase.
    for (int i = 0; i < MAX_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, handle_thread, NULL) != 0) {
            perror("pthread_create");
            close(server_fd);
            return EXIT_FAILURE;
        }
    }

    // A dance of connections, a graceful sway,
    // Accepting clients, joining the play.
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_fd == -1) {
            perror("accept");
            close(server_fd);
            return EXIT_FAILURE;
        }

        printf(MAGENTA "[Server] Client connected from %s:%d\n" RESET, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    }

    // The curtain falls, the symphony's end,
    // Threads join together, their journey to mend.
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // The socket slumbers, its purpose fulfilled,
    // Closing the gateway, its story stilled.
    close(server_fd);

    return EXIT_SUCCESS;
}