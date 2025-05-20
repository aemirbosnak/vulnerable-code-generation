//MISTRAL-7B DATASET v1.0 Category: File system simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/sysmacros.h>

typedef struct fileNode {
    char name[256];
    int size;
    struct fileNode *next;
    dev_t dev;
} FileNode;

FileNode *root = NULL;

void createFile(char *name, int size, dev_t dev) {
    FileNode *newNode = (FileNode *) malloc(sizeof(FileNode));
    strcpy(newNode->name, name);
    newNode->size = size;
    newNode->next = root;
    newNode->dev = dev;
    root = newNode;
}

void listFiles() {
    FileNode *current = root;
    printf("Curious File System:\n");
    printf("----------------------\n");
    while (current != NULL) {
        printf("%s (%d bytes) - Device %ld\n", current->name, current->size, (long int) current->dev);
        current = current->next;
    }
}

int main(int argc, char *argv[]) {
    int i;
    if (argc < 2) {
        printf("Usage: %s COMMAND [ARG1] [ARG2] ...\n", argv[0]);
        printf("Commands:\n");
        printf("  create <filename> <size> <device>\n");
        printf("  list\n");
        printf("  exit\n");
        return 1;
    }

    char command[10];
    strncpy(command, argv[1], 9);
    command[9] = '\0';

    switch (strcmp(command, "create")) {
        case 0:
            if (argc < 4) {
                printf("create: missing arguments (filename, size, device)\n");
                return 1;
            }
            createFile(argv[2], atoi(argv[3]), makedev(0, atoi(argv[4])));
            break;

        case 1:
            if (argc > 2) {
                printf("list: too many arguments\n");
                return 1;
            }
            listFiles();
            break;

        case 2:
            exit(0);
            break;

        default:
            printf("Unknown command: %s\n", command);
            return 1;
    }

    main(argc, argv); // Recursive call to simulate multi-threading or multi-process environment
}