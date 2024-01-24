//
//#pragma once
//enum enGameLevel {
//    Easy = 1,
//    Mid = 2,
//    Hard = 3,
//    Mix = 4,
//};
//enum enQuestionType {
//    Add = 1,
//    Sub = 2,
//    Mul = 3,
//    Div = 4,
//    Mixed = 5,
//};
//
//struct sRoundValues {
//    short numerator = 0;
//    short denominator = 0;
//    char operationType = '+';
//    short userAnswer = 0;
//    short correctAnswer = 0;
//    bool isUserAnswerCorrectly;
//};
//
//struct sGameData {
//    short QuestionCount = 0;
//    enGameLevel GameLevel = enGameLevel::Easy;
//    enQuestionType QuestionType = enQuestionType::Add;
//    short RightAnswersCount = 0;
//    short WrongAnswersCount = 0;
//    bool IsPlayerPassed = true;
//    struct sRoundValues roundValues;
//};
//
//short ReadQuestionsCount();
//short ReadOnlyNumber(string msg);
//short ReadUserAnswer();
//short GetRandNumberInRange(short from, short to);
//enGameLevel ReadGameLevel();
//enQuestionType ReadQuestionType();
//bool ReadNumberInRange(short from, short to, short number);
//string GetQuestionTypeName(enQuestionType questionType);
//string GetGameLevelName(enGameLevel gameLevel);
//string PassOrFail(sGameData gameData);
//string SadFace();
//string HappyFace();
//string SadOrHappyFace(sGameData gameData);