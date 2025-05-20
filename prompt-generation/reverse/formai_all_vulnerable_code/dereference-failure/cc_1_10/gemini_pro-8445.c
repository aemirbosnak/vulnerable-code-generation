//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Structure to hold the question and answer
typedef struct {
    char question[1024];
    char answer[1024];
} Question;

// Structure to hold the student's information
typedef struct {
    char name[1024];
    char roll_number[1024];
    int score;
} Student;

// Structure to hold the thread arguments
typedef struct {
    int sockfd;
    Student* student;
    Question* question;
} ThreadArgs;

// Function to handle the client connection
void* handle_client(void* args) {
    ThreadArgs* thread_args = (ThreadArgs*) args;

    // Send the question to the client
    send(thread_args->sockfd, thread_args->question, sizeof(Question), 0);

    // Receive the answer from the client
    Question answer;
    recv(thread_args->sockfd, &answer, sizeof(Question), 0);

    // Check if the answer is correct
    if (strcmp(answer.answer, thread_args->question->answer) == 0) {
        thread_args->student->score++;
    }

    // Close the client connection
    close(thread_args->sockfd);

    // Free the memory allocated for the thread arguments
    free(thread_args);

    return NULL;
}

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Bind the socket to an address
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(12345);
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(sockfd, (struct sockaddr*) &addr, sizeof(addr)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Listen for connections
    if (listen(sockfd, 5) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Create a pool of questions
    Question questions[] = {
        {"What is the capital of India?", "New Delhi"},
        {"Who is the current Prime Minister of India?", "Narendra Modi"},
        {"What is the national animal of India?", "Tiger"},
        {"What is the national bird of India?", "Peacock"},
        {"What is the national flower of India?", "Lotus"},
    };

    // Create a pool of students
    Student students[] = {
        {"John Doe", "123456", 0},
        {"Jane Doe", "654321", 0},
        {"Jack Doe", "112233", 0},
        {"Jill Doe", "445566", 0},
        {"Jim Doe", "778899", 0},
    };

    // Accept connections and handle them in separate threads
    while (1) {
        // Accept a connection
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sockfd = accept(sockfd, (struct sockaddr*) &client_addr, &client_addr_len);
        if (client_sockfd == -1) {
            perror("accept");
            continue;
        }

        // Create a new thread to handle the client connection
        ThreadArgs* thread_args = malloc(sizeof(ThreadArgs));
        thread_args->sockfd = client_sockfd;
        thread_args->student = &students[rand() % 5];
        thread_args->question = &questions[rand() % 5];
        pthread_t thread;
        if (pthread_create(&thread, NULL, handle_client, thread_args) != 0) {
            perror("pthread_create");
            close(client_sockfd);
            free(thread_args);
            continue;
        }

        // Detach the thread so that it can be cleaned up automatically
        pthread_detach(thread);
    }

    // Close the server socket
    close(sockfd);

    return EXIT_SUCCESS;
}