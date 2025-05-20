//FormAI DATASET v1.0 Category: Digital Auction System ; Style: distributed
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<time.h>
#include<fcntl.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 300

int highest_bid = 0;
int current_winner = -1;
int client_sockets[MAX_CLIENTS] = {0};
int nr_clients = 0;
int auction_running = 1;

void error(char *msg){
    perror(msg);
    exit(1);
}

void send_message(char *message, int receiver){
    if(send(client_sockets[receiver], message, strlen(message), 0) < 0){
        error("Error sending message to client.");
    }
}

void send_to_all(char *message){
    for(int i = 0; i < nr_clients; i++){
        send_message(message, i);
    }
}

void handle_bidding(char *buffer, int sender){
    int bid;
    if(sscanf(buffer, "%d", &bid) <= 0){
        send_message("Invalid bid format.", sender);
        return;
    }
    if(bid < highest_bid){
        send_message("Bid is too low.", sender);
        return;
    }
    highest_bid = bid;
    current_winner = sender;
    char message[BUFFER_SIZE];
    sprintf(message, "Your bid of %d was accepted.", bid);
    send_message(message, sender);
    sprintf(message, "Client %d just bid %d.", sender, bid);
    send_to_all(message);
}

void handle_command(char *buffer){
    if(strcmp(buffer, "exit") == 0){
        auction_running = 0;
    }
}

//Main function
int main(int argc, char *argv[]){
    int port_number;
    int server_socket;
    int client_socket;
    int max_fd;
    int fd;
    int activity;
    int bytes_received;
    int option_value = 1;
    char buffer[BUFFER_SIZE];
    char welcome_message[] = "\nWelcome to the auction!\nEnter your bid:";

    fd_set read_fds;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    socklen_t client_len = sizeof(client_address);

    if(argc < 2){
        printf("Usage: %s <port>\n", argv[0]);
        exit(0);
    }

    port_number = atoi(argv[1]);
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket < 0){
        error("Error creating socket.");
    }

    memset(&server_address, '\0', sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port_number);

    if(setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &option_value, sizeof(option_value)) < 0){
        error("Error setting socket options.");
    }

    if(bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0){
        error("Error binding to socket.");
    }

    if(listen(server_socket, 5) < 0){
        error("Error listening on socket.");
    }

    printf("Auction server started. Listening on port %d.\n", port_number);

    while(auction_running){
        FD_ZERO(&read_fds);
        FD_SET(server_socket, &read_fds);
        max_fd = server_socket;

        for(int i = 0; i < MAX_CLIENTS; i++){
            fd = client_sockets[i];
            if(fd > 0){
                FD_SET(fd, &read_fds);
            }
            if(fd > max_fd){
                max_fd = fd;
            }
        }

        activity = select(max_fd + 1, &read_fds, NULL, NULL, NULL);
        if(activity < 0){
            error("Error with select system call.");
        }

        if(FD_ISSET(server_socket, &read_fds)){
            client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_len);
            if(client_socket < 0){
                error("Error accepting connection.");
            }
            printf("New connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
            send_message(welcome_message, nr_clients);
            nr_clients++;
            for(int i = 0; i < MAX_CLIENTS; i++){
                if(client_sockets[i] == 0){
                    client_sockets[i] = client_socket;
                    break;
                }
            }
        }

        for(int i = 0; i < MAX_CLIENTS; i++){
            fd = client_sockets[i];
            if(FD_ISSET(fd, &read_fds)){
                bytes_received = recv(fd, buffer, BUFFER_SIZE, 0);
                if(bytes_received <= 0){
                    close(fd);
                    client_sockets[i] = 0;
                } else {
                    buffer[bytes_received - 1] = '\0';
                    if(i == current_winner){
                        handle_command(buffer);
                    } else {
                        handle_bidding(buffer, i);
                    }
                }
            }
        }

        if(nr_clients == 0){
            auction_running = 0;
        }
    }

    close(server_socket);
    return 0;
}