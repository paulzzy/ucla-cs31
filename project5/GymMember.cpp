#include "GymMember.h"

GymMember::GymMember(std::string name, std::string accountnumber, Kind kind)
    : mName(name), mAccountNumber(accountnumber), mKind(kind) {}

int GymMember::workoutsThisMonth() { return mWorkoutCount; }

void GymMember::startNewMonth() { mWorkoutCount = 0; }

void GymMember::newWorkout() { mWorkoutCount++; }

Kind GymMember::getKind() { return mKind; }

std::string GymMember::getKindAsString() {
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

std::string GymMember::getName() { return mName; }

std::string GymMember::getAccountNumber() { return mAccountNumber; }
