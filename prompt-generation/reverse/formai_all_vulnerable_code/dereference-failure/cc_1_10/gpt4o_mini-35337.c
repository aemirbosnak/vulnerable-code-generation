//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
#include <string.h>
#include <time.h>

#define SHM_SIZE 256
#define WATCH_DOG_PEN "watchdog_pen"
#define HARLEQUIN "harlequin"
#define LIES "lies"
#define TRUTH "truth"

typedef struct {
    char message[SHM_SIZE];
    pid_t writer;
} shared_data;

void surreal_dance() {
    printf("The dance begins! Colors swirl and words tumble like leaves in a cosmic wind.\n");
    sleep(2);
    printf("The harlequin enters, juggling truths and lies, a whimsical laugh echoes.\n");
    sleep(2);
}

void handle_signals(int sig) {
    if (sig == SIGINT) {
        printf("\nThe harlequin gracefully exits the stage, bowing to unseen patrons.\n");
        exit(0);
    }
}

int main() {
    signal(SIGINT, handle_signals);
    
    key_t key = ftok(WATCH_DOG_PEN, 65);
    int shmid = shmget(key, sizeof(shared_data), 0666 | IPC_CREAT);
    shared_data *data = (shared_data *)shmat(shmid, NULL, 0);
    
    if (data == (shared_data *)(-1)) {
        fprintf(stderr, "A mirror shattered. Could not attach shared memory.\n");
        exit(1);
    }

    // Initialize the shared memory
    data->writer = getpid();
    strcpy(data->message, "The clock strikes, blending time and dreams.");

    // Fork the surreal child
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Bubbles burst! Fork failed.\n");
        exit(1);
    }
    
    if (pid == 0) {
        // Child process: The prisoner in the echo chamber
        srand(time(NULL) ^ getpid());
        while (1) {
            if (rand() % 3 == 0) {
                printf("Child whispers into the void: '%s'\n", data->message);
            }
            sleep(1);
        }
    } else {
        // Parent process: The watchful harlequin
        surreal_dance();

        for (int i = 0; i < 10; i++) {
            sprintf(data->message, "Echoing truth number [%d]: Together we weave a tapestry of light!", i);
            printf("Parent weaves a message into the universe: '%s'\n", data->message);
            sleep(2);
        }

        // Clean up
        shmdt(data);
        shmctl(shmid, IPC_RMID, NULL);
        return 0;
    }
}