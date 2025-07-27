#include <bits/stdc++.h>
using namespace std;

/**
 * Valid Parentheses Checker
 * 
 * Difficulty: Easy
 * 
 * Problem Description:
 * Given a string `s` containing just the characters '(', ')', '{', '}', '[' and ']', 
 * determine if the input string is valid. The string is valid if:
 * 1. Open brackets are closed by the same type of brackets.
 * 2. Open brackets are closed in the correct order.
 * 
 * Approach:
 * - Use a stack to track the expected closing brackets.
 * - For each opening bracket, push the corresponding closing bracket onto the stack.
 * - For each closing bracket, check if it matches the top of the stack.
 * - If the stack is empty at the end, the string is valid.
 * 
 * Time Complexity: O(n) (single pass through the string)
 * Space Complexity: O(n) (stack usage in worst case)
 * 
 *  Checks if the input string has valid parentheses. 
 * @param s The input string containing brackets.
 * @return `true` if the parentheses are valid, `false` otherwise.
 */

bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            st.push(')');
        else if (s[i] == '{')
            st.push('}');
        else if (s[i] == '[')
            st.push(']');
        else if (st.empty() || st.top() != s[i])
        {
            return false;
        }
        else
        {
            st.pop();
        }
    }
    return st.empty();
}
int main()
{
    string s;
    cin >> s;
    bool result = isValid(s);
    cout << result << "\n";
}
