/*
  @file: State.cpp
  @author: Tim Elvart
  @date: 16 October 2017
  @brief:
  EECS 665 Assignment 1: Implementation of methods declared in State.h
*/

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
  // return the transitions of the last input character, which is always E
}

std::vector<int> State::getCharMoves(char c)
{
  std::vector<int> moves;
  int index = indexOf(inputCharacters, c); // determine which vector to return
  if(index > -1)
  {
    moves = myTransitions[index];
  }
  return moves;
}

int State::indexOf(std::vector<char> v, char x)
{
  for(unsigned int i=0; i<v.size(); i++)
  {
    if(v[i] == x) {return i;}
  }
  return -1;
}
