//FormAI DATASET v1.0 Category: Client Server Application ; Style: real-life
/* 
  Description: This is a simple chat application where Clients can connect to the server and communicate 
  with each other. 

  Operation:
  - Clients connect to the server and send their identity(username)
  - The server broadcasts this new connection to all other connected clients
  - Clients can send messages to the server
  - server broadcasts the message to all clients, except the sender

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<errno.h>
#include<signal.h>

#define PORT 8989
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

void cleanUp(int sigNum);    //for cleaning up when user terminates with a CTRL + C signal
void broadcastMsg(int sender, char msg[], int clients[], int num_clients); //broadcast a message to all connected clients

int main()
{
    int server_fd, new_socket;
    int clients[MAX_CLIENTS];
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int activity, i, valread, sd, max_sd;
    int address_len = sizeof(server_addr);
    int num_clients = 0;

    //initialize all clients to -1, indicating that they are not connected yet
    for(i=0; i<MAX_CLIENTS; i++)
        clients[i] = -1;

    //create the server socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd == -1){
        printf("Error: socket creation failed. Error Code: %d\n", errno);
        exit(EXIT_FAILURE);
    }

    //set server_addr to zero, and assign IP, PORT and address family
    memset(&server_addr, 0, address_len);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    //bind the socket to the address and port number
    if(bind(server_fd, (struct sockaddr *)&server_addr, address_len) == -1){
        printf("Error: bind failed. Error code: %d\n", errno);
        exit(EXIT_FAILURE);
    }

    //listen for incoming client connections
    if(listen(server_fd, 3) == -1){
        printf("Error: listen failed. Error code: %d\n", errno);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    //request user to press CTRL+C to terminate the server
    signal(SIGINT, cleanUp);

    while(1){
        fd_set readfds;         //set of socket file descriptors
        int max_fds = 0;       
     
        //clear the socket set
        FD_ZERO(&readfds);              
     
        //add the server_fd socket to set
        FD_SET(server_fd, &readfds);  
        max_fds = server_fd;            //set max_fds to server_fd
     
        //add connected client sockets to set
        for(i=0; i<MAX_CLIENTS; i++){   
            //get the socket descriptor of current client
            int sd = clients[i];
                 
            //if valid socket descriptor - add it to set
            if(sd > 0)
                FD_SET(sd , &readfds);

            //find highest socket descriptor, for use with the select function
            if(sd > max_fds)
                max_fds = sd;
        }
     
        //wait for an activity on one of the sockets
        activity = select(max_fds + 1 , &readfds , NULL , NULL , NULL);

        if((activity < 0) && (errno!=EINTR)){   
            printf("Error: select error. Error code: %d\n", errno);
            exit(EXIT_FAILURE);
        }
             
        //If activity is on server_fd, then there is a new client connection
        if(FD_ISSET(server_fd, &readfds)){
            if((new_socket = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t*)&address_len)) == -1){
                printf("Error: accept failed. Error code: %d\n",errno);
                exit(EXIT_FAILURE);
            }
         
            printf("New connection , socket fd is %d , ip is: %s , port: %d\n" , new_socket , inet_ntoa(client_addr.sin_addr) , ntohs(client_addr.sin_port));
         
            //add new_socket to clients array
            for (i = 0; i < MAX_CLIENTS; i++){
                if (clients[i] == -1){
                    clients[i] = new_socket;
                    num_clients++;
                    break;
                }
            }

            //send welcome message to new client
            char *welcome = "Welcome to the chat server!\nPlease enter your username:\n";
            send(new_socket, welcome, strlen(welcome), 0);
        }
             
        //if activity is on client sockets, then there is a message from a client
        for(i = 0; i < MAX_CLIENTS; i++){
            sd = clients[i];    //get the socket descriptor of current client
                 
            if(FD_ISSET(sd , &readfds)){   
                //if there is a message from the client, read it
                if ((valread = recv(sd , buffer, BUFFER_SIZE, 0)) == 0){
                    //the client terminated the connection
                    getpeername(sd , (struct sockaddr*)&client_addr , (socklen_t*)&address_len);
                    printf("Host disconnected, ip %s , port %d \n" , inet_ntoa(client_addr.sin_addr) , ntohs(client_addr.sin_port));
                        
                    //close the socket and remove it from clients array
                    close(sd);
                    clients[i] = -1;
                    num_clients--;
                }
                else{
                    buffer[valread] = '\0'; //add null character to signify end of string
             
                    //if the client has not yet sent its identity, send it to server
                    if(strlen(buffer) < 20){
                        char *connected = " has joined the chat!\n";
                        char name[20];
                        strcpy(name, buffer);
                        strcat(name, connected);
                        broadcastMsg(sd, name, clients, num_clients);
                    }
                    else{
                        //if the client has sent its identity, broadcast the message to all other clients
                        printf("%s: %s\n", buffer, buffer+20);
                        broadcastMsg(sd, buffer+20, clients, num_clients);
                    }
                }
            }
        }
    }

    //clean up
    close(server_fd);
    return 0;
}

//function to broadcast message to all connected clients, except the sender
void broadcastMsg(int sender, char msg[], int clients[], int num_clients){
    int i;
    for(i=0; i<MAX_CLIENTS; i++){
        if(clients[i] != -1 && clients[i] != sender){
            send(clients[i], msg, strlen(msg), 0);
        }
    }
}

//function to clean up when user terminates with CTRL + C signal
void cleanUp(int sigNum){
    printf("\nServer has been terminated.\n");
    exit(0);
}