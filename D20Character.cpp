#include "D20Character.hpp"

namespace D20Rules
{
    D20Character::D20Character()
    {
		SavingThrows.Fortitude.iModifier = Abilities.Constitution.iModifier;
		SavingThrows.Reflex.iModifier = Abilities.Dexterity.iModifier;
        SavingThrows.Will.iModifier = Abilities.Wisdom.iModifier;
        
        ArmorClass.iDexModifier = Abilities.Dexterity.iModifier;
    }
}
