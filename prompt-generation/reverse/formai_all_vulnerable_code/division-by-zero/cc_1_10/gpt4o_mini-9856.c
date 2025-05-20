//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_LEN 100
#define MAX_PROCESSES 10

int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

void compute_part(int start_row, int end_row, char *s1, char *s2, int result[][MAX_LEN]) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    for (int i = start_row; i <= end_row && i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                result[i][j] = j;  // Deletion
            } else if (j == 0) {
                result[i][j] = i;  // Insertion
            } else {
                int cost = (s1[i-1] == s2[j-1]) ? 0 : 1;
                result[i][j] = min(result[i-1][j] + 1,      // Deletion
                                   result[i][j-1] + 1,      // Insertion
                                   result[i-1][j-1] + cost); // Substitution
            }
        }
    }
}

int main() {
    char s1[MAX_LEN];
    char s2[MAX_LEN];
    int result[MAX_LEN][MAX_LEN] = {0};

    printf("Enter first string: ");
    fgets(s1, MAX_LEN, stdin);
    s1[strcspn(s1, "\n")] = 0; // Remove newline character
    
    printf("Enter second string: ");
    fgets(s2, MAX_LEN, stdin);
    s2[strcspn(s2, "\n")] = 0; // Remove newline character

    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int num_processes = (len1 < MAX_PROCESSES) ? len1 : MAX_PROCESSES;

    int chunk_size = (len1 + num_processes - 1) / num_processes; // ceil division
    pid_t pids[MAX_PROCESSES];

    for (int i = 0; i < num_processes; i++) {
        int start_row = i * chunk_size + 1;
        int end_row = (i + 1) * chunk_size;
        if (start_row > len1) break; // No more rows to compute
        if (end_row > len1) end_row = len1;

        pids[i] = fork();
        
        if (pids[i] < 0) {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        }
        
        if (pids[i] == 0) {
            compute_part(start_row, end_row, s1, s2, result);
            exit(EXIT_SUCCESS);
        }
    }

    // Parent process
    for (int i = 0; i < num_processes; i++) {
        if (pids[i] > 0) {
            waitpid(pids[i], NULL, 0); // Wait for child process to finish
        }
    }

    // Print the resulting matrix and return the last cell which is the distance
    printf("Levenshtein distance matrix:\n");
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (j == 0 && i == 0) {
                continue; // Skip cell for (0,0)
            }
            if (i == 0 || j == 0) {
                printf("%d ", result[i][j]);
            } else {
                printf("%d ", result[i][j]);
            }
        }
        printf("\n");
    }

    printf("Levenshtein distance: %d\n", result[len1][len2]);
    return 0;
}