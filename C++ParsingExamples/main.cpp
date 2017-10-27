/*
  Written by: Kurt Slagle

  Contact at kslagle@ku.edu with any questions
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <regex>

#include "UsingRegex.h"
#include "UsingStdin.h"
#include "UsingStreams.h"

/*
  This is C++ - there is no reason to read the file in character by character
  Use C for that. Just because you can doesn't mean you should!

  Recommended ways: 1) Reading in using the standard library (ie with '>>' and '<<') and use the 
                       existing ability to directly read types other than strings from files

                    2) Use a regular expression. You can't read from a file using a regular expression,
                       but you can read the entire file into a 'stringstream' object and then use your
                       regular expressions with that. Or read the file in line-by-line.

                       To do this with 'std::cin' input, just capture all of the input in a std::stringstream object
                       and then use that however you wish.  One advantage is that you don't have to worry about halting
                       while there is still input to be read.  Another advantage is that you don't have code reading in
                       from std::cin all over your code, which makes it much cleaner and much easier to debug.
                       std::stringstream handles ALL of the memory management for you, so you do not ever have
                       to worry about not having enough memory to read the file, and it will never overflow.
                       Examples are provided
*/

void ReadUsingTypes();

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "Please provide the example you would like to run\n";
    std::cerr << "-s to run the stringstream example\n";
    std::cerr << "-c to run the std::cin example\n";
    std::cerr << "-r to run the regex example\n";
    std::cerr << "-t to run the typical example\n";
    return 0;
  }

  try
  {
    if (strcmp(argv[1], "-s") == 0) {
      std::cout << "Using stringstreams:\n";
      ReadInUsingStringStream();
    }
    else if (strcmp(argv[1], "-c") == 0) {
      std::cout << "Using std::cin\n";
      ReadUsingStdCin();
    }
    else if (strcmp(argv[1], "-r") == 0) {
      std::cout << "Using regular expressions\n";
      ReadUsingRegex();
    }
    else if (strcmp(argv[1], "-t") == 0) {
      std::cout << "Using typical methods:\n";
      ReadUsingTypes();
    }
  }
  catch (const std::exception &exc)
  {
    std::cerr << "Whoops! Something didn't quite go as planned... " << exc.what() << "\n";
    return -1;
  }

  return 0;
}

void ReadUsingTypes()
{
  // Just declare the types you wish to read in from the file
  //   They must be plain old data (POD) types (or standard library types)
  //   unless you overloaded the '>>' operator for your class
  int IntRead = 0;
  std::string StringRead = "";
  std::string QuotedString = "";

  // File looks like this:
  /*
  10 SomeShortString "Some long string enclosed in quotes"
  */
  try
  {
    // std::quoted handles the escaping of quotes properly for us.  Since we are reading in a string inside 'std::quoted'
    //  it will attempt to read any length of characters it can find between subsequent double quotes
    std::cin >> IntRead >> StringRead >> std::quoted(QuotedString);

    std::cout << "IntRead: \""          << IntRead 
              << "\", StringRead: \""   << StringRead 
              << "\", QuotedString: \"" << QuotedString << "\"\n";
  }
  catch (const std::exception &exc)
  {
    std::cout << "File was not formatted properly: Error: " << exc.what() << "\n";
  }
}

/*
  For regex syntax: see http://www.cplusplus.com/reference/regex/ECMAScript/
*/
