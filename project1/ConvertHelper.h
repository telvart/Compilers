
#ifndef CONVERTHELPER_H
#define CONVERTHELPER_H

#include <vector>
#include <algorithm>
#include <iostream>
#include "State.h"
#include "DFAState.h"

class ConvertHelper{

public:
  ConvertHelper(std::vector<State> NFA, std::vector<char> inputCharacters,
                std::vector<int> finalStates, int numFStates, int aSize, int numStates, int initial);

  ~ConvertHelper();

  void NFAtoDFA();

  static std::vector<int> parseStateSet(std::string states);

//private:

  std::vector<int> Eclosure(int states);
  std::vector<int> EclosureSet(std::vector<int> states);
  std::vector<int> combine(std::vector<int> a1, std::vector<int> a2);
  std::vector<int> charMovesSet(std::vector<int> states, char a);
  std::vector<int> getDFAFinalStates(std::vector<DFAState> DFA, std::vector<int> NFAFinals);

  void printVector(std::vector<int> v);
  void printDFAtable(std::vector<DFAState> DFA);

  bool vectorContains(std::vector<int> v, int x);
  bool DStatescontains(std::vector<DFAState> D,std::vector<int> NFAstates);
  bool unmarkedState(std::vector<DFAState> DStates);
  int getFirstUnmarked(std::vector<DFAState> DStates);
  int getDFAnum(std::vector<DFAState> DStates,std::vector<int> NFAstates);
  int DFAinitial(std::vector<DFAState> DFA);

  std::vector<State> NFA;
  std::vector<char> inputCharacters;
  std::vector<int> finalStates;
  int numNfaFinalStates;
  int alphabetSize;
  int numStates;
  int nfaInitial;

};

#endif
