//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define PORT 8080

struct appointment {
    char name[50];
    char date[20];
    char time[20];
    int id;
};

struct appointment_list {
    struct appointment appointments[100];
    int count;
};

int create_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }
    return sockfd;
}

void bind_socket(int sockfd) {
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        exit(1);
    }
}

void listen_socket(int sockfd) {
    if (listen(sockfd, 10) < 0) {
        perror("listen");
        exit(1);
    }
}

int accept_connection(int sockfd) {
    int newsockfd = accept(sockfd, NULL, NULL);
    if (newsockfd < 0) {
        perror("accept");
        exit(1);
    }
    return newsockfd;
}

void send_data(int sockfd, void *data, int size) {
    if (send(sockfd, data, size, 0) < 0) {
        perror("send");
        exit(1);
    }
}

void receive_data(int sockfd, void *data, int size) {
    if (recv(sockfd, data, size, 0) < 0) {
        perror("recv");
        exit(1);
    }
}

void add_appointment(struct appointment_list *list, struct appointment *appointment) {
    list->appointments[list->count] = *appointment;
    list->count++;
}

void remove_appointment(struct appointment_list *list, int id) {
    int i;
    for (i = 0; i < list->count; i++) {
        if (list->appointments[i].id == id) {
            list->appointments[i] = list->appointments[list->count - 1];
            list->count--;
            break;
        }
    }
}

void print_appointment_list(struct appointment_list *list) {
    int i;
    for (i = 0; i < list->count; i++) {
        printf("%d. %s - %s - %s\n", i + 1, list->appointments[i].name, list->appointments[i].date, list->appointments[i].time);
    }
}

struct appointment create_appointment(char *name, char *date, char *time) {
    struct appointment appointment;
    strcpy(appointment.name, name);
    strcpy(appointment.date, date);
    strcpy(appointment.time, time);
    appointment.id = rand() % 1000;
    return appointment;
}

int main() {
    int sockfd = create_socket();
    bind_socket(sockfd);
    listen_socket(sockfd);

    struct appointment_list list;
    list.count = 0;

    while (1) {
        int newsockfd = accept_connection(sockfd);

        char buffer[1024];
        receive_data(newsockfd, buffer, sizeof(buffer));

        char *command = strtok(buffer, " ");

        if (strcmp(command, "add") == 0) {
            char *name = strtok(NULL, " ");
            char *date = strtok(NULL, " ");
            char *time = strtok(NULL, " ");
            struct appointment appointment = create_appointment(name, date, time);
            add_appointment(&list, &appointment);
            send_data(newsockfd, "Appointment added successfully", sizeof("Appointment added successfully"));
        } else if (strcmp(command, "remove") == 0) {
            int id = atoi(strtok(NULL, " "));
            remove_appointment(&list, id);
            send_data(newsockfd, "Appointment removed successfully", sizeof("Appointment removed successfully"));
        } else if (strcmp(command, "list") == 0) {
            print_appointment_list(&list);
            send_data(newsockfd, buffer, sizeof(buffer));
        } else {
            send_data(newsockfd, "Invalid command", sizeof("Invalid command"));
        }

        close(newsockfd);
    }

    close(sockfd);
    return 0;
}