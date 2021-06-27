#include <cstdlib>
#include <iostream>
#include "Dictonary.h"

int main()
{
	{
		//Char
		Dictonary<const char*, const char*> hashTable;
		hashTable.Add("Bob Jones", "16 Flindere St");
		hashTable.Add("Tim Smith", "34 Swanston St");
		hashTable.Add("Alice Night", "22 Left St");

		std::cout << hashTable["Bob Jones"] << std::endl;
		std::cout << hashTable["Tim Smith"] << std::endl;
		std::cout << hashTable["Alice Night"] << std::endl;
	}

	{
		//Int
		Dictonary<int, const char*> hashTable;
		hashTable.Add(32, "16 Flindere St");
		hashTable.Add(12, "34 Swanston St");
		hashTable.Add(42, "22 Left St");

		std::cout << hashTable[32] << std::endl;
		std::cout << hashTable[12] << std::endl;
		std::cout << hashTable[42] << std::endl;
	}

	{
		////Pointer
		//Dictonary<Player*, const char*> hastTable;
		//Player* p1 = new Player();
		//Player* p2 = new Player();
		//Player* p3 = new Player();

		//hastTable.Add(p1, "16 Flindere St");
		//hastTable.Add(p2, "34 Swanston St");
		//hastTable.Add(p3, "22 Left St");

		//std::cout << hastTable[p1] << std::endl;
		//std::cout << hastTable[p2] << std::endl;
		//std::cout << hastTable[p3] << std::endl;
	}
	
	{
		//Float
		//hastTable.Add(3.5f, "16 Flindere St");
		//hastTable.Add(1.5f, "34 Swanston St");
		//hastTable.Add(5.7f, "22 Left St");

		//std::cout << hastTable[3.5f] << std::endl;
		//std::cout << hastTable[1.5f] << std::endl;
		//std::cout << hastTable[5.7f] << std::endl;
	}
}