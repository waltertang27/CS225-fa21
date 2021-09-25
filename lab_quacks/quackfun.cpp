/**
 * @file quackfun.cpp
 * This is where you will implement the required functions for the
 * stacks and queues portion of the lab.
 */

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
    if(s.empty()) {
        return 0;
    }
    else {
        T var = s.top();
        s.pop();
        T ans = sum(s); 
        s.push(var);
        return ans + s.top();
    }

    // Your code here
    return T(); // stub return value (0 for primitive types). Change this!
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

    // @TODO: Make less optimistic
    stack<char> s;
    for(unsigned long i = 0; i < input.size(); i++) {

        if(input.front() == '[') {
            s.push(input.front());
        }
        else if(input.front() == ']') {
            if(s.empty()) {
                return false;
            }
            else {
                s.pop();
            }
        }
        char temp = input.front();
        input.pop();
        input.push(temp);

    }
    if(s.empty()) {
        return true;
    }
    else {
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
    stack<T> s;
    // optional: queue<T> q2;

    // Your code here
    stack<T> temp;
    stack<T> temp2;
    unsigned long count = 1;
    while(!q.empty()) {
        if(count % 2 == 1) {
            for(unsigned long j = 0; j < count; j++) {
                if(!q.empty()) {
                    s.push(q.front());
                    //std::cout << q.front();
                    q.pop();
                }
               
            }
            
        }
        else {     
            for(unsigned long j = 0; j < count; j++) {
                if(!q.empty()) {
                    temp.push(q.front());
                    //std::cout << q.front() << std::endl;
                    q.pop();
                }
                
            }
            for(unsigned long j = 0; j < count; j++) {
                if(!temp.empty()) {
                    s.push(temp.top());
                    //std::cout << temp.top();
                    //std::cout << s.top();
                    temp.pop();
                }
            }
            //std::cout << std::endl;
        }
        count++;
        
        //std::cout << std::endl;
    }
    //std::cout << "testing 150" << std::endl;
    //unsigned long size1 = s.size();
   
    //std::cout << size1 << std::endl;
    
    
    while(!s.empty()) {
        temp2.push(s.top());
        std::cout << temp2.top();
        s.pop();
    }
    //unsigned long size2 = temp2.size();
    //std::cout << "testing 157" << std::endl;
    while(!temp2.empty()) {
        q.push(temp2.top());
        std::cout << q.front();
        temp2.pop();
        //std::cout << "testing 162" << std::endl;
    }
    //std::cout << std::endl;
    }
}
