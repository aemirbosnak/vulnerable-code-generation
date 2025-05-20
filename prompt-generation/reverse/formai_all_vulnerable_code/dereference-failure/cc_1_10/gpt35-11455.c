//FormAI DATASET v1.0 Category: Sudoku solver ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

#define SIZE 9

int sudoku[SIZE][SIZE] = {
    {0, 0, 4, 7, 0, 0, 0, 0, 3},
    {0, 0, 6, 0, 0, 0, 0, 8, 0},
    {7, 0, 0, 6, 0, 3, 0, 0, 0},
    {2, 9, 0, 0, 0, 0, 7, 3, 0},
    {0, 0, 0, 0, 9, 0, 0, 0, 0},
    {0, 0, 7, 0, 0, 0, 0, 5, 1},
    {0, 0, 0, 1, 0, 2, 0, 0, 4},
    {0, 4, 0, 5, 0, 0, 1, 0, 0},
    {8, 0, 0, 0, 0, 9, 3, 0, 0}
};

int row_valid[SIZE][SIZE+1], col_valid[SIZE][SIZE+1], square_valid[SIZE][SIZE+1];

typedef struct
{
    int row;
    int col;
} parameters;

void *validate_row(void *param)
{
    parameters *params = param;
    int row = params->row;
    int found[SIZE+1] = {0};

    for(int i=0; i<SIZE; ++i)
    {
        int val = sudoku[row][i];
        if(val && found[val])
        {
            printf("\nrow %d is invalid!\n", row);
            pthread_exit(NULL);
        }
        found[val] = 1;
    }

    printf("\nrow %d is valid!\n", row);
    pthread_exit(NULL);
}

void *validate_col(void *param)
{
    parameters *params = param;
    int col = params->col;
    int found[SIZE+1] = {0};

    for(int i=0; i<SIZE; ++i)
    {
        int val = sudoku[i][col];
        if(val && found[val])
        {
            printf("\ncol %d is invalid!\n", col);
            pthread_exit(NULL);
        }
        found[val] = 1;
    }

    printf("\ncol %d is valid!\n", col);
    pthread_exit(NULL);
}

void *validate_square(void *param)
{
    parameters *params = param;
    int square = params->row;
    int found[SIZE+1] = {0};

    int row_start = (square / 3) * 3;
    int col_start = (square % 3) * 3;

    for(int i=row_start; i<row_start+3; ++i)
    {
        for(int j=col_start; j<col_start+3; ++j)
        {
            int val = sudoku[i][j];
            if(val && found[val])
            {
                printf("\nsquare %d is invalid!\n", square);
                pthread_exit(NULL);
            }
            found[val] = 1;
        }
    }

    printf("\nsquare %d is valid!\n", square);
    pthread_exit(NULL);
}

int main()
{
    pthread_t row_threads[SIZE], col_threads[SIZE], square_threads[SIZE];
    int rc, i, j;

    // Initialize valid arrays
    for(i=0; i<SIZE; ++i)
    {
        for(j=0; j<SIZE+1; ++j)
        {
            row_valid[i][j] = 0;
            col_valid[i][j] = 0;
            square_valid[i][j] = 0;
        }
    }

    // Create threads for rows
    for(i=0; i<SIZE; ++i)
    {
        parameters *params = malloc(sizeof(parameters));
        params->row = i;

        rc = pthread_create(&row_threads[i], NULL, validate_row, (void *)params);

        if(rc)
        {
            printf("Error: return code from pthread_create() is %d\n", rc);
            return 1;
        }
    }

    // Create threads for columns
    for(i=0; i<SIZE; ++i)
    {
        parameters *params = malloc(sizeof(parameters));
        params->col = i;

        rc = pthread_create(&col_threads[i], NULL, validate_col, (void *)params);

        if(rc)
        {
            printf("Error: return code from pthread_create() is %d\n", rc);
            return 1;
        }
    }

    // Create threads for squares
    for(i=0; i<SIZE; ++i)
    {
        parameters *params = malloc(sizeof(parameters));
        params->row = i;

        rc = pthread_create(&square_threads[i], NULL, validate_square, (void *)params);

        if(rc)
        {
            printf("Error: return code from pthread_create() is %d\n", rc);
            return 1;
        }
    }

    // Wait for all threads to finish
    for(i=0; i<SIZE; ++i)
    {
        pthread_join(row_threads[i], NULL);
        pthread_join(col_threads[i], NULL);
        pthread_join(square_threads[i], NULL);
    }

    printf("\nFinished validating Sudoku board!\n");

    return 0;
}