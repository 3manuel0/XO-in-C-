#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

// checking if the coditions of wining are valid
int Winning(char lines[]){
//  the winning condtions
 int winning[8][3] = {{0,1,2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
 int xcount = 0;
 int ocount = 0;
//  going through every possibility
for(int i = 0; i < 8; i++){
    for(int j = 0; j < 3; j++){
        if(lines[winning[i][j]] == 'X'){
            xcount ++;
        }else if (lines[winning[i][j]] == 'O') {
            ocount++;
        }
    }
    if(xcount != 3 && ocount != 3){
    xcount = 0 , ocount = 0;
    }else {
        printf("%s", xcount == 3 ? "X is the winner" : "O is the winner");
        return 0;
    }
}
 return 1;
}
int repeatingMoves(int movesDone[8], int move){
 for(int i = 0; i < 8; i++){
   if(move == movesDone[i]){
    return 1;
   }
 }
 return 0;
} 

int main(void){
    char lines[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'} ;
    bool playing = true;
    char XO[2] = {'X', 'O'};
    int currentMove = -1;
    int movesDone[9];
    int turn = 0;
    int choice;
    srand(time(NULL));
    int choosingPlayer  = rand() % 10;
    printf("write a number between 0 and 9 : ");
    scanf("%d", &choice);
    if (abs(choice - choosingPlayer) <= 2){
       printf("you are the first player (X)\n");
    }else {
        printf("you are the second player (O)\n");
    }
    printf("%c|%c|%c\n", lines[0], lines[1], lines[2] );
    printf("%c|%c|%c\n", lines[3], lines[4], lines[5] );
    printf("%c|%c|%c\n", lines[6], lines[7], lines[8] );
    while(playing && turn <= 8){
        scanf("%d", &currentMove);
    while(repeatingMoves(movesDone,currentMove) == 1){
        printf("square is already picked enter a new number :\n");
        scanf("%d", &currentMove);
    }
    movesDone[turn] = currentMove;
    if(turn % 2 == 0){
       lines[currentMove - 1] = 'X';
       printf("O's turn\n");
    }else{
        lines[currentMove - 1] = 'O';
        printf("X's turn\n");
    }
    printf("%c|%c|%c\n", lines[0], lines[1], lines[2] );
    printf("%c|%c|%c\n", lines[3], lines[4], lines[5] );
    printf("%c|%c|%c\n", lines[6], lines[7], lines[8] );
    if(Winning(lines) == 0){
        playing = false;
    }
    turn++;
    };    
    return 0;
};