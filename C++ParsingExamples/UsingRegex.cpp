/*
  Written by: Kurt Slagle

  Contact at kslagle@ku.edu with any questions
*/

#include "UsingRegex.h"

void ReadUsingRegex()
{
  /*
  To use a regex in C++, you must use:
  1) an instance of std::regex (or std::wregex for unicode) to store & compile the regex
  2) an instance of std::smatch (or std::wsmatch for unicode) to store the matched substrings
  3) some source string that you want to match against

  You can then call 'std::regex_match' and pass the source string, the smatch object, and the regex object 
      (in that order... You can loop over the matches like you do any normal C++ container (I did so using a for loop)
  */

  try
  {
    std::regex NestedTagsRegex(R"(([^<]+)?<[^>]+>(.*)<\/[^>]+>([^<]+)?)");
    std::smatch RegexMatch;
    std::string TestString = R"(<p>This is some <big>large introductory</big> text.</p>)";

    std::cout << "Regex used:\n\n";
    std::cout << R"(<[^>]+>(.*)<\/[^>]+>)" << "\n\n";
    std::cout << R"(Trying to match against: ")" << TestString << "\n";

    if (std::regex_match(TestString, RegexMatch, NestedTagsRegex)) {
      std::cout << "Regex matched " << RegexMatch.size() << " items\n";
      std::cout << "The matches are:\n";

      // Use 'auto', please, for everyone's sanity, use 'auto'
      //  The "real" type is 
      // std::sub_match<std::_String_const_iterator<std::_String_val<std::_Simple_types<char>>>>
      // Each 'match' is a 'sub_match' object, which is basically the range of characters in the source string
      //   that it matched against
      for (auto & match : RegexMatch) {
        std::cout << "\t\"" << match << "\"\n";

        //BUT we might need to check for nested tags!

        std::smatch rmatch;
        std::string substring = match.str();
        if (std::regex_match(substring, rmatch, NestedTagsRegex)) {
          std::cout << "Nested html tag matched " << rmatch.size() << " items\n";
          std::cout << "The matches are:\n";

          for (const auto & matchedString : rmatch) {
            std::cout << "\t\t\"" << matchedString << "\"\n";
          }
        }
      } // for (auto & match : RegexMatch)
    } 
    else {
      std::cout << "Regex didn't match :(\n";
    }
  }
  catch (...)
  {
    std::cout << "Error using regex\n";
  }

}
