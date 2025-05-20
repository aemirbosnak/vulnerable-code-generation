//FormAI DATASET v1.0 Category: Data mining ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 100
#define MAX_LINE_LENGTH 1000

struct row {
    int id;
    float data[MAX_COLS];
};

struct matrix {
    struct row rows[MAX_ROWS];
    int num_rows;
    int num_cols;
};

/**
 * Load data from a CSV file into a matrix
 */
void load_data(char *filename, struct matrix *m) {
    FILE *file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("Error opening file '%s'\n", filename);
        exit(1);
    }
    
    char line[MAX_LINE_LENGTH];
    bool first_line = true;
    
    while (fgets(line, sizeof(line), file)) {
        int num_cols = 0;
        char *token = strtok(line, ",");
        struct row r;
        r.id = m->num_rows;
        
        while (token) {
            if (first_line) {
                m->num_cols++;
            }
            r.data[num_cols++] = atof(token);
            token = strtok(NULL, ",");
        }
        
        if (num_cols != m->num_cols) {
            printf("Error: row %d has %d columns (expected %d)\n", m->num_rows, num_cols, m->num_cols);
            exit(1);
        }
        
        m->rows[m->num_rows++] = r;
        first_line = false;
    }
    
    fclose(file);
}

/**
 * Print the matrix to stdout
 */
void print_matrix(struct matrix *m) {
    for (int r = 0; r < m->num_rows; r++) {
        printf("%d:", m->rows[r].id);
        
        for (int c = 0; c < m->num_cols; c++) {
            printf(" %f", m->rows[r].data[c]);
        }
        
        printf("\n");
    }
}

/**
 * Main program
 */
int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }
    
    struct matrix m;
    m.num_rows = 0;
    m.num_cols = 0;
    
    load_data(argv[1], &m);
    print_matrix(&m);
    
    return 0;
}