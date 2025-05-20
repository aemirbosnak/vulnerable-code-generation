//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the buffer
#define BUF_SIZE 1000000

// Define the number of iterations to perform
#define NUM_ITER 1000

int main()
{
    // Define the input and output buffers
    char* in_buf = (char*)malloc(BUF_SIZE);
    char* out_buf = (char*)malloc(BUF_SIZE);

    // Initialize the input buffer with random data
    srand(time(0));
    for (int i = 0; i < BUF_SIZE; i++)
    {
        in_buf[i] = rand();
    }

    // Perform the compression NUM_ITER times
    for (int iter = 0; iter < NUM_ITER; iter++)
    {
        // Reset the output buffer
        memset(out_buf, 0, BUF_SIZE);

        // Perform the compression
        int in_pos = 0;
        int out_pos = 0;
        while (in_pos < BUF_SIZE)
        {
            // Find the length of the current run of bytes
            int len = 1;
            while ((in_pos + len < BUF_SIZE) && (in_buf[in_pos + len] == in_buf[in_pos]))
            {
                len++;
            }

            // Write the length and the byte value to the output buffer
            out_buf[out_pos++] = len;
            out_buf[out_pos++] = in_buf[in_pos];

            // Move to the next run of bytes
            in_pos += len;
        }
    }

    // Free the input and output buffers
    free(in_buf);
    free(out_buf);

    return 0;
}