//Falcon2-11B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: accurate
#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE* fptr;
    char read[100];
    int i, j, k;
    int num_reads = 0;
    int num_nucleotides = 0;
    int num_contigs = 0;
    int contig_length[100];
    int contig_num[100];
    int read_length[100];
    int num_bases = 0;
    int base[100][4] = {{0,0,0,0}};
    int start_read[100] = {0};
    int end_read[100] = {0};
    int contig_start[100] = {0};
    int contig_end[100] = {0};
    int contig_base[100][4] = {{0,0,0,0}};

    fptr = fopen("input.txt", "r");
    while (fgets(read, 100, fptr)!= NULL)
    {
        num_reads++;
        i = 0;
        while (read[i]!= '\n')
        {
            num_nucleotides++;
            base[num_reads][i] = read[i] - 'A';
            i++;
        }
        start_read[num_reads] = i;
        end_read[num_reads] = num_nucleotides - 1;
        num_bases += num_nucleotides;
        i = 0;
        while (i < num_reads - 1)
        {
            if (start_read[i] == start_read[i + 1] && end_read[i] == end_read[i + 1])
            {
                contig_num[num_contigs] = i + 1;
                contig_length[num_contigs] = end_read[i + 1] - start_read[i] + 1;
                contig_start[num_contigs] = start_read[i];
                contig_end[num_contigs] = end_read[i + 1];
                i++;
                while (i < num_reads - 1 && start_read[i] == start_read[i + 1] && end_read[i] == end_read[i + 1])
                {
                    contig_num[num_contigs] = i + 1;
                    contig_length[num_contigs] = end_read[i + 1] - start_read[i] + 1;
                    contig_start[num_contigs] = start_read[i];
                    contig_end[num_contigs] = end_read[i + 1];
                    i++;
                }
                num_contigs++;
            }
            i++;
        }
    }
    printf("Total number of reads: %d\n", num_reads);
    printf("Total number of nucleotides: %d\n", num_nucleotides);
    printf("Total number of contigs: %d\n", num_contigs);
    printf("Total length of contigs: %d\n", num_bases);

    for (i = 0; i < num_contigs; i++)
    {
        printf("Contig %d: %d nucleotides\n", i + 1, contig_length[i]);
        for (j = contig_start[i]; j <= contig_end[i]; j++)
        {
            printf("%c", base[i][j]);
        }
        printf("\n");
    }
    return 0;
}