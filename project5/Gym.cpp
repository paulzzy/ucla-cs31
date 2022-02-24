#include "Gym.h"

Gym::Gym(std::string name, std::string location, Kind kind)
    : mName(name), mLocation(location), mKind(kind) {}

void Gym::setFeatures(bool cardio, bool weights, bool pool, bool track) {
    hasCardio = cardio;
    hasWeights = weights;
    hasPool = pool;
    hasTrack = track;
}

bool Gym::canWorkoutHere(GymMember m) {
    switch (m.getKind()) {
        case EXECUTIVE:
            return mKind == EXECUTIVE || mKind == PREMIER || mKind == REGULAR;
            break;
        case PREMIER:
            return mKind == PREMIER || mKind == REGULAR;
            break;
        case REGULAR:
            return mKind == REGULAR;
            break;
        case OTHER:
            return mKind == OTHER;
            break;
        default:
            return false;
    }
}

bool Gym::checkin(GymMember& m, bool wantsCardio, bool wantsWeights,
                  bool wantsPool, bool wantsTrack) {
    if (!canWorkoutHere(m)) {
        return false;
    }

    if (!(wantsCardio && hasCardio == false) &&
        !(wantsWeights && hasWeights == false) &&
        !(wantsPool && hasPool == false) &&
        !(wantsTrack && hasTrack == false)) {
        m.newWorkout();
        return true;
    } else {
        return false;
    }
}

bool Gym::hasCardioFeatures() { return hasCardio; }

bool Gym::hasWeightsFeatures() { return hasWeights; }

bool Gym::hasPoolFeatures() { return hasPool; }

bool Gym::hasTrackFeatures() { return hasTrack; }

Kind Gym::getKind() { return mKind; }

std::string Gym::getKindAsString() {
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

std::string Gym::getLocation() { return mLocation; }

std::string Gym::getName() { return mName; }
