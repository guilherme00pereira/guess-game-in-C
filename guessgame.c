#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("################################################################\n");
    printf("     ______                         ______                      \n");
    printf("    / ____/_  _____  __________    / ____/___ _____ ___  ___    \n");
    printf("   / / __/ / / / _ \\/ ___/ ___/   / / __/ __ `/ __ `__ \\/ _ \\   \n");
    printf("  / /_/ / /_/ /  __(__  |__  )   / /_/ / /_/ / / / / / /  __/   \n");
    printf("  \\____/\\__,_/\\___/____/____/    \\____/\\__,_/_/ /_/ /_/\\___/    \n");
    printf("\n");
    printf("    Welcome to Guess Game. Try to hit a number from 1 to 100.   \n");
    printf("\n");
    printf("################################################################\n");

    int guess;
    int hit;
    int level;
    int totaltries;

    double score = 1000;

    srand(time(0));
    int secretnumber = rand() % 100;

    printf("\n");
    printf("Choose a dificulty level:\n");
    printf("\n");
    printf("(1) Easy    -> 20 guesses\n");
    printf("(2) Medium  -> 15 guesses\n");
    printf("(3) Hard    -> 7 guesses\n");
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
            totaltries = 7;
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