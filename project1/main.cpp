
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include "State.h"


int* parseFinalStates(std::string fStates, int& numFinalStates)
{
  fStates.erase(fStates.begin());
  std::cout<<fStates<<"\n";
  int i, pos;
  int* finalStates = new int[std::count(fStates.begin(), fStates.end(), ',') + 1];
  //std::cout<<std::count(fStates.begin(), fStates.end(), ',') + 1<<"\n";
  std::string temp;

  //while((fStates.find(",") != std::string::npos))
  //{
    pos = fStates.find(",");
    temp = fStates.substr(0, pos);

    std::cout<<"f";
    std::cout<<temp;
    std::cout<<"g\n";
    int temp2;
    std::cout<<stoi(temp) << "\n";


    //std::stringstream ss(temp);
    //ss.clear();
    //ss >> temp2;
    //std::cout<<temp2<<"\n";

    fStates.erase(0, pos+1);
    //finalStates[i] = atoi(temp.c_str());
    //i++;


  //}

  fStates[fStates.find("}")] = 0;
  //std::cout<<stoi(fStates)<<"\n";










  return finalStates;
}

int main(int argc, char** argv)
{

  int nfaInitialState;
  int* nfaFinalStates;
  int numStates;
  int numFinalStates;
  std::string dummy;

  std::cin>>dummy>>dummy>>dummy;
//  std::cout<<dummy<<"\n";
  nfaInitialState = (int)dummy[1] - 48;
  std::cout<<"NFA Initial: "<<nfaInitialState<<"\n";

  std::cin>>dummy>>dummy>>dummy;
  nfaFinalStates = parseFinalStates(dummy, numFinalStates);






  return 0;
}
