#include <iostream>
#include <string>

using namespace std;

bool isValidCDPlayerString(string cd_player_actions) {
    // Possible CD player actions
    const char open = 'O';
    const char insert = 'I';
    const char close = 'C';
    const char play = 'P';
    const char stop = 'S';
    const char remove = 'R';

    // Initial check
    if (cd_player_actions.size() < 1 || cd_player_actions[0] != open) {
        return false;
    }

    // Track state of CD player
    bool is_open = false;
    bool is_cd_inserted = false;
    bool is_playing = false;
    int previous_track = 0;
    int current_track = 0;

    for (size_t i = 0; i < cd_player_actions.size(); i++) {
        const char current_action = cd_player_actions[i];

        switch (current_action) {
            case open:
                if (!is_open) {
                    is_open = true;
                } else {
                    return false;
                }
                break;
            case insert:
                if (is_open && !is_cd_inserted) {
                    is_cd_inserted = true;
                } else {
                    return false;
                }
                break;
            case close:
                if (is_open) {
                    is_open = false;
                } else {
                    return false;
                }
                break;
            case play:
                if (!is_open && is_cd_inserted) {
                    is_playing = true;
                } else {
                    return false;
                }
                break;
            case stop:
                if (is_playing) {
                    is_playing = false;
                } else {
                    return false;
                }
                break;
            case remove:
                if (is_open && is_cd_inserted) {
                    is_cd_inserted = false;
                    previous_track = 0;
                    current_track = 0;
                } else {
                    return false;
                }
                break;
            default:
                // Check if a track is being played
                if (isdigit(current_action) && !is_open && is_cd_inserted &&
                    is_playing) {
                    // Convert char to corresponding digit
                    current_track = current_action - '0';
                    if (current_track != previous_track + 1) {
                        return false;
                    }
                    previous_track++;
                } else {
                    return false;
                }
                break;
        }
    }

    return true;
}

bool isOpen(string cd_player_actions) {
    return false;
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
