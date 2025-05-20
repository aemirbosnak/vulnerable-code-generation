//FormAI DATASET v1.0 Category: Chat server ; Style: optimized
#include <stdio.h> //standard input-output library
#include <stdlib.h> //standard library
#include <sys/socket.h> //socket library
#include <arpa/inet.h> //internet address library
#include <string.h> //string library
#include <unistd.h> //Unix standard library for provide access to POSIX API
#include <pthread.h> //POSIX thread library

#define PORT 9999 //defining port number to be used by socket connections

//Main chat function
void *chat_func(void *socket_desc) {
    int sock = *(int*)socket_desc; //casting socket descriptor as an int value
    char *message, buffer[256]; //declaring message and buffer
    int read_size; //variable to store the size of read operation
    
    // Welcome message
    message = "Welcome to the chat room\n";
    write(sock, message, strlen(message)); //writing data to socket
    
    //initializing chat session
    while ((read_size = recv(sock, buffer, 256, 0)) > 0 ) {
        buffer[read_size] = '\0'; //End of buffer
        // Send to all
        message = buffer;
        send(sock, message, strlen(message), 0); //send the chat message to all clients
    }
     
    if(read_size == 0) {
        puts("Client disconnected"); //print a message to console
        fflush(stdout); //clean standard output buffer
    }
    else if(read_size == -1) {
        perror("recv failed"); //perror prints the error message on the standard output
    }
         
    free(socket_desc); //free socket descriptor
    pthread_exit(NULL); //terminate a thread and returning a value to the parent thread
}

int main(int argc, char *argv[]) {
    int socket_desc, new_socket, *new_sock; //declaring variables
    struct sockaddr_in server, client; //declaring structs for server and client address and port
    
    //Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket"); //print error message
    }
    
    //Server settings
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);
    
    //Bind
    if(bind(socket_desc, (struct sockaddr *)&server , sizeof(server)) < 0) {
        puts("Bind failed"); //print error message
        return 1;
    }
     
    puts("Bind done"); //print success message
    listen(socket_desc, 3); //Listen for incoming connection
     
    puts("Waiting for incoming connections...");
    int c = sizeof(struct sockaddr_in);
     
    while ((new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c))) {
        puts("Connection accepted"); //print success message
        
        pthread_t sniffer_thread; //declaring pthread type
        new_sock = malloc(1); //allocate memory for socket descriptor
        *new_sock = new_socket; //assign new socket to socket descriptor
         
        if(pthread_create(&sniffer_thread, NULL,  chat_func, (void*) new_sock) < 0) {
            perror("could not create thread"); //print error message
            return 1;
        }         
    }
     
    if (new_socket < 0) {
        perror("accept failed"); //print error message
        return 1;
    }
     
    return 0;
}