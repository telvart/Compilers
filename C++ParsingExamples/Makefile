CPP=g++
INCL=./
CPP_VER=c++14
CFLAGS=-std=$(CPP_VER) -I$(INCL) -g -c -Wall -Wno-unused-label
LINK=$(CPP) -g -o

OBJS = UsingRegex.o UsingStreams.o UsingStdin.o main.o

TESTTAGS = TestInput.txt
TESTTYPICAL = ReadUsingTypes.txt

all: inputexamples

help: ## Output to the terminal instructing how to use
	@echo "To compile, run the \"make\" command\n"\
	      "!You must use a C++14-compliant compiler (the eecs machines should suffice)!\n"\
	      "To see the sample output when using regular expressions, use use \"make regex_example\" command\n"\
	      "To see the sample output when using streams, use the \"make streams_example\" command\n"\
	      "To see the sample output when using structs + stdcin, use the \"make stdin_example\" command\n"\
	      "To see the sample output when using typical parsing, use the \"make typical_example\" command\n"
test:
	@echo "make regex_example > RegexExampleOutput.output"
	@echo "make stdin_example > StdinExampleOutput.output"
	@echo "make streams_example > StreamsExampleOutput.output"
	@echo "make typical_example > TypicalExampleOutput.output"

inputexamples: $(OBJS)
	$(LINK) inputexamples $(OBJS)
	$(RM) *.o

regex_example: 
	./inputexamples "-r"

stdin_example: 
	./inputexamples "-c" < $(TESTTAGS)

streams_example: 
	./inputexamples "-s" < $(TESTTAGS)

typical_example:
	./inputexamples "-t" < $(TESTTYPICAL)

main.o: main.cpp
	$(CPP) $(CFLAGS) main.cpp

UsingRegex.o: UsingRegex.h UsingRegex.cpp
	$(CPP) $(CFLAGS) UsingRegex.cpp

UsingStdin.o: UsingStdin.h UsingStdin.cpp
	$(CPP) $(CFLAGS) UsingStdin.cpp

UsingStreams.o: UsingStreams.h UsingStreams.cpp
	$(CPP) $(CFLAGS) UsingStreams.cpp

clean:
	$(RM) *.o
	$(RM) *.output
	$(RM) inputexamples

.PHONY: clean inputexamples