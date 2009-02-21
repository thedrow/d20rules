#include "D20Skill.hpp"

using namespace D20Rules::Definitions;
using namespace std;

namespace D20Rules
{
	namespace Rollables
	{
		D20Skill::D20Skill()
		: 	bUsedUntrained(false),
		  	bClassSkill(false),
		  	bRetry(false),
		  	bArmorCheckPenality(false),
		  	sName(""),
		  	rmModifierName(D20Rules::Definitions::modStrength),
		  	iModifier(NULL),
		  	fRank(0),
		  	iMisc(0)
		{
		}
		
		D20Skill::D20Skill(RankType fNewRank, MiscType iNewMisc, const bool bNewUsedUntrained, const bool bNewRetry, const bool bNewArmorCheckPenality, const string sNewName, const RelatedModifier rmNewModifierName)
		: 	bUsedUntrained(bNewUsedUntrained),
		  	bClassSkill(false),
		  	bRetry(bNewRetry),
		  	bArmorCheckPenality(bNewArmorCheckPenality),
		  	sName(sNewName),
		  	rmModifierName(rmNewModifierName),
		  	iModifier(NULL),
		  	fRank(fNewRank),
		  	iMisc(iNewMisc)
		{
		}
		
		D20Skill::D20Skill(const bool bNewUsedUntrained, const bool bNewRetry, const bool bNewArmorCheckPenality, const string sNewName, const RelatedModifier rmNewModifierName)
		: 	bUsedUntrained(bNewUsedUntrained),
		  	bClassSkill(false),
		  	bRetry(bNewRetry),
		  	bArmorCheckPenality(bNewArmorCheckPenality),
		  	sName(sNewName),
		  	rmModifierName(rmNewModifierName),
		  	iModifier(NULL),
		  	fRank(0),
		  	iMisc(0)
		{
		}
		
		void D20Skill::updateSynergies()
		{
			/*if ( fRank > 5 && !qSynergies.empty() )
				while ( !qSynergies.empty() )
				{
					qSynergies.front()->iMisc += 2;
					qSynergies.pop();
				}*/
		}
	}
}
