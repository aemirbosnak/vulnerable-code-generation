//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of candidates and voters
#define NUM_CANDIDATES 5
#define NUM_VOTERS 100

// Define the candidate names
char *candidate_names[] = {"Alice", "Bob", "Carol", "Dave", "Eve"};

// Define the voter names
char *voter_names[] = {
    "Adam", "Barbara", "Chris", "Diana", "Edward", "Frank", "Gloria", "Henry", "Ida", "Jack", "Karen",
    "Larry", "Mary", "Nancy", "Oliver", "Patricia", "Quinn", "Richard", "Sarah", "Tom", "Ursula", "Victor",
    "Wanda", "Xavier", "Yvonne", "Zachary"
};

// Define the ballot structure
typedef struct {
    char *candidate_name;
    int num_votes;
} ballot;

// Define the voting system structure
typedef struct {
    ballot *ballots;
    int num_ballots;
} voting_system;

// Create a new voting system
voting_system *create_voting_system() {
    voting_system *system = malloc(sizeof(voting_system));
    system->ballots = malloc(NUM_VOTERS * sizeof(ballot));
    system->num_ballots = 0;
    return system;
}

// Destroy a voting system
void destroy_voting_system(voting_system *system) {
    free(system->ballots);
    free(system);
}

// Add a ballot to the voting system
void add_ballot(voting_system *system, char *candidate_name) {
    system->ballots[system->num_ballots].candidate_name = candidate_name;
    system->ballots[system->num_ballots].num_votes = 0;
    system->num_ballots++;
}

// Count the votes for each candidate
void count_votes(voting_system *system) {
    for (int i = 0; i < system->num_ballots; i++) {
        for (int j = 0; j < NUM_CANDIDATES; j++) {
            if (strcmp(system->ballots[i].candidate_name, candidate_names[j]) == 0) {
                system->ballots[i].num_votes++;
            }
        }
    }
}

// Find the winner of the election
char *find_winner(voting_system *system) {
    int max_votes = 0;
    char *winner_name = NULL;
    for (int i = 0; i < system->num_ballots; i++) {
        if (system->ballots[i].num_votes > max_votes) {
            max_votes = system->ballots[i].num_votes;
            winner_name = system->ballots[i].candidate_name;
        }
    }
    return winner_name;
}

// Print the results of the election
void print_results(voting_system *system) {
    printf("Election Results:\n");
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidate_names[i], system->ballots[i].num_votes);
    }
    printf("Winner: %s\n", find_winner(system));
}

// Main function
int main() {
    // Create a new voting system
    voting_system *system = create_voting_system();

    // Add ballots to the voting system
    srand(time(NULL));
    for (int i = 0; i < NUM_VOTERS; i++) {
        add_ballot(system, candidate_names[rand() % NUM_CANDIDATES]);
    }

    // Count the votes
    count_votes(system);

    // Print the results of the election
    print_results(system);

    // Destroy the voting system
    destroy_voting_system(system);

    return 0;
}