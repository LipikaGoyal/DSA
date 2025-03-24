class Solution {
    public:
        static bool comp(const vector<int>& p1, const vector<int>& p2) {
            return p1[0] < p2[0];
        }
    
        int countDays(int days, vector<vector<int>>& meetings) {
            if (meetings.empty()) return days;
    
            sort(meetings.begin(), meetings.end(), comp);
    
            vector<vector<int>> newMeetings;
            vector<int> vec1 = meetings[0];
    
            for (int i = 1; i < meetings.size(); i++) {
                if (meetings[i][0] <= vec1[1]) { 
                    vec1[1] = max(vec1[1], meetings[i][1]); 
                } else {
                    newMeetings.push_back(vec1);
                    vec1 = meetings[i];
                }
            }
            newMeetings.push_back(vec1); 
            int meetd = 0;
            for (auto& vec : newMeetings) {
                meetd += (vec[1] - vec[0] + 1);
            }
    
            return days - meetd;
        }
    };
    