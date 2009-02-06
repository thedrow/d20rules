#ifndef __Rollable
#define __Rollable

#include <list>
#include "GlobalDef.hpp"

namespace D20Rules
{
	namespace Rollables
	{
		class Rollable
		{
		protected:
			Loki::StrongPtr<short int> iTotal;
			
			virtual void updateTotal() {};
		public:
			Rollable();
			Rollable(const Rollable &rCopy);
			Rollable(const int iNewTotal);
			virtual ~Rollable() {}
			
			class Result
			{
			public:
				unsigned int RollResult;
				bool Success;
			};
			
			class MultipleResults
			{
			public:
				unsigned int RollResult;
				unsigned int Successes;
				bool Success;
			};
			
			Rollable::Result Roll(const unsigned int iDC) const; // See documention below.
			Rollable::Result Roll(const unsigned int iDC, const std::list<int> &lExtraModifiers) const; // See documention below.
				
			Rollable::MultipleResults Roll(const std::list<int> &lDCList) const; // See documention below.
			Rollable::MultipleResults Roll(const std::list<int> &lDCList, const std::list<int> &lExtraModifiers) const; // See documention below.
				
			int Roll(const Definitions::Dice dRollType, const unsigned int iRolls) const; // See documention below.
			int Roll(const Definitions::Dice dRollType, const std::list<int> &lExtraModifiers, const unsigned int iRolls) const; // See documention below.
		};
	}
}

#endif
