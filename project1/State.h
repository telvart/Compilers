/*
  @file: State.h
  @author: Tim Elvart
  @date: 16 October 2017
  @brief:
  EECS 665 Assignment 1: This class acts as a container for information about the NFA states
                         and their transitions.
*/

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

  /*
    @return this state's transitions to other states through the Epsilon symbol
  */
  std::vector<int> getEmoves();

  /*
    @return This state's transitions to other states through the input character c
  */
  std::vector<int> getCharMoves(char c);

  /*
    This function is used in getCharMoves to determine which transitions vector to return
    @return the index in v of the first occurence of x, -1 otherwise
  */
  int indexOf(std::vector<char> v, char x);


//private:
  int myStateNum;

  std::vector<std::vector<int>> myTransitions;
  // Vector of int vectors. Each index in myTransitions is a vector which holds the
  // values of states this state transitions to, the index of a character is determined by the input file

  std::vector<char> inputCharacters; // the input alphabet

};

#endif
