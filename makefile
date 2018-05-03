#	CXXFLAGS=c++0x
#output: mochila-alexandre.o 
#    g++ mochila-alexandre.cpp mochila-alexandre.o -o Recursive
	
	CXXALLFLAGS= -std=c++0x
output: 
	g++  mochila-alexandre.cpp -o mochila-alexandre $(CXXALLFLAGS)

