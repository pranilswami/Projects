#include<stdio.h>
#include<stdbool.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<windows.h>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"
int k=1,j=0;
int n=15,i=0,a[16];
int temp=0;char enter=0;
int p=3,r=3;           // p = rows and r = columns
char check;

void randomnum(int num[][4])
{
    int n=15;
    int arr[n], i=0, j=0;
    for (i = 0; i < 15; i++) // These 1-15 number will be in th matrix
        arr[i] = i + 1;

    srand(time(NULL)); // for random number generation

    int lastIndex = n - 1, index;
     
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
        {
            if (lastIndex >= 0)
            {
                index = rand() % (lastIndex + 1); // idea : performing % operation by (lastIndex+1)
                num[i][j] = arr[index];           // will give index , so put that num[index] number in matrix
                arr[index] = arr[lastIndex--];    // and replace last number with this indexed positioned number
            }                                     // and finally lastIndex--
        }
    num[i - 1][j - 1] = 0; // last number is zero
}

int swap(int num[][4])
{
    int c = 0;
    getch();
       
        switch (getch())  //ascii code will generate while pressing cursor control keys
        {
        case KEY_UP:                    
                    temp=num[p-1][r];
                    num[p-1][r]=num[p][r];
                    num[p][r]=temp;
                    p--;
                    if(p<0)
                    {
                        printf("Invalid");

                        return 0;
                    }
                    return 1;
                    break;
        case KEY_DOWN:
                    temp=num[p+1][r];
                    num[p+1][r]=num[p][r];
                    num[p][r]=temp;
                    p++;
                    if(p>3)
                    {
                        printf("Invalid");
                        return 0;
                    }
                    return 1;
                    break;
        case KEY_LEFT:
                    temp=num[p][r-1];
                    num[p][r-1]=num[p][r];
                    num[p][r]=temp;
                    r--;
                    if(r<0)
                    {
                        printf("Invalid");
                        return 0;
                    }
                    return 1;
                    break;
        case KEY_RIGHT:
                    temp=num[p][r+1];
                    num[p][r+1]=num[p][r];
                    num[p][r]=temp;
                    r++;
                    if(r>3)
                    {
                        printf("Invalid");
                        return 0;
                    } 
                    return 1;
                    break;
        case KEY_ESC:
                    return 0;
                    break;
        default:
            printf("Null\n");
            break;
        }
       
}
//Display Matrix
void show(int num[][4])
{
    
    system("cls");
    printf("\n\n");
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            printf(" | ");
            if(num[i][j]==0)
            printf("  ");
            else
            printf("%2d",num[i][j]);
        }
        printf(" |");
        printf("\n");
    }
}
// Game Rule
int gameRule()
{
    system("cls");
    int i, j, k = 1;
    int str[4][4];
    printf("\t\t  MATRIX PUZZLE\n");
    printf("\n");
    printf(ANSI_COLOR_RED "                 RULE OF THIS GAME                 \n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_RED "\n1.You can move only 1 step at a time by arrow key " ANSI_COLOR_RESET);
    printf("\n\tMove Up   : by Up arrow key ");
    printf("\n\tMove Down : by Down arrow key");
    printf("\n\tMove Left : by Left arrow key");
    printf("\n\tMove Right: by Right arrow key");

    printf(ANSI_COLOR_RED "\n2.You can move empty position at any space " ANSI_COLOR_RESET);
    printf("\n");
    printf(ANSI_COLOR_RED "\n3. For each valid move : your total number of move will decreased by 1 \n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_RED "4. Wining situation : " ANSI_COLOR_RESET);
    printf(ANSI_COLOR_RED " Number in a 4*4 matrix should be in order from 1 to 15 " ANSI_COLOR_RESET);
    printf("\n\n            winning situation:         \n");

    printf(ANSI_COLOR_YELLOW "---------------------\n" ANSI_COLOR_RESET);

    for (i = 0; i < 4; i++)
    {
        printf(ANSI_COLOR_YELLOW "| " ANSI_COLOR_RESET);
        for (j = 0; j < 4; j++)
        {

                if(i==3&&j==3)
                printf(ANSI_COLOR_YELLOW "   |" ANSI_COLOR_RESET);
                else
                printf(ANSI_COLOR_YELLOW "%2d | " ANSI_COLOR_RESET, 4 * i + j + 1);
            
        }
        printf("\n");
    }

    printf(ANSI_COLOR_YELLOW "---------------------\n" ANSI_COLOR_RESET);
    printf("\n5.You can exit the game at any time by pressing 'Escape key'");

    printf("\nSo Try to win in minimum no of move \n");

    printf("\nEnter any key to start.....   ");
    
    int c=getch();
    if(c==10)
    return 0;
}
//Winning Case
int winningcase(int num[][4])
{
    int k=1;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++,k++)
        {
            if(num[i][j]==' ' && k==16)
            {
                return 1;   
            }
            if(num[i][j]!=k)
            {
                return 0;
            }
        }
    }
}

//Main Function
int main()
{
    system("cls");
    int str[4][4];
    for (int k = 0; k < 3; k++)
        printf("\n");
    char name[20];
    printf("Player Name: ");
    gets(name);
    system("cls"); // to clear screen
    gameRule();    //game's rules
    system("cls");
    int q,count=1000;
    int num[4][4];
    
     while (1)
    { 
        randomnum(num);
       
        show(num);

        while(count!=0)
        {   
            if(winningcase(num)==1)
            {
                printf(ANSI_COLOR_GREEN"\n\nAns----------------- You WIN -----------------\n"ANSI_COLOR_RESET);
                break;
            }
            printf("\n\nPlayer Name : %s\n",name);
            printf("\nMove remaining : %d\n",count);
            q=swap(num);
            if(q==0)
            break;
            else
            show(num);
            count--;
        }
        if(count==0)
          if(winningcase(num)==0)
          {
            printf(ANSI_COLOR_RED"\n\n----------------- You LOSE -----------------\n"ANSI_COLOR_RESET);
          }
        fflush(stdin);
        char check;
        printf(ANSI_COLOR_GREEN "\nWant to play again ? \n" ANSI_COLOR_RESET);
        printf("enter 'y' to play again:  ");
        scanf("%c", &check);
        
        if ((check != 'y') && (check != 'Y'))
            break;
        system("cls");
        count = 300;
        p=3,r=3;
    }
     
    return 0; 
   
}
/*
This game involve 4x4 matrix in which 15 numbers are placed randomly and there is 1 empty space.
By using that space we need to arrange the 15 numbers in order e.g. 1,2,3...15.
This purely made in C programming language.
*/