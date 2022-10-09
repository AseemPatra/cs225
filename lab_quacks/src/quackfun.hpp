/**
 * @file quackfun.cpp
 * This is where you will implement the required functions for the
 * stacks and queues portion of the lab.
 */
#include <iostream>

namespace QuackFun {

/**
 * Sums items in a stack.
 *
 * **Hint**: think recursively!
 *
 * @note You may modify the stack as long as you restore it to its original
 * values.
 *
 * @note You may use only two local variables of type T in your function.
 * Note that this function is templatized on the stack's type, so stacks of
 * objects overloading the + operator can be summed.
 *
 * @note We are using the Standard Template Library (STL) stack in this
 * problem. Its pop function works a bit differently from the stack we
 * built. Try searching for "stl stack" to learn how to use it.
 *
 * @param s A stack holding values to sum.
 * @return  The sum of all the elements in the stack, leaving the original
 *          stack in the same state (unchanged).
 */
template <typename T>
T sum(stack<T>& s)
{
    T amount = 0;
    if (s.size() == 0){return amount;}
    T add = s.top();
    s.pop();
    amount = add + sum(s);
    s.push(add);

    // Your code here
    return amount; // stub return value (0 for primitive types). Change this!
                // Note: T() is the default value for objects, and 0 for
                // primitive types
}

/**
 * Checks whether the given string (stored in a queue) has balanced brackets.
 * A string will consist of square bracket characters, [, ], and other
 * characters. This function will return true if and only if the square bracket
 * characters in the given string are balanced. For this to be true, all
 * brackets must be matched up correctly, with no extra, hanging, or unmatched
 * brackets. For example, the string "[hello][]" is balanced, "[[][[]a]]" is
 * balanced, "[]]" is unbalanced, "][" is unbalanced, and "))))[cs225]" is
 * balanced.
 *
 * For this function, you may only create a single local variable of type
 * `stack<char>`! No other stack or queue local objects may be declared. Note
 * that you may still declare and use other local variables of primitive types.
 *
 * @param input The queue representation of a string to check for balanced brackets in
 * @return      Whether the input string had balanced brackets
 */
bool isBalanced(queue<char> input)
{
    stack<char> tot;
    int left = 0;
    int right = 0;
    int len = input.size();
    for (int index = 0; index < len; index++) {
        if (left < right) {return false;}
        tot.push(input.front());
        if (tot.top() == '[') {
            left += 1;
        }
        if (tot.top() == ']') {
            right += 1;
        }
        input.pop();
    }
    for (unsigned index = 0; index < tot.size(); index++) {
        input.push(tot.top());
        tot.pop();
    }

    // @TODO: Make less optimistic
    if (left == right) {
        return true;
    } else {
        return false;
    }
}

/**
 * Reverses even sized blocks of items in the queue. Blocks start at size
 * one and increase for each subsequent block.
 *
 * **Hint**: You'll want to make a local stack variable.
 *
 * @note Any "leftover" numbers should be handled as if their block was
 * complete.
 *
 * @note We are using the Standard Template Library (STL) queue in this
 * problem. Its pop function works a bit differently from the stack we
 * built. Try searching for "stl stack" to learn how to use it.
 *
 * @param q A queue of items to be scrambled
 */
template <typename T>
void scramble(queue<T>& q)
{
    // optional: queue<T> q2;
    int flag = 1;
    stack<T> s;
    queue<T> q2;
    
    while (q.size() != 0) {
        if (flag > (int) q.size()) {
            int size = q.size();
            if (flag - 1 % 2 != 0) {
                for (int index = 0; index < size; index++) {
                    T add = q.front();
                    s.push(add);
                    q.pop();
                }
                for (int index = 0; index < size; index++) {
                    T add = s.top();
                    q2.push(add);
                    s.pop();
                }
            }
            if (flag - 1 % 2 == 0) {
                for (int index = 0; index < size; index++) {
                    T add = q.front();
                    q2.push(add);
                    q.pop();
                }
            }
            continue;
        }
        for (int index = 0; index < flag; index++) {
            T add = q.front();
            if (flag % 2 != 0) {
                q2.push(add);
                q.pop();
            }
            if (flag % 2 == 0) {
                s.push(add);
                q.pop();
            }
            if (index == flag - 1 && flag % 2 == 0) {
                int len2 = s.size();
                for (int flip = 0; flip < len2; flip++) {
                    q2.push(s.top());
                    s.pop();
                }
            }
        }
        flag++;
    }
    int len3 = q2.size();
    for (int index = 0; index < len3; index++) {
        T add = q2.front();
        q.push(add);
        q2.pop();
    }
}
}
