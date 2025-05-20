//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080
#define MAXCLIENTS 5

int num_clients = 0;
int clients[MAXCLIENTS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *client_service(void *arg);

int main(int argc, char const *argv[]) {
    int server_fd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    }
    
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    }
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 
    
    // Binding socket to given IP and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    }
    
    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    }
    
    printf("Server started at port %d\n", PORT);
    
    // Handle multiple clients
    while(1) {
        int new_socket;
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) { 
            perror("accept"); 
            exit(EXIT_FAILURE); 
        }

        pthread_t tid;
        int *client_fd = malloc(sizeof(int));
        *client_fd = new_socket;
        pthread_create(&tid, NULL, client_service, (void *)client_fd);
    }
    return 0;
}

void *client_service(void *arg) {
    int client_fd = *(int *)arg;
    
    pthread_mutex_lock(&mutex);
    if (num_clients == MAXCLIENTS) {
        close(client_fd);
    }
    else {
        clients[num_clients++] = client_fd;
        printf("Client %d connected\n", num_clients);
    }
    pthread_mutex_unlock(&mutex);
    
    while (1) {
        char message[1024];
        int n = read(client_fd, message, sizeof(message));
        if (n <= 0) {
            // Client has disconnected
            pthread_mutex_lock(&mutex);
            for (int i = 0; i < num_clients; i++) {
                if (clients[i] == client_fd) {
                    clients[i] = clients[num_clients-1];
                    num_clients--;
                    break;
                }
            }
            printf("Client %d disconnected\n", num_clients+1);
            pthread_mutex_unlock(&mutex);
            close(client_fd);
            break;
        }
        else {
            message[n] = '\0';
            if (strcmp(message, "QUIT") == 0) {
                // Quit command received
                strcpy(message, "Goodbye!\n");
                write(client_fd, message, strlen(message));
                close(client_fd);
                break;
            }
            else {
                // Disk space analyzer code goes here...
                strcpy(message, "Disk space analysis not implemented yet\n");
                write(client_fd, message, strlen(message));
            }
        }
    }
    free(arg);
    pthread_detach(pthread_self());
    return NULL;
}