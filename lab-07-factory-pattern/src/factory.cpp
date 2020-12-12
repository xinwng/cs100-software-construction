#include "../header/factory.hpp"
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

Base *Factory::parse(char **input, int length)
{
    queue<char *> m_queue;
    stack<char *> m_stack;
    string m_string;

    for (int i = 1; i < length; ++i)
    {
        m_string = static_cast<string>(input[i]);
        if (isdigit(m_string.at(0)))
        {
            m_queue.push(input[i]);
        }
        else if ((m_string == "*") || (m_string == "/") || (m_string == "+") || (m_string == "-") || m_string == "**")
        {
            while (!m_stack.empty())
            {
                m_queue.push(m_stack.top());
                m_stack.pop();
            }
            m_stack.push(input[i]);
        }
        else
        {
            cout << "incorrect input, returning nullptr" << endl;
            return nullptr;
        }
    }

    while (!m_stack.empty())
    {
        m_queue.push(m_stack.top());
        m_stack.pop();
    }

    queue<Base *> m_queue2;
    Base *base1;
    Base *base2;
    Base *base3;
    while (!m_queue.empty())
    {
        m_string = static_cast<string>(m_queue.front());
        if (m_string == "+")
        {
            base2 = m_queue2.front();
            m_queue2.pop();
            base3 = m_queue2.front();
            m_queue2.pop();
            base1 = new Add(base2, base3);
            m_queue2.push(base1);
            m_queue.pop();
        }
        else if (m_string == "-")
        {
            base2 = m_queue2.front();
            m_queue2.pop();
            base3 = m_queue2.front();
            m_queue2.pop();
            base1 = new Sub(base2, base3);
            m_queue2.push(base1);
            m_queue.pop();
        }
        else if (m_string == "*")
        {
            base2 = m_queue2.front();
            m_queue2.pop();
            base3 = m_queue2.front();
            m_queue2.pop();
            base1 = new Mult(base2, base3);
            m_queue2.push(base1);
            m_queue.pop();
        }
        else if (m_string == "**")
        {
            base2 = m_queue2.front();
            m_queue2.pop();
            base3 = m_queue2.front();
            m_queue2.pop();
            base1 = new Pow(base2, base3);
            m_queue2.push(base1);
            m_queue.pop();
        }
        else if (m_string == "/")
        {
            base2 = m_queue2.front();
            m_queue2.pop();
            base3 = m_queue2.front();
            m_queue2.pop();
            base1 = new Div(base2, base3);
            m_queue2.push(base1);
            m_queue.pop();
        }
        else
        {
            double temp;
            temp = stod(m_string);
            base1 = new Op(temp);
            m_queue.pop();
            m_queue2.push(base1);
        }
    }
    return m_queue2.front();
}