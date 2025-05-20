//Falcon2-11B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: visionary
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

struct read_info {
    char name[100];
    int start;
    int length;
};

int Read_Seq(struct read_info* read_info, FILE* infile) {
    int count = 0;
    int ch;

    while ((ch = fgetc(infile))!= EOF) {
        if (ch == '>') {
            count++;
        } else {
            read_info->start = ftell(infile);
            read_info->length = 0;
            while ((ch = fgetc(infile))!= EOF) {
                read_info->length++;
            }
            read_info->length--;
            fseek(infile, read_info->start, SEEK_SET);
        }
    }

    return count;
}

int main() {
    struct read_info reads[1000];
    int nreads = 0;

    FILE* infile = fopen("read_info.txt", "r");
    if (infile == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    FILE* outfile = fopen("output.txt", "w");
    if (outfile == NULL) {
        printf("Error opening output file\n");
        return 1;
    }

    while (Read_Seq(reads, infile) > 0) {
        nreads++;
        fprintf(outfile, "%s\n", reads[nreads].name);
        fwrite(reads[nreads].name, sizeof(char), strlen(reads[nreads].name), outfile);
        fwrite(reads[nreads].start, sizeof(int), 4, outfile);
        fwrite(&reads[nreads].length, sizeof(int), 4, outfile);
    }

    fclose(infile);
    fclose(outfile);

    printf("Read %d reads from file\n", nreads);
    return 0;
}