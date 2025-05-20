//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 100

// function to calculate checksum for a given string
unsigned int checksum(char str[])
{
    unsigned int sum = 0;
    int i;
    for(i=0; i<strlen(str); i++)
        sum += str[i];
    return sum;
}

int main()
{
    char message[MAX_LEN];
    int num_players;

    // get message and number of players
    printf("Enter the message: ");
    fgets(message, MAX_LEN, stdin);
    printf("Enter the number of players: ");
    scanf("%d", &num_players);

    // calculate checksum of original message
    unsigned int orig_sum = checksum(message);
    printf("Original checksum: %u\n", orig_sum);

    // divide the message into equal chunks for each player
    int len = strlen(message);
    int chunk_size = len / num_players;
    char *chunks[num_players];
    int i, j;
    for(i=0, j=0; i<num_players; i++, j+=chunk_size) {
        chunks[i] = (char *)malloc((chunk_size+1) * sizeof(char));
        strncpy(chunks[i], message+j, chunk_size);
        chunks[i][chunk_size] = '\0';
    }

    // send chunks to each player to calculate partial checksum
    unsigned int partial_sums[num_players];
    for(i=0; i<num_players; i++) {
        printf("Player %d received: %s\n", i+1, chunks[i]);
        partial_sums[i] = checksum(chunks[i]);
        printf("Partial checksum for Player %d: %u\n", i+1, partial_sums[i]);
    }

    // calculate final checksum by adding all partial checksums
    unsigned int final_sum = 0;
    for(i=0; i<num_players; i++)
        final_sum += partial_sums[i];
    printf("Final checksum: %u\n", final_sum);

    // check if final checksum matches the original checksum
    if(final_sum == orig_sum)
        printf("Checksum verification successful!\n");
    else
        printf("Checksum verification failed!\n");

    return 0;
}