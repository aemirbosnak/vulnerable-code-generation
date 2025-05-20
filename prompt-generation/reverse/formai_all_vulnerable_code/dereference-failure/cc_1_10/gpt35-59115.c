//FormAI DATASET v1.0 Category: Chat server ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h> 
#include<sys/socket.h>
#include<netinet/in.h>
#include<pthread.h>

// Error function to print error messages
void error(const char *msg)
{
    perror(msg);
    exit(1);
}

// Thread function for each client connection
void *handle_client(void *arg)
{
    int sockfd = *(int*)arg;
    char buffer[256];
    int n;

    // Communication with the client
    while(1)
    {
        // Read the message from the client
        bzero(buffer,256);
        n = read(sockfd,buffer,255);
        if (n < 0) error("ERROR reading from socket");

        // Print the message on server's console
        printf("Client: %s\n",buffer);

        // Write a response to the client
        n = write(sockfd,"Server: I got your message",26);
        if (n < 0) error("ERROR writing to socket");
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    // Check for the correct number of arguments
    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }

    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    // Create a socket for server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    // Initialize the server address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
            sizeof(serv_addr)) < 0) 
            error("ERROR on binding");

    // Listen for incoming connections
    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    // Accept new connections and create a thread for each connection
    while (1) {
        newsockfd = accept(sockfd, 
                (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) 
            error("ERROR on accept");

        printf("Client connected\n");

        // Create a thread for the client
        pthread_t thread_id;
        if(pthread_create(&thread_id, NULL, handle_client, (void*)&newsockfd) < 0)
        {
            perror("could not create thread");
            return 1;
        }

        pthread_detach(thread_id);
    }

    close(sockfd);
    return 0; 
}