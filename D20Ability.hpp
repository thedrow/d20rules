#ifndef __D20Ability
#define __D20Ability

#include <string>
#include "Rollable.hpp"
#include "GlobalDef.hpp"

namespace D20Rules
{
    namespace PrivateData
    {
	   struct AbilityData
	   {
	   	   Loki::StrongPtr<D20Rules::Definitions::ScoreType> iScore;
			Loki::StrongPtr<D20Rules::Definitions::ModifierType, false> iModifier;
			D20Rules::Definitions::ScoreType iTemp;


			AbilityData()
			:	iScore(new D20Rules::Definitions::ScoreType(10)),
				iModifier(0),
				iTemp(0)
			{
			}

			AbilityData(const D20Rules::Definitions::ScoreType iNewScore)
			:	iScore(new D20Rules::Definitions::ScoreType(iNewScore)),
				iModifier(0),
				iTemp(0)
			{
			}

			AbilityData(AbilityData &ad)
			:	iScore(ad.iScore),
				iTemp(ad.iTemp)
  		  	{
		       }
	   };
    }
	namespace Rollables
	{
		class D20Ability : public Rollable
		{
		private:
			Loki::StrongPtr<PrivateData::AbilityData> Data;
			
			inline Definitions::ModifierType calculateModifier(const Definitions::ScoreType iScore) const { return (iScore - 10 - (iScore % 2)) / 2; }
						
			/*! \author Omer Katz
					\date 09/04/05
					\brief This function is used to update iTotal's value.
						
					iTotal here represents the active modifier.
					For more intfo about the active modifier see getActiveModifier()'s documention.
			*/
			void updateTotal() { *iTotal = calculateModifier(*(Data->iScore)); }
		public:
				D20Ability();
				D20Ability(const Definitions::ScoreType iNewScore);
				virtual ~D20Ability() {}
						
			/*! \author Omer Katz
					\date 2004
					\brief The function returns the score of the ability.
			*/
			inline Definitions::ScoreType getScore() const { return (*(Data->iScore) - Data->iTemp); }
					
			/*! \author Omer Katz
					\date 2004
					\brief The function returns the modifier of the ability.
			*/
			inline Definitions::ModifierType getModifier() { updateTotal(); return *iTotal; }
					
			/*! \author Omer Katz
					\date 2004
					\brief The function returns the temporary score of the ability.
			*/
			inline Definitions::ScoreType getTempScore() const { return *(Data->iScore); }
					
			/*! \author Omer Katz
					\date 2004
					\brief The procedure sets the score of the ability.
					
					It also sets the modifier of the score automaticly.
					\param iNewScore - a constant integer
			*/
			inline void setScore(const Definitions::ScoreType iNewScore) { *(Data->iScore) = iNewScore; updateTotal(); }
					
			/*! \author Omer Katz
					\date 2004
					\brief The procedure sets the temporary score of the ability.
						
					It also sets the temporary modifier of the score automaticly.
					\param iNewTempScore - a constant integer
			*/
			void setTempScore(const Definitions::ScoreType iNewTempScore);

			void rollAbility();
			
			inline Definitions::ScoreType operator=(const Definitions::ScoreType iNewScore) { setScore(iNewScore); return *(Data->iScore); }
			inline Definitions::ScoreType operator+=(const Definitions::ScoreType iNewScore) { setScore(*(Data->iScore) + iNewScore); return *(Data->iScore); }
			inline Definitions::ScoreType operator-=(const Definitions::ScoreType iNewScore) { setScore(*(Data->iScore) - iNewScore); return *(Data->iScore); }
            
			template <class DataType, class SourceType>
			friend Loki::StrongPtr<DataType, false> D20Rules::Definitions::getData(SourceType &obj);
		};
	}
}

#endif
