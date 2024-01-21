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
struct sGameData {
    short QuestionCount = 0;
    enGameLevel GameLevel = enGameLevel::Easy;
    enQuestionType QuestionType = enQuestionType::Add;
};
void Start() {
    ReadQuestionsCount();
    ReadGameLevel();
    ReadQuestionType();
}
int main()
{
    Start();
    std::cout << "Hello World!\n";
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
