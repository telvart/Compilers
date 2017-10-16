/*
  @file: DFAState.cpp
  @author: Tim Elvart
  @date: 16 October 2017
  @brief:
  EECS 665 Assignment 1: Implementation of methods declared in DFAState.h
*/

#include "DFAState.h"

DFAState::DFAState(int num, std::vector<int> NFAStates, std::vector<char> alphabet)
{
  myNum = num;
  myStates = NFAStates;
  DFAmark = false;
  inputCharacters = alphabet;
  transitions = new int[inputCharacters.size()];

  for(unsigned int i =0; i<inputCharacters.size()-1; i++) // initialize transitions
    transitions[i] = -1;

}

DFAState::~DFAState()
{
  //delete[] transitions;
}
