/*
  @file: DFAState.h
  @author: Tim Elvart
  @date: 16 October 2017
  @brief:
  EECS 665 Assignment 1: This class acts as a container for information that will be used in constructing the DFA
*/

#ifndef DFASTATE_H
#define DFASTATE_H

#include <vector>

class DFAState
{
public:

  DFAState(int stateNum, std::vector<int> NFAStates, std::vector<char> alphabet);

  ~DFAState();

  std::vector<int> myStates; //the NFA states that this DFA state has
  std::vector<char> inputCharacters; //the input alphabet
  int* transitions; //transitions to another DFA State
  int myNum; //state number
  bool DFAmark; //used in DFA construction

};

#endif
