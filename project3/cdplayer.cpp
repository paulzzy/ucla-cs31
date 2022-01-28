#include <iostream>
#include <string>

using namespace std;

// Track state of CD player
struct CdPlayerState {
    bool is_valid = false;
    bool is_open = false;
    bool is_cd_inserted = false;
    bool is_playing = false;
    int previous_track = 0;
    int current_track = 0;
    int total_tracks_played = 0;
};

CdPlayerState getCdPlayerState(string cd_player_actions) {
    CdPlayerState cd_player;
    cd_player.is_valid = false;

    // Possible CD player actions, excluding tracks
    const char open = 'O';
    const char insert = 'I';
    const char close = 'C';
    const char play = 'P';
    const char stop = 'S';
    const char remove = 'R';

    // Initial check for length and first char, which must be 'O'
    if (cd_player_actions.size() < 1 || cd_player_actions.at(0) != open) {
        return cd_player;
    } else {
        cd_player.is_open = true;
    }

    // Skip first char since it was already checked
    for (size_t i = 1; i < cd_player_actions.size(); i++) {
        const char current_action = cd_player_actions.at(i);

        switch (current_action) {
            case open:
                if (!cd_player.is_open) {
                    cd_player.is_open = true;
                } else {
                    return cd_player;
                }
                break;
            case insert:
                if (cd_player.is_open && !cd_player.is_cd_inserted) {
                    cd_player.is_cd_inserted = true;
                } else {
                    return cd_player;
                }
                break;
            case close:
                if (cd_player.is_open) {
                    cd_player.is_open = false;
                } else {
                    return cd_player;
                }
                break;
            case play:
                if (!cd_player.is_open && cd_player.is_cd_inserted) {
                    cd_player.is_playing = true;
                } else {
                    return cd_player;
                }
                break;
            case stop:
                if (cd_player.is_playing) {
                    cd_player.is_playing = false;
                } else {
                    return cd_player;
                }
                break;
            case remove:
                if (cd_player.is_open && cd_player.is_cd_inserted) {
                    cd_player.is_cd_inserted = false;
                    cd_player.previous_track = 0;
                    cd_player.current_track = 0;
                } else {
                    return cd_player;
                }
                break;
            default:
                // Check if a track is being played
                if (isdigit(current_action) && !cd_player.is_open &&
                    cd_player.is_cd_inserted && cd_player.is_playing) {
                    // Convert char to corresponding integer digit
                    cd_player.current_track = current_action - '0';
                    if (cd_player.current_track !=
                        cd_player.previous_track + 1) {
                        return cd_player;
                    }
                    cd_player.previous_track++;
                } else {
                    return cd_player;
                }
                break;
        }
    }

    cd_player.is_valid = true;
    return cd_player;
}

bool isValidCDPlayerString(string cd_player_actions) {
    return getCdPlayerState(cd_player_actions).is_valid;
}

bool isOpen(string cd_player_actions) {
    return getCdPlayerState(cd_player_actions).is_open;
}

bool hasCD(string cd_player_actions) {
    return false;
}

int totalTracksPlayed(string cd_player_actions) {
    return 0;
}

int currentTrack(string cd_player_actions) {
    return 0;
}

int main() {
    const string valid_tests[] = {"OICP123SP456SORICP123",
                                  "OIRICP123SOR",
                                  "OICP123ORICP123",
                                  "OICPO",
                                  "OICPOR",
                                  "OICP123O",
                                  "OICP123SOCP456S",
                                  "OICP123SOCP456S",
                                  "OICP123P456SOR",
                                  "OICPP123SOR",
                                  "OICP123SORICP123456SOR",
                                  "OICP123OC",
                                  "OICP123OCP",
                                  "OICP123OCP456"};
    const string invalid_tests[] = {"xyz",
                                    "oic",
                                    "OIC xyz",
                                    "P123S",
                                    "OCIP123S",
                                    "OICR",
                                    "OCOICC",
                                    "OCOICOO",
                                    "OIP123",
                                    "OCP123",
                                    "OICS",
                                    "OP123C",
                                    "OIR123",
                                    "OIR123P",
                                    "OC123P",
                                    "OICP123ORICP456",
                                    "OICP147S",
                                    "OICP123SOCP123S",
                                    "OICP123P123456SOR",
                                    "OICS123OC"};

    for (const string test : valid_tests) {
        assert(isValidCDPlayerString(test));
    }
    for (const string test : invalid_tests) {
        assert(!isValidCDPlayerString(test));
    }

    cerr << "All tests succeeded" << endl;
    return 0;
}
