/*main.cpp*/
//
// Author: Sharva Thakur, UIC, Spring 2021
// Assignment: Project 3 part 1 
// UIN: 654135206 
//

#include <iostream>
#include <string>

#include "token.h"
#include <cmath>

using namespace std;
struct Variable{
		string name;
		string type;
		string value;
		
};

int search(Variable memory[], string& varname, int& NumVars){
	int a =0;
    for (int z = 0; z<NumVars; z++){
        if (memory[z].name == varname){
            a = z;
            return a;
        }
    }
   return -1;
}

void print(string& varname, Token program[], int& PC, Variable memory[], int NumVars){
	
	if (program[PC].ID == TokenID::RIGHT_PAREN){
		PC = PC - 1; 
		cout << endl; 
		}
	else if(program[PC+1].ID == TokenID::COMMA){
		
		while(program[PC].ID != TokenID::RIGHT_PAREN){
			if (program[PC+1].ID == TokenID::COMMA){
				PC ++;
			}
			else{
				cout << varname << " " ; 
				PC ++;
				varname = program[PC].Value; 
				int index1 = 0;
				index1 = search(memory, varname, NumVars);
				if (index1 != -1){
				varname = memory[index1].value;
				}
			}
		}
		PC = PC-1 ;
		cout << endl;
	}
	else{
		cout << varname << endl;
	}
	
	
}



void executeStmt(Token program[], int& PC, Variable memory[], int& NumVars){
	
	if(program[PC].Value == "print"){
		
		PC = PC + 2;
		string varname; 
		varname = program[PC].Value;
		
		int index1 = 0;
		
		 
		
		index1 = search(memory, varname, NumVars);
		


		if (index1 != -1){
			varname = memory[index1].value;
			print(varname,program, PC, memory,NumVars);
		}
		else {
			print(varname,program, PC, memory,NumVars);
		}
		
		
		
		PC++;
	


	}
	
	else{
		
		string varname;
		varname = program[PC].Value;

		
		PC = PC + 2; 
		Token left = program[PC];
		
			
		
		string leftvalue;
		string result;
		string rightvalue;
		string resultType;
		
		
		if (program[PC+1].ID == TokenID::PLUS || program[PC+1].ID == TokenID::MINUS || program[PC+1].ID== TokenID::MULT || 
			program[PC+1].ID == TokenID::LT ||program[PC+1].ID == TokenID::POWER ||program[PC+1].ID == TokenID::DIV || 
			program[PC+1].ID == TokenID::MOD||program[PC+1].ID == TokenID::GT|| program[PC+1].ID ==TokenID::EQUAL_EQUAL) {
			
			
			leftvalue = left.Value ;
			
			
			
			
			
			
			PC ++;
			
			Token op = program[PC];
			
			
			Token right = program[PC+1];
			
			
			rightvalue = right.Value;
			
			
			string righttype,lefttype;
			int A ,B= 0; 
			
			
			A = search(memory,program[PC+1].Value , NumVars);
			
			if (A != -1){
				righttype == memory[A].type ;
			}
			else {
				if (program[PC-1].ID == 19){
				righttype = "STR";
				}
				else{
				righttype= "INT";
				}
			}
			
			B = search(memory,program[PC-1].Value , NumVars);
			
			if (B != -1){
				lefttype == memory[B].type ;
			}
			else {
				if (program[PC-1].ID ==19){
				lefttype = "STR";
				}
				else{
				lefttype = "INT";
				}
			}
			
			
			
			
			int a,b=0; 
			
			
			a = search(memory, leftvalue, NumVars);
			
			if (a != -1){
				leftvalue =memory[a].value;
			}
			
			
			
			b = search(memory, rightvalue, NumVars);
				
			if (b != -1){
				rightvalue = memory[b].value;
			}
			
			
			
			
			
			
			
			
			if (op.ID == TokenID::PLUS ){
				int s = 0;
				
				
				if (righttype == "INT" || lefttype == "INT"){
					s = stoi(leftvalue)+ stoi(rightvalue);	
					result = to_string(s);
					resultType = "INT"; 
					
				}
				else {
					result = leftvalue + rightvalue;
					resultType = "STR"; 
				}
				
				
				
			}
			
	 		 else if(op.ID == TokenID::MINUS){
				int s = 0;
				
				
				s = stoi(leftvalue)- stoi(rightvalue);	
				result = to_string(s);
			 }
			
			else if(op.ID== TokenID::MULT){
				int s = 0;
				
				
				s = stoi(leftvalue)* stoi(rightvalue);	
				result = to_string(s);
			}
			
			else if(op.ID == TokenID::LT){
				int s = 0;
				
				
				s = stoi(leftvalue)< stoi(rightvalue);	
				result = to_string(s);
				
			}
			
			else if (op.ID == TokenID::POWER){
				int s = 0;
				
				s = pow(stoi(leftvalue),stoi(rightvalue));
				result = to_string(s);
			}
			else if(op.ID == TokenID::DIV){
				int s = 0;
				
				if (rightvalue!= "0"){
					s = stoi(leftvalue)/ stoi(rightvalue);	
					result = to_string(s);
				}
			}
			else if(op.ID == TokenID::MOD){
				int s = 0;
				
				
				if (rightvalue!= "0"){
					s = stoi(leftvalue)/ stoi(rightvalue);	
					result = to_string(s);
				}
				 
			     
			}
			else if(op.ID == TokenID::GT){
				int s = 0;
				
				
				s = stoi(leftvalue)> stoi(rightvalue);	
				result = to_string(s);	
				
			}
			else if(op.ID == TokenID::EQUAL_EQUAL){
				
				if (leftvalue== rightvalue){
					result = "1";
				}
				else if(leftvalue!= rightvalue){
					result = "0";
				}
				
			}
			else if(op.ID == TokenID::GTE){
				
				
				if (leftvalue>= rightvalue){
					result = "1";
				}
				else {
					result = "0";
				}
			}
			else if(op.ID == TokenID::LTE){
				
				if (leftvalue<= rightvalue){
					result = "1";
				}
				else {
					result = "0";
				}
				
			}
			else if(op.ID == TokenID::NOT_EQUAL){
				
				if (leftvalue!= rightvalue){
					result = "1";
				}
				else if(leftvalue== rightvalue){
					result = "0";
				}
			}
				
			
			
			resultType = lefttype;
			
			PC = PC +1;
	    }
		else {
			
			leftvalue = left.Value;
			int a = 0;
			a = search(memory, leftvalue, NumVars);
			
			if (a != -1){
				leftvalue =memory[a].value;
			}
			
			result = leftvalue;
			
			
			if (left.ID == 18){
				resultType = "INT";
			}
			else{
				resultType = "STR";
			}
			
		}
		
		int index =0;  
		index = search(memory, varname, NumVars);
		if (index == -1){
			memory[NumVars].name = varname;
			memory[NumVars].value = result;
			memory[NumVars].type = resultType;
			
			NumVars ++; 
		}
		else{
			
			memory[index].value = result;
			memory[index].type = resultType;
			
		}
	}
}

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

   Token* program;
	int ProgramSize;
	 program = inputSimplePy (filename, ProgramSize);
	
	Variable* memory;
	memory = new Variable[MemorySize];
	
	int PC = 0; // start with first stmt
	int NumVars = 0;
	
	
	while (program[PC].ID != TokenID::EOS){
	   executeStmt(program, PC, memory, NumVars);
	   PC++; 
    }
	
	delete[] program;
	delete[] memory;
	
	
	return 0;
	
	
}
