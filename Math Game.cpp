
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std; 

enum enQuestionLevel { EasyLevel = 1, Hardlevel = 2, MidLevel = 3 , Mix = 4 };

enum enOperationType {Add = 1, Sub = 2, Div = 3, Mult = 4 , MixOp = 5};

int RandomNumber(int To, int From)
{
    return  rand() % (To - From + 1) + From;
}

string GetOpTypeSympole(enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::Add: return "+";
    case enOperationType::Sub:return "-";
    case enOperationType::Div:return"/";
    case enOperationType::Mult:return "*";
    default: return "+"; 

    }
}

enOperationType GetRandomOpType()
{

    return (enOperationType)RandomNumber(4, 1);
   

}

string GetQuestionLevelText(enQuestionLevel QuestionLevel)
{
    string ArrQuestionLevel[4] = { "Easy", "Medium", "Hard", "Mixed" };
    return ArrQuestionLevel[QuestionLevel - 1]; 
}

enQuestionLevel ReadQuestionLevel()
{
    short QuestionLevel = 0;

    do
    {
        cout << " Please Enter The Question Level { [1] EasyLevel, [2] Hardlevel, [3] MidLevel , [4] Mix }" << endl; 
        cin >> QuestionLevel;
    } while (QuestionLevel < 1 || QuestionLevel > 4);

    return (enQuestionLevel)QuestionLevel; 
}

enOperationType ReadOpType()
{
    short OpType ; 

    do
    {
        cout << "Please Enter Operation Type {[1] Add, [2] Sub, [3] Div, [4] Mult , [5] Mix} " << endl;
        cin >> OpType; 

    } while (OpType < 1 || OpType > 5);

    return (enOperationType)OpType;
}

void SetScreenColor(bool right)
{
	 

    if (right)
        system("color 2F");
    else
    {
        system("color 4F");

        cout << "\a";
    }
}

int SimpleCalculater(int Number1, int Number2, enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::Add:return Number1 + Number2; 
       
    case enOperationType::Sub:return Number1 - Number2; 

    case enOperationType::Mult:return Number1 * Number2;

    case enOperationType::Div:return Number1 / Number2;

    default: return Number1 + Number2;

    }
}

struct stQuestion
{
    int Number1 = 0; 

    int Number2 = 0; 

    enQuestionLevel QuestionLevel; 

    enOperationType OperationType; 

    short PlayerAnswer = 0; 

    short CorectAnswer = 0; 

    bool AnswerResult = false; 
};

struct stQuizz
{
    stQuestion QuestionList[100]; 

    short NumberOfQuestions = 0;

    enQuestionLevel QuestionLevel;

    enOperationType OpType; 

    short NumberofCorectAnswers = 0;

    short NumberofWrongAnswers = 0; 

    bool IsPass = false; 

};

stQuestion GenerateQuestions(enQuestionLevel QuestionLevel, enOperationType OpType)
{
    stQuestion Question; 

    if (QuestionLevel == enQuestionLevel::Mix)
        QuestionLevel = (enQuestionLevel)RandomNumber(3, 1);

        

    if (OpType == enOperationType::MixOp)
        OpType = GetRandomOpType();


		

    Question.OperationType = OpType; 

    switch (QuestionLevel)
    {
    case enQuestionLevel ::EasyLevel:
        Question.Number1 = RandomNumber(1, 10);
        Question.Number2 = RandomNumber(1, 10);

        break; 

    case enQuestionLevel::MidLevel:
        Question.Number1 = RandomNumber(10, 50);
        Question.Number2 = RandomNumber(10, 50);

        break; 

    case enQuestionLevel::Hardlevel:
        Question.Number1 = RandomNumber(50, 100);
        Question.Number2 = RandomNumber(50, 100);

        break;
    }

    Question.CorectAnswer = SimpleCalculater(Question.Number1, Question.Number2, Question.OperationType);

    Question.QuestionLevel = QuestionLevel;


    return Question;

}

