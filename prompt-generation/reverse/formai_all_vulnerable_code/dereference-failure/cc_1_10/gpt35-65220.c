//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include <sys/time.h>
#include <errno.h>

#define MAXBUF 4096

int sock_to_monitor; // socket file descriptor for monitoring

// Function to gracefully handle interruptions
void sig_handler(int signo){
    if (signo == SIGINT){
        printf("\n\nReceived SIGINT. Closing the socket and terminating the program.\n");
        close(sock_to_monitor);
        exit(0);
    }
}

int main(int argc, char * argv[]){

    // Check if IP address and port are given as command line arguments
    if(argc < 3){
        printf("Please provide the IP address and Port number to monitor.\n");
        return -1;
    }

    // Check for valid IP address
    struct sockaddr_in servaddr;
    if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0){
        printf("Invalid IP address\n");
        return -1;
    }

    // Check if the given Port number is valid
    int port_number = atoi(argv[2]); // Convert port number string to integer
    if(port_number <= 0 || port_number > 65535){
        printf("Invalid Port number\n");
        return -1;
    }

    // Create socket to monitor QoS
    if((sock_to_monitor = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0){
        perror("Error creating socket");
        return -1;
    }

    // Set socket options to reuse address
    int sockopt = 1;
    if(setsockopt(sock_to_monitor, SOL_SOCKET, SO_REUSEADDR, &sockopt, sizeof(sockopt)) < 0){
        perror("Error setting socket options");
        return -1;
    }

    // Bind the socket to the given local address and Port number
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port_number);
    if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0){
        printf("Invalid IP address\n");
        return -1;
    }
    if(bind(sock_to_monitor, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0){
        perror("Error binding socket");
        return -1;
    }

    // Listen for incoming connections
    if(listen(sock_to_monitor, 10) < 0){
        perror("Error listening to socket");
        return -1;
    }

    printf("Monitoring network QoS on IP address: %s, Port number: %d\n", argv[1], port_number);

    // Register signal handler for graceful termination of the program
    signal(SIGINT, sig_handler);

    // Accept incoming connections and monitor QoS
    while(1){
        int client_socket;
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);

        // Accept incoming connections
        if((client_socket = accept(sock_to_monitor, (struct sockaddr *)&client_address, &client_address_len)) < 0){
            perror("Error accepting incoming connection");
            continue;
        }

        // Get the hostname of the remote client
        char host_name[MAXBUF];
        struct hostent *host_entry;
        if((host_entry = gethostbyaddr((const void *)&client_address.sin_addr.s_addr, sizeof(client_address.sin_addr.s_addr), AF_INET)) == NULL){
            strcpy(host_name, "Unknown");
        }
        else{
            strcpy(host_name, host_entry->h_name);
        }

        // Get the time of the incoming connection
        char * time_string;
        time_t current_time;
        struct tm * time_info;
        time(&current_time);
        time_info = localtime(&current_time);
        time_string = asctime(time_info);
        time_string[strlen(time_string) - 1] = '\0';

        printf("Incoming connection on socket %d from host %s (%s)\n", client_socket, host_name, time_string);

        // Monitor QoS for the incoming connection
        // Here you can implement your QoS monitoring algorithm


        // Close the client socket after monitoring QoS
        close(client_socket);
    }

    return 0;
}