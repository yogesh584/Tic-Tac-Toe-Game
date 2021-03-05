#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int genrateRandomeNumber() // this function is used to genrate random number
{
    srand(time(NULL));
    return rand() % 10;
}

int main()
{
    int position, previous_position[9]; // We create position varible to get in waht position user want to get value and previous_position array is used to check that user or computer not entered same position again.

    char array[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}; // this array is used to get values and type is char because we need 'X' and 'O' to display and starting values is added because we need to display starting values to user

    for (int i = 0; i < 10; i++)
    {
        system("cls"); // this is very important because every time when user entered values then we want to display values from entered by user in same matrix or same Game

        // This is the Game Stracture

        printf("     |     |     \n");
        printf("  %c  |  %c  |  %c   \n", array[0][0], array[0][1], array[0][2]);
        printf("_____|_____|_____\n");
        printf("     |     |     \n");
        printf("  %c  |  %c  |  %c   \n", array[1][0], array[1][1], array[1][2]);
        printf("_____|_____|_____\n");
        printf("     |     |     \n");
        printf("  %c  |  %c  |  %c   \n", array[2][0], array[2][1], array[2][2]);
        printf("     |     |     \n");

        // ----------------------------------------------------------------------------------------------------------------------------------------------------------
        // Here we will check that who is the winner with every special condition

        if ((array[0][0] == 'X' && array[0][1] == 'X' && array[0][2] == 'X')
         || (array[0][0] == 'X' && array[1][0] == 'X' && array[2][0] == 'X')
         || (array[0][0] == 'X' && array[1][1] == 'X' && array[2][2] == 'X')
         || (array[2][2] == 'X' && array[2][1] == 'X' && array[2][0] == 'X')
         || (array[2][2] == 'X' && array[1][2] == 'X' && array[0][2] == 'X') 
         || (array[0][2] == 'X' && array[1][1] == 'X' && array[2][0] == 'X') 
         || (array[1][0] == 'X' && array[1][1] == 'X' && array[1][2] == 'X') 
         || (array[0][1] == 'X' && array[1][1] == 'X' && array[2][1] == 'X'))
        {
            printf("\n-------------------------------------------------------------\n");
            printf("\nPlayer 1 Wins !\n");
            printf("\n-------------------------------------------------------------\n");
            break;
        }
        else if ((array[0][0] == 'O' && array[0][1] == 'O' && array[0][2] == 'O') 
             ||  (array[0][0] == 'O' && array[1][0] == 'O' && array[2][0] == 'O') 
             ||  (array[0][0] == 'O' && array[1][1] == 'O' && array[2][2] == 'O') 
             ||  (array[2][2] == 'O' && array[2][1] == 'O' && array[2][0] == 'O') 
             ||  (array[2][2] == 'O' && array[1][2] == 'O' && array[0][2] == 'O') 
             ||  (array[0][2] == 'O' && array[1][1] == 'O' && array[2][0] == 'O') 
             ||  (array[1][0] == 'O' && array[1][1] == 'O' && array[1][2] == 'O') 
             ||  (array[0][1] == 'O' && array[1][1] == 'O' && array[2][1] == 'O'))
        {
            printf("\n-------------------------------------------------------------\n");
            printf("\nComputer Wins !\n");
            printf("\n-------------------------------------------------------------\n");
            break;
        }

        // we don't want get values from user after completing so we fix the value that if i == 9 then say Draw and quit the Game

        if (i == 9)
        {
            printf("\n-------------------------------------------------------------\n");
            printf("\nThis Game is Draw !\n");
            printf("\n-------------------------------------------------------------\n");
            break;
        }

        // ------------------------------------------------------------------------------------------------------------------------------------------------
        // In this section we just get the values from user and computer 

        if (i == 0 || i % 2 == 0) // we just say that if i == 0 or i == 2 or i == 4 and so on. for that this is user turn
        {
            start1: // it is neccary because when user entered previous position again then it will help us to goto this section again and remember it can't be done by continue statement

            printf("Enter a number to choose a position : ");
            printf("Player 1 : ");
            scanf("%d", &position); // Getting values from User as we describe in the comment in the line number : 13
        }

        else
        {
            printf("Computer's Turn !\n");

            start3: // it is nessary because computer is genrating random number then if genrated number by comnputer is same of previous number then we just say that goto start3 to check this go next section

            position = genrateRandomeNumber(); // Getting values from Computer in position varible

            // as we know that computer is genrating random number between 0 to 9 but we dont need 0  so we just say that if position == 0  then goto start3 

            if (position == 0)
            {
                goto start3; // as we descibe we just say when position == 0  then goto start3
            }
        }

        // ------------------------------------------------------------------------------------------------------------------------------------------------------
        // This is section for checking the number then entered by user or genrated by computer is not similar to previous values 

        int j = 0;
        start2: // this is also very neccery because when frist previous value is not match to position then we need to go up to check another values. it can't be done by continue statement because continue through you outside of parent loop but we only need to child loop and I think there is no another way.
        for (; j < i; j++)
        {
            if (i == 0 || i % 2 == 0) // As I already tell you that this is for person not for computer.
            {
                if (previous_position[j] == position)
                {
                    printf("\n------------------------------------------------------------------\n");
                    printf("This Position is Already Selected");
                    printf("\n------------------------------------------------------------------\n");
                    goto start1; // As I tell you that if position == previous position then goto start1.
                }
                else // if not match then got to start2 because it checked previous one value but not all previous values so check all the values we just say that goto start2
                {
                    j++; // we need to increase value of j because we want to check another values not same again.
                    goto start2;
                }
            }
            else // this is for computer entered value checking not person and this is simalar like person checking
            {
                if (previous_position[j] == position)
                {
                    goto start3;
                }
                else
                {
                    j++;
                    goto start2;
                }
            }
        }

        // ------------------------------------------------------------------------------------------------------------------------------------------------------
        // This section is to change array values from numbers to 'X' or 'O' And this is important part for player

        if (position == 1) // we simply say for every situatiion that if computer enters value then change numeric value to 'O' and if in position person entered value then change numeric value to 'X' as you can see
        {
            if (i == 0 || i % 2 == 0) // This is for person
            {
                array[0][0] = 'X';
            }
            else // this is for computer
            {
                array[0][0] = 'O';
            }
        }
        else if (position == 2)
        {
            if (i == 0 || i % 2 == 0)
            {
                array[0][1] = 'X';
            }
            else
            {
                array[0][1] = 'O';
            }
        }
        else if (position == 3)
        {
            if (i == 0 || i % 2 == 0)
            {
                array[0][2] = 'X';
            }
            else
            {
                array[0][2] = 'O';
            }
        }
        else if (position == 4)
        {
            if (i == 0 || i % 2 == 0)
            {
                array[1][0] = 'X';
            }
            else
            {
                array[1][0] = 'O';
            }
        }
        else if (position == 5)
        {
            if (i == 0 || i % 2 == 0)
            {
                array[1][1] = 'X';
            }
            else
            {
                array[1][1] = 'O';
            }
        }
        else if (position == 6)
        {
            if (i == 0 || i % 2 == 0)
            {
                array[1][2] = 'X';
            }
            else
            {
                array[1][2] = 'O';
            }
        }
        else if (position == 7)
        {
            if (i == 0 || i % 2 == 0)
            {
                array[2][0] = 'X';
            }
            else
            {
                array[2][0] = 'O';
            }
        }
        else if (position == 8)
        {
            if (i == 0 || i % 2 == 0)
            {
                array[2][1] = 'X';
            }
            else
            {
                array[2][1] = 'O';
            }
        }
        else if (position == 9)
        {
            if (i == 0 || i % 2 == 0)
            {
                array[2][2] = 'X';
            }
            else
            {
                array[2][2] = 'O';
            }
        }
        previous_position[i] = position; // now we need to add previous values to checking
    }

    return 0;
}

// Completed And Working Properly