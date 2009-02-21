#ifndef __D20ArmorClass
#define __D20ArmorClass

#include "D20DifficultyClass.hpp"
#include "GlobalDef.hpp"

namespace D20Rules
{
	class D20Character;
	
	namespace RolledAgainst
	{
		class D20ArmorClass : public D20DifficultyClass
		{
			D20Rules::Definitions::ArmorBonusType iArmorBonus;
			D20Rules::Definitions::ShieldBonusType iShieldBonus;
			Loki::StrongPtr<D20Rules::Definitions::ModifierType, false> iDexModifier;
			D20Rules::Definitions::SizeModifierType iSize;
			D20Rules::Definitions::NaturalArmorBonusType iNaturalArmor;
			D20Rules::Definitions::DefelectionModifierType iDeflection;
			D20Rules::Definitions::DodgeBonusType iDodgeBonus;
			D20Rules::Definitions::MiscType iMisc;
			
			bool bFlatFooted;
			bool bTouchArmorClass;
			
			void updateTotal()
			{
				*iTotal = 10;
				
				if ( !bFlatFooted )
					*iTotal += *iDexModifier + iDodgeBonus;
				
				if ( !bTouchArmorClass )
					*iTotal += iArmorBonus + iShieldBonus + iNaturalArmor;
					
				*iTotal += iSize + iDeflection + iMisc;
			}
		public:
			D20ArmorClass();
			
			inline bool isCharacterFlatFooted() { return bFlatFooted; }
			
			inline D20Rules::Definitions::DodgeBonusType getDodgeBonus() const { return iDodgeBonus; }
			inline D20Rules::Definitions::ShieldBonusType getShieldBonus() const { return iShieldBonus; }
			inline D20Rules::Definitions::SizeModifierType getSizeModifier() const  { return iSize; }
			inline D20Rules::Definitions::NaturalArmorBonusType getNaturalArmorBonus() const { return iNaturalArmor; }
			inline D20Rules::Definitions::DefelectionModifierType getDefelectionModifier() const { return iDeflection; }
			inline D20Rules::Definitions::DodgeBonusType getMisc() const { return iMisc; }

			inline short int getArmorClass() { updateTotal(); return *iTotal; }
			
			friend class D20Character;
		};
	}
}

#endif
