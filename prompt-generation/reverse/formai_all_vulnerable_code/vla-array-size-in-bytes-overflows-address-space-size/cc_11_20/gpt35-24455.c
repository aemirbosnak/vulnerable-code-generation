//FormAI DATASET v1.0 Category: File system simulation ; Style: surprised
#include <stdio.h>

int main() {
    printf("Oh my filesystem!\n");
    printf("This is one heck of a program!\n");
    printf("Let's start with declaring our disk size.\n");

    int diskSize;
    printf("Enter your desired disk size (in MB): ");
    scanf("%d", &diskSize);
    printf("Great! We have a %dMB disk now.\n", diskSize);

    // Create a 2D array to represent our file system
    int fs[diskSize][1024];
    printf("Our filesystem has been created with %d blocks of 1024 bytes each.\n", diskSize);

    printf("Let's create a file now.\n");
    printf("Enter the name of your file: ");

    char fileName[20];
    scanf("%s", fileName);
    printf("File %s has been created.\n", fileName);

    printf("Time to write data to %s.\n", fileName);
    printf("How many bytes do you want to write? (up to 1024 bytes)\n");

    int bytes;
    scanf("%d", &bytes);
    printf("Please enter the data you want to write:\n");

    // Create a buffer to store our data
    char data[1024];
    scanf("%s", data);

    // Write our data to the first available block
    for (int i = 0; i < diskSize; i++) {
        if (fs[i][0] == 0) {
            // This block is available
            for (int j = 0; j < bytes; j++) {
                fs[i][j] = (int)data[j];
            }
            printf("Data has been written to block %d.\n", i);
            break;
        }
    }

    printf("Would you like to read a file? (y/n)\n");

    char response;
    scanf(" %c", &response);

    if (response == 'y') {
        printf("Enter the name of the file you want to read:\n");

        char readFileName[20];
        scanf("%s", readFileName);

        // Find the block containing our file
        int blockNumber = -1;
        for (int i = 0; i < diskSize; i++) {
            if (fs[i][0] == (int)readFileName[0]) {
                // This block might contain our file
                for (int j = 0; j < 20; j++) {
                    if (fs[i][j] != (int)readFileName[j]) {
                        break;
                    }
                    if (j == 19) {
                        // This is our file
                        printf("File found at block %d.\n", i);
                        blockNumber = i;
                    }
                }
            }
        }

        if (blockNumber == -1) {
            printf("File not found.\n");
        } else {
            printf("Reading file %s:\n", readFileName);
            for (int i = 0; i < 1024; i++) {
                if (fs[blockNumber][i] == 0) {
                    break;
                }
                printf("%c", (char)fs[blockNumber][i]);
            }
        }
    }

    printf("Thanks for using our filesystem!\n");

    return 0;
}