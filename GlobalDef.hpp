#ifndef __GlobalDef
#define __GlobalDef

#define DND
#ifdef DND
	#define Version "3.5"
#endif

#include <loki/SmartPtr.h>
#include <loki/StrongPtr.h>

namespace D20Rules
{
	namespace Definitions
	{
		typedef unsigned int ScoreType;
		typedef short int ModifierType;
		typedef unsigned short int BaseType;
		typedef float RankType;
		typedef short int MiscType;
		typedef short int ArmorBonusType;
		typedef short int DodgeBonusType;
		typedef short int ShieldBonusType;
		typedef short int NaturalArmorBonusType;
		typedef short int SizeModifierType;
		typedef short int DefelectionModifierType;
		
		
		typedef unsigned short int LevelType;
		typedef unsigned short int ChallengeRatingType;
		typedef unsigned long int XPType;
		
		typedef short int RangePenaltyType;
		
		typedef short int HPType;
		
		typedef unsigned short int BaseAttackType;
		
		/*typedef unsigned int ClassAttributeType;
		typedef unsigned int FeatAttributeType;
		typedef unsigned int FeatPrerequisitesAttributeType;
		typedef unsigned int ItemAttributeType;*/
		
		typedef unsigned short int WeightType;
		typedef unsigned short int HeightType;
		
		typedef unsigned short int SpeedType;
		
		
		enum RelatedModifier
		{
			modStrength = 0,
			modDexterity,
			modConstitution,
			modWisdom,
			modIntelligence,
			modCharisma
		};
		
		enum BaseAttackRating
		{
			barPoor,
			barAverage,
			barGood
		};
		
		enum SavingThrowRating
		{
			strPoor,
			strGood
		};
		
		enum RelatedSavingThrow
		{
			stFortitude,
			stReflex,
			stWill
		};
		
		enum Size
		{
			Fine,
			Diminutive,
			Tiny,
			Small,
			Medium,
			Large,
			Huge,
			Gargantuan,
			Colossal
		};
		
		enum Dice
		{
			d2 = 2,
			d3 = 3,
			d4 = 4,
			d6 = 6,
			d8 = 8,
			d10 = 10,
			d12 = 12,
			d20 = 20,
			d100 = 100
		};
		
		enum CharacterAlignment
		{
			LawfulGood,
			NaturalGood,
			ChaoticGood,
			LawfulNatural,
			TrueNatural,
			ChaoticNatural,
			LawfulEvil,
			NaturalEvil,
			ChaoticEvil
		};
		
		enum LoadCarrying
		{
            LightLoad,
            MediumLoad,
            HeavyLoad
        };
        
		template <class DataType, class SourceType>
		Loki::StrongPtr<DataType, false> getData(SourceType &obj)
		{
			return obj.Data;
		}
	}
}

#endif
