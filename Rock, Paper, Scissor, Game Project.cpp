

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;



enum enGameChoice {Stone = 1, Paper = 2, Scissor = 3};

enum enWinner {Playr = 1, Computer = 2 , Draw = 3};

struct stRoundInfo
{
    short RoundNumber = 0; 
    enGameChoice PlayerChoice; 
    enGameChoice ComputerChoice;
    enWinner Winer; 
    string WineerName; 
};

struct stGameReslut
{
    short GameRounds = 0; 
    short PlayerWineTimes = 0;
    short ComputerWineTimes = 0;
    short DrawTimes = 0;
    enWinner GameWinner; 
    string WineerName = ""; 

};

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From; 
}

 enGameChoice ComputerChoice()
{
     return (enGameChoice)RandomNumber(1, 3);
}

 enGameChoice ReadPlayer1Choice()
 {
     short Choice; 

     do
     {
         cout << "\n Your Choice : [1]:Stone , [2]:Paper, [3]:Scissor ";
         cin >> Choice; 


     } while (Choice < 1 || Choice > 3);

     return (enGameChoice)Choice;
 } 

 string ChoiceName(enGameChoice Choice)
 {
     string ArrGameChoices[3] = { "Stone", "Paper", "Scissor" };
     return ArrGameChoices[Choice - 1];
 }

 string WinnerName(enWinner Winner)
 {
     string ArrWinnerName[3] = { "Player", "Computer", "Draw" };
     return ArrWinnerName[Winner - 1];
 }

 enWinner WhoWonTheRound(stRoundInfo RoundInfo)
 {
     if (RoundInfo.PlayerChoice == RoundInfo.ComputerChoice)
         return enWinner::Draw;

     switch (RoundInfo.PlayerChoice)
     {
     case enGameChoice::Stone:
         return (RoundInfo.ComputerChoice == enGameChoice::Paper) ? enWinner::Computer : enWinner::Playr;

     case enGameChoice::Paper:
         return (RoundInfo.ComputerChoice == enGameChoice::Scissor) ? enWinner::Computer : enWinner::Playr;

     case enGameChoice::Scissor:
         return (RoundInfo.ComputerChoice == enGameChoice::Stone) ? enWinner::Computer : enWinner::Playr;
     }
 }

 enWinner WhowonTheGame(short PlayerWineTimes, short ComputerWineTimes)
 {
     if (PlayerWineTimes > ComputerWineTimes)
         return enWinner::Playr;
     else if (ComputerWineTimes > PlayerWineTimes)
         return enWinner::Computer;
     else
         return enWinner::Draw;
 }

 void PrintRoundResult(stRoundInfo RoundInfo)
 {
     cout << "\n ------------------ Round [" << RoundInfo.RoundNumber << "] ----------------------\n\n";
     cout << " Player Choice : " << ChoiceName(RoundInfo.PlayerChoice) << endl;
     cout << " Coomputer Choice : " << ChoiceName(RoundInfo.ComputerChoice) << endl; 
     cout << " Round Winner : [" << RoundInfo.WineerName << "]\n";
     cout << "------------------------------------------\n" << endl;
 }

 stGameReslut PlayGame(short HowmanyRounds)
 {
     stRoundInfo RoundInfo;

     short PlayrWintimes = 0, ComputerWintimes = 0, DrawTimes = 0; 

     for (short GameRound = 1; GameRound <= HowmanyRounds; GameRound++)
     {
         cout << "\n Round : [" << GameRound << "] Begins: \n";

         RoundInfo.RoundNumber = GameRound; 
         RoundInfo.PlayerChoice = ReadPlayer1Choice();
         RoundInfo.ComputerChoice = ComputerChoice();
         RoundInfo.Winer = WhoWonTheRound(RoundInfo);
         RoundInfo.WineerName = WinnerName(RoundInfo.Winer);


         if (RoundInfo.Winer == enWinner::Playr)
             PlayrWintimes++;
         else if (RoundInfo.Winer == enWinner::Computer)
             ComputerWintimes++;
         else
             DrawTimes++; 

         PrintRoundResult(RoundInfo);
     }


     return{ HowmanyRounds,PlayrWintimes,ComputerWintimes,DrawTimes,WhowonTheGame(PlayrWintimes,ComputerWintimes),WinnerName(WhowonTheGame(PlayrWintimes,ComputerWintimes)) };


 }

 void StartGame()
 {
     char PlayAgain = 'Y'; 

     do 
     {
         system("cls");

         stGameReslut GameReslut = PlayGame(3);

         cout << "\n Game Over ! Winner :" << GameReslut.WineerName << endl; 

         cout << "\n DO you want to play agian (Y/N) : ";
         cin >> PlayAgain; 

     } while (PlayAgain == 'Y' || PlayAgain == 'y');
 }

int main()
{
    srand((unsigned)time(NULL));
    StartGame();



    return 0; 
}
