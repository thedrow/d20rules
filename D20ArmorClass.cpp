#include "D20ArmorClass.hpp"

namespace D20Rules
{
	namespace RolledAgainst
	{
		D20ArmorClass::D20ArmorClass()
		: D20DifficultyClass(10),
		  iArmorBonus(0),
		  iShieldBonus(0),
		  iDexModifier(NULL),
		  iSize(0),
		  iNaturalArmor(0),
		  iDeflection(0),
		  iDodgeBonus(0),
		  iMisc(0),
		  bFlatFooted(false),
		  bTouchArmorClass(false)
		{
		}
	}
}
