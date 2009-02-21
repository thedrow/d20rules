#ifndef __D20HitPoints
#define __D20HitPoints

#include "GlobalDef.hpp"
#include "Rollable.hpp"

namespace D20Rules
{
	class D20Character;
	
	namespace Rollables
	{
		class D20HitPoints : public Rollable
		{
		private:
			Loki::StrongPtr<D20Rules::Definitions::ModifierType, false> iConModifier;

			D20Rules::Definitions::HPType iMaxHP;
			D20Rules::Definitions::HPType iTempHP;
			D20Rules::Definitions::HPType iCurrentHP;
			D20Rules::Definitions::HPType iNonlethalDamage;

			unsigned short int iHD;
			
			void updateTotal() { iTotal = iConModifier; }
		public:
			D20HitPoints();
			
			inline Definitions::HPType getMaxHP() const { return iMaxHP; }
			inline Definitions::HPType getTempHP() const { return iTempHP; }
			inline Definitions::HPType getCurrentHP() const { return iCurrentHP; }
			
			Definitions::HPType addHitDie(const Definitions::Dice dHitDie);
			
			inline void healDamage(const Definitions::HPType iHealedHP) { iCurrentHP += iHealedHP < iMaxHP ? iHealedHP : iMaxHP; }
			inline void doDamage(const Definitions::HPType iHPLost) { iCurrentHP -= iHPLost; }
			
			inline void setTempHP(const Definitions::HPType iNewTempHP) { iTempHP = iNewTempHP; }
			
		
			friend class D20Character;
		};
	}
}

#endif
