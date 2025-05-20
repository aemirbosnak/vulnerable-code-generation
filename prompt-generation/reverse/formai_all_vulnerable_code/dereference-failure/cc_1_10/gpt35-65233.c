//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_CLIENTS 100
#define BUFFER_SIZE 1024

// data structure for holding client information
typedef struct {
    int sockfd;
    struct sockaddr_in address;
    int pid;
} client_t;

// data structure for holding QoS information
typedef struct {
    int bandwidth;
    int latency;
    int jitter;
} qos_t;

// global array for holding client information
client_t clients[MAX_CLIENTS];

// function for handling client requests
void *handle_client(void *arg) {
    client_t *client = (client_t *) arg;
    char buffer[BUFFER_SIZE];
    int status = 1;

    while(status) {
        memset(buffer, 0, BUFFER_SIZE);
        int read_status = read(client->sockfd, buffer, BUFFER_SIZE);
        if(read_status < 0) {
            printf("Error reading from client %s\n", inet_ntoa(client->address.sin_addr));
            status = 0;
            break;
        } else if(read_status == 0) {
            printf("Client %s disconnected.\n", inet_ntoa(client->address.sin_addr));
            status = 0;
            break;
        } else {
            // parse incoming message to get QoS values
            qos_t qos;
            sscanf(buffer, "%d %d %d", &qos.bandwidth, &qos.latency, &qos.jitter);

            // do something with QoS values
            printf("Received QoS values from client %s: bandwidth = %d, latency = %d, jitter = %d\n",
                inet_ntoa(client->address.sin_addr), qos.bandwidth, qos.latency, qos.jitter);

            // send response back to client
            char response[] = "Received QoS values.";
            write(client->sockfd, response, strlen(response));
        }
    }

    // clean up after client disconnects
    close(client->sockfd);
    pthread_exit(NULL);
}

// main function for starting server
int main(int argc, char *argv[]) {
    int sockfd, new_sockfd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // create socket for server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // set socket options
    if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Error setting socket options");
        exit(EXIT_FAILURE);
    }

    // set socket address properties
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(atoi(argv[1]));

    // bind socket to address
    if(bind(sockfd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // start listening for client connections
    if(listen(sockfd, MAX_CLIENTS) < 0) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    // main loop for handling client connections
    int num_clients = 0;
    while(1) {
        // accept incoming client connection
        new_sockfd = accept(sockfd, (struct sockaddr *) &address, (socklen_t *) &addrlen);
        if(new_sockfd < 0) {
            perror("Error accepting connection");
            continue;
        }

        // add client information to array of clients
        client_t client = { new_sockfd, address, getpid() };
        clients[num_clients++] = client;
        printf("New client connected: %s\n", inet_ntoa(client.address.sin_addr));

        // spawn thread to handle client requests
        pthread_t thread_id;
        if(pthread_create(&thread_id, NULL, handle_client, (void *) &client) < 0) {
            perror("Error creating thread");
            continue;
        }
        pthread_detach(thread_id);
    }

    // clean up when server shuts down
    close(sockfd);
    return 0;
}