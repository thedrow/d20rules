#include <cmath>
#include "GlobalDef.hpp"
#include "D20BaseAttack.hpp"

using namespace std;
using namespace D20Rules::Definitions;

namespace D20Rules
{
	namespace Rollables
	{
        D20BaseAttack::D20BaseAttack()
        : iMiscModifier(0),
          iSizeModifier(0),
          iRangePenaltyModifier(0)
        {
            lAttacks.push_back(0);
            iterAttacks = lAttacks.begin()++;
        }
        
        void D20BaseAttack::calculateBaseAttack(Definitions::LevelType iLevel, Definitions::BaseAttackRating barRating)
        {
            BaseAttackType iNewBaseAttack = *(lAttacks.begin()++);
            
            lAttacks.clear();
        	switch ( barRating )
        	{
        	case barGood:
        		lAttacks.push_back(iNewBaseAttack + iLevel);
        		break;
        	case barAverage:
        		for ( unsigned short int i = 2; i <= iLevel; i++ )
        			if ( i % 4 != 1 )
        				iNewBaseAttack++;
        
        		lAttacks.push_back(iNewBaseAttack);
        		break;
        	case barPoor:
        		lAttacks.push_back(iNewBaseAttack + iLevel / 2);
        	}
        
            iterAttacks = lAttacks.begin()++;
            if ( *iterAttacks > 6 )
            {
                lAttacks.push_back(*iterAttacks - 5);
        
                if ( *iterAttacks > 11 )
                {
                    lAttacks.push_back(*iterAttacks - 10);
            
                        if ( *iterAttacks > 16 )
                            lAttacks.push_back(*iterAttacks - 15);
                }
            }
        }
	}
}
