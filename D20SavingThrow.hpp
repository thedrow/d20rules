#ifndef __D20SavingThrow
#define __D20SavingThrow

#include "GlobalDef.hpp"
#include "Rollable.hpp"

namespace D20Rules
{
	class D20Character;
	
	namespace Rollables
	{
		class D20SavingThrow : public Rollable
		{
		private:
			D20Rules::Definitions::BaseType iBase;
			Loki::StrongPtr<D20Rules::Definitions::ModifierType, false> iModifier;
			D20Rules::Definitions::MiscType iMisc;
			D20Rules::Definitions::MiscType iTemp;
			
			void updateTotal() { *iTotal = iBase + *iModifier + iMisc + iTemp; }
		public:
			D20SavingThrow(Definitions::BaseType iNewBase, Definitions::MiscType iNewMisc);
			D20SavingThrow();
			
			inline Definitions::BaseType getBase() { return iBase; }
			inline Definitions::ModifierType getModifier() { return *iModifier; }
			inline Definitions::MiscType getMisc() { return iMisc; }
			inline Definitions::MiscType getTemp() { return iTemp; }
			inline int getTotal() { updateTotal(); return *iTotal; }
			
			void addBase(Definitions::LevelType iLevel, Definitions::SavingThrowRating strRating);
			void removeBase(Definitions::LevelType iLevel, Definitions::SavingThrowRating strRating);
			
			inline void setMisc(Definitions::MiscType iNewMisc) { iMisc = iNewMisc; }
			inline void setTemp(Definitions::MiscType iNewTemp) { iTemp = iNewTemp; }
			
			friend class D20Character;
		};
	}
}

#endif
