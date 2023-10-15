#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; (i)<static_cast<int>(n); ++(i))
#define repr(i,l,r) for(int i=static_cast<int>(l); (i)<static_cast<int>(r); ++(i))
#define revrep(i,n) for(int i=static_cast<int>(n)-1; (i)>=0; --(i))

/* num of input state: 2^16
 * num of output state: 2^(7*4)
 *
 *
*/

constexpr int display_count = 4;
constexpr int segment_count = 7;
constexpr int switch_count = 16;

struct LinkedTarget {
    int display_idx;
    int segment_idx;

    LinkedTarget(int display_idx, int segment_idx) : display_idx(display_idx), segment_idx(segment_idx) {}
    bool operator==(const LinkedTarget& rhs) const {
        return display_idx == rhs.display_idx && segment_idx == rhs.segment_idx;
    }
};

struct Switch {
    vector<LinkedTarget> linked_targets;

    explicit Switch(const vector<LinkedTarget>& linked_targets) : linked_targets(linked_targets) {}
};

using Switches = array<Switch, switch_count>;
using DisplayState = array<array<bool, segment_count>, display_count>;

struct ProblemSetting {
    int use_switch_count;
    Switches switches;
    DisplayState initial_display_state;
    ProblemSetting(int use_switch_count, const Switches& switches, const DisplayState& initial_display_state)
            : use_switch_count(use_switch_count), switches(switches), initial_display_state(initial_display_state) {}
};

bool validate_switches(const Switches& switches) {
    for(const auto& sw : switches) {
        for(const auto& target : sw.linked_targets) {
            if (target.display_idx < 0 || target.display_idx >= display_count) return false;
            if (target.segment_idx < 0 || target.segment_idx >= segment_count) return false;
        }
    }
    rep(i, switch_count) {
        rep(j, switch_count) {
            if (i == j) continue;
            if (switches[i].linked_targets.size() != switches[j].linked_targets.size()) continue;
            auto a = switches[i].linked_targets;
            auto b = switches[j].linked_targets;
            sort(a.begin(), a.end(), [](const LinkedTarget& lhs, const LinkedTarget& rhs) { return lhs.display_idx < rhs.display_idx || (lhs.display_idx == rhs.display_idx && lhs.segment_idx < rhs.segment_idx); });
            sort(b.begin(), b.end(), [](const LinkedTarget& lhs, const LinkedTarget& rhs) { return lhs.display_idx < rhs.display_idx || (lhs.display_idx == rhs.display_idx && lhs.segment_idx < rhs.segment_idx); });
            if (a == b)  {
                cerr << "switch " << i << " and " << j << " are same" << endl;
                return false;
            }
        }
    }
    return true;
}

