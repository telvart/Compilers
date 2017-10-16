/*
  @file: ConvertHelper.h
  @author: Tim Elvart
  @date: 16 October 2017
  @brief:
  EECS 665 Assignment 1: This class was used a container for functions that would be used in the NFAtoDFA algorithm.
                         It was created to not have a massive main.cpp. This class implements E-closure, move(T,a) and
                         the actual subset construction algorithm.
*/

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

  /*
    This function takes a string in the form of "{}" "{1}" "{1,2,3,...,n}" and returns the
    n numbers from the string in a vector
  */
  static std::vector<int> parseStateSet(std::string states);

  /*
    This function takes in an NFA state number, and returns the epsilon closure of just that state from the NFA
  */
  std::vector<int> Eclosure(int state);

  /*
    This function takes a vector NFA state nums, and returns the combined Eclosure of each of those states
  */
  std::vector<int> EclosureSet(std::vector<int> states);

  /*
    This function takes in a vector of NFA state numbers and an input character a, and returns in a vector the number of all of the states
    reachable from the NFA states through the character a
  */
  std::vector<int> charMovesSet(std::vector<int> states, char a);

  /*
    This is a utility function which combines two sorted int vectors together, prevents duplicates and returns the combination
    as a vector
  */
  std::vector<int> combine(std::vector<int> a1, std::vector<int> a2);

  /*
    This function takes in a DFA, and a vector containing the final states of its equivalent NFA, and returns
    the final states of the DFA in a vector
  */
  std::vector<int> getDFAFinalStates(std::vector<DFAState> DFA, std::vector<int> NFAFinals);

  /*
    Prints a vector in this format "{v[0],v[1],...,v[v.size()-1]}"
  */
  void printVector(std::vector<int> v);

  /*
    Prints information about the DFA in a transtion table like in the input file
  */
  void printDFAtable(std::vector<DFAState> DFA);


  /*
    Utility to see if a vector contains a value
  */
  bool vectorContains(std::vector<int> v, int x);

  /*
    Utility for checking if Dstates has a DFA state that contains the NFA states in the NFAstates vector
    Used in the subset construction algorithm
  */
  bool DStatescontains(std::vector<DFAState> D,std::vector<int> NFAstates);

  /*
    Utility for checking if DStates currently has a DFA state that has not been marked through the subset construction algorithm
    Used in the subset construction algorithm
  */
  bool unmarkedState(std::vector<DFAState> DStates);

  /*
    Returns the index of the first unmarked DFA state in DStates
    Used in the subset construction algorithm
  */
  int getFirstUnmarked(std::vector<DFAState> DStates);

  /*
    Returns the state number of the DFA state that contains the NFA states in DStates
  */
  int getDFAnum(std::vector<DFAState> DStates,std::vector<int> NFAstates);
  
  /*
    Returns the state number of the DFA which contains the intial state of the NFA
  */
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
