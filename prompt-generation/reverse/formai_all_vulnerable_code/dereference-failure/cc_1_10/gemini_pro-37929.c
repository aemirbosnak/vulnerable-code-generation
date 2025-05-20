//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

typedef struct point {
    int x;
    int y;
} point;

typedef struct maze {
    int width;
    int height;
    char **grid;
} maze;

maze *create_maze(int width, int height) {
    maze *m = malloc(sizeof(maze));
    m->width = width;
    m->height = height;
    m->grid = malloc(sizeof(char *) * height);
    for (int i = 0; i < height; i++) {
        m->grid[i] = malloc(sizeof(char) * width);
    }
    return m;
}

void destroy_maze(maze *m) {
    for (int i = 0; i < m->height; i++) {
        free(m->grid[i]);
    }
    free(m->grid);
    free(m);
}

void print_maze(maze *m) {
    for (int i = 0; i < m->height; i++) {
        for (int j = 0; j < m->width; j++) {
            printf("%c", m->grid[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(maze *m, point p) {
    return p.x >= 0 && p.x < m->width && p.y >= 0 && p.y < m->height && m->grid[p.y][p.x] != '#';
}

int find_path(maze *m, point start, point end) {
    // Create a queue of points to visit.
    point queue[m->width * m->height];
    int head = 0;
    int tail = 0;
    queue[tail++] = start;

    // Create a visited array to keep track of which points have been visited.
    int visited[m->width][m->height];
    for (int i = 0; i < m->height; i++) {
        for (int j = 0; j < m->width; j++) {
            visited[i][j] = 0;
        }
    }

    // Mark the start point as visited.
    visited[start.y][start.x] = 1;

    // While the queue is not empty, keep searching for a path.
    while (head != tail) {
        // Get the next point from the queue.
        point p = queue[head++];

        // If the point is the end point, we have found a path.
        if (p.x == end.x && p.y == end.y) {
            return 1;
        }

        // Otherwise, add all valid moves from the point to the queue.
        point moves[4] = {
            {p.x-1, p.y},
            {p.x+1, p.y},
            {p.x, p.y-1},
            {p.x, p.y+1}
        };
        for (int i = 0; i < 4; i++) {
            point move = moves[i];
            if (is_valid_move(m, move) && !visited[move.y][move.x]) {
                queue[tail++] = move;
                visited[move.y][move.x] = 1;
            }
        }
    }

    // If the queue is empty, we have not found a path.
    return 0;
}

int main() {
    // Create a maze.
    maze *m = create_maze(10, 10);
    for (int i = 0; i < m->height; i++) {
        for (int j = 0; j < m->width; j++) {
            m->grid[i][j] = rand() % 2 == 0 ? '#' : '.';
        }
    }

    // Print the maze.
    print_maze(m);

    // Find a path from the start point to the end point.
    point start = {0, 0};
    point end = {m->width-1, m->height-1};
    int path_found = find_path(m, start, end);

    // Print the result.
    if (path_found) {
        printf("Path found!\n");
    } else {
        printf("No path found.\n");
    }

    // Destroy the maze.
    destroy_maze(m);

    return 0;
}