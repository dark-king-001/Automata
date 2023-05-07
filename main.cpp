#include <iostream>
#include <string>
using namespace std;
#include "src/State.hpp"
int main() {
    // Create the states
    state s1, s2, s3, s4, s5, s6, s7, s8, s9;
    
    // Add transitions between states
    s1.addState(' ', &s1);
    s1.addState('<', &s2);

    s2.addState('a', &s3);
    s2.addState('/', &s6);

    s3.addState('p', &s4);
    s4.addState('p', &s5);
    s5.addState('>', &s1);

    s6.addState('a', &s7);
    s7.addState('p', &s8);
    s8.addState('p', &s9);
    s9.addState('>', NULL);

    s5.writeChar = " bit-stream-true \n";
    s9.writeChar = " bit-stream-false \n";
    
    // Test the DFA
    string input = "<app>     </app>";
    cout << "Input: " << input << endl;
    s1.transition(&s1, input);
    
    return 0;
}