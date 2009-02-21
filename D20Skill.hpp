#ifndef _D20Skill
#define _D20Skill

#include <queue>
#include <string>
#include <cmath>
#include "Rollable.hpp"
#include "GlobalDef.hpp"

namespace D20Rules
{
	namespace Rollables
	{
		class D20Skill : public Rollable
		{
		private:	
			Loki::StrongPtr<unsigned short int, false> iMaxRank;

			const bool bUsedUntrained;
			const bool bClassSkill;
			const bool bRetry;
			const bool bArmorCheckPenality;

			const std::string sName;
			const D20Rules::Definitions::RelatedModifier rmModifierName;
			Loki::StrongPtr<D20Rules::Definitions::ModifierType, false> iModifier;
			D20Rules::Definitions::RankType fRank;
			D20Rules::Definitions::MiscType iMisc;
			
			void updateTotal()
			{
				*iTotal = (int) (std::ceil(fRank)) + iMisc + *(iModifier);
				updateSynergies();
			}
			
			void updateSynergies();
		public:
			D20Skill();
			D20Skill(Definitions::RankType iNewRank, Definitions::MiscType iNewMisc, const bool bNewUsedUntrained, const bool bNewRetry, const bool bNewArmorCheckPenality, const std::string sNewName, const Definitions::RelatedModifier rmNewModifierName);
			D20Skill::D20Skill(const bool bNewUsedUntrained, const bool bNewRetry, const bool bNewArmorCheckPenality, const std::string sNewName, const Definitions::RelatedModifier rmNewModifierName);
			
			bool isClassSkill() { return bClassSkill; }
			inline bool isUsedUntrained() const { return bUsedUntrained; }
			
			inline Definitions::RankType getRank() const { return fRank; }
			inline Definitions::MiscType getMisc() const { return iMisc; }
			inline Definitions::ModifierType getModifier() const { return *(iModifier); }
			inline std::string getName() const { return sName; }
			inline Definitions::RelatedModifier getRelatedModifier() const { return rmModifierName; }
			inline short int getTotal() { updateTotal(); return *iTotal; }
			
			inline void setRank(Definitions::RankType fNewRank) { fRank = fNewRank <= *(iMaxRank) ? fNewRank : fRank; }
			inline void setMisc(Definitions::MiscType iNewMisc) { iMisc = iNewMisc; }
			
			template <class DataType, class SourceType>
			friend Loki::StrongPtr<DataType, false> D20Rules::Definitions::getData(SourceType &obj);
		};
	}
}

#endif
