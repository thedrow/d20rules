#include "D20HitPoints.hpp"

namespace D20Rules
{
	namespace Rollables
	{
		D20HitPoints::D20HitPoints()
		: iConModifier(NULL),
		  iMaxHP(0),
		  iTempHP(0),
		  iCurrentHP(0),
		  iNonlethalDamage(0)
		{
		}
		
		Definitions::HPType D20HitPoints::addHitDie(const Definitions::Dice dHitDie)
		{
			Definitions::HPType iNewHitDie = Roll(dHitDie, 1);

			updateTotal();
			iMaxHP += iNewHitDie;

			if ( iHD == 0 )
				iCurrentHP = iMaxHP;

			iHD++;

			return iNewHitDie;
		}
	}
}
