//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_MESSAGE_SIZE 512

// Message structure for IPC
struct msg_buf {
    long mtype;
    char content[MAX_MESSAGE_SIZE];
};

// Function to convert string to lowercase
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to check if a word is in the dictionary
int check_word(const char *word, const char *dictionary_file) {
    FILE *fp = fopen(dictionary_file, "r");
    if (fp == NULL) {
        fprintf(stderr, "Could not open dictionary file.\n");
        return -1;
    }

    char dict_word[MAX_WORD_LENGTH];
    to_lowercase(word);
    while (fgets(dict_word, sizeof(dict_word), fp) != NULL) {
        dict_word[strcspn(dict_word, "\n")] = '\0'; // Remove newline character
        if (strcmp(dict_word, word) == 0) {
            fclose(fp);
            return 1; // Word found
        }
    }

    fclose(fp);
    return 0; // Word not found
}

// Function to process a chunk of text
void process_text(const char *text_chunk, const char *dictionary_file, int msg_queue_id) {
    char *token = strtok((char *)text_chunk, " \n");
    while (token != NULL) {
        if (!check_word(token, dictionary_file)) {
            struct msg_buf msg;
            msg.mtype = 1; // Message type
            snprintf(msg.content, sizeof(msg.content), "Misspelled word: %s", token);
            msgsnd(msg_queue_id, &msg, sizeof(msg.content), 0);
        }
        token = strtok(NULL, " \n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <text_file> <dictionary_file> <number_of_procs>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *text_file = argv[1];
    const char *dictionary_file = argv[2];
    int num_procs = atoi(argv[3]);
    
    FILE *fptr = fopen(text_file, "r");
    if (!fptr) {
        perror("Error opening text file");
        return EXIT_FAILURE;
    }

    struct msg_buf msg;
    key_t key = ftok("msg_queue_key", 65);
    int msg_queue_id = msgget(key, 0666 | IPC_CREAT);
    
    char buffer[MAX_MESSAGE_SIZE];
    int count = 0;

    // Divide text into chunks for processing
    while (fgets(buffer, sizeof(buffer), fptr) != NULL) {
        process_text(buffer, dictionary_file, msg_queue_id);
        count++;
        
        // If we reach the desired number of processes, wait for completion
        if (count % (MAX_MESSAGE_SIZE / num_procs) == 0) {
            sleep(1); // Simulating process time
        }
    }

    fclose(fptr);

    // Cleanup and print results
    for (int i = 0; i < count; i++) {
        msgrcv(msg_queue_id, &msg, sizeof(msg.content), 1, 0);
        printf("%s\n", msg.content);
    }

    // Remove the message queue
    msgctl(msg_queue_id, IPC_RMID, NULL);
    
    return EXIT_SUCCESS;
}