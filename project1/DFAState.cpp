#include "DFAState.h"

DFAState::DFAState(int num, std::vector<int> NFAStates, std::vector<char> alphabet)
{
  myNum = num;
  myStates = NFAStates;
  DFAmark = false;
  inputCharacters = alphabet;
  transitions = new int[inputCharacters.size()];

  for(unsigned int i =0; i<inputCharacters.size()-1; i++)
    transitions[i] = -1;

}

DFAState::~DFAState()
{
  //delete[] transitions;
}
