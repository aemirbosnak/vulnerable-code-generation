//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 21
#define MAXSIZE 1024

int main(int argc, char *argv[]) {
    int data_socket;
    int optval = 1;
    int i, j, k, l;
    char message[MAXSIZE];
    char buffer[MAXSIZE];
    char username[MAXSIZE];
    char password[MAXSIZE];
    char filename[MAXSIZE];
    char server_ip[MAXSIZE];
    char *command;
    struct sockaddr_in server_socket;
    memset(&server_socket, 0, sizeof(server_socket));

    // check if arguments are provided for IP address
    if(argc < 2) {
        printf("Please provide IP address\n");
        exit(1);
    }

    // set server IP
    strcpy(server_ip, argv[1]);

    // Open data socket
    if((data_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        perror("Error: failed to create socket");
        exit(1);
    }

    // set socket option
    if(setsockopt(data_socket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
        perror("Error: setsockopt failed");
        exit(1);
    }

    // set server details
    server_socket.sin_family = AF_INET;
    server_socket.sin_port = htons(PORT);
    server_socket.sin_addr.s_addr = inet_addr(server_ip);

    // connect to the server
    if(connect(data_socket, (struct sockaddr*)&server_socket, sizeof(server_socket)) < 0) {
        perror("Error: Failed to connect to server");
        exit(1);
    }

    // read server response
    if(recv(data_socket, buffer, sizeof(buffer), 0) < 0) {
        perror("Error: Failed to receive from server");
        exit(1);
    }

    printf("%s\n", buffer);

    // receive user name and password
    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    // create message to send
    sprintf(message, "USER %s\r\n", username);

    // send message to server
    if(send(data_socket, message, strlen(message), 0) < 0) {
        perror("Error: Failed to send message");
        exit(1);
    }

    // read server response
    if(recv(data_socket, buffer, sizeof(buffer), 0) < 0) {
        perror("Error: Failed to receive from server");
        exit(1);
    }

    if(strstr(buffer, "331") == NULL) {
        printf("Wrong username, Please try again\n");
        exit(1);
    }

    printf("%s\n", buffer);

    // create message to send
    sprintf(message, "PASS %s\r\n", password);

    // send message to server
    if(send(data_socket, message, strlen(message), 0) < 0) {
        perror("Error: Failed to send message");
        exit(1);
    }

    // read server response
    if(recv(data_socket, buffer, sizeof(buffer), 0) < 0) {
        perror("Error: Failed to receive from server");
        exit(1);
    }

    if(strstr(buffer, "230") == NULL) {
        printf("Wrong password, Please try again\n");
        exit(1);
    }

    printf("%s\n", buffer);

    // get name of file to download
    printf("Enter name of file to download: ");
    scanf("%s", filename);

    // create message to send
    sprintf(message, "TYPE I\r\n");

    // send message to server
    if(send(data_socket, message, strlen(message), 0) < 0) {
        perror("Error: Failed to send message");
        exit(1);
    }

    // read server response
    if(recv(data_socket, buffer, sizeof(buffer), 0) < 0) {
        perror("Error: Failed to receive from server");
        exit(1);
    }

    printf("%s\n", buffer);

    // create message to send
    sprintf(message, "PASV\r\n");

    // send message to server
    if(send(data_socket, message, strlen(message), 0) < 0) {
        perror("Error: Failed to send message");
        exit(1);
    }

    // read server response
    if(recv(data_socket, buffer, sizeof(buffer), 0) < 0) {
        perror("Error: Failed to receive from server");
        exit(1);
    }

    printf("%s\n", buffer);

    // parse server response string to obtain IP and Port for data transfer
    j = 0;
    for(i = 0; i < strlen(buffer); i++) {
        if(buffer[i] == '(') {
            k = 0;
            l = 0;
            memset(message, 0, sizeof(message));
            for(j = i + 1; j < strlen(buffer); j++) {
                if(buffer[j] == ',') {
                    k++;
                    continue;
                }
                if(k == 4) {
                    if(buffer[j] == ',') {
                        // skip
                    }
                    else if(buffer[j] == ')') {
                        break;
                    }
                    else {
                        message[l] = buffer[j];
                        l++;
                    }
                }
            }
            break;
        }
    }

    // convert IP and port to integers
    int p1, p2, p3, p4, port1, port2;
    sscanf(message, "%d,%d,%d,%d,%d,%d", &p1, &p2, &p3, &p4, &port1, &port2);
    sprintf(server_ip, "%d.%d.%d.%d", p1, p2, p3, p4);
    int port = (port1 * 256) + port2;

    // open data socket
    int data_socket2;
    if((data_socket2 = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        perror("Error: Failed to create socket");
        exit(1);
    }

    // set socket option
    if(setsockopt(data_socket2, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
        perror("Error: setsockopt failed");
        exit(1);
    }

    // set data socket details
    struct sockaddr_in socket_details;
    memset(&socket_details, 0, sizeof(socket_details));
    socket_details.sin_family = AF_INET;
    socket_details.sin_port = htons(port);
    socket_details.sin_addr.s_addr = inet_addr(server_ip);

    // connect to server on data socket
    if(connect(data_socket2, (struct sockaddr*)&socket_details, sizeof(socket_details)) < 0) {
        perror("Error: Failed to connect to server");
        exit(1);
    }

    // create message to send
    sprintf(message, "RETR %s\r\n", filename);

    // send message to server
    if(send(data_socket, message, strlen(message), 0) < 0) {
        perror("Error: Failed to send message");
        exit(1);
    }

    // read server response
    if(recv(data_socket, buffer, sizeof(buffer), 0) < 0) {
        perror("Error: Failed to receive from server");
        exit(1);
    }

    printf("%s\n", buffer);

    FILE *file = fopen(filename, "w");

    // receive file data from server
    while(1) {
        int bytes_received = recv(data_socket2, buffer, sizeof(buffer), 0);
        if(bytes_received < 0) {
            perror("Error: Failed to receive from server");
            exit(1);
        }
        else if(bytes_received == 0) {
            // end of file
            break;
        }
        fwrite(buffer, bytes_received, 1, file);
    }

    fclose(file);

    // create message to send
    sprintf(message, "QUIT\r\n");

    // send message to server
    if(send(data_socket, message, strlen(message), 0) < 0) {
        perror("Error: Failed to send message");
        exit(1);
    }

    // read server response
    if(recv(data_socket, buffer, sizeof(buffer), 0) < 0) {
        perror("Error: Failed to receive from server");
        exit(1);
    }

    printf("%s\n", buffer);

    close(data_socket);
    close(data_socket2);

    return 0;
}