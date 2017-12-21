// https://www.hackerrank.com/challenges/arithmetic-expressions/
#include <iostream>
#include <vector>
#include <iterator>
#include <utility>
#include <cassert>
using std::cout;

static const auto result = 101;

enum class Operation
{
    plus,
    minus,
    multiply
};
std::ostream& operator<<(std::ostream& os, const Operation op)
{
    switch (op)
    {
    case Operation::plus:
        os << '+';
        break;
    case Operation::minus:
        os << '-';
        break;
    case Operation::multiply:
        os << '*';
        break;
    }
    return os;
}

/* For multiply, if last is 3 and end_result is 7, then new_end_result = (101+7)/3 = 36 */
int magic(int res, int last, int mod)
{
    for (auto i = 0; i < last; i++)
        if ((i * mod + res) % last == 0)
            return (i * mod + res) / last;
    assert(0);
    return -1;
}

template <typename InputIt>
auto func(InputIt start, InputIt end,
          typename std::iterator_traits<InputIt>::value_type end_result)
{
    if (start == end - 1)
    {
        return std::make_pair(std::vector<Operation>{}, *start % result == end_result);
    }
    auto last = *(end - 1);
    {
        auto new_end_result = (end_result - last) % result;
        if (new_end_result < 0)
            new_end_result += result;
        auto[op, possible] = func(start, end - 1, new_end_result);
        if (possible)
        {
            op.push_back(Operation::plus);
            return std::make_pair(op, possible);
        }
    }
    {
        auto new_end_result = (end_result + last) % result;
        auto[op, possible] = func(start, end - 1, new_end_result);
        if (possible)
        {
            op.push_back(Operation::minus);
            return std::make_pair(op, possible);
        }
    }
    {
        auto new_end_result = magic(end_result, last, result);
        auto[op, possible] = func(start, end - 1, new_end_result);
        if (possible)
        {
            op.push_back(Operation::multiply);
            return std::make_pair(op, possible);
        }
    }
    return std::make_pair(std::vector<Operation>{}, false);
}

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> input(N);
    for (auto i = 0; i < N; i++)
        std::cin >> input[i];
    //std::vector input{22, 79, 21};
    //std::vector input{55, 3, 45, 33, 25};

    auto last = input.back();
    {
        auto[op, possible] = func(begin(input), end(input), 0);
        if (possible)
        {
            for (auto i = 0u; i < op.size(); i++)
                cout << input[i] << op[i];
            cout << last << '\n';
        }
    }
    /*{
        // plus
        auto[op, possible] = func(begin(input), end(input) - 1, result - last);
        if (possible)
        {
            for (auto i = 0u; i < op.size(); i++)
                cout << input[i] << op[i];
            cout << input[input.size() - 2] << "+" << last << '\n';
        }
    }
    {
        // minus
        auto[op, possible] = func(begin(input), end(input) - 1, last);
        if (possible)
        {
            for (auto i = 0u; i < op.size(); i++)
                cout << input[i] << op[i];
            cout << input[input.size() - 2] << "-" << last << '\n';
        }
    }
    {
        // multiply
        auto[op, possible] = func(begin(input), end(input) - 1, magic(result, last, result));
        if (possible)
        {
            for (auto i = 0u; i < op.size(); i++)
                cout << input[i] << op[i];
            cout << input[input.size() - 2] << "*" << last << '\n';
        }
    }*/
}
