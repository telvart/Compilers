/*
  Written by: Kurt Slagle

  Contact at kslagle@ku.edu with any questions
*/

#include "UsingStreams.h"

/*
  For this one, we will read the file into a "stringsream"

  We can interface with it just like we do file streams, except that you can read
  a file into a stringstream and then pull parts out of it

  Basically, we'll gobble all the input in the beginning and then more carefully
  parse it later
*/

void SkipWhitespace(std::stringstream &Stream)
{
  while (isspace(Stream.peek()))
    Stream.ignore();
}

void ReadInUsingStringStream()
{
  
  std::string Temp;
  std::stringstream StorageStream;

  /*  
    Read everything from standard input all at once
    Now, if something goes wrong we won't have an input stream still hanging around
  */
  StorageStream << std::cin.rdbuf();

  std::string startingTag, endingTag, contents;

  // I'm cheating a bit here, but we'll discard the first '<' so we can leave the code in the loop cleaner
  if (( char ) StorageStream.peek() == '<')
    StorageStream.ignore();

  while (StorageStream) { // While this stringstream still has characters inside of it (we haven't parsed everything)

    // We'll try to pull off a tag

    startingTag = "";
    SkipWhitespace(StorageStream);

    // Read every character up to the first '>' encountered
    // into the string "startingTag"
    std::getline(StorageStream, startingTag, '>');
    SkipWhitespace(StorageStream);

    std::cout << "Tag: \"" << startingTag << "\"\n";

    // Read every character up to the first '<' encountered
    // into the string "contents"
    std::getline(StorageStream, contents, '<');

    if (!contents.empty())
      std::cout << "Contents: \"" << contents << "\"\n";

  }

}
