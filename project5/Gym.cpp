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
            return true;
            break;
        case PREMIER:
            return mKind == PREMIER || mKind == REGULAR || mKind == OTHER;
            break;
        case REGULAR:
            return mKind == REGULAR || mKind == OTHER;
            break;
        case OTHER:
            return mKind == OTHER;
            break;
    }
}

bool Gym::checkin(GymMember& m, bool wantsCardio, bool wantsWeights,
                  bool wantsTrack) {
    if (!canWorkoutHere(m)) {
        return false;
    }

    if (!(wantsCardio && hasCardio == false) &&
        !(wantsWeights && hasWeights == false) &&
        !(wantsTrack && hasTrack == false)) {
        m.newWorkout();
        return true;
    } else {
        return false;
    }
}
