// Math Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
using namespace std;
enum enGameLevel {
    Easy = 1,
    Mid = 2,
    Hard = 3,
    Mix = 4,
};
enum enQuestionType {
    Add = 1,
    Sub = 2,
    Mul =3,
    Div = 4,
    Mixed = 5,
};

string GetQuestionTypeName(enQuestionType questionType) {
    switch (questionType)
    {
    case Add:
        return "Addition";
        break;
    case Sub:
        return "Subtraction";
        break;
    case Mul:
        return "Multiplication";
        break;
    case Div:
        return "Divition";
        break;
    default:
        return "Mixed";
        break;
    }
}

short ReadOnlyNumber(string msg) {
    short number;
    do
    {
        cout << msg;
        cin  >> number;
    } while (number - number != 0);
    return number;
}

bool ReadNumberInRange(short from, short to,short number) { 
  return number >= from && number <= to;
}

short ReadQuestionsCount(){
 return ReadOnlyNumber("How Many Question Do You Want To Answer ? ");
}

enGameLevel ReadGameLevel() {
    short level;
    do
    {
        level = ReadOnlyNumber("Enter Question Level [1]:Easy [2]:Mid [3]:Hard [4]:Mix ? ");
    } while (!ReadNumberInRange(1,4,level));
    return (enGameLevel)level;
}

enQuestionType ReadQuestionType() {
    short type;
    do
    {
        type = ReadOnlyNumber("Enter Question Type [1]:Add [2]:Sub [3]:Mul [4]:Div [5]:Mix ? ");
    } while (!ReadNumberInRange(1, 5, type));
    return (enQuestionType)type;
}

string GetGameLevelName(enGameLevel gameLevel) {
    switch (gameLevel)
    {
    case Easy:
        return "Easy";
        break;
    case Mid:
        return "Middle";
        break;
    case Hard:
        return "Hard";
        break;
    case Mix:
        return "Mixed";
        break;
    default:
        return "Easy";
        break;
    }
}
struct sRoundValues {
    short numerator = 0;
    short denominator = 0;
    char operationType = '+';
    short userAnswer = 0;
    short correctAnswer = 0;
    bool isUserAnswerCorrectly;
};


string PassOrFail(sGameData gameData) {
    if (gameData.IsPlayerPassed) {
        return "Pass";
    }
    else
    {
        return "Fail";
    }
}
string SadFace() {
    return ";-(";
}

string HappyFace() {
    return ":-)";
}

string SadOrHappyFace(sGameData gameData) {
    if (gameData.IsPlayerPassed) {
        return HappyFace();
    }
    else
    {
        return SadFace();
    }
}

void PrintRoundQuestionHeader(short questionNumber,short totalQuestions ) {
    cout << "Question [" << questionNumber << "/" << totalQuestions << "]" << endl;
}

struct sGameData {
    short QuestionCount = 0;
    enGameLevel GameLevel = enGameLevel::Easy;
    enQuestionType QuestionType = enQuestionType::Add;
    short RightAnswersCount = 0;
    short WrongAnswersCount = 0;
    bool IsPlayerPassed = true;
    struct sRoundValues& roundValues;
};

short ReadUserAnswer() {
    short userAnswer;
    cin >> userAnswer;
    return userAnswer;
}
char OperationType(enQuestionType questionType) {
    switch (questionType)
    {
    case Add:
        return '+';
        break;
    case Sub:
        return '-';
        break;
    case Mul:
        return '*';
        break;
    case Div:
        return '/';
        break;
    }
};

short GetRandNumberInRange(short from, short to) {
    return rand() % (to - from + 1) + from;
}

void PrintQuestionExpresion(sGameData gameData) {
    cout << gameData.roundValues.numerator << endl;
    cout << gameData.roundValues.denominator << " " << OperationType(gameData.QuestionType) << endl;
    cout << "---------------" << endl;
}



void PrintRightAnswer(sRoundValues roundValues) {
    cout << "The Answer Is : " << roundValues.correctAnswer<<endl;
}

void VerticalSpacing(short number) {
    for (short i = 0; i < number; i++)
    {
        cout << "\n";
    }
}


void BackgroundColor(bool isCorrectlyAnswerThisQuestion) {
    switch (isCorrectlyAnswerThisQuestion)
    {case true:
        system("color 2F");
        break;
    default:
        system("color 0F");
        break;
    }
}

void WrongAnswerSoundEffect(bool isCorrectlyAnswerThisQuestion){
    if (!isCorrectlyAnswerThisQuestion) {
        cout << "\a";
}
}
void ShowGameEffects(sRoundValues roundValues) {
    BackgroundColor(roundValues.isUserAnswerCorrectly);
    WrongAnswerSoundEffect(roundValues.isUserAnswerCorrectly);
}


void PrintRoundResults(sRoundValues roundValues) {
    if (roundValues.isUserAnswerCorrectly) {
        cout << "Right Answer " << HappyFace()<<endl;
    }
    else
    {
        cout << "Wrong Answer " << SadFace()<<endl;
        PrintRightAnswer(roundValues);
        
    }
    ShowGameEffects(roundValues);
    VerticalSpacing(2);
}




void ReadGameData(sGameData &gameData) {
    gameData.QuestionCount = ReadQuestionsCount();
    gameData.GameLevel = ReadGameLevel();
    gameData.QuestionType = ReadQuestionType();
}






void PlayGameRounds(sGameData gameData) {
    sRoundValues roundValue;

    for (short Question = 1; Question <= gameData.QuestionCount; Question++)
    {
        PrintRoundQuestionHeader(Question, gameData.QuestionCount);
        VerticalSpacing(1);
        PrintQuestionExpresion(gameData);
        ReadUserAnswer();
        PrintRoundResults(roundValue);
    }
}
void PrintFinalResultHeader(string passedOrFail, string face) {
    cout << "-------------------------------------" << endl;
    cout << " Final Result Is " << passedOrFail << face << endl;
    cout << "-------------------------------------" << endl;
}
void PrintFinalResultPanal(sGameData gameData) {
    cout << "Number Of Questions : " << gameData.QuestionCount << endl;
    cout << "Question Level      : " << GetGameLevelName(gameData.GameLevel) << endl;
    cout << "Operation Type      : " << GetQuestionTypeName(gameData.QuestionType) << endl;
    cout << "Number Of Right Answers: " << gameData.RightAnswersCount << endl;
    cout << "Number Of Wrong Answers: " << gameData.WrongAnswersCount << endl;
    cout << "-------------------------------------" << endl;
}

void PrintFinalResult(sGameData gameData) {
    PrintFinalResultHeader(PassOrFail(gameData), SadOrHappyFace(gameData));
    VerticalSpacing(1);
    PrintFinalResultPanal(gameData);
}
void StartGame() {
    sGameData gameData;
    ReadGameData(gameData);
    PlayGameRounds(gameData);
    PrintFinalResult(gameData);
}

void AskUserIfHeWantToPlayAgain() {
    cout << "Do You Want To Play Again? Y/N? " << endl;
}




void GameLoop() {
    char again;
    do
    {
        StartGame();
        
        AskUserIfHeWantToPlayAgain();
        cin >> again;
        
    } while (again =='Y'||again == 'y');

}

void Start() {
    ReadQuestionsCount();
    ReadGameLevel();
    ReadQuestionType();
   
}
int main()
{
    GameLoop();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
