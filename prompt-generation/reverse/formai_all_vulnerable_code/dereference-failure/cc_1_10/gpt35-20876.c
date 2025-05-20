//FormAI DATASET v1.0 Category: Temperature monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// asynchronous callback function definition
typedef void (*callback)(float temp);

// function to read temperature
void readTemperature(callback cb) {
    float temp = 0.0;
    int fd = open("/sys/class/thermal/thermal_zone0/temp", O_RDONLY); // open temperature file
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    char buf[10];
    read(fd, buf, 10); // read temperature value from file
    temp = atof(buf) / 1000.0; // convert temperature value to float

    close(fd); // close file descriptor
    cb(temp); // invoke callback function with temperature value
}

// function to handle client requests
void handleClient(int socket) {
    float temp;
    readTemperature(&temp); // read current temperature value

    char buffer[1024];
    sprintf(buffer, "Current temperature: %.2f C\n", temp); // create response message

    send(socket, buffer, sizeof(buffer), 0); // send response message to client
    close(socket); // close socket connection
}

int main() {
    int serverSocket, newSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addrSize = sizeof(clientAddr);

    serverSocket = socket(AF_INET, SOCK_STREAM, 0); // create socket

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // bind socket to localhost

    bind(serverSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr)); // bind socket to address

    listen(serverSocket, 5); // listen for incoming connections

    while (1) {
        newSocket = accept(serverSocket, (struct sockaddr *) &clientAddr, &addrSize); // accept incoming connection
        handleClient(newSocket); // handle client request asynchronously
    }

    close(serverSocket); // close server socket connection
    return 0;
}