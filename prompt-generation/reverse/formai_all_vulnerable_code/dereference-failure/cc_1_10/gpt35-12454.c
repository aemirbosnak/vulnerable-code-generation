//FormAI DATASET v1.0 Category: File Synchronizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <dirent.h>
#include <pthread.h>

// function to check if a file exists
int check_file_exists(char *filename)
{
    if (access(filename, F_OK) != -1)
        return 1;
    else
        return 0;
}

// function to get the list of files in a directory
int get_file_list(char *directory, char ***file_list, int *file_count)
{
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir(directory)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_type == DT_REG) {
                *file_count += 1;
                *file_list = realloc(*file_list, (*file_count) * sizeof(char*));
                (*file_list)[*file_count - 1] = malloc(strlen(ent->d_name) + 1);
                strcpy((*file_list)[*file_count - 1], ent->d_name);
            }
        }
        closedir(dir);
        return 1;
    } else {
        return 0;
    }
}

// function to synchronize a file from peer to local directory
void synchronize_file(char *peer_address, char *filename)
{
    char command[100];

    sprintf(command, "scp %s:%s ./", peer_address, filename);
    system(command);
}

// function to synchronize all files from peer to local directory
void synchronize_all_files(char *peer_address, char **file_list, int file_count)
{
    int i;

    for (i = 0; i < file_count; i++) {
        synchronize_file(peer_address, file_list[i]);
    }
}

// function to synchronize a file from local directory to peer
void synchronize_file_to_peer(char *peer_address, char *filename)
{
    char command[100];

    sprintf(command, "scp %s ./ %s:", filename, peer_address);
    system(command);
}

// function to synchronize all files from local directory to peer
void synchronize_all_files_to_peer(char *peer_address, char **file_list, int file_count)
{
    int i;

    for (i = 0; i < file_count; i++) {
        synchronize_file_to_peer(peer_address, file_list[i]);
    }
}

// thread function to synchronize files from peer to local directory periodically
void* sync_files_from_peer(void* arg)
{
    char *peer_address = (char*) arg;
    char **file_list;
    int file_count = 0;

    while (1) {
        // get the list of files in the peer directory
        file_list = NULL;
        file_count = 0;
        get_file_list(peer_address, &file_list, &file_count);

        // synchronize all files that are not already in the local directory
        int i;
        for (i = 0; i < file_count; i++) {
            if (!check_file_exists(file_list[i])) {
                synchronize_file(peer_address, file_list[i]);
            }
        }

        // free the memory for file_list
        for (i = 0; i < file_count; i++) {
            free(file_list[i]);
        }
        free(file_list);

        // sleep for 10 seconds before next synchronization
        sleep(10);
    }

    return NULL;
}

// thread function to synchronize files from local directory to peer periodically
void* sync_files_to_peer(void* arg)
{
    char *peer_address = (char*) arg;
    char **file_list;
    int file_count = 0;

    while (1) {
        // get the list of files in the local directory
        file_list = NULL;
        file_count = 0;
        get_file_list(".", &file_list, &file_count);

        // synchronize all files that are not already in the peer directory
        int i;
        for (i = 0; i < file_count; i++) {
            if (!check_file_exists(file_list[i])) {
                synchronize_file_to_peer(peer_address, file_list[i]);
            }
        }

        // free the memory for file_list
        for (i = 0; i < file_count; i++) {
            free(file_list[i]);
        }
        free(file_list);

        // sleep for 10 seconds before next synchronization
        sleep(10);
    }

    return NULL;
}

// main function
int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <peer_address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *peer_address = argv[1];
    pthread_t thread_from_peer, thread_to_peer;

    // create thread to synchronize files from peer to local directory
    if (pthread_create(&thread_from_peer, NULL, sync_files_from_peer, peer_address) != 0) {
        fprintf(stderr, "Error creating synchronization thread from peer\n");
        exit(EXIT_FAILURE);
    }

    // create thread to synchronize files from local directory to peer
    if (pthread_create(&thread_to_peer, NULL, sync_files_to_peer, peer_address) != 0) {
        fprintf(stderr, "Error creating synchronization thread to peer\n");
        exit(EXIT_FAILURE);
    }

    // wait for the threads to complete
    pthread_join(thread_from_peer, NULL);
    pthread_join(thread_to_peer, NULL);

    return 0;
}