#include <forward_list>
#include <iostream>
#include <memory>
using namespace std;

class Stack { // creates forward list stack
private:
  forward_list<char> list_stack_;

public:
  Stack() { list_stack_ = {}; }
  const forward_list<char> &GetListStack() const { return list_stack_; }
  // adds element to front of list
  void Push(char data) { list_stack_.push_front(data); }
  // deletes first element of list
  void Pop() {
    if (list_stack_.empty()) {
      cout << "Stack is empty\n";
    }
    list_stack_.pop_front();
  }
  // prints first element of list
  char Peek() {
    if (list_stack_.empty()) {
      cout << "Stack is empty" << endl;
      return '\0'; // return a default value for empty stack
    }
    return list_stack_.front();
  }
  // dispalys stack
  void DisplayStack() {
    if (list_stack_.empty()) {
      cout << "Stack is empty" << endl;
      return;
    }
    for (auto i : list_stack_) {
      cout << "|" << i << "|" << endl;
    }
    cout << endl;
  }
};
// checks if parentheis are balanced () [] {}
bool AreParenthesisBalanced(string expr) {
  // creates new object of stack class and allows access to it
  Stack stack;
  // iterate through the expression and add/remove elements from stack
  for (int i = 0; i < expr.length(); i++) {
    if (stack.GetListStack().empty()) {
      stack.Push(expr[i]);
    } else if ((stack.Peek() == '(' && expr[i] == ')') ||
               (stack.Peek() == '{' && expr[i] == '}') ||
               (stack.Peek() == '[' && expr[i] == ']')) {
      // remove element from stack
      stack.Pop();
    } else { // push element to stack
      stack.Push(expr[i]);
    }
  }
  if (stack.GetListStack().empty()) {
    return true;
  }
  // display stack if the expression is not balanced
  stack.DisplayStack();
  return false;
}

int main() {
  // stores user input
  string expr;
  // prompts user input
  cout << "Enter expression: ";
  cin >> expr;
  // calls bool and checks if true/false
  if (AreParenthesisBalanced(expr)) {
    cout << "Balanced";
  } else {
    cout << "Not Balanced";
  }
  return 0;
}
