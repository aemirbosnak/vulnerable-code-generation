//FormAI DATASET v1.0 Category: Client Server Application ; Style: multivariable
// A client-server application that allows multiple users to connect and chat
// with each other. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_USERS 10
#define MAX_MESSAGE_LEN 256

int users[MAX_USERS]; // array to hold user socket file descriptors
int num_users = 0;
pthread_mutex_t num_users_mutex = PTHREAD_MUTEX_INITIALIZER; // mutex to synchronize access to num_users

// function to handle messages received from other users
void *handle_message(void *arg) {
    int *sock_ptr = (int *)arg;
    int sock = *sock_ptr;
    char buffer[MAX_MESSAGE_LEN];
    
    while(1) {
        memset(buffer, 0, MAX_MESSAGE_LEN); // clear the buffer
        int n = read(sock, buffer, MAX_MESSAGE_LEN); // read the message
        
        if(n < 0) {
            printf("Error reading from socket\n");
            break;
        }
        else if(n == 0) { // user has disconnected
            printf("User disconnected\n");
            break;
        }
        else { // message received
            printf("Message received: %s", buffer);
            
            // broadcast the message to all other users
            pthread_mutex_lock(&num_users_mutex);
            for(int i=0; i<num_users; i++) {
                if(users[i] != sock) { // don't send to the sender
                    write(users[i], buffer, strlen(buffer));
                }
            }
            pthread_mutex_unlock(&num_users_mutex);
        }
    }
    
    // remove the socket from the list of active users
    pthread_mutex_lock(&num_users_mutex);
    int i;
    for(i=0; i<num_users; i++) {
        if(users[i] == sock) {
            break;
        }
    }
    
    for(; i<num_users-1; i++) {
        users[i] = users[i+1];
    }
    
    num_users--;
    pthread_mutex_unlock(&num_users_mutex);
    close(sock);
    return NULL;
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[MAX_MESSAGE_LEN];
    pthread_t thread;

    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    
    // check for correct usage
    if(argc < 2) {
        printf("Usage: %s port\n", argv[0]);
        exit(1);
    }
    
    // create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }
    
    portno = atoi(argv[1]);
    
    // initialize the server address struct
    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    
    // bind the socket to the server address
    if(bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error binding socket\n");
        exit(1);
    }
    
    listen(sockfd, 5); // listen for incoming connections
    
    while(1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen); // accept incoming connection
        
        if(newsockfd < 0) {
            printf("Error accepting connection\n");
            continue;
        }
        
        // check if maximum number of users has been reached
        pthread_mutex_lock(&num_users_mutex);
        if(num_users >= MAX_USERS) {
            printf("Maximum number of users reached\n");
            pthread_mutex_unlock(&num_users_mutex);
            close(newsockfd);
            continue;
        }
        
        // add the new user to the array of active users
        users[num_users] = newsockfd;
        num_users++;
        pthread_mutex_unlock(&num_users_mutex);
        
        // create a new thread to handle incoming messages from the user
        if(pthread_create(&thread, NULL, handle_message, &newsockfd) != 0) {
            printf("Error creating thread\n");
            continue;
        }
        else {
            printf("New user connected\n");
        }
    }
    
    return 0;
}