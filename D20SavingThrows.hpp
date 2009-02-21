#ifndef __D20SavingThrows
#define __D20SavingThrows

#include "GlobalDef.hpp"
#include "D20SavingThrow.hpp"

namespace D20Rules
{
	namespace Containers
	{
		class D20SavingThrows
		{
		public:
			Rollables::D20SavingThrow Fortitude;
		  	Rollables::D20SavingThrow Reflex;
		  	Rollables::D20SavingThrow Will;
		  		
		  	D20SavingThrows(const Definitions::BaseType iBaseFort, const Definitions::BaseType iBaseRef, const Definitions::BaseType iBaseWill, const Definitions::MiscType iMiscFort, const Definitions::MiscType iMiscRef, const Definitions::MiscType iMiscWill);
		  	D20SavingThrows();
		};
	}
}

#endif
