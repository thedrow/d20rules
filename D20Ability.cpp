#include "GlobalDef.hpp"
#include "D20Ability.hpp"
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace D20Rules::Definitions;
using namespace Loki;
using namespace std;

namespace D20Rules
{
	namespace Rollables
	{
		D20Ability::D20Ability()
		: iScore(new D20Rules::Definitions::ScoreType(10)),
		  iTemp(0)
		{
			iModifier = iTotal;
		}
		
		D20Ability::D20Ability(const ScoreType iNewScore)
		: Rollable(calculateModifier(iNewScore)),
		  iScore(new D20Rules::Definitions::ScoreType(iNewScore)),
		  iTemp(0)
		{
            iModifier = iTotal;
		}
		
		void D20Ability::setTempScore(const ScoreType iNewTempScore)
		{
			if ( iNewTempScore )
			{
				*iScore = iNewTempScore;
				iTemp = iNewTempScore - *iScore;
			}
			else
			{
				*iScore -= iTemp;
				iTemp = 0;
			}
			
			updateTotal();
		}
		
		void D20Ability::rollAbility()
		{
         	*iTotal = 0;

         	vector<ScoreType> v;
         	v.push_back(Roll(d6, 1));
         	v.push_back(Roll(d6, 1));
         	v.push_back(Roll(d6, 1));
        	v.push_back(Roll(d6, 1));

	        sort(v.begin(), v.end());

	        vector<ScoreType>::iterator iter = v.begin();
         	iter++;
			setScore(accumulate(iter, v.end(), 0, plus<ScoreType>()));
        }
	}
}
