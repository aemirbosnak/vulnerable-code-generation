//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <pthread.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 7070
#define IP "127.0.0.1"
#define BUFFER_SIZE 1024

void *scan_file(void *path);
void *handle_connection(void *socket_desc);
int is_infected(char *filename);
int count_files(char *path);

int main(int argc, char *argv[]) {
    int socket_desc, client_sock, c, *new_sock;
    struct sockaddr_in server, client;
    pthread_t thread_id;
    DIR *dir;
    struct dirent *ent;

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc < 0) {
        perror("Failed to create socket.\n");
        return 1;
    }

    // Prepare server sockaddr_in struct
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(IP);
    server.sin_port = htons(PORT);

    // Bind socket
    if (bind(socket_desc, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("Failed to bind socket.\n");
        return 1;
    }

    // Listen for connections
    listen(socket_desc, 3);

    // Accept incoming connections
    c = sizeof(struct sockaddr_in);
    while ((client_sock = accept(socket_desc, (struct sockaddr *) &client, (socklen_t *) &c))) {
        new_sock = malloc(1);
        *new_sock = client_sock;

        if (pthread_create(&thread_id, NULL, handle_connection, (void *) new_sock) < 0) {
            perror("Failed to create thread.\n");
            return 1;
        }
    }
    if (client_sock < 0) {
        perror("Failed to accept connection.\n");
        return 1;
    }

    // Scan files
    if (argc == 2) {
        dir = opendir(argv[1]);
        if (dir == NULL) {
            perror("Failed to open directory.\n");
            return 1;
        }

        int total_files = count_files(argv[1]);
        pthread_t tid[total_files];

        int i = 0;
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_type == DT_REG) {
                char *path = malloc(strlen(argv[1]) + strlen(ent->d_name) + 2);
                sprintf(path, "%s/%s", argv[1], ent->d_name);
                pthread_create(&tid[i], NULL, scan_file, (void *) path);
                i++;
            }
        }

        for (int j = 0; j < i; j++) {
            pthread_join(tid[j], NULL);
        }

        closedir(dir);
    }

    return 0;
}

// Scan a file for virus
void *scan_file(void *path) {
    char *filename = (char *) path;
    if (is_infected(filename)) {
        printf("WARNING: %s is infected with viruses.\n", filename);
    }
}

// Handle client connection
void *handle_connection(void *socket_desc) {
    char buffer[BUFFER_SIZE], result[BUFFER_SIZE];
    int sock = *(int *) socket_desc;
    int read_size;

    while ((read_size = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        char *filename = buffer;
        if (is_infected(filename)) {
            strcpy(result, "Infected");
        } else {
            strcpy(result, "Clean");
        }
        send(sock, result, strlen(result), 0);
    }

    if (read_size == 0) {
        puts("Client disconnected.");
        fflush(stdout);
    } else if (read_size == -1) {
        perror("Failed to receive data.\n");
    }

    free(socket_desc);
    return 0;
}

// Check if file is infected
int is_infected(char *filename) {
    int result = 0;
    char *cmd = malloc(strlen("clamscan ") + strlen(filename) + 1);
    sprintf(cmd, "clamscan %s", filename);

    FILE *output = popen(cmd, "r");
    if (output) {
        char buffer[BUFFER_SIZE];
        while (!feof(output)) {
            fgets(buffer, BUFFER_SIZE, output);
            if (strstr(buffer, "FOUND") != NULL) {
                result = 1;
                break;
            }
        }
        pclose(output);
    } else {
        perror("Failed to execute command.\n");
    }

    free(cmd);
    return result;
}

// Count the number of files in a directory
int count_files(char *path) {
    int count = 0;
    DIR *dir;
    struct dirent *ent;

    dir = opendir(path);
    if (dir == NULL) {
        perror("Failed to open directory.\n");
        return 0;
    }

    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_type == DT_REG) {
            count++;
        }
    }

    closedir(dir);
    return count;
}