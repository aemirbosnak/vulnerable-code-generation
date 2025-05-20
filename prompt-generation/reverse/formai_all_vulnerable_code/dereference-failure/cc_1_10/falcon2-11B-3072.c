//Falcon2-11B DATASET v1.0 Category: Compression algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char* input = "abracadabra";
    char* output = (char*)malloc(strlen(input) + 1);
    int count, i, j;
    int num_chars, num_runs, max_run_length;
    int* run_lengths = (int*)malloc(sizeof(int));

    count = 0;
    num_chars = 0;
    num_runs = 0;
    max_run_length = 0;
    run_lengths[0] = 0;
    for (i = 0; i < strlen(input); i++) {
        if (input[i]!= input[i+1]) {
            if (run_lengths[num_runs] == 0) {
                num_chars++;
            }
            count++;
            num_runs++;
            run_lengths[num_runs] = 1;
            if (num_chars > max_run_length) {
                max_run_length = num_chars;
            }
        } else {
            run_lengths[num_runs]++;
        }
    }
    if (num_runs == 1) {
        run_lengths[num_runs] = max_run_length;
    }
    for (i = 0; i < num_runs; i++) {
        for (j = 0; j < run_lengths[i]; j++) {
            output[count++] = input[i];
        }
    }
    output[count] = '\0';

    printf("Input: %s\n", input);
    printf("Output: %s\n", output);

    free(input);
    free(output);
    free(run_lengths);

    return 0;
}