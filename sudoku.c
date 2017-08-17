#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void sudoku_read(int v[][9])
{
    FILE *sudoku = fopen("sudoku.txt", "r");
    int i,j;

    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
            fscanf(sudoku, "%d", &v[i][j]);

    fclose(sudoku);
}

void sudoku_print(int v[][9])
{
    int i,j;

    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        // {   if(v[i][j] != 0)
                printf("%d  ", v[i][j]);
            // else
            //     printf("   ");
        // }

        printf("\n");
    }
}

bool sudoku_check(int v[][9], int value, int lin, int col)
{
    int i, j;

    for(i=0;i<9;i++) //checking the line
        if(v[lin][i] == value)
            return false;

    for(i=0;i<9;i++) //checking the col
        if(v[col][i] == value)
            return false;

    if(lin < 3 && col < 3) //first sub square
    {
        for(i=0;i<3;i++)
            for(j=col;j<3;j++)
                if(v[i][j] == value)
                    return false;
    }
    else if(lin < 3 && col < 6) //second sub square
    {
            for(i=0;i<3;i++)
                for(j=col;j<6;j++)
                    if(v[i][j] == value)
                        return false;
    }
    else if(lin < 3 && col < 9) //third sub square
    {
            for(i=0;i<3;i++)
                for(j=col;j<9;j++)
                    if(v[i][j] == value)
                        return false;
    }
    if(lin < 6 && col < 3) //first sub square
    {
        for(i=3;i<6;i++)
            for(j=col;j<3;j++)
                if(v[i][j] == value)
                    return false;
    }
    else if(lin < 6 && col < 6) //second sub square
    {
            for(i=3;i<6;i++)
                for(j=col;j<6;j++)
                    if(v[i][j] == value)
                        return false;
    }
    else if(lin < 6 && col < 9) //third sub square
    {
            for(i=3;i<6;i++)
                for(j=col;j<9;j++)
                    if(v[i][j] == value)
                        return false;
    }
    if(lin < 9 && col < 3) //first sub square
    {
        for(i=6;i<9;i++)
            for(j=col;j<3;j++)
                if(v[i][j] == value)
                    return false;
    }
    else if(lin < 9 && col < 6) //second sub square
    {
            for(i=6;i<9;i++)
                for(j=col;j<6;j++)
                    if(v[i][j] == value)
                        return false;
    }
    else if(lin < 9 && col < 9) //third sub square
    {
            for(i=6;i<9;i++)
                for(j=col;j<9;j++)
                    if(v[i][j] == value)
                        return false;
    }

    return true;
}

bool sudoku_solve(int v[][9], int lin, int col)
{
    int value;

    for(i=lin;i<9;i++)
    {
        for(j=col;j<9;j++)
        {
            if(v[i][j] == 0)
            {
                for(value = 1; value < 10; value++)
                {
                    if(sudoku_check(s, value, i, j))
                    {
                        v[i][j] = value;
                    }
                    else
                        continue;

                    if(sudoku_solve(v, i, j))
                    {
                        return true;
                    }
                }

                return false;
            }
        }
    }
    return false;
}

int main()
{
    int s[9][9];

    sudoku_read(s);
    // sudoku_print(s);
    sudoku_solve(s, 0, 0);

    return 0;
}
