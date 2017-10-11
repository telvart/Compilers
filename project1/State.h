

#ifndef STATE_H
#define STATE_H

#include <vector>
#include <algorithm>
#include <iostream>

class State{

public:
  State(std::vector<std::vector<int>> transitions, int stateNum,
        std::vector<char> a);
  ~State();

  std::vector<int> getEmoves();
  std::vector<int> getCharMoves(char c);

  int indexOf(std::vector<char> v, char x);


//private:
  int myStateNum, alphabetSize;
  bool DFAmark;
  std::vector<std::vector<int>> myTransitions;


  std::vector<char> inputCharacters;
};

#endif
