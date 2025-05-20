//FormAI DATASET v1.0 Category: Spell checking ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXWORD 100
#define MAXLINE 1000

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
int is_valid(char *);

int main()
{
    struct tnode *root;
    char word[MAXWORD];
    root = NULL;

    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0]) && is_valid(word))
            root = addtree(root, word);
    }

    treeprint(root);
    return 0;
}

struct tnode *talloc(void);
char *strdup_custom(char *);

struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = strdup_custom(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) {
        p->count++;
    } else if (cond < 0) {
        p->left = addtree(p->left, w);
    } else {
        p->right = addtree(p->right, w);
    }
    return p;
}

char *strdup_custom(char *s)
{
    char *p;
    p = (char *) malloc(strlen(s) + 1);
    if (p != NULL) {
        strcpy(p, s);
    }
    return p;
}

void treeprint(struct tnode *p)
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

int getch(void);
void ungetch(int);

int getword(char *word, int lim)
{
    int c, d, comment, string;
    char *w = word;

    while (isspace(c = getch()))
        ;

    if (c == '/') {
        if ((d = getch()) == '*') {
            comment = 1;
        } else {
            ungetch(d);
            *w = c;
            return c;
        }
    } else if (c == '"') {
        string = 1;
    }

    if (c != EOF) {
        *w++ = c;
    }
    if (!isalpha(c) && c != '_' && c != '/'
            && c != '*' && !string) {
        *w = '\0';
        return c;
    }

    for (; --lim > 0; w++) {
        *w = getch();
        if (*w == '/' && *(w-1) == '*' && comment) {
            comment = 0;
            w--;
        } else if (*w == '"') {
            string = !string;
            w--;
        } else if (!isalnum(*w) && *w != '_'
                && !comment && !string) {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

int is_valid(char *word)
{
    char *keywords[] = {
          "auto", "break", "case", "char", "const", "continue", "default",
          "do", "double", "else", "enum", "extern", "float", "for", "goto",
          "if", "int", "long", "register", "return", "short", "signed",
          "sizeof", "static", "struct", "switch", "typedef", "union",
          "unsigned", "void", "volatile", "while"
          };
    int n_keywords = sizeof(keywords) / sizeof(keywords[0]);

    int i;
    for (i = 0; i < n_keywords; ++i) {
        if (strcmp(word, keywords[i]) == 0) {
            return 0;
        }
    }

    return 1;
}

struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}