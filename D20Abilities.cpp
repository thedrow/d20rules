#include "D20Abilities.hpp"
#include "D20Ability.hpp"
#include "GlobalDef.hpp"

using namespace D20Rules::Rollables;
using namespace D20Rules::Definitions;

namespace D20Rules
{
	namespace Containers
	{
		D20Abilities::D20Abilities()
		{
		}
		
		short int D20Abilities::rollAbilities()
		{
            Strength.rollAbility();
            Dexterity.rollAbility();
            Constitution.rollAbility();
            Wisdom.rollAbility();
            Intelligence.rollAbility();
            Charisma.rollAbility();
            
            return Strength.getModifier() + Dexterity.getModifier() + Constitution.getModifier() + Wisdom.getModifier() + Intelligence.getModifier() + Charisma.getModifier();
        }
	}
}		
