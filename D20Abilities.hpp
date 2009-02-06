#ifndef __D20Abilities
#define __D20Abilities

#include "D20Ability.hpp"
#include "GlobalDef.hpp"

namespace D20Rules
{
	namespace Containers
	{
		class D20Abilities
		{
		public:
			Rollables::D20Ability Strength;
			Rollables::D20Ability Dexterity;
			Rollables::D20Ability Constitution;
			Rollables::D20Ability Wisdom;
			Rollables::D20Ability Intelligence;
			Rollables::D20Ability Charisma;
			
			D20Abilities();
			D20Abilities(Definitions::ScoreType, Definitions::ScoreType, Definitions::ScoreType, Definitions::ScoreType, Definitions::ScoreType, Definitions::ScoreType);
			
			short int rollAbilities();
		};
	}
}
		
#endif
