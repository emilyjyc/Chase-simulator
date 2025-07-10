#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define row 8 
#define col 8 

int pwstatus[col] = { 0 };
int pbstatus[col] = { 0 };
int end=0;
char board[row][col] = {
                    { 'R' , 'N' , 'B' , 'Q' , 'K' , 'B' , 'N' , 'R' },
                    { 'P' , 'P' , 'P' , 'P' , 'P' , 'P' , 'P' , 'P' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { 'p' , 'p' , 'p' , 'p' , 'p' , 'p' , 'p' , 'p' },
                    { 'r' , 'n' , 'b' , 'q' , 'k' , 'b' , 'n' , 'r' }
};//棋盤(上方白下方黑) 

void display();
void change(int*, int*, int*, int*);
void capture(int*, int*,int* ,int*);

int pawnw(int, int, int, int);
int pawnb(int, int, int, int);

int rookw(int, int, int, int);
int rookb(int, int, int, int);

int knightw(int, int, int, int);
int knightb(int, int, int, int);

int bishopw(int, int, int, int);
int bishopb(int, int, int, int);

int kingw(int, int, int, int);
int kingb(int, int, int, int);

int queenw(int, int, int, int);
int queenb(int, int, int, int);

void Player1();
void Player2();
int check(int, int);
int check2(int, int);

int main()
{
    int  x = 0;
    

    printf("\nCHESS GAME\n");
    printf("\nPLEASE PRESS ENTER TO START");

    getchar();
    system("cls");

    do
    {
        x++; 
        system("cls");
        display();

        if ((x % 2) == 0)
        {
            Player2();
        }
        else
        {
            Player1();
        }//判斷誰走 

        printf(" \n\nPress Enter To Continue ! \n\n ");

        
    } while (end!=1);//玩家一二輪流移動棋子直到王死掉(end=1) 

}

void display()//顯示棋盤 
{
    char i;
    int j, k;

    printf(" ");
    for (i = 1; i <= col; i++) {
        printf("   %d",i);//每個直列 
    }
    printf("\n");

    for (k = 0; k < row; k++)
    {
        printf("  ");
        for (i = 0; i < 33; i++) {
            printf("-");
        }
        printf("\n");
        printf("%d ", k + 1);//每個橫列 

        for (j = 0; j < row; j++) {
            printf("| %c ", board[k][j]);
        }
        printf("| \n");
    }

    printf("  ");
    for (i = 0; i < 33; i++) {
        printf("-");
    }
    printf("\n");

}

void change(int *Pr1, int *Pc1, int *Pr2, int *Pc2)//移動棋子 
{
    char temp;

    temp = board[*Pr1][*Pc1];
    board[*Pr1][*Pc1] = board[*Pr2][*Pc2];
    board[*Pr2][*Pc2] = temp;//設中間變數交換位置 

    printf("Press to Continue");
    
}

void capture(int *Ar1, int *Ac1, int *Ar2, int *Ac2)//吃掉棋子 
{
    char temp;

    temp = board[*Ar2][*Ac2];
    board[*Ar2][*Ac2] = board[*Ar1][*Ac1];
    board[*Ar1][*Ac1] = ' ';//設中間變數交換位置，被吃的顯示空白 
    
    if (temp == 'k' ){ 
        printf("\nWHITE  WIN!\n\nCONGRADURATION!!!\n");
        system("pause");
        printf("---The game is end---");
        end = end + 1;//end=1程式停止
    }//王被吃
    else if (temp == 'K') {
        printf("\nBLACK  WIN!\n\nCONGRADURATION!!!\n");
        system("pause");
        printf("---The game is end---");
        end = end + 1;//end=1程式停止 
    }//王被吃
    else {
        printf("You capture %c ! Press to Continue", temp);
        system("pause");
    }
    printf(" You capture %c ! Press to Continue", temp);
    
}


int pawnw(int jr1, int jc1, int jr2, int jc2) {

    if (pwstatus[jc1] == 1)
    {
        if (jr2 == jr1 + 1 && jc2 == jc1) {
            return 1;
        }

        if (jr2 == jr1 + 2 && jc2 == jc1) {
            return 1;
        }
        else
        {
            --pwstatus[jc1];
            return 0;
        }
    }//判斷一開始兵走一格或兩格 

    if (pwstatus[jc1] != 1)
    {
        if (jr2 == jr1 + 1 && jc2 == jc1) 
            return 1;
        if (jr2 == jr1 + 1 && jc2 == jc1 + 1 && check(jr1 + 1, jc1 + 1) == 2)
            return 1;
        if (jr2 == jr1 + 1 && jc2 == jc1 - 1 && check(jr1 + 1, jc1 - 1) == 2)
            return 1;
        else
            return 0;
    }//判斷兵走法 
    
}//白色的pawn 
int pawnb(int jr1, int jc1, int jr2, int jc2) {

    if (pbstatus[jc1] == 1)
    {
        if (jr2 == jr1 - 1 && jc2 == jc1) {
            return 1;
        }

        if (jr2 == jr1 - 2 && jc2 == jc1) {
            return 1;
        }
        else
        {
            --pbstatus[jc1];
            return 0;
        }
    }//判斷一開始兵走一格或兩格 

    if (pbstatus[jc1] != 1)
    {
        if (jr2 == jr1 - 1 && jc2 == jc1) {
            return 1;
        }

        if (jr2 == jr1 - 1 && jc2 == jc1 + 1 && check(jr1 + 1, jc1 + 1) == 2)
            return 1;

        if (jr2 == jr1 - 1 && jc2 == jc1 - 1 && check(jr1 + 1, jc1 - 1) == 2)
            return 1;
        else
            return 0;
    }//判斷兵走法 
}//黑色的pawn

int rookw(int jr1, int jc1, int jr2, int jc2) {

    static int i, j ;

    if (jr2 == jr1 && jc2 <= jc1) {
        for (j = 1; jc1 - j > jc2 ; j++) {
            if (board[jr1][jc1 - i] != ' ') {
                return 0;
            }   
        }
        if (check(jr2, jc2) != 0) {
            return 1;
        }
        else
            return 0;
    }//判斷城堡直行或橫行走法(以下皆是) 
    
    if (jr2 == jr1 && jc2 >= jc1) {
        for (j = 1; jc1 + j < jc2; j++) {
            if (board[jr1][jc1 + i] != ' ') {
                return 0;
            }
        }
        if (check(jr2, jc2) != 0) {
            return 1;
        }
        else
            return 0;
    }

    if (jr2 <= jr1 && jc2 == jc1) {
        for (i = 1; jr1 - i > jr2; i++) {
            if (board[jr1 - i][jc1] != ' ') {
                return 0;
            }
        }
        if (check(jr2, jc2) != 0) {
            return 1;
        }
        else
            return 0;
    }

    if (jr2 >= jr1 && jc2 == jc1) {
        for (i = 1; jr1 + i < jr2; i++) {
            if (board[jr1 + i][jc1] != ' ') {
                return 0;
            }
        }
        if (check(jr2, jc2) != 0) {
            return 1;
        }
        else
            return 0;
    }
    else
        return 0;

}//白色的rook 
int rookb(int jr1, int jc1, int jr2, int jc2) {

    static int i, j;

    if (jr2 == jr1 && jc2 <= jc1) {
        for (j = 1; jc1 - j > jc2; j++) {
            if (board[jr1][jc1 - i] != ' ') {
                return 0;
            }
        }
        if (check2(jr2, jc2) != 0) {
            return 1;
        }
        else
            return 0;
    }//判斷城堡直行或橫行走法(以下皆是) 

    if (jr2 == jr1 && jc2 >= jc1) {
        for (j = 1; jc1 + j < jc2; j++) {
            if (board[jr1][jc1 + i] != ' ') {
                return 0;
            }
        }
        if (check2(jr2, jc2) != 0) {
            return 1;
        }
        else
            return 0;
    }

    if (jr2 <= jr1 && jc2 == jc1) {
        for (i = 1; jr1 - i > jr2; i++) {
            if (board[jr1 - i][jc1] != ' ') {
                return 0;
            }
        }
        if (check2(jr2, jc2) != 0) {
            return 1;
        }
        else
            return 0;
    }

    if (jr2 >= jr1 && jc2 == jc1) {
        for (i = 1; jr1 + i < jr2; i++) {
            if (board[jr1 + i][jc1] != ' ') {
                return 0;
            }
        }
        if (check(jr2, jc2) != 0) {
            return 1;
        }
        else
            return 0;
    }

    else
        return 0;

}//黑色的rook 

int knightw(int jr1, int jc1, int jr2, int jc2) {

    if (jr2 == jr1 + 2 && jc2 == jc1 + 1 && check(jr2,jc2) != 0)
        return 1;//判斷騎士日走法(以下皆是) 
    if (jr2 == jr1 + 2 && jc2 == jc1 - 1 && check(jr2, jc2) != 0)
        return 1;
    if (jr2 == jr1 - 2 && jc2 == jc1 + 1 && check(jr2, jc2) != 0)
        return 1;
    if (jr2 == jr1 - 2 && jc2 == jc1 - 1 && check(jr2, jc2) != 0)
        return 1;
    if (jr2 == jr1 + 1 && jc2 == jc1 + 2 && check(jr2, jc2) != 0)
        return 1;
    if (jr2 == jr1 + 1 && jc2 == jc1 - 2 && check(jr2, jc2) != 0)
        return 1;
    if (jr2 == jr1 - 1 && jc2 == jc1 + 2 && check(jr2, jc2) != 0)
        return 1;
    if (jr2 == jr1 - 1 && jc2 == jc1 - 2 && check(jr2, jc2) != 0)
        return 1;
}//黑色騎士 
int knightb(int jr1, int jc1, int jr2, int jc2) {

    if (jr2 == jr1 + 2 && jc2 == jc1 + 1 && check2(jr2, jc2) != 0)
        return 1;//判斷騎士日走法(以下皆是)
    if (jr2 == jr1 + 2 && jc2 == jc1 - 1 && check2(jr2, jc2) != 0)
        return 1;
    if (jr2 == jr1 - 2 && jc2 == jc1 + 1 && check2(jr2, jc2) != 0)
        return 1;
    if (jr2 == jr1 - 2 && jc2 == jc1 - 1 && check2(jr2, jc2) != 0)
        return 1;
    if (jr2 == jr1 + 1 && jc2 == jc1 + 2 && check2(jr2, jc2) != 0)
        return 1;
    if (jr2 == jr1 + 1 && jc2 == jc1 - 2 && check2(jr2, jc2) != 0)
        return 1;
    if (jr2 == jr1 - 1 && jc2 == jc1 + 2 && check2(jr2, jc2) != 0)
        return 1;
    if (jr2 == jr1 - 1 && jc2 == jc1 - 2 && check2(jr2, jc2) != 0)
        return 1;
}//白色騎士 


int bishopw(int jr1, int jc1, int jr2, int jc2) {

    static int  j;

    if (jr2 - jr1 == jc2 - jc1 ) {
        if (jr2 <= jr1 && jc2 <= jc1) {
            for (j = 1; jc1 - j > jc2; j++) {
                if (board[jr1 - j][jc1 - j] != ' ') {
                    return 0;
                }
            }
            if (check(jr2, jc2) != 0) {
                return 1;
            }
            else
                return 0;
        }
        if (jr2 >= jr1 && jc2 >= jc1) {
            for (j = 1; jc1 + j < jc2; j++) {
                if (board[jr1 + j][jc1 + j] != ' ') {
                    return 0;
                }
            }
            if (check(jr2, jc2) != 0) {
                return 1;
            }
            else
                return 0;
        }
    }//判斷騎士斜走法(以下皆是)

    if (jr2 - jr1 == -(jc2 - jc1)) {
        if (jr2 >= jr1 && jc2 <= jc1) {
            for (j = 1; jc1 - j > jc2; j++) {
                if (board[jr1 + j][jc1 - j] != ' ') {
                    return 0;
                }
            }
            if (check(jr2, jc2) != 0) {
                return 1;
            }
            else
                return 0;
        }
        if (jr2 <= jr1 && jc2 >= jc1) {
            for (j = 1; jc1 + j < jc2; j++) {
                if (board[jr1 - j][jc1 + j] != ' ') {
                    return 0;
                }
            }
            if (check(jr2, jc2) != 0) {
                return 1;
            }
            else
                return 0;
        }
    }
    else
        return 0;
}//白色主教 
int bishopb(int jr1, int jc1, int jr2, int jc2) {

    static int  j;

    if (jr2 - jr1 == jc2 - jc1) {
        if (jr2 <= jr1 && jc2 <= jc1) {
            for (j = 1; jc1 - j > jc2; j++) {
                if (board[jr1 - j][jc1 - j] != ' ') {
                    return 0;
                }
            }
            if (check2(jr2, jc2) != 0) {
                return 1;
            }
            else
                return 0;
        }
        if (jr2 >= jr1 && jc2 >= jc1) {
            for (j = 1; jc1 + j < jc2; j++) {
                if (board[jr1 + j][jc1 + j] != ' ') {
                    return 0;
                }
            }
            if (check2(jr2, jc2) != 0) {
                return 1;
            }
            else
                return 0;
        }
    }//判斷騎士斜走法(以下皆是)

    if (jr2 - jr1 == -(jc2 - jc1)) {
        if (jr2 >= jr1 && jc2 <= jc1) {
            for (j = 1; jc1 - j > jc2; j++) {
                if (board[jr1 + j][jc1 - j] != ' ') {
                    return 0;
                }
            }
            if (check2(jr2, jc2) != 0) {
                return 1;
            }
            else
                return 0;
        }
        if (jr2 <= jr1 && jc2 >= jc1) {
            for (j = 1; jc1 + j < jc2; j++) {
                if (board[jr1 - j][jc1 + j] != ' ') {
                    return 0;
                }
            }
            if (check2(jr2, jc2) != 0) {
                return 1;
            }
            else
                return 0;
        }
    }
    else
        return 0;
}//黑色主教


int kingw(int jr1, int jc1, int jr2, int jc2) {
    
    if (jr2 == jr1 && jc2 == jc1 + 1) {
        if (check(jr2, jc2) != 0) {
            return 1;
        }
        else
            return 0;
    }//判斷國王九宮格走法(以下皆是)
       
    if (jr2 == jr1 && jc2 == jc1 - 1) {
        if (check(jr2, jc2) != 0) {
            return 1;
        }
        else
            return 0;
    }

    if (jr2 == jr1 - 1 && jc2 == jc1 + 1) {
        if (check(jr2, jc2) != 0) {
            return 1;
        }
        else
            return 0;
    }

    if (jr2 == jr1 - 1 && jc2 == jc1) {
        if (check(jr2, jc2) != 0) {
            return 1;
        }
        else
            return 0;
    }

    if (jr2 == jr1 - 1 && jc2 == jc1 - 1) {
        if (check(jr2, jc2) != 0) {
            return 1;
        }
        else
            return 0;
    }

    if (jr2 == jr1 + 1 && jc2 == jc1 + 1) {
        if (check(jr2, jc2) != 0) {
            return 1;
        }
        else
            return 0;
    }

    if (jr2 == jr1 + 1 && jc2 == jc1) {
        if (check(jr2, jc2) != 0) {
            return 1;
        }
        else
            return 0;
    }

    if (jr2 == jr1 + 1 && jc2 == jc1 - 1) {
        if (check(jr2, jc2) != 0) {
            return 1;
        }
        else
            return 0;
    }

    else
        return 0;
}//白色國王 
int kingb(int jr1, int jc1, int jr2, int jc2)
{
    if (jr2 == jr1 && jc2 == jc1 + 1) {
        if (check2(jr2, jc2) != 0) {
            return 1;
        }
        else
            return 0;
    }//判斷國王九宮格走法(以下皆是)

    if (jr2 == jr1 && jc2 == jc1 - 1) {
        if (check2(jr2, jc2) != 0) {
            return 1;
        }
        else
            return 0;
    }

    if (jr2 == jr1 - 1 && jc2 == jc1 + 1) {
        if (check2(jr2, jc2) != 0) {
            return 1;
        }
        else
            return 0;
    }

    if (jr2 == jr1 - 1 && jc2 == jc1) {
        if (check2(jr2, jc2) != 0) {
            return 1;
        }
        else
            return 0;
    }

    if (jr2 == jr1 - 1 && jc2 == jc1 - 1) {
        if (check2(jr2, jc2) != 0) {
            return 1;
        }
        else
            return 0;
    }

    if (jr2 == jr1 + 1 && jc2 == jc1 + 1) {
        if (check2(jr2, jc2) != 0) {
            return 1;
        }
        else
            return 0;
    }

    if (jr2 == jr1 + 1 && jc2 == jc1) {
        if (check2(jr2, jc2) != 0) {
            return 1;
        }
        else
            return 0;
    }

    if (jr2 == jr1 + 1 && jc2 == jc1 - 1) {
        if (check2(jr2, jc2) != 0) {
            return 1;
        }
        else
            return 0;
    }

    else
        return 0;
}//黑色國王



int queenw(int jr1, int jc1, int jr2, int jc2)
{
    static int i, j;

    if (jr2 == jr1 && jc2 <= jc1) {
        for (j = 1; jc1 - j > jc2; j++) {
            if (board[jr1][jc1 - i] != ' ') {
                return 0;
            }
        }
        if (check(jr2, jc2) != 0) {
            return 1;
        }
        else
            return 0;
    }//判斷皇后使用主教和城堡的走法(以下皆是)

    if (jr2 == jr1 && jc2 >= jc1) {
        for (j = 1; jc1 + j < jc2; j++) {
            if (board[jr1][jc1 + i] != ' ') {
                return 0;
            }
        }
        if (check(jr2, jc2) != 0) {
            return 1;
        }
        else
            return 0;
    }

    if (jr2 <= jr1 && jc2 == jc1) {
        for (i = 1; jr1 - i > jr2; i++) {
            if (board[jr1 - i][jc1] != ' ') {
                return 0;
            }
        }
        if (check(jr2, jc2) != 0) {
            return 1;
        }
        else
            return 0;
    }

    if (jr2 >= jr1 && jc2 == jc1) {
        for (i = 1; jr1 + i < jr2; i++) {
            if (board[jr1 + i][jc1] != ' ') {
                return 0;
            }
        }
        if (check(jr2, jc2) != 0) {
            return 1;
        }
        else
            return 0;
    }
    if (jr2 - jr1 == jc2 - jc1) {
        if (jr2 <= jr1 && jc2 <= jc1) {
            for (j = 1; jc1 - j > jc2; j++) {
                if (board[jr1 - j][jc1 - j] != ' ') {
                    return 0;
                }
            }
            if (check(jr2, jc2) != 0) {
                return 1;
            }
            else
                return 0;
        }
        if (jr2 >= jr1 && jc2 >= jc1) {
            for (j = 1; jc1 + j < jc2; j++) {
                if (board[jr1 + j][jc1 + j] != ' ') {
                    return 0;
                }
            }
            if (check(jr2, jc2) != 0) {
                return 1;
            }
            else
                return 0;
        }
    }

    if (jr2 - jr1 == -(jc2 - jc1)) {
        if (jr2 >= jr1 && jc2 <= jc1) {
            for (j = 1; jc1 - j > jc2; j++) {
                if (board[jr1 + j][jc1 - j] != ' ') {
                    return 0;
                }
            }
            if (check(jr2, jc2) != 0) {
                return 1;
            }
            else
                return 0;
        }
        if (jr2 <= jr1 && jc2 >= jc1) {
            for (j = 1; jc1 + j < jc2; j++) {
                if (board[jr1 - j][jc1 + j] != ' ') {
                    return 0;
                }
            }
            if (check(jr2, jc2) != 0) {
                return 1;
            }
            else
                return 0;
        }
    }
    else
        return 0;
}//白色皇后 
int queenb(int jr1, int jc1, int jr2, int jc2) {

    static int i, j;

    if (jr2 == jr1 && jc2 <= jc1) {
        for (j = 1; jc1 - j > jc2; j++) {
            if (board[jr1][jc1 - i] != ' ') {
                return 0;
            }
        }
        if (check2(jr2, jc2) != 0) {
            return 1;
        }
        else
            return 0;
    }//判斷皇后使用主教和城堡的走法(以下皆是)

    if (jr2 == jr1 && jc2 >= jc1) {
        for (j = 1; jc1 + j < jc2; j++) {
            if (board[jr1][jc1 + i] != ' ') {
                return 0;
            }
        }
        if (check2(jr2, jc2) != 0) {
            return 1;
        }
        else
            return 0;
    }

    if (jr2 <= jr1 && jc2 == jc1) {
        for (i = 1; jr1 - i > jr2; i++) {
            if (board[jr1 - i][jc1] != ' ') {
                return 0;
            }
        }
        if (check2(jr2, jc2) != 0) {
            return 1;
        }
        else
            return 0;
    }

    if (jr2 >= jr1 && jc2 == jc1) {
        for (i = 1; jr1 + i < jr2; i++) {
            if (board[jr1 + i][jc1] != ' ') {
                return 0;
            }
        }
        if (check(jr2, jc2) != 0) {
            return 1;
        }
        else
            return 0;
    }

    if (jr2 - jr1 == jc2 - jc1) {
        if (jr2 <= jr1 && jc2 <= jc1) {
            for (j = 1; jc1 - j > jc2; j++) {
                if (board[jr1 - j][jc1 - j] != ' ') {
                    return 0;
                }
            }
            if (check2(jr2, jc2) != 0) {
                return 1;
            }
            else
                return 0;
        }
        if (jr2 >= jr1 && jc2 >= jc1) {
            for (j = 1; jc1 + j < jc2; j++) {
                if (board[jr1 + j][jc1 + j] != ' ') {
                    return 0;
                }
            }
            if (check2(jr2, jc2) != 0) {
                return 1;
            }
            else
                return 0;
        }
    }

    if (jr2 - jr1 == -(jc2 - jc1)) {
        if (jr2 >= jr1 && jc2 <= jc1) {
            for (j = 1; jc1 - j > jc2; j++) {
                if (board[jr1 + j][jc1 - j] != ' ') {
                    return 0;
                }
            }
            if (check2(jr2, jc2) != 0) {
                return 1;
            }
            else
                return 0;
        }
        if (jr2 <= jr1 && jc2 >= jc1) {
            for (j = 1; jc1 + j < jc2; j++) {
                if (board[jr1 - j][jc1 + j] != ' ') {
                    return 0;
                }
            }
            if (check2(jr2, jc2) != 0) {
                return 1;
            }
            else
                return 0;
        }
    }
    else
        return 0;


}//黑色皇后





void Player1()
{
    int p1, p2;
    int c1, c2, r1, r2;

    printf("\n turn the white-status\n");
again1:
    printf("\nEnter Position of Element to Move ( RC ): ");
    scanf_s("%d", &p1);

    c1 = p1 % 10 -1;//取col值 
    r1 = p1 / 10 -1;//取row值 

    switch (board[r1][c1])
    {
    case 'P': printf("You choose Pawwn on %d", p1);
        ++pwstatus[c1];
        break;
    case 'R': printf("You choose Rook on %d", p1);
        break;
    case 'N':printf("You choose Knight on %d", p1);
        break;
    case 'B': printf("You choose Bishop on %d", p1);
        break;
    case 'K': printf("You choose King on %d", p1);
        break;
    case 'Q': printf("You choose Queen on %d", p1);
        break;
    default: printf("Position Wrong! "); goto again1;
    }//判斷你要動哪個棋子 

    printf("\nEnter Position of Place to Send ( RC ): ");
    scanf_s("%d", &p2);
    c2 = p2 % 10 - 1;//取要移動到的col值
    r2 = p2 / 10 - 1;//取要移動到的row值

    switch (board[r1][c1])
    {
    case 'P': 
        pawnw(r1, c1, r2, c2);
        if (pawnw(r1, c1, r2, c2) == 1) {
            break;
        }
        else printf("This piece can't move like this!\n"); goto again1;

    case 'R':
        rookw(r1, c1, r2, c2);
        if (rookw(r1, c1, r2, c2) == 1) {
            break;
        }
        else printf("This piece can't move like this!\n"); goto again1;
    case 'N':
        knightw(r1, c1, r2, c2);
        if (knightw(r1, c1, r2, c2) == 1) {
            break;
        }
        else printf("This piece can't move like this!\n"); goto again1;
    case 'B':
        bishopw(r1, c1, r2, c2);
        if (bishopw(r1, c1, r2, c2) == 1) {
            break;
        }
        else printf("This piece can't move like this!\n"); goto again1;
    case 'K':
        kingw(r1, c1, r2, c2);
        if (kingw(r1, c1, r2, c2) == 1) {
            break;
        }
        else printf("This piece can't move like this!\n"); goto again1;
    case 'Q':
        queenw(r1, c1, r2, c2);
        if (queenw(r1, c1, r2, c2) == 1) {
            break;
        }
        else printf("This piece can't move like this!\n"); goto again1;
    }//判斷是否能走 

    if (check(r2, c2) == 2) {
        capture(&r1, &c1, &r2, &c2);
    }//判斷是否有旗子吃 
    else if (check(r2, c2) == 1) {
        change(&r1, &c1, &r2, &c2);
    }//判斷沒旗子就走 
    else {
        printf("This way can't go! Please choose another way--");
        system("pause"); goto again1;
    }
               
}//玩家一(白棋上方) 


void Player2()
{
    int p1, p2;
    int c1, c2, r1, r2;

    printf("\n turn the black-status\n");
    
again2:
    printf("\nEnter Position of Element to move (RC)-- ");
    scanf_s("%d", &p1);
   
    c1 = p1 % 10 - 1;//取col值
    r1 = p1 / 10 - 1;//取row值
    

    switch (board[r1][c1])
    {
    case 'p': printf("You choose pawn on %d", p1);
        ++pbstatus[c1];
        break;
    case 'r':  printf("You choose rook on %d", p1);
        break;
    case 'n':  printf("You choose knight on %d", p1);
        break;
    case 'b':  printf("You choose bishop on %d", p1);
        break;
    case 'k':  printf("You choose king on %d", p1);
        break;
    case 'q':  printf("You choose queen on %d", p1);
        break;
    default: printf("Position Wrong! "); goto again2;
    }//判斷你要動哪個棋子

    printf("\nEnter Position of Place to Send ( RC ): ");
    scanf_s("%d", &p2);
    c2 = p2 % 10 - 1;//取要移動到的col值
    r2 = p2 / 10 - 1;//取要移動到的row值

    switch (board[r1][c1])
    {
    case 'p':
        pawnb(r1, c1, r2, c2);
        if (pawnb(r1, c1, r2, c2) == 1) {
            break;
        }
        else printf("This piece can't move like this!"); goto again2;
    case'r':
        rookb(r1, c1, r2, c2);
        if (rookb(r1, c1, r2, c2) == 1) {
            break;
        }
        else printf("This piece can't move like this!"); goto again2;
    case'n':
        knightb(r1, c1, r2, c2);
        if (knightw(r1, c1, r2, c2) == 1) {
            break;
        }
        else printf("This piece can't move like this!"); goto again2;
    case 'b':
        bishopb(r1, c1, r2, c2);
        if (bishopb(r1, c1, r2, c2) == 1) {
            break;
        }
        else printf("This piece can't move like this!"); goto again2;
    case 'k':
        kingb(r1, c1, r2, c2);
        if (kingb(r1, c1, r2, c2) == 1) {
            break;
        }
        else printf("This piece can't move like this!"); goto again2;
    case 'q':
        queenb(r1, c1, r2, c2);
        if (queenb(r1, c1, r2, c2) == 1) {
            break;
        }
        else printf("This piece can't move like this!"); goto again2;
    }//判斷是否能走

    if (check2(r2, c2) == 2) {
        capture(&r1, &c1, &r2, &c2);
    }//判斷是否有旗子吃
    else if (check2(r2, c2) == 1) {
        change(&r1, &c1, &r2, &c2);
    }//判斷沒旗子就走
    else {
        printf("This way can't go! Please choose another way--");
        system("pause"); goto again2;
    }
    
}//玩家一(黑棋下方)
int check(int x, int y)
{
    switch (board[x][y])
    {
    case 'p': return 2;
    case 'r': return 2;
    case 'n': return 2;
    case 'b': return 2;
    case 'k': return 2;
    case 'q': return 2;
    case ' ': return 1;
    default: return 0;
    } 
}//判斷棋盤上的棋子 
int check2(int x, int y)
{
    switch (board[x][y])
    {
    case 'P': return 2;
    case 'R': return 2;
    case 'N': return 2;
    case 'B': return 2;
    case 'K': return 2;
    case 'Q': return 2;
    case ' ': return 1;
    default: return 0;
    }
}//判斷棋盤上的棋子