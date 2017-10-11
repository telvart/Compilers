#include "State.h"



State::State(std::vector<std::vector<int>> transitions, int stateNum,
             std::vector<char> a)
{
  myTransitions = transitions;
  myStateNum = stateNum;
  inputCharacters = a;
}

State::~State()
{
  //if(myTransitions != nullptr)
//  {
    //delete[] myTransitions;
  //}
}

std::vector<int> State::getEmoves()
{
  return myTransitions[myTransitions.size() - 1];
}
