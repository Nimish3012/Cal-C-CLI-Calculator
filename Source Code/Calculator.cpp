#include<iostream>
#include<string>
using namespace std;
string Exp;
double result;
int length1 = 0 , length2 = 0 ;

// string input();
// bool HasOP(string Exp);
// void evaluation(string Exp);
// void performOP(string Exp, char OP);
// void update(string Exp,int i);

    


//input function to take input and process the input into a mathematical expression
string input()
{
    cout<<"\n\nEnter the expression : ";
    string input;
    string exp;
    getline(cin, input);
    //cout << endl<< input;
    for (int i = 0; i < input.length(); i++)
    {   
        if (input.at(i) != ' ')
        {
            exp.push_back(input.at(i));
        }
    }
    cout<<"Your Expression is : "<<exp<<endl;
    return exp;
}


//This function check the presence of any operator in the expression
bool HasOP(string &Exp)
{
    int count= 0;
    for(int i=0; i<Exp.length(); i++)
    {
        if(Exp.at(i)=='/' || Exp.at(i)=='*' ||  Exp.at(i)=='+' || Exp.at(i)=='-')
        {
            return true;
        }
    }
    return false;
}


bool isDecimal(char c)
{
    if(c>='0' && c<='9' || c=='.')
    {
        return true;
    }
    else
    {
        return false;
    }
}

//
void update(int start, int length, string result)
{
    Exp.replace(start, length, result);
    cout<<endl<< "Updated string is  "<<Exp;
}
//this function will perform the required operation to the function
void performOP(string Exp, char OP)
{
    for(int i=0;i<Exp.length();i++)
    {
        if(Exp.at(i)==OP)
        {
            int start = i-1;
            int end = i+1;

            
            while(start >=0 && isDecimal(Exp.at(start)))   //replace isDigit() with a user defined function supporting floating point//
            {
                start--;// final value of 'start' is index of previous operator or -1
            }
            while(end < Exp.length() && isDecimal(Exp.at(end)))
            {
                end++;// final value of 'end' is index of next operator or at length of the expression
            }
            string opr1 = Exp.substr(start + 1, i - start - 1);
            string opr2 = Exp.substr(i + 1, end - i - 1);
                        
            double operand1 = stod(opr1);
            double operand2 = stod(opr2);
            
            //cout<<endl<<"substring to be evaluated : "<<operand1<<OP<<operand2<<endl;

            switch (OP)
            {
            case '/':
                //cout<<"/\n";
                result = operand1 / operand2;

                break;
            case '*':
                //cout<<"*\n";
                result = operand1 * operand2;
                break;
            case '+':
                //cout<<"+\n";
                result = operand1 + operand2;
                break;

            case '-':
                //cout<<"-\n";
                result = operand1 - operand2;
                break;

            default:
                break;
            }


            //cout<<endl<<"result after individual operation "<<result;
            string result_str = to_string(result); 
            //cout<< "\nthe converted string is : "<<result_str; 
            update(start+1, opr1.length() + opr2.length()+1, result_str);
        }
        
    }
}

void evaluation(string &Exp)
{
    for(char c : Exp)
    {
        
        if( c == '/')
        {   
            //cout<<"\n Exp at this instance : "<<Exp;
            //cout<<"\n Current OP index : "<<Exp.find(c);
            performOP(Exp,'/');
        }
    }

    for(char c : Exp)
    {
        if( c == '*')
        {
            //cout<<"\n Exp at this instance : "<<Exp;
            //cout<<"\n Current OP index : "<<Exp.find(c);
            performOP(Exp,'*');
        }
    }

    for(char c : Exp)
    {
        if( c == '+')
        {
            //cout<<"\n Exp at this instance : "<<Exp;
            // cout<<"\n Current OP index : "<<Exp.find(c);
            performOP(Exp,'+');
        }
    }

    for(char c : Exp)
    {
        if( c == '-')
        {
            // cout<<"\n Exp at this instance : "<<Exp;
            // cout<<"\n Current OP index : "<<Exp.find(c);
            performOP(Exp,'-');
        }
    }

}





int main()
{
    cout<<".......Welcome To Cal-C: (A Command Line Calculator).......\n ";
    cout<<"You can write expression in any order, it will be solved in DMAS priority\n ";
    //it can solve the expression in any order it can also ignore whitespaces;
    
    char choise;
    do{
        Exp = input();      //input string -> valid expression
                            //the input will be taken by the inpur funciont , and it will rearrage the string in the correct expression;
                            //it also deals with whitespaces in the middle of the string
        
        if(HasOP(Exp))      //checks for the presence of an operator in the exprssion
        {
            evaluation(Exp); //entire calculatoin takes place through this function
            cout<<"\nFinal Exp = "<<stod(Exp);
        }
        else
        {
            cout<<"\nInvalid Syntax";
        }

        cout<<"\nDo you want to continue (Y/N) : ";
        cin>>choise;    cin.ignore();

    }while(choise=='Y' || choise=='y');
    cout<<"\n ........Thank You For Using Cal-C........ \n ........Press Any Key To Exit Now........";
    getchar();
    return 0;
}