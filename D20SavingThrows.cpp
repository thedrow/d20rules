#include "GlobalDef.hpp"
#include "D20SavingThrows.hpp"

using namespace D20Rules::Definitions;

namespace D20Rules
{
	namespace Containers
	{
		D20SavingThrows::D20SavingThrows(const BaseType iBaseFort, const BaseType iBaseRef, const BaseType iBaseWill, const Definitions::MiscType iMiscFort, const Definitions::MiscType iMiscRef, const Definitions::MiscType iMiscWill)
		: Fortitude(iBaseFort, iMiscFort),
		  Reflex(iBaseRef, iMiscRef),
		  Will(iBaseWill, iMiscWill)
		{
		}
		
		D20SavingThrows::D20SavingThrows()
		{
		}
	}
}
