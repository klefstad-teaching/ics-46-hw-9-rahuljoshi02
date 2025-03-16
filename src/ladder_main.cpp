#include "ladder.h"

int main() {
    cout << "Testing is_adjacent:\n";
    cout << "cat -> bat: " << is_adjacent("cat", "bat") << endl;
    cout << "cat -> cats: " << is_adjacent("cat", "cats") << endl;
    cout << "cat -> cut: " << is_adjacent("cat", "cut") << endl;
    cout << "cat -> dog: " << is_adjacent("cat", "dog") << endl;
    
    set<string> word_list;
    load_words(word_list, "src/words.txt");
    string start = "cat";
    string end = "dog";
    vector<string> ladder = generate_word_ladder(start, end, word_list);
    print_word_ladder(ladder);
    return 0;
}