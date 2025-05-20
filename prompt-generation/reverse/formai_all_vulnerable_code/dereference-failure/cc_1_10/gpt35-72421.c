//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generate_random_numbers(int lower, int upper, int count) {
    int* numbers = (int*) malloc(count * sizeof(int));
    int num, i = 0;
    srand(time(0));
    while (i < count) {
        num = (rand() % (upper-lower+1)) + lower;
        int j = 0;
        while (j < i && num != numbers[j]) j++;
        if (j == i) {
            numbers[i] = num;
            i++;
        }
    } 
    return numbers;
}

void print_board(int* numbers) {
    printf("\t|---|---|---|---|---|\n");
    for (int i = 0; i < 5; i++) {
        printf("\t|");
        for (int j = 0; j < 5; j++) {
            if (i == 2 && j == 2)
                printf("###|");
            else
                printf(" %02d|", numbers[i*5+j]);
        }
        printf("\n\t|---|---|---|---|---|\n");
    }
}

int main() {
    printf("\nWelcome to Cyberpunk Bingo!\n");
    printf("\nGet ready to survive the neon-drenched streets of Night City with this twisted and exciting game.\n");
    printf("\nBut first, let's generate your lucky numbers!:\n\n");
    
    int* nums = generate_random_numbers(1, 75, 25);
    print_board(nums);
    
    int num_calls = 0;
    int bingo = 0;
    
    printf("\n\nPress enter to start the game...");
    getchar();
    
    while (!bingo) {
        printf("\n\nPress enter to call out the next number...");
        getchar();
        system("cls||clear");
        int num = nums[num_calls];
        printf("\nThe next number is: %d", num);
        num_calls++;
        
        printf("\n\nPlayer Board:\n\n");
        print_board(nums);
        
        char choice;
        printf("Do you have this number? (Y/N): ");
        scanf("%c", &choice);
        
        if (choice == 'Y' || choice == 'y') {
            int i = 0;
            while (i < 25 && nums[i] != num) i++;
            nums[i] = -1;
            printf("\nYou have crossed off %d!\n", num);
        }
        
        int rows[5] = {0, 0, 0, 0, 0};
        int cols[5] = {0, 0, 0, 0, 0};
        int diag1 = 0;
        int diag2 = 0;
        
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (i == j) {
                    diag1 += (nums[i*5+j] == -1);
                    diag2 += (nums[i*5+4-j] == -1);
                }
                rows[i] += (nums[i*5+j] == -1);
                cols[j] += (nums[i*5+j] == -1);
            }
        }
        
        for (int i = 0; i < 5; i++) {
            if (rows[i] == 5) {
                printf("\n\nBINGO! You have just won the game by completing row %d!\n\n", i+1);
                bingo = 1;
                break;
            }
            
            if (cols[i] == 5) {
                printf("\n\nBINGO! You have just won the game by completing column %d!\n\n", i+1);
                bingo = 1;
                break;
            }
        }
        
        if (diag1 == 5) {
            printf("\n\nBINGO! You have just won the game by completing the first diagonal!\n\n");
            bingo = 1;
        }
        
        if (diag2 == 5) {
            printf("\n\nBINGO! You have just won the game by completing the second diagonal!\n\n");
            bingo = 1;
        }
        
        if (!bingo && num_calls == 25) {
            printf("\n\nSorry, you have lost the game. Better luck next time!\n\n");
            break;
        }
    }
    
    free(nums);    

    return 0;
}