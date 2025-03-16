#include "ladder.h"



void error(string word1, string word2, string msg) {
    cerr << word1 << ", " << word2 << ": " << msg;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    int len1 = str1.length();
    int len2 = str2.length();
    int i = 0;
    int j = 0;
    int counter = 0;

    if (abs(len1 - len2) > d) return false;

    while (i < len1 && j < len2) {
        if (str1[i] != str2[j]) {
            counter++;
            if (counter > d) return false;

            if (len1 > len2) {
                i++;
            } else if (len1 < len2) {
                j++;
            } else {
                i++;
                j++;
            }
        } else {
            i++;
            j++;
        }
    }
    counter += (len1 - i) + (len2 - j);
    return counter <= d;
}


bool is_adjacent(const string& word1, const string& word2){
    return edit_distance_within(word1, word2, 1);
}


vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    queue<vector<string>> ladder_queue;
    ladder_queue.push({begin_word});

    set<string> visited;
    visited.insert(begin_word);

    while (!ladder_queue.empty()) {
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder.back();
        for (const string & word : word_list) {
            if (is_adjacent(last_word, word)) {
                if (!visited.contains(word)) {
                    visited.insert(word);
                    vector<string> new_ladder = ladder;
                    new_ladder.push_back(word);
                    if (word == end_word) {
                        return new_ladder;
                    }
                    ladder_queue.push(new_ladder);
                }
            }
        }
    }
    return {};
}

void load_words(set<string> & word_list, const string& file_name) {
    ifstream file(file_name);
    string word;
    while (file >> word) {
        word_list.insert(word);
    }
}

void print_word_ladder(const vector<string>& ladder) {
    if (ladder.empty()) {
        return;
    } else {
        for (size_t i = 0; i < ladder.size(); ++i) {
            cout << ladder[i];
            if (i < ladder.size() - 1) cout << " -> ";
        }
        cout << endl;
    }
}

void verify_word_ladder() {
    
}