//GEMINI-pro DATASET v1.0 Category: Database querying ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main()
{
    sqlite3 *db;
    sqlite3_stmt *stmt;
    int rc;
    char *sql;
    char *zErrMsg = 0;
    int nrows, ncols;
    char **azResult;

    // Open the database
    rc = sqlite3_open("test.db", &db);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Prepare the statement
    sql = "SELECT * FROM t1;";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Can't prepare statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Execute the statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_ROW)
    {
        fprintf(stderr, "Can't execute statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Get the number of rows and columns
    nrows = sqlite3_column_count(stmt);
    ncols = sqlite3_data_count(stmt);

    // Allocate memory for the result
    azResult = (char **)malloc(sizeof(char *) * nrows * ncols);
    if (!azResult)
    {
        fprintf(stderr, "Can't allocate memory for result\n");
        sqlite3_close(db);
        return 1;
    }

    // Copy the results into the array
    for (int i = 0; i < nrows; i++)
    {
        for (int j = 0; j < ncols; j++)
        {
            azResult[i * ncols + j] = strdup((char *)sqlite3_column_text(stmt, j));
        }
    }

    // Print the results
    for (int i = 0; i < nrows; i++)
    {
        for (int j = 0; j < ncols; j++)
        {
            printf("%s ", azResult[i * ncols + j]);
        }
        printf("\n");
    }

    // Free the memory for the result
    for (int i = 0; i < nrows * ncols; i++)
    {
        free(azResult[i]);
    }
    free(azResult);

    // Finalize the statement
    sqlite3_finalize(stmt);

    // Close the database
    sqlite3_close(db);

    return 0;
}