#ifndef _D20Skills
#define _D20Skills

#include <string>
#include <map>
#include <list>
#include "D20Skill.hpp"
#include "GlobalDef.hpp"

namespace D20Rules
{
	namespace Containers
	{
		class D20Skills
		{
		private:
			std::map<std::string, Loki::StrongPtr<D20Rules::Rollables::D20Skill> > mapSkills;
			
			unsigned short int iMaxSkillsPoints;
		public:
			D20Skills();
			
			inline Loki::StrongPtr<Rollables::D20Skill, false> operator [](const std::string sSkillName) { return mapSkills.find(sSkillName) != mapSkills.end() ? mapSkills[sSkillName] : NULL; }
			
			std::list<Loki::StrongPtr<Rollables::D20Skill, false> > getSkillsByModifier(const Definitions::RelatedModifier rmModifierName);
			unsigned short int getTotalSkillPoints();
			inline unsigned short int getMaxSkillPoints() { return iMaxSkillsPoints; }
		};
	}
}

#endif
