
#ifndef CONVERTHELPER_H
#define CONVERTHELPER_H

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "State.h"

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

  void printVector(std::vector<int> v);

  bool vectorContains(std::vector<int> v, int x);
  bool unmarkedState(std::vector<State> DStates);

  std::vector<State> NFA;
  std::vector<char> inputCharacters;
  std::vector<int> finalStates;
  int numNfaFinalStates;
  int alphabetSize;
  int numStates;
  int nfaInitial;


};

#endif
