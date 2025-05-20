//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: scientific
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Cell {
    char *text;
    int width;
    int height;
} Cell;

typedef struct Grid {
    Cell **cells;
    int width;
    int height;
} Grid;

Grid *create_grid(int width, int height) {
    Grid *grid = malloc(sizeof(Grid));
    grid->width = width;
    grid->height = height;
    grid->cells = malloc(sizeof(Cell *) * height);
    for (int i = 0; i < height; i++) {
        grid->cells[i] = malloc(sizeof(Cell) * width);
        for (int j = 0; j < width; j++) {
            grid->cells[i][j].text = "";
            grid->cells[i][j].width = 0;
            grid->cells[i][j].height = 0;
        }
    }
    return grid;
}

void free_grid(Grid *grid) {
    for (int i = 0; i < grid->height; i++) {
        for (int j = 0; j < grid->width; j++) {
            free(grid->cells[i][j].text);
        }
        free(grid->cells[i]);
    }
    free(grid->cells);
    free(grid);
}

void set_cell(Grid *grid, int x, int y, char *text) {
    int width = strlen(text);
    int height = 1;
    grid->cells[y][x].text = malloc(sizeof(char) * (width + 1));
    strcpy(grid->cells[y][x].text, text);
    grid->cells[y][x].width = width;
    grid->cells[y][x].height = height;
}

void print_grid(Grid *grid) {
    for (int i = 0; i < grid->height; i++) {
        for (int j = 0; j < grid->width; j++) {
            printf("%s", grid->cells[i][j].text);
        }
        printf("\n");
    }
}

int main() {
    Grid *grid = create_grid(80, 24);
    set_cell(grid, 0, 0, "   ______               __                                                      ");
    set_cell(grid, 0, 1, "  /      \\            /  |       ____  ____      ____________________________   ");
    set_cell(grid, 0, 2, " /$$$$$$  |          /$$ |  ,'\\  ,'    \\ \\   \\    /       /$$    $$  \\$$\\   \\  ");
    set_cell(grid, 0, 3, "|  $$  \\$$ |        /$$$ | /$$$ |  |  \\ \\  \\  / |      | $$    $$  \\$$\\   \\ ");
    set_cell(grid, 0, 4, " \\$$  $$  |       /$$/ |/$$/ /   |  \\ \\  \\/  / |      | $$$$$$$$   \\$$\\  \\ ");
    set_cell(grid, 0, 5, "  \\$$$$$$/        | $$  |$$/    |   \\ \\    /  / /      | $$  __$$   \\$$\\  \\");
    set_cell(grid, 0, 6, "   \\  $$         |  $$$$/      |    \\ \\  /  / /       | $$ |  $$   \\$$\\  \\");
    set_cell(grid, 0, 7, "    \\$$         |   $$$/       |     \\ \\/  / /        | $$ |  $$   \\$$\\  \\");
    set_cell(grid, 0, 8, "    \\$$         |    $$ |       |      \\  / /         | $$ |  $$    \\$$\\  \\");
    set_cell(grid, 0, 9, "    \\$$         |    $$ |       |       \\/ /          | $$ |  $$    \\$$\\  \\");
    set_cell(grid, 0, 10, "     \\$$        |    $$/        |        \\/           |  $$$$$$/     \\$$\\  \\");
    set_cell(grid, 0, 11, "      \\$$        |    $$ |        |         \\            \\ $$  _____      \\$$\\ ");
    set_cell(grid, 0, 12, "       \\$$       /    $$ |        |          \\           |  $$ /$$/       \\$$\\");
    set_cell(grid, 0, 13, "        \\$$     /    $$/         |           \\          |   $$<          \\$$\\");
    set_cell(grid, 0, 14, "         \\$$   /     $$/          |            \\         |    $$ |          \\$$\\");
    set_cell(grid, 0, 15, "          \\$$ /      $$/           |             \\        |     $$/           \\$$\\");
    set_cell(grid, 0, 16, "           \\$/       $$/            |              \\_______|______$$/            \\$$\\");
    set_cell(grid, 0, 17, "                                                                         $$\ /");
    set_cell(grid, 0, 18, "                                                                         $$\ ");
    set_cell(grid, 0, 19, "                                                                         $$\__");
    set_cell(grid, 0, 20, "                                                                          $$\ ");
    set_cell(grid, 0, 21, "                                                                          $$\ ");
    set_cell(grid, 0, 22, "                                                                          $$\ ");
    set_cell(grid, 0, 23, "                                                                           \\$");
    print_grid(grid);
    free_grid(grid);
    return 0;
}