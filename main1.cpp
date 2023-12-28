/*main.cpp*/

// Author: Sharva Thakur, UIC, Spring 2021
// Assignment: Project 03 part 1
// UIN: 654135206 

#include <iostream>
#include <string>

#include "token.h"

using namespace std;

int search(Variable* memory, int& num_vars, string name){
	
	
	
	
}

struct variable{
		string name;
		string type;
		string value;
		
};
// ##################################################################################
//
// main filename memorysize
//
int main(int argc, char* argv[])
{
   // 
   // 1. process command-line args:
   //
   // argv[0]: ./main
   // argv[1]: filename.py
   // argv[2]: memorysize
   //
   if (argc != 3)
   {
      cout << "usage: ./main filename.py memorysize" << endl;
      return 0;
   }

   string filename(argv[1]);  // this is your SimplePy program file
   int    MemorySize = stoi(argv[2]);  // this is size for Memory array


   //
   // TODO: call inputSimplePy to input the SimplePy program, and
   // you'll get back an array of Tokens.  Allocate another array
   // for your memory, and then start executing!
   //
	
   cout << filename << endl;    // delete these eventually
   cout << MemorySize << endl;
	
	
	
	
   Token* A;
	int ProgramSize;
	 A = inputSimplePy (filename, ProgramSize);
	           
	int PC = 0; // “program counter”
	//while ( A[PC].ID != TokenID::EOS){
	//	cout << A[PC] << endl;
	//}

	//while loop to loop every element 
	
	//int mem_siz = 0;
	
    variable* memory;
	memory = new variable[MemorySize];
	
    int NumVar = 0;
	while(A[PC].ID != TokenID::EOS){
		


		if(A[PC].Value == "print"){
			cout << A[PC+2].Value << endl; 
			PC= PC+1;
		}                                                                                                      
		else{

			
			memory[NumVar].name = A[PC].Value; 
			PC ++; 
			PC ++;
			
			Token LeftVal;
			
			LeftVal = A[PC];
			
			PC ++; 
			
			
			if (A[PC].ID == TokenID::PLUS || A[PC].ID == TokenID::MINUS || A[PC].ID == TokenID::MULT || A[ PC].ID == TokenID::LT){
				
				Token right;
					
				right = A[PC];
				
				Token Operator;
				
				Operator = A[PC+1];
				
				cout << Operator; 
				
				
				
			}
			
			
			PC++;
		}
		
		
	}
	
	
	
   return 0;
}
