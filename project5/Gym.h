#ifndef GYM_H
#define GYM_H

#include <string>
#include "GymMember.h"

class Gym {
   private:
    std::string mName;
    std::string mLocation;
    Kind mKind;
    bool hasCardio = false;
    bool hasWeights = false;
    bool hasPool = false;
    bool hasTrack = false;

   public:
    Gym(std::string name, std::string location, Kind kind);

    void setFeatures(bool cardio, bool weights, bool pool, bool track);

    bool canWorkoutHere(GymMember m);

    bool checkin(GymMember& m, bool wantsCardio, bool wantsWeights,
                 bool wantsTrack);
};

#endif
