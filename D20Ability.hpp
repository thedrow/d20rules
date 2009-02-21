#ifndef __D20Ability
#define __D20Ability

#include <string>
#include "Rollable.hpp"
#include "GlobalDef.hpp"

namespace D20Rules
{
	class D20Character;

	namespace Rollables
	{
		class D20Ability : public Rollable
		{
		private:
			Loki::StrongPtr<D20Rules::Definitions::ScoreType> iScore;
			Loki::StrongPtr<D20Rules::Definitions::ModifierType, false> iModifier;
			D20Rules::Definitions::ScoreType iTemp;
			
			inline Definitions::ModifierType calculateModifier(const Definitions::ScoreType iScore) const { return (iScore - 10 - (iScore % 2)) / 2; }
						
			/*! \author Omer Katz
					\date 09/04/05
					\brief This function is used to update iTotal's value.
						
					iTotal here represents the active modifier.
					For more intfo about the active modifier see getActiveModifier()'s documention.
			*/
			void updateTotal() { *iTotal = calculateModifier(*iScore); }
		public:
				D20Ability();
				D20Ability(const Definitions::ScoreType iNewScore);
				virtual ~D20Ability() {}
						
			/*! \author Omer Katz
					\date 2004
					\brief The function returns the score of the ability.
			*/
			inline Definitions::ScoreType getScore() const { return *iScore - iTemp; }
					
			/*! \author Omer Katz
					\date 2004
					\brief The function returns the modifier of the ability.
			*/
			inline Definitions::ModifierType getModifier() { updateTotal(); return *iTotal; }
					
			/*! \author Omer Katz
					\date 2004
					\brief The function returns the temporary score of the ability.
			*/
			inline Definitions::ScoreType getTempScore() const { return *iScore; }
					
			/*! \author Omer Katz
					\date 2004
					\brief The procedure sets the score of the ability.
					
					It also sets the modifier of the score automaticly.
					\param iNewScore - a constant integer
			*/
			inline void setScore(const Definitions::ScoreType iNewScore) { *iScore = iNewScore; updateTotal(); }
					
			/*! \author Omer Katz
					\date 2004
					\brief The procedure sets the temporary score of the ability.
						
					It also sets the temporary modifier of the score automaticly.
					\param iNewTempScore - a constant integer
			*/
			void setTempScore(const Definitions::ScoreType iNewTempScore);

			void rollAbility();
			
			inline Definitions::ScoreType operator=(const Definitions::ScoreType iNewScore) { setScore(iNewScore); return *iScore; }
			inline Definitions::ScoreType operator+=(const Definitions::ScoreType iNewScore) { setScore(*iScore + iNewScore); return *iScore; }
			inline Definitions::ScoreType operator-=(const Definitions::ScoreType iNewScore) { setScore(*iScore - iNewScore); return *iScore; }
            
			friend class D20Character;
		};
	}
}

#endif
