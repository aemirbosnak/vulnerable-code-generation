//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <string.h>

#define MAX_MESSAGE_SIZE 1024
#define MAX_SERVERS 10

struct Server {
    char name[50];
    char ip[20];
    int port;
    int socket_fd;
};

void check_error(int result, const char *msg) {
    if (result == -1) {
        perror(msg);
        exit(1);
    }
}

void read_server_data(struct Server *server, FILE *fp) {
    char line[100];
    fgets(line, 100, fp);

    char *token;
    token = strtok(line, " ");
    strcpy(server->name, token);

    token = strtok(NULL, " ");
    strcpy(server->ip, token);

    token = strtok(NULL, " ");
    server->port = atoi(token);
}

void read_config(struct Server servers[], int *num_servers) {
    FILE *fp = fopen("config.txt", "r");
    int i = 0;
    while (!feof(fp)) {
        read_server_data(&servers[i], fp);
        i++;
    }
    fclose(fp);
    *num_servers = i;
}

void connect_to_servers(struct Server servers[], int num_servers) {
    int i;
    for (i = 0; i < num_servers; i++) {
        struct sockaddr_in server_address;
        server_address.sin_family = AF_INET;
        server_address.sin_addr.s_addr = inet_addr(servers[i].ip);
        server_address.sin_port = htons(servers[i].port);

        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        check_error(sockfd, "Error creating socket");

        int conn_result = connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address));
        check_error(conn_result, "Error connecting to server");

        servers[i].socket_fd = sockfd;
    }
}

void send_message(int socket_fd, char message[]) {
    int message_len = strlen(message);
    int send_result = send(socket_fd, message, message_len, 0);
    check_error(send_result, "Error sending message");
}

void receive_message(int socket_fd, char message[]) {
    int received_bytes = recv(socket_fd, message, MAX_MESSAGE_SIZE, 0);
    check_error(received_bytes, "Error receiving message");
    message[received_bytes] = '\0';
}

int main() {
    struct Server servers[MAX_SERVERS];
    int num_servers;
    read_config(servers, &num_servers);
    connect_to_servers(servers, num_servers);

    while (1) {
        int i;
        for (i = 0; i < num_servers; i++) {
            char message[MAX_MESSAGE_SIZE];
            sprintf(message, "GET / HTTP/1.0\r\nHost: %s:%d\r\nConnection: close\r\n\r\n", servers[i].ip, servers[i].port);
            send_message(servers[i].socket_fd, message);

            char response[MAX_MESSAGE_SIZE];
            receive_message(servers[i].socket_fd, response);

            printf("Received from %s: %s\n", servers[i].name, response);

            close(servers[i].socket_fd);
        }
        printf("-----------------------------------\n");
        sleep(5);
        connect_to_servers(servers, num_servers);
    }
    return 0;
}