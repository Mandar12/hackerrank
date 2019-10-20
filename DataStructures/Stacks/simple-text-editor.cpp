/* https://www.hackerrank.com/challenges/simple-text-editor/problem
In this challenge, you must implement a simple text editor. Initially, your editor contains an empty string, S. You must perform Q operations of the following 4 types:

append(W) - Append string W to the end of S.
delete(k) - Delete the last k characters of S.
print(k) - Print the kth character of S.
undo() - Undo the last (not previously undone) operation of type 1 or 2, reverting S to the state it was in prior to that operation.
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    int number_of_operations; // Q
    cin >> number_of_operations;
    string S;
    // We could have stack with pair<int /*operation type*/, variant<int, string> /* argument */>
    // Or we can use 3 different stacks: operations, string arguments, integer arguments for size efficiency.
    // In case of append operation, we need to store size of string
    // In case of delete operation, we need to store content of string (last k chars)
    stack<int> history;
    stack<int> append_arg;
    stack<string> delete_arg;
    for (auto i = 0; i < number_of_operations; i++)
    {
        int type; // {1, 2, 3, 4}
        cin >> type;
        string str;
        int k;
        switch (type)
        {
        case 1: // append
            cin >> str;
            S.append(str);
            history.push(type);
            append_arg.push(str.size());
            break;

        case 2: // delete
            cin >> k;
            history.push(type);
            delete_arg.push(S.substr(S.size() - k, k));
            S.erase(S.size() - k, k);
            break;

        case 3: // print
            cin >> k;
            cout << S[k - 1] << '\n';
            // No need to add 'print' to history
            break;

        case 4: // undo
        {
            const int last = history.top();
            if (last == 1)
            {
                const int k = append_arg.top();
                S.erase(S.size() - k, k);
                append_arg.pop();
            }
            else // if (last == 2)
            {
                const string& s = delete_arg.top();
                S.append(s);
                delete_arg.pop();
            }
            history.pop();
            break;
        }

        default:
            cout << "Wrong type\n";
            exit(-1);
        }
    }
    return 0;
}

/*
Sample Input
8
1 abc
3 3
2 3
1 xy
3 2
4 
4 
3 1

Sample Output
c
y
a
*/