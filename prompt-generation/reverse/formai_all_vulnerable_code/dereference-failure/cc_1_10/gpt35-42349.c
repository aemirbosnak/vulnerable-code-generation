//FormAI DATASET v1.0 Category: Socket programming ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *message;
    
    //Seed random number generator with current time in microseconds to generate a unique message
    srand((unsigned) time(NULL)*1000000);
    
    //Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
   
    //Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        return -1;
    }
   
    //Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection Failed");
        return -1;
    }

    //Generate a unique message
    char *prefix = "Client ";
    int num = rand() % 100;
    char num_str[3];
    snprintf(num_str, 3, "%d", num);
    message = malloc(strlen(prefix) + strlen(num_str) + 1);
    strcpy(message, prefix);
    strcat(message, num_str);

    //Encrypt message
    for (int i = 0; i < strlen(message); i++) {
        message[i] = message[i] ^ (i+1); //XOR with incremental byte value
    }

    //Send message to server
    send(sock, message, strlen(message), 0);
    printf("Message sent: %s\n", message);

    //Receive response from server
    char buffer[1024] = {0};
    int valread = read(sock, buffer, 1024);
    
    //Decrypt and print server response
    for (int i = 0; i < valread; i++) {
        buffer[i] = buffer[i] ^ (i+1); //XOR with incremental byte value
    }
    printf("Server response: %s\n", buffer);

    free(message);

    return 0;
}