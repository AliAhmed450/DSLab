#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

bool isOpening(char c) {
    return c == '(' || c == '{' || c == '[' || c == '<';
}

bool isClosing(char c) {
    return c == ')' || c == '}' || c == ']' || c == '>';
}

int main() {
    string expr;
    cout << "Enter expression: ";
	getline(cin,expr);
    stack<pair<char, int>> st;

    unordered_map<char, char> match = {
        {')', '('},
        {'}', '{'},
        {']', '['},
        {'>', '<'}
    };

    unordered_map<char, char> reverseMatch = {
        {'(', ')'},
        {'{', '}'},
        {'[', ']'},
        {'<', '>'}
    };

    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i];

        // Opening bracket
        if (isOpening(c)) {
            st.push({c, i});
        }
        // Closing bracket
        else if (isClosing(c)) {
            // Extra closing bracket
            if (st.empty()) {
                cout << "Error: Extra closing bracket '" << c
                     << "' at position " << i << endl;
                return 0;
            }

            char topChar = st.top().first;
            int topPos = st.top().second;

            // Wrong-type mismatch
            if (topChar != match[c]) {
                cout << "Error: Mismatched bracket at position " << i << endl;
                cout << "Expected '" << reverseMatch[topChar]
                     << "' but found '" << c << "'" << endl;
                cout << "Opening bracket '" << topChar
                     << "' was at position " << topPos << endl;
                return 0;
            }

            st.pop();
        }
    }

    // Unclosed opening brackets
    if (!st.empty()) {
        cout << "Error: Unclosed bracket(s) detected\n";
        while (!st.empty()) {
            cout << "Unclosed '" << st.top().first
                 << "' at position " << st.top().second << endl;
            st.pop();
        }
        return 0;
    }

    cout << "Expression is balanced and valid ✅" << endl;
    return 0;
}
