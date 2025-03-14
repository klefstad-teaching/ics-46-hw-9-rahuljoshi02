#include "ladder.h"

int main() {
    set<string> word_list;
    load_words(word_list, "words.txt");

    set<string> word_vector(word_list.begin(), word_list.end());

    string begin_word = "hit";
    string end_word = "cog";

    vector<string> result = generate_word_ladder(begin_word, end_word, word_vector);

    if (!result.empty()) {
        print_word_ladder(result);
        verify_word_ladder();
    } else {
        cout << "No ladder found" << endl;
    }

    return 0;
}