//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define LOG_FILE "cyberlog.txt"
#define BUFFER_SIZE 1024

typedef struct {
    char name[50];
    int age;
    char *occupation;
} Cyberperson;

void log_error(const char *message) {
    int fd = open(LOG_FILE, O_WRONLY | O_APPEND);
    if (fd < 0) {
        perror("Error opening log file");
        exit(EXIT_FAILURE);
    }

    char error_message[BUFFER_SIZE];
    strcpy(error_message, "[ERROR] ");
    strcat(error_message, message);

    size_t len = strlen(error_message);
    write(fd, error_message, len);

    close(fd);
}

Cyberperson *create_cyberperson(const char *name, int age, const char *occupation) {
    Cyberperson *person = (Cyberperson *) malloc(sizeof(Cyberperson));

    if (!person) {
        log_error("Error allocating memory for Cyberperson");
        return NULL;
    }

    strcpy(person->name, name);
    person->age = age;

    size_t occupation_len = strlen(occupation) + 1;
    person->occupation = (char *) malloc(occupation_len);

    if (!person->occupation) {
        log_error("Error allocating memory for Cyberperson occupation");
        free(person);
        return NULL;
    }

    strcpy(person->occupation, occupation);

    return person;
}

void destroy_cyberperson(Cyberperson *person) {
    free(person->occupation);
    free(person);
}

int main() {
    Cyberperson *johnny = NULL;

    if (create_cyberperson("Johnny Mnemonic", 32, "Data Dealer") != NULL) {
        johnny = create_cyberperson("Jane Doe", 25, "Netrunner");

        if (johnny != NULL) {
            printf("Created Cyberperson %s (%d)\n", johnny->name, johnny->age);
            printf("Created Cyberperson %s (%d)\n", johnny->occupation);

            destroy_cyberperson(johnny);
        }

        printf("Created Cyberperson %s (%d)\n", johnny->name, johnny->age);
        printf("Created Cyberperson %s (%d)\n", johnny->occupation);

        destroy_cyberperson(johnny);
    }

    return EXIT_SUCCESS;
}