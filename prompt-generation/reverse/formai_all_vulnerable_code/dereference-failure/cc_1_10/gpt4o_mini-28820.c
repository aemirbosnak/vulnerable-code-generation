//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

// Function to get a character from input
char getch(void) {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

// Function to check if a key is pressed
int kbhit(void) {
    struct termios oldt, newt;
    int oldf;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    if ((ch = getchar()) != EOF) {
        ungetc(ch, stdin);
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        fcntl(STDIN_FILENO, F_SETFL, oldf);
        return 1;
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    return 0;
}

void displayPage(char **page, int lines) {
    system("clear");
    for(int i = 0; i < lines; i++) {
        printf("%s", page[i]);
    }
}

void readBook(const char *bookPath) {
    FILE *file = fopen(bookPath, "r");
    if (file == NULL) {
        perror("Could not open book file");
        return;
    }

    char **pages = malloc(100 * sizeof(char *));
    char buffer[256];
    int pageCount = 0;
    int lineCount = 0;
    int linesPerPage = 20;

    // Read the book into pages
    while (fgets(buffer, sizeof(buffer), file)) {
        if (lineCount < linesPerPage) {
            pages[pageCount] = strdup(buffer);
            lineCount++;
        } else {
            pageCount++;
            lineCount = 0;
            pages[pageCount] = strdup(buffer);
        }
    }
    fclose(file);
    pageCount++; // to account for last page

    int currentPage = 0;
    while (1) {
        displayPage(pages + currentPage * linesPerPage, linesPerPage);
        
        if (currentPage > 0) {
            printf("\nPress 'b' to go back or 'n' to go next (q to quit): ");
        } else {
            printf("\nPress 'n' to go next (q to quit): ");
        }

        while (1) {
            if (kbhit()) {
                char ch = getch();
                if (ch == 'n' && currentPage < pageCount - 1) {
                    currentPage++;
                    break;
                } else if (ch == 'b' && currentPage > 0) {
                    currentPage--;
                    break;
                } else if (ch == 'q') {
                    goto end;
                }
            }
        }
    }

    end:
    for (int i = 0; i < pageCount; i++) {
        free(pages[i]);
    }
    free(pages);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <book_file>\n", argv[0]);
        return 1;
    }

    readBook(argv[1]);
    return 0;
}