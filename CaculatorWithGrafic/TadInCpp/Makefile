Apps= Apps
Bin= Bin
External_Library_exprtk= External_Library/exprtk.hpp
Header= Header
Include= Include
Library= Library
Object= Object

Flags= -03 -Wall

comp: 
	g++ -c Include/FindNumber.cpp -I muparser/include -IHeader -DMUPARSER_STATIC -o Object/FindNumber.o
	g++ Apps/Main.cpp Include/FindNumber.cpp muparser/src/*.cpp -I muparser/include -I Header -DMUPARSER_STATIC -o Bin/Main.exe
	
main:
	g++	Apps/Main.cpp	Object/*.o	-IHeader -o	Bin/Main.exe
	
FindNumber:
	g++ -c Include/FindNumber.cpp -IHeader -IExternal_Library -o Object/FindNumber.o


run:
	$(Bin)/Main.exe