/*
  Written by: Kurt Slagle

  Contact at kslagle@ku.edu with any questions
*/

#include "UsingStdin.h"
#include "Structs.h"

bool AcceptChar(char c, std::istream &inputStream)
{
  return ( inputStream.peek() == c );
}

bool ParseNestedTags()
{
  StartingHtmlTag StartTag;
  EndingHtmlTag EndTag;

  std::cin >> StartTag;
  if (!StartTag)
    return false;

  std::string text("");
  std::getline(std::cin, text, '<');
  std::cin.putback('<');

  std::cout << "grabbed \"" << text << "\" as content\n";

  std::cin >> EndTag;
  if (!EndTag)
    return false;

  std::cout << "\tParsed nested tags + contents:\n";
  std::cout << "\tStarting tag: \"" << StartTag << "\"\n";
  std::cout << "\tContents    : \"" << text     << "\"\n";
  std::cout << "\tEnding tag  : \"" << EndTag   << "\"\n";

  return true;
}

void ReadUsingStdCin()
{
  // We will parse the first tag (which doesn't have nested tags)
  // then the text up until the end tag
  // and then parse the ending tag

  while (std::cin) {
    StartingHtmlTag StartTag;
    EndingHtmlTag EndTag;
    std::cin >> StartTag;

    if (!std::cin) break;

    if (StartTag.Text.empty()) {
      std::cerr << "Error. Expected to be able to parse a starting html tag\n";
      return;
    }

    std::string text("");
    std::getline(std::cin, text, '<');
    std::cin.putback('<');

    std::cout << "grabbed \"" << text << "\" as content\n";

    //Then we should be able to parse an ending tag
    std::cin >> EndTag;
    if (!EndTag) {

      //Try to parse nested tags before we error out
      if (ParseNestedTags()) {
        //Then if that was successful, we might have some leftover "content" after the end of the nested tags but before the ending tag
        std::getline(std::cin, text, '<');
        std::cin.putback('<');
      }
      else {
        std::cerr << "Error. Expected to be able to parse an ending html tag and there were no nested tags to match instead\n";
        return;
      }
    }

    std::cin >> EndTag;
    if (!EndTag) {
        std::cerr << "Error. Expected to be able to parse an ending html tag after parsing nested tags\n";
        return;
    }

    std::cout << "Parsed tags + contents:\n";
    std::cout << "Starting tag: \"" << StartTag << "\"\n";
    std::cout << "Contents    : \"" << text     << "\"\n";
    std::cout << "Ending tag  : \"" << EndTag   << "\"\n";

    while (std::cin && isspace(std::cin.peek()))
      std::cin.ignore();
  }

}
