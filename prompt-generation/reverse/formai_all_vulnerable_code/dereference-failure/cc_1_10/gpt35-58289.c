//FormAI DATASET v1.0 Category: File Synchronizer ; Style: puzzling
#include <stdio.h>
#include <string.h>

void print_puzzle(int num_moves, char from, char to, char using){
    printf("Move %d: Move disk from %c to %c using %c\n", num_moves, from, to, using);
}

void hanoi(int num_disks, char from, char to, char using, int *num_moves){
    if(num_disks == 1){
        (*num_moves)++;
        print_puzzle(*num_moves, from, to, using);
        return;
    }
    hanoi(num_disks-1, from, using, to, num_moves);
    (*num_moves)++;
    print_puzzle(*num_moves, from, to, using);
    hanoi(num_disks-1, using, to, from, num_moves);
}

void sync_files(char *file1, char *file2){
    printf("Synchronizing %s and %s...\n", file1, file2);
    FILE *fp1 = fopen(file1, "r");
    FILE *fp2 = fopen(file2, "r");
    if(fp1 == NULL){
        printf("Error opening %s\n", file1);
        return;
    }
    if(fp2 == NULL){
        printf("Error opening %s\n", file2);
        return;
    }
    char ch1 = fgetc(fp1);
    char ch2 = fgetc(fp2);
    int diff_count = 0;
    while (ch1 != EOF || ch2 != EOF){
        if(ch1 != ch2){
            printf("\nDifference found at position %d\n", diff_count+1);
            printf("%s: %c\n", file1, ch1);
            printf("%s: %c\n", file2, ch2);
            printf("Synchronizing...\n");
            int moves = 0;
            hanoi(diff_count+1, 'A', 'C', 'B', &moves);
            printf("Synchronization completed!\n");
            return;
        }
        diff_count++;
        ch1 = fgetc(fp1);
        ch2 = fgetc(fp2);
    }
    printf("Files are identical!\n");
    fclose(fp1);
    fclose(fp2);
}

int main(){
    char file1[] = "file1.txt";
    char file2[] = "file2.txt";
    sync_files(file1, file2);
    return 0;
}