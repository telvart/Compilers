
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "State.h"

int* parseFinalStates(std::string fStates, int& numNfaFinalStates)
{
  fStates.erase(fStates.begin());
  int i = 0, pos;
  int* finalStates = new int[std::count(fStates.begin(), fStates.end(), ',') + 1];
  std::string temp;

  while((fStates.find(",") != std::string::npos))
  {
    pos = fStates.find(",");
    temp = fStates.substr(0, pos);
    fStates.erase(0, pos+1);
    finalStates[i] = stoi(temp);
    i++;
  }
  fStates[fStates.find("}")] = 0;

  finalStates[i] = stoi(fStates);

  numNfaFinalStates = i + 1;
  return finalStates;
}

int main(int argc, char** argv)
{

  int nfaInitialState, numNfaStates, numNfaFinalStates, aSize=0, *nfaFinalStates;

  std::string dummy;

  std::cin>>dummy>>dummy>>dummy;
  dummy.erase(dummy.begin());
  dummy[dummy.find("}")] = 0;

  nfaInitialState = stoi(dummy);
  std::cout<<"NFA Initial: "<<nfaInitialState<<"\n";

  std::cin>>dummy>>dummy>>dummy;
  nfaFinalStates = parseFinalStates(dummy, numNfaFinalStates);

  std::cout<<"NFA Final State(s): ";
  for(int i=0; i<numNfaFinalStates; i++)
    std::cout<<nfaFinalStates[i]<<" ";

  std::cout<<"\n";
  std::cin>>dummy>>dummy>>dummy;

  numNfaStates = stoi(dummy);
  std::cout<<"NFA # States: "<<numNfaStates<<"\n";

  std::cin>>dummy;

  std::cout<<"Input Alphabet: ";
  while(dummy != "E")
  {
    std::cin>>dummy;
    std::cout<<dummy<<" ";
    aSize++;
  }
  std::cout<<"\n"<<"Alphabet Size: "<<aSize<<"\n";






  return 0;
}
