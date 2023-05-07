#include <iostream>
#include <string>
using namespace std;
#include "src/State.hpp"
int main() {
    // Create the states
    state s1, s2, s3, s4, s5;
    
    // Add transitions between states
    s1.addState('p', &s2);
    s2.addState('r', &s3);
    s3.addState('i', &s4);
    s4.addState('n', &s5);
    s5.addState('t', NULL);
    s5.writeChar = "echo";
    
    // Test the DFA
    string input = "print";
    cout << "Input: " << input << endl;
    cout << "Output: ";
    s1.transition(&s1, input);
    
    return 0;
}