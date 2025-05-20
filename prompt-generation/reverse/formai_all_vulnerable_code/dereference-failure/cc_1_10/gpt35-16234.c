//FormAI DATASET v1.0 Category: Phone Book ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <sys/time.h>

#define PHONEBOOK_SIZE 100

struct contact {
    char name[50];
    char phone_number[20];
};

struct phonebook {
    struct contact contacts[PHONEBOOK_SIZE];
    int num_contacts;
};

struct phonebook pb;

int open_phonebook(const char* filename) {
    int fd = open(filename, O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        fprintf(stderr, "Error opening phonebook: %s\n", strerror(errno));
    }
    return fd;
}

int read_phonebook(int fd, struct phonebook* pb) {
    int bytes_read = read(fd, pb, sizeof(struct phonebook));
    if (bytes_read == -1) { 
        fprintf(stderr, "Error reading phonebook: %s\n", strerror(errno));
        return -1;
    }
    return bytes_read;
}

int write_phonebook(int fd, const struct phonebook* pb) {
    int bytes_written = write(fd, pb, sizeof(struct phonebook));
    if (bytes_written == -1) {
        fprintf(stderr, "Error writing phonebook: %s\n", strerror(errno));
        return -1;
    }
    return bytes_written;
}

void print_phonebook(const struct phonebook* pb) {
    printf("Name\tPhone number\n");
    for (int i = 0; i < pb->num_contacts; i++) {
        printf("%s\t%s\n", pb->contacts[i].name, pb->contacts[i].phone_number);
    }
}

bool add_contact(struct phonebook* pb, const char* name, const char* phone_number) {
    if (pb->num_contacts >= PHONEBOOK_SIZE) {
        fprintf(stderr, "Phonebook is full!\n");
        return false;
    }
    strcpy(pb->contacts[pb->num_contacts].name, name);
    strcpy(pb->contacts[pb->num_contacts].phone_number, phone_number);
    pb->num_contacts++;
    return true;
}

bool remove_contact(struct phonebook* pb, const char* name) {
    for (int i = 0; i < pb->num_contacts; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            pb->num_contacts--;
            pb->contacts[i] = pb->contacts[pb->num_contacts];
            memset(&pb->contacts[pb->num_contacts], 0, sizeof(struct contact));
            return true;
        }
    }
    fprintf(stderr, "Contact not found!\n");
    return false;
}

int main(int argc, char** argv) {
    int fd;
    fd_set rfds;
    struct timeval tv;
    int retval;
    char buffer[100];
    
    memset(&pb, 0, sizeof(struct phonebook));

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <phonebook file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fd = open_phonebook(argv[1]);

    if (read_phonebook(fd, &pb) == -1) {
        exit(EXIT_FAILURE);
    }

    while (true) {
        FD_ZERO(&rfds);
        FD_SET(STDIN_FILENO, &rfds);

        tv.tv_sec = 5;
        tv.tv_usec = 0;

        retval = select(STDIN_FILENO + 1, &rfds, NULL, NULL, &tv);
        
        if (retval == -1) {
            fprintf(stderr, "Error in select: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        } else if (retval > 0) {
            fgets(buffer, sizeof(buffer), stdin);

            if (strncmp(buffer, "quit", 4) == 0) {
                break;
            } else if (strncmp(buffer, "list", 4) == 0) {
                print_phonebook(&pb);
            } else if (strncmp(buffer, "add", 3) == 0) {
                char name[50];
                char phone_number[20];
                sscanf(buffer, "add %49[^,],%19s", name, phone_number);
                add_contact(&pb, name, phone_number);
            } else if (strncmp(buffer, "remove", 6) == 0) {
                char name[50];
                sscanf(buffer, "remove %49s", name);
                remove_contact(&pb, name);
            } else {
                printf("Invalid command!\n");
            }
        }
    }

    if (write_phonebook(fd, &pb) == -1) {
        exit(EXIT_FAILURE);
    }

    close(fd);

    return EXIT_SUCCESS;
}