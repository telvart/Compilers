
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

  void NFAtoDFA();
  std::vector<int> getEmoves(int statenum);


  static int* parseFinalStates(std::string fStates, int& numNfaFinalStates);
  static std::vector<int> parseStateSet(std::string states);

  std::vector<int> Eclosure(int states);
  std::vector<int> EclosureSet(std::vector<int> states);

  std::vector<int> combine(std::vector<int> a1, std::vector<int> a2);

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
