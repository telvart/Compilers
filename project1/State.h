

#ifndef STATE_H
#define STATE_H

#include <vector>

class State{

public:
  State(std::vector<std::vector<int>> transitions, int stateNum,
        std::vector<char> a);
  ~State();

  std::vector<int> getEmoves();


//private:
  int myStateNum;
  std::vector<std::vector<int>> myTransitions;

  int alphabetSize;
  std::vector<char> inputCharacters;
};

#endif
