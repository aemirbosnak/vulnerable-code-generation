//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/time.h>

// Custom data type for our shared memory segment
typedef struct {
    int x;
    char name[100];
} shm_data;

// Function to create a shared memory segment
int create_shared_memory(int size) {
    // Allocate the shared memory segment using the shmget() system call.
    int shm_id = shmget(IPC_PRIVATE, size, IPC_CREAT | IPC_EXCL | 0666);
    if (shm_id < 0) {
        perror("shmget failed");
        exit(1);
    }
    return shm_id;
}

// Function to attach the shared memory segment to the current process
void *attach_shared_memory(int shm_id) {
    // Attach the shared memory segment to the current process using the shmat() system call.
    shm_data *shm_ptr = (shm_data *)shmat(shm_id, 0, 0);
    if (shm_ptr == (shm_data *)-1) {
        perror("shmat failed");
        exit(1);
    }
    return shm_ptr;
}

// Function to initialize the shared memory segment
void initialize_shared_memory(shm_data *shm_ptr) {
    // Set the initial values for the shared data.
    shm_ptr->x = 0;
    strcpy(shm_ptr->name, "Uninitialized");
}

// Function to read the shared memory segment
void read_shared_memory(shm_data *shm_ptr) {
    // Print the current values of the shared data.
    printf("shm_ptr->x: %d\n", shm_ptr->x);
    printf("shm_ptr->name: %s\n\n", shm_ptr->name);
}

// Function to write to the shared memory segment
void write_to_shared_memory(shm_data *shm_ptr) {
    // Prompt the user for new values and update the shared data.
    printf("Enter a new value for shm_ptr->x: ");
    scanf("%d", &shm_ptr->x);
    printf("Enter a new value for shm_ptr->name: ");
    scanf("%s", shm_ptr->name);
}

// Main function
int main() {
    // Create a shared memory segment.
    int shm_id = create_shared_memory(sizeof(shm_data));

    // Attach the shared memory segment to the current process.
    shm_data *shm_ptr = (shm_data *)attach_shared_memory(shm_id);

    // Initialize the shared memory segment.
    initialize_shared_memory(shm_ptr);

    // Read the shared memory segment initially.
    printf("Initial values of the shared memory segment:\n");
    read_shared_memory(shm_ptr);

    // Keep modifying and reading the shared memory data until the user presses Ctrl+C.
    while (1) {
        printf("-------------------------------------\n");
        printf("1. Read the shared memory segment\n");
        printf("2. Write to the shared memory segment\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                read_shared_memory(shm_ptr);
                break;
            case 2:
                write_to_shared_memory(shm_ptr);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid choice from 1 to 3.\n");
        }
    }

    // Detach the shared memory segment from the current process.
    shmdt(shm_ptr);

    // Delete the shared memory segment.
    shmctl(shm_id, IPC_RMID, NULL);

    return 0;
}