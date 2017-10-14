#ifndef DFASTATE_H
#define DFASTATE_H

#include <vector>

class DFAState
{
public:

  DFAState(int stateNum, std::vector<int> NFAStates, std::vector<char> alphabet);
  ~DFAState();


std::vector<int> myStates;
std::vector<char> inputCharacters;
int* transitions;
int myNum;
bool DFAmark;


};

#endif
