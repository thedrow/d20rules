#ifndef _D20BaseAttack
#define _D20BaseAttack

#include <loki/StrongPtr.h>
#include <list>
#include <queue>
#include "Rollable.hpp"
#include "GlobalDef.hpp"

namespace D20Rules
{
	class D20Character;
	
	namespace Rollables
	{
		class D20BaseAttack : public Rollable
		{
		private:
            D20Rules::Definitions::MiscType iMiscModifier;
        	D20Rules::Definitions::SizeModifierType iSizeModifier;
        	D20Rules::Definitions::RangePenaltyType iRangePenaltyModifier;

        	Loki::StrongPtr<D20Rules::Definitions::ModifierType, false> iMeeleModifier;
        	Loki::StrongPtr<D20Rules::Definitions::ModifierType, false> iRangeModifier;
			
			void updateTotal() { *iTotal = *iterAttacks + iMiscModifier + iSizeModifier; }
			
			std::list<Definitions::BaseAttackType> lAttacks;
			std::list<Definitions::BaseAttackType>::iterator iterAttacks;
		public:
            D20BaseAttack();
            
            void calculateBaseAttack(Definitions::LevelType iLevel, Definitions::BaseAttackRating barRating);
            
			inline short getMeleeBaseAttack() { updateTotal(); return *iTotal + *(iMeeleModifier); }
			inline short int getRangeBaseAttack() { updateTotal(); return *iTotal + *(iMeeleModifier) + iRangePenaltyModifier; }
			
			inline void nextBaseAttack() { iterAttacks++; if ( iterAttacks == lAttacks.end() ) iterAttacks = lAttacks.begin()++; }
			
			friend class D20Character;
		};
	}
}

#endif
