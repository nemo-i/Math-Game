//#include "Common.h";
//string GetQuestionTypeName(enQuestionType questionType) {
//    switch (questionType)
//    {
//    case Add:
//        return "Addition";
//        break;
//    case Sub:
//        return "Subtraction";
//        break;
//    case Mul:
//        return "Multiplication";
//        break;
//    case Div:
//        return "Divition";
//        break;
//    default:
//        return "Mixed";
//        break;
//    }
//}
//string GetGameLevelName(enGameLevel gameLevel) {
//    switch (gameLevel)
//    {
//    case Easy:
//        return "Easy";
//        break;
//    case Mid:
//        return "Middle";
//        break;
//    case Hard:
//        return "Hard";
//        break;
//    case Mix:
//        return "Mixed";
//        break;
//    default:
//        return "Easy";
//        break;
//    }
//}
//string PassOrFail(sGameData gameData) {
//    if (gameData.IsPlayerPassed) {
//        return "Pass";
//    }
//    else
//    {
//        return "Fail";
//    }
//}
//string SadFace() {
//    return ";-(";
//}
//
//string HappyFace() {
//    return ":-)";
//}
//
//string SadOrHappyFace(sGameData gameData) {
//    if (gameData.IsPlayerPassed) {
//        return HappyFace();
//    }
//    else
//    {
//        return SadFace();
//    }
//}