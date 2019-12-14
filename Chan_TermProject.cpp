//Program Name: ALGEBRA TUTOR
//Author: Jared Chan
//Purpose: Final Project: Modification of Math Tutor program to incorporate solving for variables

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void showMenu();                            //function prototype containing the menu
int getProblemForm();                        //prototype for getting roblem type choice/termination
int getFirstNum(int);                          //prototype for the first number
int getSecondNum(int, int);                         //prototype for second number
int getAnswer(int, int, int);               //prototype for answer
void displayProblem(int, int, int, int);    //prototype for problem dispplay

int main()      //Main Function
{
    bool run = true;        //Boolean value for Run (run program)
    int form; 
	int firstNum;                     
    int secondNum;
	int answer;
	while(run == true)      //program runs until user inputs a 5
    {
        showMenu();
        form = getProblemForm();
		firstNum = getFirstNum(form);
		secondNum = getSecondNum(form, firstNum);
		answer = getAnswer(form, firstNum, secondNum);
		displayProblem(form, firstNum, secondNum, answer);		
        
	}
}


void showMenu()             //showMenu function containing the menu

{
    cout << "Solve for X. Enter ""Q"" at any time to quit." << endl;                      //cout statements describing the Menu
	cout << "------------------------" << endl;
}
//Problem Form Function: Generates # 1-4 and randomly chooses a problem type
int getProblemForm()     
{
    int form = rand() % 4 + 1;            
    return form;         
}

//generate the first number
int getFirstNum(int form)                                  
{
	cout << endl;
	int first;    
	if (form == 1 || form == 2 ) 
	{
		first = rand() % 50 + 1;
	}
    else if (form == 3 || form == 4)
    {
		first = rand() % 10 + 1;
	}
	return first;                                    
}
//Getting Second Number
int getSecondNum(int form, int firstNum)                               
{
	int second;
	if (form == 1 || form == 2)            
	{
		second = firstNum + rand() % 50;                    
	}	
    else if (form == 3)                          
	{
		second = firstNum * (rand() % 10 + 1);
	}
	else if (form == 4)                          
	{
		second = firstNum *(rand() % 10 + 1);        
	}

//returns value of the second number
	return second;                                      
}
//function that calculates the answers
int getAnswer(int form, int firstNum, int secondNum)           
{
    int answer;                                         
	if (form == 1)                                
	{
		answer = secondNum - firstNum;                  
	}
	else if (form == 2)                           
	{
		answer = firstNum + secondNum; 
	}
	
	else if (form == 3)                            
	{
		answer = secondNum / firstNum;                   
	}
	else if (form == 4)                           
	{
        answer = secondNum / firstNum;
	}
	return answer;
}
//function that displays problems	
void displayProblem(int form, int firstNum, int secondNum, int answer)                         
{
	int userAnswer;       
//for loop allows user to attempt the problem up to four times.
//this is used in every case.                                
	for (int tries = 3; tries >= 0; tries--)                   
	{             
        //random number = 1, form is 1st + X = 2nd                                           
		if (form == 1)
		{
			cout << firstNum << " + " << "X" << " = " << secondNum << endl << endl;
			cout << "X " << "= ?" << endl;
			cout << endl;
			cin >> userAnswer;                                                  //user input answer
			
			if (userAnswer == answer)                                           //compare user answer to correct answer
			{
				cout << "Correct!" << endl << endl;                             //cout for correct answer
				break;
			}
			else if (tries == 0)                       //no attempts remain
			{
				cout << "Incorrect. The correct answer is " << answer << "." << endl << endl;       //Answer displayed after 3 incorrect tries
			}
			else
			{
				cout << "Incorrect. " << tries << " attempts remaining." << endl;   //cout, announces # attempts remaining (value of int tries)
			}
		}
        //random number = 2, form X - 1st = 2nd 
		else if (form == 2)                                   
		{
			cout << "X"<< " - " << firstNum << " = " << secondNum << endl << endl;
			cout << "X " << "= ?" << endl;
		    cout << endl;
			cin >> userAnswer;
			
			if (userAnswer == answer)
			{
				cout << "Correct!" << endl << endl;                                                     
				break;
			}
			else if (tries == 0)                                                                       
			{
				cout << "Incorrect. The correct answer is " << answer << "." << endl << endl;               
			}
			else    
			{
				cout << "Incorrect. " << tries << " attempts remaining." << endl;
			}
			
		}
        //random number = 3, form is 1st * X = 2nd 
		else if (form == 3)                         
		{
			cout << firstNum << " * " << "X" << " = " << secondNum << endl << endl;
	        cout << "X " << "= ?" << endl;
		    cout << endl;
			cin >> userAnswer;
			
			if (userAnswer == answer)                                  
			{
				cout << "Correct!" << endl << endl;
				break;
			}
			else if (tries == 0)
			{
				cout << "Incorrect. The correct answer is " << answer << "." << endl << endl;
			}
			else
			{
				cout << "Incorrect. " << tries << " attempts remaining." << endl;
			}
		}
        //random number = 1, form is 2nd / X = 1st 
		else if (form == 4)                                                       //user chose division, same logic as above
		{
            cout << secondNum << " / " << "X" << " = " << firstNum << endl << endl;                      
			cout << "X " << "= ?" << endl;
		    cout << endl;
			cin >> userAnswer;
			
			if (userAnswer == answer)                         
			{
				cout << "Correct!" << endl << endl;
				break;
			}
			else if (tries == 0)
			{
				cout << "Incorrect. The correct answer is " << answer << "." << endl << endl;
			}
			else
			{
				cout << "Incorrect. " << tries << " attempts remaining." << endl;
			}
		}
	}
}

//Forms
//FIRSTNUM ALWAYS BTWN 1 and 27
//1) X + firstnum = secondnum       --> secondnum > firstnum
//2) X - firstnum = secondnum              --> answer < firstnum
//3) X * firstnum = secondnum           --> secondnum divisible by firstnum
//4) X / firstnum = secondnum         --> answer divisible by firstnum

















