//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>

#define MAX_IP_LEN 15

int main(int argc, char *argv[]){
    char *users[] = {"Alice", "Bob", "Charlie", "Eve", "Dave"};
    char *ips[] = {"192.168.0.1", "192.168.0.2", "192.168.0.3", "192.168.0.4", "192.168.0.5", "192.168.0.6"};
    int connections[5][5] = {{0, 1, 1, 0, 0}, {1, 0, 1, 1, 0}, {1, 1, 0, 0, 1}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0}};
    int num_users = 5;

    // Create socket and initialize sockaddr_in
    int sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock_fd == -1){
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(struct sockaddr_in));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(12121);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket to port 12121
    if(bind(sock_fd, (const struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening for connections on port 12121\n");

    // Loop to receive messages from clients
    while(1){
        char buffer[MAX_IP_LEN+10];
        struct sockaddr_in client_addr;
        socklen_t addr_len = sizeof(client_addr);
        memset(buffer, '\0', sizeof(buffer));
        int bytes = recvfrom(sock_fd, buffer, sizeof(buffer), 0, 
                        (struct sockaddr *)&client_addr, &addr_len);
        if(bytes < 0){
            perror("recvfrom failed");
            exit(EXIT_FAILURE);
        }

        char *ip = buffer;
        ip[bytes-1] = '\0';
        int u1 = -1, u2 = -1;
        for(int i=0;i<num_users;i++){
            if(strcmp(ips[i], ip) == 0){
                if(u1 == -1) u1 = i;
                else u2 = i;
            }
        }
        if(u1 == -1 || u2 == -1){
            printf("Error: Invalid IP address\n");
            continue;
        }

        printf("%s is connected to %s\n", users[u1], users[u2]);
        connections[u1][u2] = connections[u2][u1] = 1;
    }

    close(sock_fd);
    return 0;
}