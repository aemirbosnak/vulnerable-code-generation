//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function prototypes */
void print_intro();
void set_up_table(char **table);
void print_table(char **table);
int quiz_user(char **table);

/* Main function */
int main()
{
    char **table;
    int score = 0;

    /* Set up the periodic table */
    table = malloc(10 * sizeof(char *));
    set_up_table(table);

    /* Print the game intro */
    print_intro();

    /* Quiz the user */
    score = quiz_user(table);

    /* Print the final score */
    printf("\n\nYour final score is: %d/118", score);

    /* Free up memory */
    free(table);
}

/* Function definitions */
void print_intro()
{
    printf("Welcome to the Periodic Table Quiz!\n\n");
    printf("In this quiz, you will be asked to name elements on the periodic table.\n");
    printf("You will earn points for correctly naming elements and lose points for incorrect answers.\n\n");
}

void set_up_table(char **table)
{
    /* Initialize the periodic table */
    table[0] = strdup("H   He");
    table[1] = strdup("Li  Be  B   C   N   O   F   Ne");
    table[2] = strdup("Na  Mg  Al  Si  P   S   Cl  Ar");
    table[3] = strdup("K   Ca  Sc  Ti  V   Cr  Mn  Fe  Co  Ni  Cu  Zn  Ga  Ge  As  Se  Br  Kr");
    table[4] = strdup("Rb  Sr  Y   Zr  Nb  Mo  Tc  Ru  Rh  Pd  Ag  Cd  In  Sn  Sb  Te  I   Xe");
    table[5] = strdup("Cs  Ba  La  Ce  Pr  Nd  Pm  Sm  Eu  Gd  Tb  Dy  Ho  Er  Tm  Yb  Lu  Hf  Ta  W   Re  Os  Ir  Pt  Au  Hg  Tl  Pb  Bi  Po  At  Rn");
    table[6] = strdup("Fr  Ra  Ac  Th  Pa  U   Np  Pu  Am  Cm  Bk  Cf  Es  Fm  Md  No  Lr  Rf  Db  Sg  Bh  Hs  Mt  Ds  Rg  Cn  Nh  Fl  Mc  Lv  Ts  Og");
}

void print_table(char **table)
{
    printf("Here is the periodic table:\n\n");

    printf(" ");
    for (int i = 0; i < 118; i++)
    {
        printf("-");
    }
    printf("\n");

    for (int i = 0; i < 7; i++)
    {
        printf("|%s", table[i]);
        printf("|\n");
    }

    printf(" ");
    for (int i = 0; i < 118; i++)
    {
        printf("-");
    }
    printf("\n");
}

int quiz_user(char **table)
{
    char name[2];
    int score = 0;
    int total_questions = 10;

    printf("\nEnter any letter if you are ready to start the quiz!\n");
    char s[10];
    scanf("%s", s);

    for (int i = 0; i < total_questions; i++)
    {
        int element = rand() % 118;

        printf("\nQuestion %d:\n", i + 1);
        printf("What is the symbol for element #%d on the periodic table?\n", element + 1);
        printf("Type your answer below:\n");

        scanf("%s", name);

        if (strcmp(name, table[element/18][3*(element%18)]) == 0)
        {
            printf("\nCorrect! +%d points\n", 10 - i);
            score += 10-i;
        }
        else
        {
            printf("\nIncorrect. The correct answer is %s. -%d points\n", table[element/18][3*(element%18)], i+1);
            score -= i+1;
        }
    }

    return score;
}