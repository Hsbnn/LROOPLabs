#include <iostream>
#include "transformation.hpp"

using namespace std;

int main()
{
    int hour, min;
    string period;
    char a;
    cout << "Введите часы и период, (например, 8:30 am) которые будут закодированы в 24-часовом формате" << endl;
    cin >> hour >> a >> min >> period;
    cout << transformation(hour, min, period) << endl;
    return 0;
}
