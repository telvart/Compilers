
#include "ConvertHelper.h"

ConvertHelper::ConvertHelper(std::vector<State> NFA, std::vector<char> inputCharacters,
  int* finalStates, int numFStates, int aSize, int numStates, int initial)
{
  this->NFA = NFA;
  this->inputCharacters = inputCharacters;
  this->finalStates = finalStates;
  this->numNfaFinalStates = numFStates;
  this->alphabetSize = aSize;
  this->numStates = numStates;
  this->nfaInitial = initial;

}

ConvertHelper::~ConvertHelper()
{

}

void ConvertHelper::toDFA()
{

}

std::vector<int> ConvertHelper::getEmoves(int statenum)
{
  State s = NFA[statenum];
  return s.myTransitions[s.alphabetSize-1];
}

std::vector<int> ConvertHelper::Eclosure(std::vector<int> states)
{

  std::vector<int> returnVal;

  for(int i=0; i<states.size(); i++) //foreach state
  {
    State currentState = NFA[states[i]-1];
    if(!vectorContains(returnVal, currentState.myStateNum))
    {
      returnVal.push_back(currentState.myStateNum);
    }
    std::vector<int> moves = currentState.myTransitions[currentState.myTransitions.size()-1];
    //std::cout<<"E MOVES: ";
    for(int j=0; j<moves.size(); j++)
    {
      if(!vectorContains(returnVal, moves[j]))
      {
        returnVal.push_back(moves[j]);
      }
    }


  }

  return returnVal;




}



bool ConvertHelper::vectorContains(std::vector<int> v, int x)
{
  if(std::find(v.begin(), v.end(), x) != v.end())
  {
    return true;
  }
  return false;
}



int* ConvertHelper::parseFinalStates(std::string fStates, int& numNfaFinalStates)
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

std::vector<int> ConvertHelper::parseStateSet(std::string states)
{
  std::vector<int> transitions; //new int[std::count(states.begin(), states.end(), ',') + 1];

  if(states == "{}") {return transitions;}

  states.erase(states.begin());
  int i = 0, pos;
  std::string temp;

  while((states.find(",") != std::string::npos))
  {
    pos = states.find(",");
    temp = states.substr(0, pos);
    states.erase(0, pos+1);
    transitions.push_back(stoi(temp));
    i++;
  }
  states[states.find("}")] = 0;

  transitions.push_back(stoi(states));

  return transitions;


}
