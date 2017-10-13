#include "DFAState.h"

DFAState::DFAState(int num, std::vector<int> NFAStates)
{
  myNum = num;
  myStates = NFAStates;
  DFAmark = false;

}

DFAState::~DFAState()
{
  
}
