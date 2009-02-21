#include "D20Skills.hpp"
#include "D20Skill.hpp"
#include "GlobalDef.hpp"
#include <string>
#include <map>
#include <cmath>

using namespace std;
using namespace D20Rules;
using namespace D20Rules::Rollables;
using namespace D20Rules::Definitions;
using namespace Loki;

namespace D20Rules
{
	namespace Containers
	{
		D20Skills::D20Skills()
		{
		}
		
		list<StrongPtr<D20Skill, false> > D20Skills::getSkillsByModifier(const RelatedModifier rmModifierName)
		{
			list<StrongPtr<D20Skill, false> > lSkillsList;
			for ( map<string, StrongPtr<D20Skill> >::iterator iter = mapSkills.begin(); iter != mapSkills.end(); ++iter )
				if ( iter->second->getRelatedModifier() == rmModifierName )
					lSkillsList.push_back(iter->second);
					
			return lSkillsList;
		}
		
		unsigned short int D20Skills::getTotalSkillPoints()
		{
			unsigned short int iSum = 0;
			for ( map<string, StrongPtr<D20Skill> >::iterator iter = mapSkills.begin(); iter != mapSkills.end(); ++iter)
				iSum += (unsigned short int) ceil(iter->second->getRank());
				
			return iSum;
		}
	}
}
