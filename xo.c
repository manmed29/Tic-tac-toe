#include <stdio.h>
#include <stdbool.h>

#define board_size 3
// test
void init_board(char board[board_size][board_size])
{
    for (int i = 0; i < board_size; i++)
    {
        for (int j = 0; j < board_size; j++)
        {
            board[i][j] = ' ';
        }
    }
}
void print_board(char board[board_size][board_size])
{
    printf("\t\t\t\t\t\t %c | %c | %c \n",board[0][0],board[0][1],board[0][2]);
    printf("\t\t\t\t\t\t---|---|---\n");
    printf("\t\t\t\t\t\t %c | %c | %c \n",board[1][0],board[1][1],board[1][2]);
    printf("\t\t\t\t\t\t---|---|---\n");
    printf("\t\t\t\t\t\t %c | %c | %c \n",board[2][0],board[2][1],board[2][2]);
}
bool player_won(char board[board_size][board_size], char player)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
           printf("Player %c won!\n",player);
           return true;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            printf("Player %c won!\n",player);
           return true;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        printf("Player %c won!\n",player);
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        printf("Player %c won!\n",player);
        return true;
    }
    return false;
}

int main()
{
    char playing_board[3][3];
    char player_1 = 'X';
    char player_2 = 'O';
    int move_counter = 0;

    int move1 = 0;
    int move2 = 0;
    init_board(playing_board);
    print_board(playing_board);
    while (1)
    {
        while (1)
        {
            printf("player 1 to play:\n");
            scanf("%d",&move1);
            scanf("%d",&move2);
            if (playing_board[move1][move2] == ' ')
            {
                playing_board[move1][move2] = player_1;
                move_counter++;
                break;
            }
            printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!----this cell is not empty!\n!!!!!!!!!!!!!!!!!!----please try again\n");
        }
        if (player_won(playing_board,player_1))
        {
            break;
        }else if (move_counter == 9)
        {
            printf("it is a draw!!\n");
            break;
        }
        print_board(playing_board);
        while (1)
        {
            printf("player 2 to play:\n");
            scanf("%d",&move1);
            scanf("%d",&move2);
            if (playing_board[move1][move2] == ' ')
            {
                playing_board[move1][move2] = player_2;
                move_counter++;
                break;
            }
            printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!----this cell is not empty!\n!!!!!!!!!!!!!!!!!!----please try again\n");
        }
        if (player_won(playing_board,player_2))
        {
            break;
        }else if (move_counter == 9)
        {
            printf("it is a draw!!\n");
            break;
        }
        print_board(playing_board);
    }

    return 0;
}