
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
                int* finalStates, int numFStates, int aSize, int numStates, int initial);

  ~ConvertHelper();

  void toDFA();
  std::vector<int> getEmoves(int statenum);


  static int* parseFinalStates(std::string fStates, int& numNfaFinalStates);
  static std::vector<int> parseStateSet(std::string states);

  std::vector<int> Eclosure(std::vector<int> states);


  bool vectorContains(std::vector<int> v, int x);




  std::vector<State> NFA;
  std::vector<char> inputCharacters;
  int* finalStates;
  int numNfaFinalStates;
  int alphabetSize;
  int numStates;
  int nfaInitial;




};

#endif
