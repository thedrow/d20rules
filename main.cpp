#include <iostream>
#include "D20Character.hpp"

using namespace std;
using namespace D20Rules;

int main()
{
	D20Character c;
	c.Abilities.Wisdom.setScore(13);
	cout << c.SavingThrows.Will.getTotal();
    cin.get();
    return 0;
}
