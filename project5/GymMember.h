#ifndef GYM_MEMBER_H
#define GYM_MEMBER_H

#include <string>
#include "Kind.h"

class GymMember {
   private:
    std::string mName;
    std::string mAccountNumber;
    Kind mKind;
    int mWorkoutCount = 0;
};

#endif
