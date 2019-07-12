 /*! \mainpage Logic Assignment 2
 *
 * @section Assumptions
 *
 *         > The input is expected to be fully parenthesized statement.
 *
 *         > <statement> ::= p | ~p | ~(<statement>) | (<statement>^<statement>) | (<statement>V<statement>) |(<statement>><statement>)
 *
 * @section Input
 *
 *         > First line should be a infix expression which follows the above assumption.
 *
 * @section Limitations
 *
 *         > No output is generated for no input.
 *
 * @bug No known bugs.
 *
 * @section Code_Testing
 *
 * <a href="Q1testcase.html">Click here</a>
 *
 * @section Made_by

        Sarthak Gaur 2017A7PS0250H

        Vrutik Halani 2017A7PS1732H

        Vivek Soni 2017A7PS0173H
 */
#include <iostream>
using namespace std;
#include<vector>
#include "isSymbol.h"
#include "postfix.h"
#include "binarytree.h"
#include "infixtraversal.h"
int main() {
    vector<char> s; /*!< Vector s for storing the expression */
	string mainstr; /*!< String mainstr for taking input */
	cout<<"Enter infix expression: ";
	cin>>mainstr;
	///<mainstr pushed into Vector s
	for(int i=0;i<mainstr.length();i++){
        s.push_back(mainstr[i]);
	}
	postfix(s); /*!< Task 1: Converting the expression into postfix by calling postfix()*/
	cout<<"Converted postfix expression: ";
	for(int i=0;i<s.size();i++){
        if(s[i]!='(')
            cout<<s[i]; /*!< Printing postfix */
    else
        s.erase(s.begin()+i);
	}
    cout<<endl;
    cout<<"Infix expression after inorder tranversal: ";
    binarytree obj; /*!< Object of class binarytree created */
    obj.maketree(s); /*!< Task 2: Passing the postfix expression to create a parse tree by calling binarytree.maketree()*/
    if(mainstr.length()==1) /*!< Incase there is a single character, print it*/
        cout<<obj.mainroot->data;
    else if(obj.mainroot->data=='~') /*!< Task 3: Else pass the expression for infix traversal by calling infixtraversal() */
        infixtraversal(obj.mainroot);
    else{
        cout<<'(';
        infixtraversal(obj.mainroot);
        cout<<')';
    }
	return 0;
}
