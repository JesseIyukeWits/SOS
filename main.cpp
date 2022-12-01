#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

class game {

public:
    game();

    void initBoard(int a,char board[][16]);
    void MovP1(int a,char board[][16],ofstream &outFile);
     void MovP2(int a,char board[][16],ofstream &outFile);


private:

};

game::game()
{
}


void game::initBoard(int a,char board[][16]) //initiliases board with size of board and refrencing
{

    for(int r=0; r<a; r++) // loop that goes through entire board
    {
        for(int c=0; c<a ; c++)
        {
            board[r][c]= '#'; //empty spaces

        }
    }
}

void game::MovP1(int a,char board[][16],ofstream &outFile)
{
    int r, c, i=1, s=2;
    int count=0;
    int player1=0;

    int n,t,y;

    vector<int>ValR;
    vector<int>ValC;

        srand(time(0));
     y=(rand()%2);




    for(c=0; c<a; c++)
    {
        for(r=0; r<a; r++)
        {


            if(board[r][c]=='#')
            {
                //looks for 'O' around the 8 directions for an empty space

                //  left to right
                if(board[r+i][c]=='O')
                {

                    if(board[r+s][c]=='S')
                    {
                        board[r][c]='U';
                        count++;
                    }

                }
                //right to left
                if(board[r-i][c]=='O')
                {

                    if(board[r-s][c]=='S')
                    {
                        board[r][c]='U';
                         count++;
                    }

                }
                // Up to down
                if(board[r][c+i]=='O')
                {


                    if(board[r][c+s]=='S')
                    {
                        board[r][c]='U';
                         count++;
                    }


                }
                //Down to up
                if(board[r][c-i]=='O')
                {

                    if(board[r][c-s]=='S')
                    {
                        board[r][c]='U';
                         count++;
                    }

                }

                //Diagonals


                if(board[r+i][c+i]=='O')
                {
                    if(board[r+s][c+s]=='S')
                    {
                        board[r][c]='U';
                         count++;

                    }
                }

                if(board[r-i][c-i]=='O')
                {

                    if(board[r-s][c-s]=='S')
                    {
                        board[r][c]='U';
                         count++;
                    }

                }

                if(board[r-i][c+i]=='O'&&r>=0&&c>=0)
                {

                    if(board[r-s][c+s]=='S')
                    {
                        board[r][c]='U';
                         count++;

                    }

                }
                if(board[r+i][c-i]=='O')
                {

                    if(board[r+s][c-s]=='S')
                    {

                        board[r][c]='U';
                         count++;

                    }

                }
            }

        }

    }

    for(c=0; c<a; c++)
    {
        for(r=0; r<a; r++)
        {
            if(count==0)
            {
                for(r=0; r<a; r++)
                {
                    for(c=0; c<a; c++)
                    {
                        if(board[r][c]=='#')
                        {
                            //row and column inicies enter vector list

                            ValR.push_back(r);
                            ValC.push_back(c);

                        }
                    }
                }

                //random choice in list
                srand(time(0));
                t=ValR.size();
                n=(rand()%t);
                y=(rand()%2);

                if(y==0)
                {
                    outFile<<"Player1: "<<"r"<<ValR[n]<<"c"<<ValC[n]<<" O"<<endl;
                    board[ValR[n]][ValC[n]]='O';
                }
                else if(y==1)
                {
                    board[ValR[n]][ValC[n]]='S';
                    outFile<<"Player1: "<<"r"<<ValR[n]<<"c"<<ValC[n]<<" S"<<endl;

                }
            }
            else if(count>0)
            {
                for(r=0; r<a; r++)
                {
                    for(c=0; c<a; c++)
                    {
                        if(board[r][c]=='U')
                        {
                            board[r][c]='S';
                            outFile<<"Player1: "<<"r"<<r<<"c"<<c<<" S"<<endl;

                            player1++;
                        }
                    }
                }
            }
        }
    }
    count=0;

}



