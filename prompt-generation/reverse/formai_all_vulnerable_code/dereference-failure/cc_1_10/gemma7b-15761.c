//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_CANDIDATES 10

typedef struct Candidate
{
    char name[20];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];

int main()
{
    int fd, i, j, votes, candidate_id;
    char ballot_paper[20];

    // Initialize candidates
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        candidates[i].votes = 0;
    }

    // Open the ballot box
    fd = open("ballot_box.txt", O_CREAT | O_RDWR);
    if (fd == -1)
    {
        perror("Error opening ballot box");
        exit(1);
    }

    // Read the ballot paper
    read(fd, ballot_paper, 20);

    // Validate the ballot paper
    if (strlen(ballot_paper) != 20)
    {
        perror("Invalid ballot paper");
        exit(1);
    }

    // Count the votes
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        candidate_id = ballot_paper[i] - 'a';
        if (candidate_id >= 0 && candidate_id < MAX_CANDIDATES)
        {
            candidates[candidate_id].votes++;
        }
    }

    // Print the results
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("%s has %d votes.\n", candidates[i].name, candidates[i].votes);
    }

    // Close the ballot box
    close(fd);

    return 0;
}