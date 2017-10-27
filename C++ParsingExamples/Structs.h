/*
  Written by: Kurt Slagle

  Contact at kslagle@ku.edu with any questions
*/

#pragma once

#include <string>
#include <iostream>
#include <istream>

struct StartingHtmlTag
{
  std::string Text = ""; // The text for the tag, without the < >

  /* We'll define the extraction operator so it knows how to parse itself 
     Process:

     First ignore all extra whitespace at the front
     Then we make sure the first non-whitespace char is a '<'
        if it isn't, we just return so we don't destroy anything

     We discard the '<' since we don't actually store it
     Then we check to make sure the next char isn't a '/'
       If it is, then we put the '<' BACK and return
  
     Now we just keep grabbing and storing the next character
       until we reach the '>'
     We discard the '>' and return

     We store the tag in a temp string and don't change our "Text" member 
       so that its old value will be retained if, for some reason,
       we fail to parse. That way at least we will won't lose the good 
       value we used to have
  
  */
  friend std::istream& operator >> (std::istream &Input, StartingHtmlTag &Tag)
  {
  	if (!Input)
  		return Input;

    std::string temp("");

    while (isspace(Input.peek()))
      Input.ignore();

    if (( char )Input.peek() != '<')
      return Input;

    Input.ignore(); 

    if (( char )Input.peek() == '/') {
      Input.putback('<');
      return Input;
    }

   	std::getline(Input, temp, '>');

    Tag.Text = temp; 
    return Input;
  }

  friend std::ostream& operator << (std::ostream &Output, const StartingHtmlTag &Tag)
  {
    Output << "<" << Tag.Text << ">";
    return Output;
  }

  operator bool() const { return !Text.empty(); }
};

/*
  The process will be nearly identical to the starting tag
  EXCEPT that we want to make sure it HAS the '/' symbol.
  If it doesn't, we will put back anything we took out and just return.
*/
struct EndingHtmlTag
{
  std::string Text = "";

  friend std::istream& operator >> (std::istream &Input, EndingHtmlTag &Tag)
  {
  	if (!Input)
  		return Input;

    std::string temp("");

    while (isspace(Input.peek()))
      Input.ignore();

    if (( char )Input.peek() != '<')
      return Input;

    Input.ignore();

    if (( char )Input.peek() != '/') {
      Input.putback('<');
      return Input;
    }

    Input.ignore(); // Ignore the '/' so we don't store it in our string

 	std::getline(Input, temp, '>');

    Tag.Text = temp;
    return Input;
  }

  friend std::ostream& operator << (std::ostream &Output, const EndingHtmlTag &Tag)
  {
    Output << "</" << Tag.Text << ">";
    return Output;
  }

  operator bool() const { return !Text.empty(); }
};
