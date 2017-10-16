/*
  @file: main.cpp
  @author: Tim Elvart
  @date: 16 October 2017
  @brief:
  EECS 665 Assignment 1: This program handles extracting all of the information from the input file, and passing it
                         to the helper class to be used in conversion. Calls the subset construction algorithm.
*/


#include <iostream>
#include <string>
#include "State.h"
#include "ConvertHelper.h"

int nfaInitialState, numNfaStates, numNfaFinalStates, aSize=0;
std::vector<char> alphabet;
std::vector<State> NFA, DFA;
std::vector<int> nfaFinalStates;
std::string dummy;

int main(int argc, char** argv)
{

  //lines 26-59 read from the input and extract the information
  std::cin>>dummy>>dummy>>dummy;
  dummy.erase(dummy.begin());
  dummy[dummy.find("}")] = 0;

  nfaInitialState = stoi(dummy);

  std::cin>>dummy>>dummy>>dummy;
  nfaFinalStates = ConvertHelper::parseStateSet(dummy);
  numNfaFinalStates = nfaFinalStates.size();

  std::cin>>dummy>>dummy>>dummy;

  numNfaStates = stoi(dummy);

  std::cin>>dummy;

  while(dummy != "E")
  {
    std::cin>>dummy;
    alphabet.push_back(dummy[0]);
    aSize++;
  }

  for(int i=0; i< numNfaStates; i++)
  {
    std::cin>>dummy;
    std::vector<std::vector<int>> transitions;
    for(int j =0; j<aSize; j++)
    {
      std::cin>>dummy;
      transitions.push_back(ConvertHelper::parseStateSet(dummy));
    }
    NFA.push_back(State(transitions, i+1, alphabet));
  }

  ConvertHelper h =
  ConvertHelper(NFA, alphabet, nfaFinalStates, numNfaFinalStates, aSize, numNfaStates, nfaInitialState);

  h.NFAtoDFA(); // call the DFA construction algorithm

  return 0;
}