void game::MovP2(int a,char board[][16],ofstream &outFile)
{
    int r, c, i=1, s=2;
    int count=0;
    int player2=0;

    int n,t,y;

    vector<int>ValR;
    vector<int>ValC;

    srand(time(0));
     y=(rand()%2);



    for(c=0; c<a; c++)
    {
        for(r=0; r<a; r++)
        {

            if(board[r][c]=='#')
            {
                if(board[r+i][c]=='O')
                {
                    if(board[r+s][c]=='S')
                    {
                        board[r][c]='U';
                        count++;
                    }

                }
                if(board[r-i][c]=='O')
                {

                    if(board[r-s][c]=='S')
                    {
                        board[r][c]='U';
                         count++;
                    }

                }
                if(board[r][c+i]=='O')
                {


                    if(board[r][c+s]=='S')
                    {
                        board[r][c]='U';
                         count++;
                    }


                }
                if(board[r][c-i]=='O')
                {

                    if(board[r][c-s]=='S')
                    {
                        board[r][c]='U';
                         count++;
                    }

                }


                if(board[r+i][c+i]=='O')
                {
                    if(board[r+s][c+s]=='S')
                    {
                        board[r][c]='U';
                         count++;

                    }
                }

                if(board[r-i][c-i]=='O')
                {

                    if(board[r-s][c-s]=='S')
                    {
                        board[r][c]='U';
                         count++;
                    }

                }

                if(board[r-i][c+i]=='O'&&r>=0&&c>=0)
                {

                    if(board[r-s][c+s]=='S')
                    {
                        board[r][c]='U';
                         count++;

                    }

                }
                if(board[r+i][c-i]=='O')
                {

                    if(board[r+s][c-s]=='S')
                    {

                        board[r][c]='U';
                         count++;

                    }

                }
            }

        }

    }

    for(c=0; c<a; c++)
    {
        for(r=0; r<a; r++)
        {
            if(count==0)
            {
                for(r=0; r<a; r++)
                {
                    for(c=0; c<a; c++)
                    {
                        if(board[r][c]=='#')
                        {
                            ValR.push_back(r);
                            ValC.push_back(c);

                        }
                    }
                }
                srand(time(0));
                t=ValR.size();

                n=(rand()%t);



                if(y==0)
                {
                    outFile<<"Player2: "<<"r"<<ValR[n]<<"c"<<ValC[n]<<" O"<<endl;

                    board[ValR[n]][ValC[n]]='O';
                }
                else
                {
                    board[ValR[n]][ValC[n]]='S';
                    outFile<<"Player2: "<<"r"<<ValR[n]<<"c"<<ValC[n]<<" S"<<endl;

                }
            }
            else
            {
                for(r=0; r<a; r++)
                {
                    for(c=0; c<a; c++)
                    {
                        if(board[r][c]=='U')
                        {
                            board[r][c]='S';
                            outFile<<"Player2: "<<"r"<<r<<"c"<<c<<" S"<<endl;
                            player2++;
                            outFile<<"Player2: point scored"<<endl;
                        }
                    }
                }
            }
        }
    }
    count=0;

}



int main()
{

    ifstream inFile;
    ofstream outFile;

    inFile.open("input.txt");
    outFile.open("output.txt");

    int  h;// number of spots it can fill
     int a; //size of board

   while(inFile>>a)
   {
        h=(a*a);

    game obj; //object for class 'game'



    char board[a][16];

    outFile<<"size = "<<a<<endl;

    obj.initBoard(a,board);

for(int i=0; i<h; i)
{
        if(i%2==0)
        {
            //player 1 turn
            obj.MovP1(a,board,outFile);
            i++;
        }
        else if(i%2==1)
        {
            //player 2 turn
            obj.MovP2(a,board,outFile);
            i++;
        }

}

   }

    inFile.close();
    outFile.close();




    return 0;

}
