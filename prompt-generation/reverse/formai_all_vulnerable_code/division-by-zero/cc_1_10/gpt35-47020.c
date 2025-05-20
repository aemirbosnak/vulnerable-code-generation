//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c_length, read_len, i, j, k, current_pos, matches, mismatch, gaps;
    char c_seq[1000], read[100];
    
    // Input the genome sequence and its length
    printf("Enter the dna sequence: ");
    scanf("%s", c_seq);
    c_length = strlen(c_seq);
    
    // Input the read length
    printf("Enter the read length: ");
    scanf("%d", &read_len);
    
    // Generate random starting position for simulating reads
    srand(time(NULL));
    current_pos = rand() % (c_length - read_len + 1);
    
    // Keep generating reads until end of genome is reached
    while(current_pos <= c_length - read_len)
    {
        // Generate read from current position
        for(i=0; i<read_len; i++)
        {
            read[i] = c_seq[current_pos+i];
        }
        read[read_len] = '\0';
        
        // Display the generated read
        printf("Read generated from position %d: %s\n", current_pos, read);
        
        // Count the number of matches, mismatches and gaps in the read
        matches = 0;
        mismatch = 0;
        gaps = 0;
        for(i=0; i<read_len; i++)
        {
            if(read[i] == c_seq[current_pos+i])
            {
                matches++;
            }
            else if(read[i] == '-' || c_seq[current_pos+i] == '-')
            {
                gaps++;
            }
            else
            {
                mismatch++;
            }
        }
        
        // Display the match statistics for the read
        printf("Match: %d, Mismatch: %d, Gaps: %d\n\n", matches, mismatch, gaps);
        
        // Change position to simulate next read
        current_pos += rand() % read_len + 1;
    }
    
    return 0;
}