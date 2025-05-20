//FormAI DATASET v1.0 Category: Client Server Application ; Style: multiplayer
// This is an example C Client Server Application in a multiplayer style
#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <unistd.h> 

#define PORT 8000 
#define MAX_PLAYERS 3 //maximum of 3 players allowed in our game
#define BUFFER_SIZE 1024 //maximum buffer size

int playersCount = 0; //initialize player count to zero

//Structure for player
struct player {
    char name[20];
    int score;
};

struct player players[MAX_PLAYERS]; //an array of players

//Function to broadcast the message
void broadcast(int sender, char *message) {
    int i;
    char buffer[BUFFER_SIZE];

    //loop through all the players
    for (i = 0; i < MAX_PLAYERS; i++) {
        //if the player is active and not the sender, send the message
        if (i != sender && players[i].score != -1) {
            sprintf(buffer, "Player %s: %s", players[sender].name, message);
            send(i, buffer, strlen(buffer), 0);
        }
    }
}

//Thread function for each player
void *threadFunction(void *arg) {
    int playerNum = *(int*)arg;
    char buffer[BUFFER_SIZE];
    int n;

    //set the player's name
    sprintf(buffer, "Welcome, you are Player %d! What is your name?", playerNum+1);
    send(playerNum, buffer, strlen(buffer), 0);

    //receive the player's name
    n = recv(playerNum, buffer, BUFFER_SIZE, 0);
    buffer[n] = '\0';
    strcpy(players[playerNum].name, buffer);

    //loop for the game
    while (1) {
        sprintf(buffer, "Enter a number between 1 and 100. -1 to quit");
        send(playerNum, buffer, strlen(buffer), 0);

        //receive the player's guess
        n = recv(playerNum, buffer, BUFFER_SIZE, 0);
        buffer[n] = '\0';
        int guess = atoi(buffer);

        //if the player wants to quit, exit the thread
        if (guess == -1) {
            players[playerNum].score = -1;
            sprintf(buffer, "Goodbye!");
            send(playerNum, buffer, strlen(buffer), 0);
            pthread_exit(NULL);
        }

        //check if the guess is correct
        if (guess == 50) {
            sprintf(buffer, "Congratulations! You win!");
            send(playerNum, buffer, strlen(buffer), 0);
            players[playerNum].score++;
            broadcast(playerNum, " has won this round!");
        } else if (guess < 50) {
            sprintf(buffer, "Your guess of %d is too low.", guess);
            send(playerNum, buffer, strlen(buffer), 0);
        } else {
            sprintf(buffer, "Your guess of %d is too high.", guess);
            send(playerNum, buffer, strlen(buffer), 0);
        }
    }
}

int main() {
    int server_socket, client_socket, addr_len; 
    struct sockaddr_in server_addr, client_addr; 
    pthread_t threads[MAX_PLAYERS]; 

    //initialize all scores to 0
    for (int i = 0; i < MAX_PLAYERS; i++) {
        players[i].score = 0;
    }

    //create the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    //set the server address
    server_addr.sin_family = AF_INET; 
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY); 
    server_addr.sin_port = htons(PORT); 
    
    //bind the socket to the server address
    bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    
    //listen to the socket
    listen(server_socket, MAX_PLAYERS); 
    
    printf("Waiting for players to join...\n");
    
    //loop to handle multiple players
    while (playersCount < MAX_PLAYERS) {
        //accept a client connection
        addr_len = sizeof(client_addr); 
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_len);
    
        //if too many players, tell the client and close the socket
        if (playersCount == MAX_PLAYERS) {
            char buf[BUFFER_SIZE] = "Sorry, the game is already full.";
            send(client_socket, buf, strlen(buf), 0);
            close(client_socket);
        } else {
            //create a new thread for the client
            pthread_create(&threads[playersCount], NULL, threadFunction, &client_socket);
            playersCount++;
        }
    }

    //wait for all threads to finish before closing the server socket
    for (int i = 0; i < MAX_PLAYERS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    close(server_socket);
    return 0;
}