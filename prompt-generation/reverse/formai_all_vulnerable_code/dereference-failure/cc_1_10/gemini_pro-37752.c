//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *title;
    char *genre;
    int year;
    double rating;
} Movie;

int compare(const void *a, const void *b) {
    const Movie *a_movie = (const Movie *)a;
    const Movie *b_movie = (const Movie *)b;
    return strcmp(a_movie->title, b_movie->title);
}

int main() {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("movies.txt", "r");
    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    Movie movies[100];
    int num_movies = 0;

    while ((read = getline(&line, &len, fp)) != -1) {
        char *title = strtok(line, ",");
        char *genre = strtok(NULL, ",");
        int year = atoi(strtok(NULL, ","));
        double rating = atof(strtok(NULL, ","));

        movies[num_movies++] = (Movie){ title, genre, year, rating };
    }

    qsort(movies, num_movies, sizeof(Movie), compare);

    printf("**====================================================================================================================================================**\n");
    printf("**                                      |    |                                                                  |                                **\n");
    printf("**                                      V    V                                                                  V                                **\n");
    printf("** =========================================================== ** WARNING: MOVIE REVIEWS WRITTEN IN A POST-APOCALYPTIC STYLE ** ============================================================ **\n");
    printf("**                                      ^    ^                                                                  ^                                **\n");
    printf("**                                      |    |                                                                  |                                **\n");
    printf("**====================================================================================================================================================**\n");
    printf("\n");

    for (int i = 0; i < num_movies; i++) {
        printf("**                                     ************************************************************************************************************************                                     **\n");
        printf("**                                     * Title: %s                                                                  *                                     **\n", movies[i].title);
        printf("**                                     * Genre: %s                                                                  *                                     **\n", movies[i].genre);
        printf("**                                     * Year: %d                                                                  *                                     **\n", movies[i].year);
        printf("**                                     * Rating: %f                                                                  *                                     **\n", movies[i].rating);
        printf("**                                     ************************************************************************************************************************                                     **\n");
        printf("\n");

        if (movies[i].rating >= 8.0) {
            printf("**                                      .--'''''''--.                                      **\n");
            printf("**                                      :  o      o  :                                      **\n");
            printf("**                                      :   '.    .'   :                                      **\n");
            printf("**                                      :     '-''-'     :                                      **\n");
            printf("**                                      `.    | . |    ,'                                      **\n");
            printf("**                                        '._.'   '._.'                                        **\n");
            printf("**                                   .,-.._      _..-,.                                   **\n");
            printf("**                                  ( _'  .'\.-''-'/'.  '_ )                                  **\n");
            printf("**                                  '-.   /   `.`-._`   .-'                                  **\n");
            printf("**                                    '._.'      '--` '._.'                                    **\n");
            printf("**                                      '-._      _,-'                                      **\n");
            printf("**                                          '-.  .-'                                          **\n");
            printf("**                                              '.'                                              **\n");
            printf("\n");
            printf("**                                   This movie is a must-see! It's one of the best movies I've ever seen.                                   **\n");
            printf("\n");
        } else if (movies[i].rating >= 6.0) {
            printf("**                                      .--'''''''--.                                      **\n");
            printf("**                                      :  o      o  :                                      **\n");
            printf("**                                      :   '.    .'   :                                      **\n");
            printf("**                                      :     '-''-'     :                                      **\n");
            printf("**                                      `.    | . |    ,'                                      **\n");
            printf("**                                        '._.'   '._.'                                        **\n");
            printf("**                                   .,-.._      _..-,.                                   **\n");
            printf("**                                  ( _'  .'\.-''-'/'.  '_ )                                  **\n");
            printf("**                                  '-.   /   `.`-._`   .-'                                  **\n");
            printf("**                                    '._.'      '--` '._.'                                    **\n");
            printf("**                                      '-._      _,-'                                      **\n");
            printf("**                                          '-.  .-'                                          **\n");
            printf("**                                              :  :                                              **\n");
            printf("\n");
            printf("**                                   This movie is pretty good. It's not the best movie I've ever seen, but it's definitely worth watching.                                   **\n");
            printf("\n");
        } else if (movies[i].rating >= 4.0) {
            printf("**                                      .--'''''''--.                                      **\n");
            printf("**                                      :  o      o  :                                      **\n");
            printf("**                                      :   '.    .'   :                                      **\n");
            printf("**                                      :     '-''-'     :                                      **\n");
            printf("**                                      `.    | . |    ,'                                      **\n");
            printf("**                                        '._.'   '._.'                                        **\n");
            printf("**                                   .,-.._      _..-,.                                   **\n");
            printf("**                                  ( _'  .'\.-''-'/'.  '_ )                                  **\n");
            printf("**                                  '-.   /   `.`-._`   .-'                                  **\n");
            printf("**                                    '._.'      '--` '._.'                                    **\n");
            printf("**                                      '-._      _,-'                                      **\n");
            printf("**                                          '-.  .-'                                          **\n");
            printf("**                                              :  :                                              **\n");
            printf("\n");
            printf("**                                   This movie is okay. It's not the worst movie I've ever seen, but it's not the best either.                                   **\n");
            printf("\n");
        } else {
            printf("**                                      .--'''''''--.                                      **\n");
            printf("**                                      :  o      o  :                                      **\n");
            printf("**                                      :   '.    .'   :                                      **\n");
            printf("**                                      :     '-''-'     :                                      **\n");
            printf("**                                      `.    | . |    ,'                                      **\n");
            printf("**                                        '._.'   '._.'                                        **\n");
            printf("**                                   .,-.._      _..-,.                                   **\n");
            printf("**                                  ( _'  .'\.-''-'/'.  '_ )                                  **\n");
            printf("**                                  '-.   /   `.`-._`   .-'                                  **\n");
            printf("**                                    '._.'      '--` '._.'                                    **\n");
            printf("**                                      '-._      _,-'                                      **\n");
            printf("**                                          '-.  .-'                                          **\n");
            printf("**                                              :  :                                              **\n");
            printf("\n");
            printf("**                                   This movie is terrible. It's one of the worst movies I've ever seen.                                   **\n");
            printf("\n");
        }
        printf("\n");
    }

    fclose(fp);
    free(line);

    return 0;
}