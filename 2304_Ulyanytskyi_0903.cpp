#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

void display_list(const list<double>& numbers)
{
    cout << "{ ";
    for (const auto& number : numbers)
        cout << number << ' ';
    cout << "}\n";
}

void remove_nearby_number(list<double>& numbers, double threshold)
{
    for (auto it = numbers.begin(); it != numbers.end();)
    {
        if (next(it) != numbers.end() && abs(*it - *next(it)) < threshold)
        {
            it = numbers.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

int main()
{
    list<double> numbers = { 2.2, 1.4, 5.6, 7.8, 10.2, 1.38, 15.3, 21, 5.64 };
    double threshold = 0.1 * (*numbers.begin());

    cout << "Original list: \t\t\t";
    display_list(numbers);

    numbers.sort();

    cout << "Sorted list: \t\t\t";
    display_list(numbers);

    remove_nearby_number(numbers, threshold);

    cout << "List after removing number: \t";
    display_list(numbers);

    return 0;
}