#include <iostream>
#include <stack>
#include <string>

class Solution
{
public:
    bool isValid(std::string str)
    {
        std::stack<char> syms;
        std::cout << "size : " << str.size() << std::endl;

        for (int i = 0; i < str.size(); i++)
        {
            // 检测到左括号，入栈
            if ('(' == str[i] || '[' == str[i] || '{' == str[i])
            {
                syms.push(str[i]);
            }
            // 检测到右括号
            else if (')' == str[i] || ']' == str[i] || '}' == str[i])
            {
                if (syms.empty())
                    return false;
                
                if ((')' == str[i] && '(' == syms.top()) ||
                         (']' == str[i] && '[' == syms.top()) ||
                         ('}' == str[i] && '{' == syms.top()) )
                {
                    syms.pop();
                    continue;
                }

                return false;
            }
        }

        return syms.empty();
    }
};

int main()
{
    std::string str = "(";

    Solution sln;

    std::cout << sln.isValid(str) << std::endl;

    return 0;
}
