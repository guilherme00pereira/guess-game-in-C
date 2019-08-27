#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int guess;
    int hit;
    int level;
    int totaltries;

    double score = 1000;

    srand(time(0));
    int secretnumber = rand() % 100;

    printf("Choose a dificulty level:\n");
    printf("(1) Easy (2) Default (3) Hard\n\n");
    printf("Your choice is: ");

    scanf("%d", &level);

    switch(level) {
        case 1: 
            totaltries = 20;
            break;
        case 2:
            totaltries = 15;
            break;
        default:
            totaltries = 6;
            break;
    }

    for(int i = 1; i <= totaltries; i++) {

        printf("-> Try %d of %d\n", i, totaltries);

        printf("Guess a number: ");
        scanf("%d", &guess);

        if(guess < 0) {
            printf("You can't guess a negative number!\n");
            i--;
            continue;
        }

        hit = guess == secretnumber;

        if(hit) {
            break;
        } else if(guess > secretnumber) {
            printf("\nYou've guess a higher number than then secret!\n\n");
        } else {
            printf("\nYou've guess a lower number than then secret!\n\n");
        }

        double lostpoints = abs(guess - secretnumber) / 2.0;
        score = score - lostpoints;
    }

    printf("\n");
    if(hit) {
        printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
        printf("\nCogratulations! You win!\n");
        printf("Your score is %.2f. See ya!\n\n", score);
    } else {

        printf("       \\|/ ____ \\|/    \n");   
        printf("        @~/ ,. \\~@      \n");   
        printf("       /_( \\__/ )_\\    \n");   
        printf("          \\__U_/        \n");

        printf("\nYou loose! Try again!\n\n");
    }

}