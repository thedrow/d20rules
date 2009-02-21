#include "GlobalDef.hpp"
#include "D20SavingThrow.hpp"

using namespace D20Rules::Definitions;
using namespace Loki;

namespace D20Rules
{
	namespace Rollables
	{
		D20SavingThrow::D20SavingThrow(BaseType iNewBase, MiscType iNewMisc)
		: Rollable(iNewBase + iNewMisc)
		{
		}
		
		D20SavingThrow::D20SavingThrow()
		: iBase(0),
		  iMisc(0),
		  iTemp(0)
		{
		}
		
		void D20SavingThrow::addBase(LevelType iLevel, SavingThrowRating strRating)
		{
			BaseType iCurrentBase = iBase;
			switch ( strRating )
			{
			case strGood:
				iBase += (2 + iLevel / 2) - iCurrentBase;
				break;
			case strPoor:
				iBase += (iLevel / 3) - iCurrentBase;
				break;
			};
		}
		
		void D20SavingThrow::removeBase(LevelType iLevel, SavingThrowRating strRating)
		{
			BaseType iCurrentBase = iBase;
			switch ( strRating )
			{
			case strGood:
				iBase -= (2 + iLevel / 2) - iCurrentBase;
				break;
			case strPoor:
				iBase -= (iLevel / 3) - iCurrentBase;
				break;
			};
		}
	}
}
