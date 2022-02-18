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

   public:
    GymMember(std::string name, std::string accountnumber, Kind kind) {
        mName = name;
        mAccountNumber = accountnumber;
        mKind = kind;
    }

    int workoutsThisMonth() { return mWorkoutCount; }

    void startNewMonth() { mWorkoutCount = 0; }

    void newWorkout() { mWorkoutCount++; }

    Kind getKind() { return mKind; }

    std::string getKindAsString() {
        switch (mKind) {
            case OTHER:
                return "OTHER";
                break;
            case REGULAR:
                return "REGULAR";
                break;
            case PREMIER:
                return "PREMIER";
                break;
            case EXECUTIVE:
                return "EXECUTIVE";
                break;
            default:
                return "SOMETHING_HAS_GONE_TERRIBLY_WRONG";
                break;
        }
    }

    std::string getName() { return mName; }

    std::string getAccountNumber() { return mAccountNumber; }
};

#endif
