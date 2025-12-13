#include <string>
#include <iostream>
#include <set>

using namespace std;

// A simple Node structure for the tree
struct Node {
    char value;
    Node* left;
    Node* right;

    Node(char v) : value(v), left(nullptr), right(nullptr) {}
};

// Global set for unary operators (example)
set<char> unaryops = {'!', '~'}; 

/**
 * Finds the index of the closing parenthesis matching the one at 'lo'.
 * NOTE: Returns 'lo' itself if a[lo] is not an opening parenthesis (for simple operands).
 */
int match(const string& a, int lo) {
    if (a[lo] != '(') return lo; // Case for single char operand like '3' in (3+5)

    int count = 0;
    while (true) {
        if (a[lo] == '(') {
            count++;
        } else if (a[lo] == ')') {
            count--;
        }
        
        if (count == 0) {
            return lo; // Found the matching closing parenthesis
        }
        lo++;
    }
    return -1; // Error: Unbalanced
}

Node* expressiontree(string a, int lo, int hi) {
    // Base Case: Single leaf node (number or variable)
    if (lo == hi) {
        return new Node(a[lo]);
    }

    // Case 1: Unary Operator (e.g., "(-5)")
    // Checks if the char after the opening '(' is a unary op
    if (unaryops.count(a[lo + 1])) {
        Node* x = new Node(a[lo + 1]); // The operator
        // The operand is everything after the operator, excluding the outer parens
        x->right = expressiontree(a, lo + 2, hi - 1); 
        return x;
    }
    
    // Case 2: Binary Operator (e.g., "(A+B)")
    else {
        // Find the split point. 
        // lo+1 is the start of the Left Operand. 
        // 'k' will be the end index of the Left Operand.
        int k = match(a, lo + 1);

        // The operator is immediately after the left operand (at k+1)
        Node* x = new Node(a[k + 1]);

        // Left Child: from start of left operand (lo+1) to its end (k)
        x->left = expressiontree(a, lo + 1, k);

        // Right Child: from after operator (k+2) to end of expression (hi-1)
        x->right = expressiontree(a, k + 2, hi - 1);

        return x;
    }
}
