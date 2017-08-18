#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SUDOKU_SIZE 81
#define SUDOKU_COL_NUM 9
#define SUDOKU_LIN_NUM 9

void sudoku_read(int v[SUDOKU_SIZE])
{
    FILE *sudoku = fopen("sudoku.txt", "r"); //reading sudoku file
    int i;

    for(i=0;i<SUDOKU_SIZE;i++)
        fscanf(sudoku, "%d", &v[i]);

    fclose(sudoku);
}

void sudoku_print(int v[SUDOKU_SIZE]) //Print sudoku into display
{
    int i,j;

    for(i=0;i<SUDOKU_COL_NUM;i++)
    {
        for(j=0;j<SUDOKU_COL_NUM;j++)
            printf("%d ", v[i*SUDOKU_COL_NUM + j]);

        printf("\n");
    }
}

bool sudoku_check(int v[SUDOKU_SIZE], int value, int pos)
{
    int i, j;
    int lin, col;

    lin = pos / SUDOKU_COL_NUM; //getting the line number
    col = pos % SUDOKU_COL_NUM; //getting the column number

    for(i=0; i<SUDOKU_COL_NUM; i++) //checking the line
        if(v[lin*SUDOKU_COL_NUM + i] == value)
            return false;

    for(i=0; i<SUDOKU_LIN_NUM; i++) //checking the col
        if(v[i*SUDOKU_COL_NUM + col] == value)
            return false;

    if(lin < 3 && col < 3) //first upper sub square
    {
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
                if(v[i*SUDOKU_COL_NUM + j] == value)
                    return false;
    }
    else if(lin < 3 && col < 6) //second upper sub square
    {
            for(i=0;i<3;i++)
                for(j=3;j<6;j++)
                    if(v[i*SUDOKU_COL_NUM + j] == value)
                        return false;
    }
    else if(lin < 3 && col < 9) //third upper sub square
    {
            for(i=0;i<3;i++)
                for(j=6;j<9;j++)
                    if(v[i*SUDOKU_COL_NUM + j] == value)
                        return false;
    }
    else if(lin < 6 && col < 3) //first middle sub square
    {
        for(i=3;i<6;i++)
            for(j=0;j<3;j++)
                if(v[i*SUDOKU_COL_NUM + j] == value)
                    return false;
    }
    else if(lin < 6 && col < 6) //second middle sub square
    {
            for(i=3;i<6;i++)
                for(j=3;j<6;j++)
                    if(v[i*SUDOKU_COL_NUM + j] == value)
                        return false;
    }
    else if(lin < 6 && col < 9) //third middle sub square
    {
            for(i=3;i<6;i++)
                for(j=6;j<9;j++)
                    if(v[i*SUDOKU_COL_NUM + j] == value)
                        return false;
    }
    else if(lin < 9 && col < 3) //first lower sub square
    {
        for(i=6;i<9;i++)
            for(j=0;j<3;j++)
                if(v[i*SUDOKU_COL_NUM + j] == value)
                    return false;
    }
    else if(lin < 9 && col < 6) //second lower sub square
    {
            for(i=6;i<9;i++)
                for(j=3;j<6;j++)
                    if(v[i*SUDOKU_COL_NUM + j] == value)
                        return false;
    }
    else if(lin < 9 && col < 9) //third lower sub square
    {
            for(i=6;i<9;i++)
                for(j=6;j<9;j++)
                    if(v[i*SUDOKU_COL_NUM + j] == value)
                        return false;
    }

    return true;
}

bool sudoku_solve(int v[SUDOKU_SIZE], int pos) //Function that find the sudoku solution
{
    int value, i, j;

    for(i = pos; i < SUDOKU_SIZE; i++)
    {
        if(v[i] == 0)
        {
            for(value = 1; value < 10; value++)
            {
                if(sudoku_check(v, value, i))
                {
                    v[i] = value;
                }
                else
                {
                    continue;
                }

                if(sudoku_solve(v, i+1))
                    return true;
                v[i] = 0;
            }
            return false;
        }
    }
    return true;
}

int main()
{
    int s[SUDOKU_SIZE], i;
    bool test = true;

    sudoku_read(s); //Read the sudoku
    if(sudoku_solve(s, 0)) //Find the solution
    {
        printf("Solution found!!!\n");
        sudoku_print(s); //print solution
    }
    else
    {
        printf("Solution doesn't exist!!!\n");
    }

    return 0;
}
