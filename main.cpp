#include <iostream>
#include <string>
using namespace std;
class state {
private:
    class node {
    public:
        char readChar;
        state *nextState;
        node *next;

        node(char c, state *s) : readChar(c), nextState(s), next(nullptr) {}
    };

    node *root;
public:
    string writeChar;

    state() : root(nullptr) {}

    void addState(char c, state *s) {
        node *new_node = new node(c, s);
        if (root == nullptr) {
            root = new_node;
        } else {
            node *curr = root;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = new_node;
        }
    }

    state* search(char c) {
        node *curr = root;
        while (curr != nullptr) {
            if (curr->readChar == c) {
                return curr->nextState;
            }
            curr = curr->next;
        }
        return nullptr;
    }
    void transition(state *currentState, const string &input, size_t index = 0) {
        if (index == input.size()) {
            return;
        }

        char currentChar = input[index];
        state::node *currNode = currentState->root;
        bool found = false;

        while (currNode != nullptr) {
            if (currNode->readChar == currentChar) {
                cout << currentState->writeChar;
                currentState = currNode->nextState;
                found = true;
                break;
            }
            currNode = currNode->next;
        }

        if (!found) {
            cout << "string not accepted\n";
            return;
        }

        transition(currentState, input, index + 1);
    }
};
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