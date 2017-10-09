
#include <iostream>
#include <string>
#include "State.h"
#include "ConvertHelper.h"

int nfaInitialState, numNfaStates, numNfaFinalStates, aSize=0, *nfaFinalStates;
std::vector<char> alphabet;
std::vector<State> NFA;
std::string dummy;

int main(int argc, char** argv)
{

  std::cin>>dummy>>dummy>>dummy;
  dummy.erase(dummy.begin());
  dummy[dummy.find("}")] = 0;

  nfaInitialState = stoi(dummy);

  std::cin>>dummy>>dummy>>dummy;
  nfaFinalStates = ConvertHelper::parseFinalStates(dummy, numNfaFinalStates);

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

  ConvertHelper help =
  ConvertHelper(NFA, alphabet, nfaFinalStates, numNfaFinalStates, aSize, numNfaStates, nfaInitialState);

  std::vector<int> initial;
  initial.push_back(4);
  std::vector<int> test;
  test = help.Eclosure(initial);

  std::cout<<"E closure {4} = ";
  for(int j=0; j<test.size(); j++)
  {
    std::cout<<test[j]<<" ";
  }
  std::cout<<"\n";

  //help.toDFA();



//
// std::cout<<"NFA Initial: "<<nfaInitialState<<"\n";
//
// std::cout<<"NFA Final State(s): ";
// for(int i=0; i<numNfaFinalStates; i++)
//   std::cout<<nfaFinalStates[i]<<" ";
//
// std::cout<<"\n";
// std::cout<<"NFA # States: "<<numNfaStates<<"\n";
//
// std::cout<<"Input Alphabet: ";
//
//
// for(int i=0; i<aSize; i++)
// {
//   std::cout<<NFA[0].inputCharacters[i]<<" ";
// }
//
// std::cout<<"\n"<<"Alphabet Size: "<<aSize<<"\n";
//
// for(int i=0; i<numNfaStates; i++)
// {
//   State currentState = NFA[i];
//   std::cout<<"State: "<<currentState.myStateNum<<" ";
//   for(int j=0; j<aSize; j++)
//   {
//       std::cout<<"{";
//       for(int k = 0; k < currentState.myTransitions[j].size(); k++)
//       {
//         std::cout<<currentState.myTransitions[j][k]<<" ";
//       }
//       std::cout<<"} ";
//   }
//   std::cout<<"\n";
// }








  return 0;
}
