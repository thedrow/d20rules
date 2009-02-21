#ifndef __D20DifficultyClass
#define __D20DifficultyClass

#include <loki/SmartPtr.h>

namespace D20Rules
{
	namespace RolledAgainst
	{
		class D20DifficultyClass
		{
		protected:
			Loki::SmartPtr<short int> iTotal;

			virtual void updateTotal() = 0;
		public:
			D20DifficultyClass(const short int iNewTotal)
			: iTotal(new short int(iNewTotal))
			{
				
			}
			
			virtual ~D20DifficultyClass() {}
		};
	}
}

#endif
