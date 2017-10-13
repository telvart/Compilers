#ifndef DFASTATE_H
#define DFASTATE_H

#include <vector>

class DFAState
{
public:
  DFAState(int stateNum, std::vector<int> NFAStates);
  ~DFAState();





std::vector<int> myStates;
int myNum;
bool DFAmark;










};

#endif
