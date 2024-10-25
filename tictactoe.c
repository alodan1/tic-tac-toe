#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER = 'X';
const char COMP = 'O';

void reset_booard();
void print_board();
//if cuntion returns 0 it's done
int check_free_spaces();
void player_move();
void comp_move(); 
//checks win conditions
char check_winner();
void print_winner(char);

int main(){
    char winner = ' ';
    reset_booard();

    while(winner == ' ' && check_free_spaces() != 0){
        print_board();
        player_move();
        winner = check_winner();
        if(winner != ' ' || check_free_spaces() == 0) {break;}
        comp_move();
        winner = check_winner();
        if(winner != ' ' || check_free_spaces() == 0) {break;}
    }
    print_board();
    print_winner(winner);
}

void reset_booard()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            //starts the board empty and/or clears the board
            board[i][j]=' ';
        }
    }
}
void print_board(){
    for(int i=0;i<3;i++){
    printf(" %c | %c | %c ", board[i][0],board[i][1],board[i][2]);
    if(i==2) {
        printf("\n");
        break;
        }
    printf("\n---|---|---\n");
    }
}

//if cuntion returns 0 it's done
int check_free_spaces()
{
    int free_space = 9;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++){
            if(board[i][j]!=' ')
            {
                //checks if board in row i column j is emmpty
                //if it is, lower the amount of free_space
                free_space--; 
            }
        }
    }
    return free_space;
}

void player_move()
{
    int x,y;
    do
    {
        do
        {
            printf("Enter row number (1-3): ");
            scanf("%d", &x);
            x-=1;
            if(x<0 || x>2)
            {
                printf("you entered an incorrect input, try again\n");
            }
        }while(x<0 || x>2);
        do
        {
            printf("Enter column number (1-3): ");
            scanf("%d", &y);
            y-=1;
            if(y<0 || y>2)
            {
                printf("you entered an incorrect input, try again\n");
            }
        }while(y<0 || y>2);

        if(board[x][y] != ' ')
        {
            printf("Invalid move!!\n");
        } else {
            board[x][y] = PLAYER;
            break;
        }
    }while(board[x][y] != ' ');
}

void comp_move()
{
    srand(time(NULL));
    int x,y;

    if(check_free_spaces() > 0)
    {
        do
        {
            x = rand() %3;
            y = rand() %3;
        } while (board[x][y]!=' ');

        board[x][y] = COMP;
        
    } else{
        print_winner(' ');
    }
} 
//checks win conditions
char check_winner()
{
    //checks rows
    for(int i=0;i<3;i++)
    {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }
    //checks columns
    for(int i=0;i<3;i++)
    {
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }
    //checks diagonals
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
        {
            return board[0][0];
        }
    if(board[0][2] == board[1][1] && board[0][0] == board[2][0])
        {
            return board[0][2];
        }

    return ' ';
}

void print_winner(char winner)
{
    if(winner == PLAYER)
    {
        printf("You win!!");

    } else if(winner == COMP){
        printf("You lose TwT");
    }
    else 
        printf("It's a tied game");
}