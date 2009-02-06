#ifndef __D20Character
#define __D20Character

#include "D20Abilities.hpp"

namespace D20Rules
{
    namespace PrivateData
    {
    }
    
    class D20Character
    {
    private:
        
    public:
        D20Character();
        
        Containers::D20Abilities Abilities;
    };
}

#endif
