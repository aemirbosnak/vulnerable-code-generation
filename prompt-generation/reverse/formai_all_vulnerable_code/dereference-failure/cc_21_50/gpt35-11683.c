//FormAI DATASET v1.0 Category: Data mining ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 200
#define MAX_NUM_COLUMNS 20
#define MAX_FILE_NAME_LENGTH 100

int main() {
    char file_name[MAX_FILE_NAME_LENGTH], delimiter;
    int min_support, num_transactions, num_columns, i, j, k;

    // Get user input for file name, delimiter, and minimum support
    printf("Enter the file name: ");
    scanf("%s", file_name);

    printf("Enter the delimiter: ");
    scanf(" %c", &delimiter);

    printf("Enter the minimum support: ");
    scanf("%d", &min_support);

    // Open the file and read in the data
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("\nError opening file\n\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    char* token;

    // Read in the first line to get the number of columns
    fgets(line, MAX_LINE_LENGTH, file);
    num_columns = 0;

    token = strtok(line, &delimiter);
    while (token != NULL) {
        num_columns++;
        token = strtok(NULL, &delimiter);
    }

    // Create the matrix to store the data
    int** data = (int**) malloc(MAX_NUM_COLUMNS * sizeof(int*));
    for (i = 0; i < MAX_NUM_COLUMNS; i++) {
        data[i] = (int*) malloc(num_columns * sizeof(int));
    }

    // Store the data in the matrix
    num_transactions = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        token = strtok(line, &delimiter);

        j = 0;
        while (token != NULL) {
            data[j][num_transactions] = atoi(token);
            j++;
            token = strtok(NULL, &delimiter);
        }

        num_transactions++;
    }

    fclose(file);

    // Create the auxillary matrix to store the counts
    int** counts = (int**) malloc(MAX_NUM_COLUMNS * sizeof(int*));
    for (i = 0; i < MAX_NUM_COLUMNS; i++) {
        counts[i] = (int*) calloc(num_columns, sizeof(int));
    }

    // Count the frequency of each item
    for (i = 0; i < num_transactions; i++) {
        for (j = 0; j < num_columns; j++) {
            if (data[j][i] == 1) {
                counts[j][0]++;
            }
        }
    }

    // Create the frequent itemsets
    int num_freq_itemsets = 0;
    int freq_itemsets[MAX_NUM_COLUMNS];

    for (i = 0; i < num_columns; i++) {
        if (counts[i][0] >= min_support) {
            freq_itemsets[num_freq_itemsets] = i;
            num_freq_itemsets++;
        }
    }

    // Loop through and generate the candidate itemsets
    int* candidate_itemsets[MAX_NUM_COLUMNS];
    int num_candidate_itemsets[MAX_NUM_COLUMNS];

    for (i = 0; i < MAX_NUM_COLUMNS; i++) {
        candidate_itemsets[i] = (int*) malloc(num_freq_itemsets * sizeof(int));
    }

    for (k = 2; k <= num_columns; k++) {
        // Generate the candidate itemsets of length k
        for (i = 0; i < num_freq_itemsets; i++) {
            for (j = i + 1; j < num_freq_itemsets; j++) {
                int match = 1;

                // Check if the first k-2 elements match
                for (int l = 0; l < k - 2; l++) {
                    if (candidate_itemsets[l][i] != candidate_itemsets[l][j]) {
                        match = 0;
                        break;
                    }
                }

                // If they match, add the new itemset to the list of candidates
                if (match == 1) {
                    candidate_itemsets[k - 1][num_candidate_itemsets[k - 1]] = freq_itemsets[i];
                    candidate_itemsets[k - 1][num_candidate_itemsets[k - 1] + 1] = freq_itemsets[j];
                    num_candidate_itemsets[k - 1]++;
                }
            }
        }

        // Count the frequency of each candidate itemset
        for (i = 0; i < num_transactions; i++) {
            for (j = 0; j < num_candidate_itemsets[k - 1]; j++) {
                int match = 1;

                // Check if all elements in the candidate itemset are present in the transaction
                for (int l = 0; l < k; l++) {
                    if (data[candidate_itemsets[l][j]][i] != 1) {
                        match = 0;
                        break;
                    }
                }

                // If they match, increment the count
                if (match == 1) {
                    counts[j][k - 1]++;
                }
            }
        }

        // Generate the frequent itemsets of length k
        num_freq_itemsets = 0;

        for (i = 0; i < num_candidate_itemsets[k - 1]; i++) {
            if (counts[i][k - 1] >= min_support) {
                freq_itemsets[num_freq_itemsets] = i;
                num_freq_itemsets++;
            }
        }

        // If no frequent itemsets were found, exit
        if (num_freq_itemsets == 0) {
            break;
        }
    }

    printf("\nFrequent itemsets:\n");

    // Print the frequent itemsets
    for (i = 0; i < num_columns; i++) {
        if (counts[i][0] >= min_support) {
            printf("{%d} ", i);
        }
    }

    for (k = 2; k <= num_columns; k++) {
        for (i = 0; i < num_freq_itemsets; i++) {
            if (counts[i][k - 1] >= min_support) {
                printf("{");

                for (j = 0; j < k; j++) {
                    printf("%d", candidate_itemsets[j][i]);

                    if (j != k - 1) {
                        printf(", ");
                    }
                }

                printf("} ");
            }
        }
    }

    printf("\n\n");

    return 0;
}