int calc_solution_count(const ProblemSetting& problem_setting) {
    const int use_switch_count = problem_setting.use_switch_count;
    const Switches& switches = problem_setting.switches;
    const DisplayState& initial_display_state = problem_setting.initial_display_state;

    const int state_count = 1 << use_switch_count;
    DisplayState display_state{};

    int solution_count = 0;
    rep(state_id, state_count) {
        display_state = initial_display_state;

        rep(i, switch_count) {
            if (state_id & (1 << i)) {
                for(const auto& target : switches[i].linked_targets) {
                    display_state[target.display_idx][target.segment_idx] = !display_state[target.display_idx][target.segment_idx];
                }
            }
        }
        bool ok = true;
        rep(i, display_count) {
            rep(j, segment_count) {
                if (!display_state[i][j]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
        }

//        if (ok) {
//            rep(i, switch_count) {
//                if (state_id & (1 << i)) {
//                    cout << i << ", ";
//                }
//            }
//            cout << endl;
//        }

        solution_count += ok;
    }
    return solution_count;
}

void dump_problem_info(const ProblemSetting& problem_setting) {
    if (!validate_switches(problem_setting.switches)) {
        cerr << "invalid switches" << endl;
        return;
    }

    cout << "solution counts: " << calc_solution_count(problem_setting) << endl;

    rep(i, display_count) {
        rep(j, segment_count) {
            // cout << "display_state[1][0] <= sw_state[2];"
            cout << "display_state[" << i << "][" << j << "] <= ~(" << (problem_setting.initial_display_state[i][j] ? 1 : 0);
            rep(k, problem_setting.switches.size()) {
                const auto& sw = problem_setting.switches[k];
                rep(l, sw.linked_targets.size()) {
                    const auto& target = sw.linked_targets[l];
                    if (target.display_idx == i && target.segment_idx == j) {
                        cout << " ^ " << "sw_state[" << k << "]";
                    }
                }
            }
            cout << ");" << endl;
        }
    }
}

int main() {
    ProblemSetting problem0(
        16,
        {
            Switch({ {0,0} }),
            Switch({ {0,1} }),
            Switch({ {0,2} }),
            Switch({ {0,3} }),
            Switch({ {0,4} }),
            Switch({ {0,5} }),
            Switch({ {0,6} }),
            Switch({ {0,0} }),
            Switch({ {0,1} }),
            Switch({ {0,2} }),
            Switch({ {0,3} }),
            Switch({ {0,4} }),
            Switch({ {0,5} }),
            Switch({ {0,6} }),
            Switch({ {0,0} }),
            Switch({ {0,1} }),
        },
        {
            array<bool, segment_count>{false, false, false, false, false, false, false},
            array<bool, segment_count>{true, true, true, true, true, true, true},
            array<bool, segment_count>{true, true, true, true, true, true, true},
            array<bool, segment_count>{true, true, true, true, true, true, true},
        }
    );
    ProblemSetting problem1(
        16,
        {
            Switch({ {0,0}, {1,0} }),
            Switch({ {0,6}, {1,6} }),
            Switch({ {0,3}, {1,3} }),
            Switch({ {0,1}, {1,1} }),
            Switch({ {0,2}, {1,2} }),
            Switch({ {0,5}, {1,5} }),
            Switch({ {0,4}, {1,4} }),
            Switch({ {0,1}, {1,5} }),
            Switch({ {0,5}, {1,1} }),
            Switch({ {0,2}, {1,4} }),
            Switch({ {0,4}, {1,2} }),
            Switch({ {0,0}, {1,3} }),
            Switch({ {0,3}, {1,0} }),
            Switch({ {0,0}, {1,6} }),
            Switch({ {0,6}, {1,3} }),
            Switch({ {0,3}, {1,6} }),
        },
        {
            array<bool, segment_count>{false, false, false, false, false, false, false},
            array<bool, segment_count>{false, false, false, false, false, false, false},
            array<bool, segment_count>{true, true, true, true, true, true, true},
            array<bool, segment_count>{true, true, true, true, true, true, true},
        }
    );

    ProblemSetting problem2(
        16,
        {
            Switch({ {0,1}, {0,2}, {0,6}, {1,0}, {1,3} }),
            Switch({ {0,2}, {1,2} }),
            Switch({ {1,1}, {1,2}, {1,4}, {1,5}, {1,6}, {2, 0}, {2,6}, {2,3} }),
            Switch({ {0,1}, {1,4}, {2, 0}, {0,4}, {1,2}, {2, 2} }),
            Switch({ {0,3}, {2, 1} }),
            Switch({ {0,4}, {1,2}, {2, 2} }),
            Switch({ {0,4}, {1,1}, {2, 1}, {0,5}, {1,3}, {2, 1} }),
            Switch({ {1,5}, {2, 6} }),
            Switch({ {0,5}, {1,3}, {2, 1} }),
            Switch({ {0,2}, {1,2}, {2, 4}, {0,1}, {1,5}, {2, 2} }),
            Switch({ {2, 1} }),
            Switch({ {0,1}, {1,5}, {1,0}, {2, 0} }),
            Switch({ {1,0}, {2, 0} }),
            Switch({ {0,5} }),
            Switch({ {0,0}, {0,3}, {0,4}, {0,5}, {2,1}, {2,2}, {2,4}, {2,5} }),
            Switch({ {0,3}, {2, 3} }),
        },
        {
            array<bool, segment_count>{false, false, false, false, false, false, false},
            array<bool, segment_count>{false, false, false, false, false, false, false},
            array<bool, segment_count>{false, false, false, false, false, false, false},
            array<bool, segment_count>{true, true, true, true, true, true, true},
        }
    );

    ProblemSetting problem3(
        16,
        {
            Switch({ {0,1}, {0,6}, {1,6}, {2,1}, {2,2}, {3,6} }),
            Switch({ {0,3}, {0,6}, {1,2}, {2,0}, {2,4}, {3,0} }),
            Switch({ {0,0}, {1,4}, {2,0}, {2,2}, {3,1} }),
            Switch({ {0,4}, {1,0}, {1,1}, {2,3}, {3,1}, {3,5} }),
            Switch({ {0,1}, {0,5}, {1,2}, {1,1}, {1,5}, {2,0}, {3,0}, {3,4} }),
            Switch({ {1,2}, {0,5}, {1,4}, {2,2}, {2,6}, {3,0}, {3,6} }),
            Switch({ {0,0}, {0,2}, {0,5}, {1,3}, {2,0}, {3,0}, {3,2}, {3,3} }),
            Switch({ {0,0}, {0,1}, {0,5}, {1,4}, {2,4}, {3,0} }),
            Switch({ {0,2}, {0,5}, {1,3}, {1,4}, {1,6}, {2,2}, {3,0}, {3,5} }),
            Switch({ {0,2}, {0,5}, {1,2}, {1,5}, {2,6}, {3,3} }),
            Switch({ {1,2}, {0,5}, {1,4}, {2,1}, {2,5}, {3,3}, {3,6} }),
            Switch({ {0,1}, {0,3}, {0,2}, {1,3}, {2,1}, {3,2} }),
            Switch({ {0,1}, {0,3}, {0,4}, {1,2}, {2,2}, {3,2}, {3,3}, {3,4} }),
            Switch({ {0,1}, {1,4}, {2,1}, {2,4}, {3,0} }),
            Switch({ {0,0}, {0,5}, {1,1}, {1,6}, {2,5}, {3,0} }),
            Switch({ {0,4}, {1,0}, {1,3}, {2,5}, {3,0}, {3,2} }),
        },
        {
            array<bool, segment_count>{false, false, false, false, false, false, false},
            array<bool, segment_count>{false, false, false, false, false, false, false},
            array<bool, segment_count>{false, false, false, false, false, false, false},
            array<bool, segment_count>{false, false, false, false, false, false, false},
        }
    );


    ProblemSetting problem4(
        16,
        {
            Switch({ {0,1}, {1,6} }),
            Switch({ {0,2}, {1,0} }),
            Switch({ {0,0}, {1,3} }),
            Switch({ {0,5}, {1,1} }),
            Switch({ {0,4}, {1,4} }),
            Switch({ {0,3} }),
            Switch({ {0,6}, {1,1} }),
            Switch({ {0,1}, {1,4} }),
            Switch({ {0,2}, {1,1} }),
            Switch({ {0,4} }),
            Switch({ {0,6}, {1,2} }),
            Switch({ {0,1}, {1,5} }),
            Switch({ {0,2}, {1,4} }),
            Switch({ {0,3}, {1,3} }),
            Switch({ {0,5} }),
            Switch({ {0,1}, {1,0} }),
        },
        {
            array<bool, segment_count>{false, false, false, false, false, false, false},
            array<bool, segment_count>{false, false, false, false, false, false, false},
            array<bool, segment_count>{true, true, true, true, true, true, true},
            array<bool, segment_count>{true, true, true, true, true, true, true},
        }
    );
    dump_problem_info(problem3);

    return 0;
}