void GenerateQuizzQuestions(stQuizz& Quizz)
{
    for (short Question = 0; Question < Quizz.NumberOfQuestions; Question++)
    {
        Quizz.QuestionList[Question] = GenerateQuestions(Quizz.QuestionLevel, Quizz.OpType);
    }
}

void AskandCorectQuestionListAnswers(stQuizz& Quizz)
{
    for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestions; QuestionNumber++)
    {
        cout << "\nQustion[" << QuestionNumber + 1 << "/" << Quizz.NumberOfQuestions << "]\n";

        cout << Quizz.QuestionList[QuestionNumber].Number1;

        cout << GetOpTypeSympole(Quizz.QuestionList[QuestionNumber].OperationType) << " ";

        cout << Quizz.QuestionList[QuestionNumber].Number2 << "=";

        cin >> Quizz.QuestionList[QuestionNumber].PlayerAnswer;

        if (Quizz.QuestionList[QuestionNumber].PlayerAnswer == Quizz.QuestionList[QuestionNumber].CorectAnswer)
        {
            cout << "Corect Answer\n";
            Quizz.NumberofCorectAnswers++;
        }

        else
        {
            cout << " Wrong!  Corect Answer " << Quizz.QuestionList[QuestionNumber].CorectAnswer << endl;

            Quizz.NumberofWrongAnswers++;
        }

        Quizz.IsPass = (Quizz.NumberofCorectAnswers >= Quizz.NumberofWrongAnswers);
   
    }
}

void PrintTheQuestion(stQuizz& Quizz, short QuestionNumber)
{
    cout << "\n";
    cout << " Question [" << QuestionNumber + 1 << "/" << Quizz.NumberOfQuestions << "] \n\n";
    cout << Quizz.QuestionList[QuestionNumber].Number1 << endl; 
    cout << Quizz.QuestionList[QuestionNumber].Number2 << " ";
    GetOpTypeSympole(Quizz.QuestionList[QuestionNumber].OperationType);
    cout << "\n-----------------" << endl; 
}

short ReadhowmanyQuestions()
{
    short NumberofQuestions = 0;

    do
    {
        cout << " How Many Questions do you want to Answer ? " << endl; 
        cin >> NumberofQuestions;

    } while (NumberofQuestions < 1 || NumberofQuestions > 10);

    return NumberofQuestions; 
}

int ReadQuestionAnswer()
{
    int Answer = 0; 

    cin >> Answer; 

    return Answer;
}

void PlayGame()
{
    stQuizz Quizz;

    Quizz.NumberOfQuestions = 5;

    Quizz.QuestionLevel = enQuestionLevel::EasyLevel;

    Quizz.OpType = enOperationType::MixOp;


    for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestions; QuestionNumber++)
    {
        Quizz.QuestionList[QuestionNumber] = GenerateQuestions(Quizz.QuestionLevel, Quizz.OpType);
    }

    AskandCorectQuestionListAnswers(Quizz);

    cout << "\nQuizz completed ! Right Answers " << Quizz.NumberofCorectAnswers;

    cout << " Wrong Answers :" << Quizz.NumberofWrongAnswers << "\n";

    cout << (Quizz.IsPass ? " You Passed The Quizz " : "You Failed the Quizz\n");
}

void PlaymMathGame()
{
    stQuizz Quizz;

    Quizz.NumberOfQuestions = ReadhowmanyQuestions();
    
    Quizz.QuestionLevel = ReadQuestionLevel();

    Quizz.OpType = ReadOpType();

    GenerateQuizzQuestions(Quizz);

    AskandCorectQuestionListAnswers(Quizz);

   


}

void RestScreen()
{
    

    system("cls");
    system("color 0F");


	
   
}

void StartGame()
{
    char Play = 'Y';

    do
    {

        
        RestScreen();
  
        PlaymMathGame();


        cout << " Do you want to Play Again (Y/N)? " << endl; 
        cin >> Play; 
    } while (Play == 'Y' || Play == 'y');

    
}




int main()
{
    srand((unsigned)time(NULL));
    StartGame();
    
   

    

    return 0;
}
