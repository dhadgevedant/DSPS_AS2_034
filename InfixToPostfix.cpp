/*
	Write a cpp program for expression conversion, infix to postfix using stack

*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;


class InfixToPostfixConverter {

private:

    
    int getPrecedence(char op) {
    
        if (op == '^') return 3;
        else if (op == '*' || op == '/') return 2;
        else if (op == '+' || op == '-') return 1;
        return 0;
    }

    
    bool isOperator(char ch) {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
    }

    
    bool isOperand(char ch) {
        return isalnum(ch);
    }

public:
    
    string convert(const string& infix) {
        stack<char> opStack;
        string postfix;

        for (char ch : infix){
            if (isOperand(ch)){
                postfix += ch; // append operand to postfix
            } 
            else if (ch == '(') {
                opStack.push(ch); // push ( onto stack
            } 
            else if (ch == ')') {
                // pop from stack to postfix until ( is encountered
                while (!opStack.empty() && opStack.top() != '(') {
                    postfix += opStack.top();
                    opStack.pop();
                }
                if (!opStack.empty() && opStack.top() == '(') {
                    opStack.pop(); // remove ( from stack
                }
            } else if (isOperator(ch)){
                // pop from stack to postfix while top of stack has higher or equal precedence
                while (!opStack.empty() && isOperator(opStack.top()) &&
                       getPrecedence(ch) <= getPrecedence(opStack.top())) {
                    postfix += opStack.top();
                    opStack.pop();
                }
                opStack.push(ch); // push current operator onto stack
            }
        }

        // Pop all remaining operators from stack
        while (!opStack.empty()) {
            postfix += opStack.top();
            opStack.pop();
        }

        return postfix;
    }
};

int main() {
    InfixToPostfixConverter converter;
    string infixExpr = "a+b*(c^d-e)^(f+g*h)-i";
    string postfixExpr = converter.convert(infixExpr);

    cout << "Infix Expression: " << infixExpr << endl;
    cout << "Postfix Expression: " << postfixExpr << endl;

    return 0;
}

