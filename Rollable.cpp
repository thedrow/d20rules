#include <numeric>
#include <algorithm>
#include <functional>

#include "Rollable.hpp"
#include "GlobalDef.hpp"

using namespace std;
using namespace D20Rules::Definitions;

namespace D20Rules
{
	namespace Rollables
	{
	    Rollable::Rollable(const int iNewTotal)
	    : iTotal(new short int(iNewTotal))
	    {
	    	srand(time(NULL));
	    }
	    
	    Rollable::Rollable()
	    : iTotal(new short int(0))
	    {
	    	srand(time(NULL));
	    }
	    
	    Rollable::Rollable(const Rollable &rCopy)
	    : iTotal(rCopy.iTotal)
	    {
	    	srand(time(NULL));
	    }

		Rollable::Result Rollable::Roll(const unsigned int iDC) const
		{
			Rollable::Result r;
	
			r.RollResult = 1 + rand() % 20 + *iTotal;
	
			if ( r.RollResult == 20 )
				r.RollResult = r.RollResult + 10;
			else if ( r.RollResult == 1 )
				r.RollResult = r.RollResult - 10;
			
			if ( r.RollResult < 1 )
				r.RollResult = 1;
	
			r.Success = r.RollResult >= iDC;
	
			return r;
		}
		
		Rollable::Result Rollable::Roll(const unsigned int iDC, const std::list<int> &lExtraModifiers) const
		{
			Rollable::Result r;
		
			r.RollResult = 1 + rand() % 20 + *iTotal + accumulate(lExtraModifiers.begin(), lExtraModifiers.end(), 0);
		
			if ( r.RollResult == 20 )
				r.RollResult = r.RollResult + 10;
			else if ( r.RollResult == 1 )
				r.RollResult = r.RollResult - 10;
				
			if ( r.RollResult < 1 )
					r.RollResult = 1;
		
			r.Success = r.RollResult >= iDC;
		
			return r;
		}
				
		Rollable::MultipleResults Rollable::Roll(const std::list<int> &lDCList) const
		{
			Rollable::MultipleResults mr;
			
			mr.RollResult = 1 + rand() % 20 + *iTotal;
		
			if ( mr.RollResult == 20 )
				mr.RollResult = mr.RollResult + 10;
			else if ( mr.RollResult == 1 )
				mr.RollResult = mr.RollResult - 10;
				
			if ( mr.RollResult < 1 )
					mr.RollResult = 1;
			
			mr.Successes = count_if(lDCList.begin(), lDCList.end(), bind2nd(less_equal<int>(), mr.RollResult));
			
			mr.Success = mr.Successes > 0;
			
			return mr;
		}
			
		Rollable::MultipleResults Rollable::Roll(const std::list<int> &lDCList, const std::list<int> &lExtraModifiers) const
		{
			Rollable::MultipleResults mr;
			
			mr.RollResult = 1 + rand() % 20 + *iTotal + accumulate(lExtraModifiers.begin(), lExtraModifiers.end(), 0);;
		
			if ( mr.RollResult == 20 )
				mr.RollResult = mr.RollResult + 10;
			else if ( mr.RollResult == 1 )
				mr.RollResult = mr.RollResult - 10;
				
			if ( mr.RollResult < 1 )
					mr.RollResult = 1;
			
			mr.Successes = count_if(lDCList.begin(), lDCList.end(), bind2nd(less_equal<int>(), mr.RollResult));
			
			mr.Success = mr.Successes > 0;
			
			return mr;
		}
						
		int Rollable::Roll(const Dice dRollType, const unsigned int iRolls) const
		{	
			int r = 0;
		
			for ( unsigned short int i = 0; i < iRolls; i++ )
				r = 1 + rand() % dRollType + *iTotal;
		
			return r < 1 ? 1 : r;
		}
			
		int Rollable::Roll(const Dice dRollType, const std::list<int> &lExtraModifiers, const unsigned int iRolls = 1) const
		{
			int r = 0;
		
			for ( unsigned short int i = 0; i < iRolls; i++ )
				r = 1 + rand() % dRollType + *iTotal + accumulate(lExtraModifiers.begin(), lExtraModifiers.end(), 0);
		
			return r < 1 ? 1 : r;
		}
	}
}
