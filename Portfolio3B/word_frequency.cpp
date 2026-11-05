
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <cctype>
#include <iomanip>

#include "../Portfolio3A/HashTable.h"
#include "../Portfolio3A/MinHeap.h"

struct WordCount {
    std::string word;
    int count;

    bool operator<(const WordCount& other) const {
        if (count != other.count) {
            return count > other.count;
        }

        return word < other.word;
    }
};

void addWord(
    const std::string& word,
    HashTable<std::string, int>& counts,
    std::unordered_map<std::string, int>& reference
) {
    if (word.empty()) {
        return;
    }

    int* existing = counts.find(word);

    if (existing != nullptr) {
        (*existing)++;
    }
    else {
        counts.insert(word, 1);
    }

    reference[word]++;
}

void processToken(
    const std::string& token,
    HashTable<std::string, int>& counts,
    std::unordered_map<std::string, int>& reference
) {
    std::string word;

    for (char ch : token) {
        unsigned char character = static_cast<unsigned char>(ch);

        if (std::isalpha(character)) {
            word += static_cast<char>(std::tolower(character));
        }
        else {
            addWord(word, counts, reference);
            word.clear();
        }
    }

    addWord(word, counts, reference);
}

int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cout << "Usage: ./word_frequency filename.txt\n";
        return 1;
    }

    std::ifstream file(argv[1]);

    if (!file) {
        std::cout << "\n";
        std::cout << "========================================\n";
        std::cout << "          WORD FREQUENCY ANALYZER       \n";
        std::cout << "========================================\n";
        std::cout << "Error: Could not open the file.\n";
        return 1;
    }

    HashTable<std::string, int> counts;
    std::unordered_map<std::string, int> reference;

    std::string token;

    while (file >> token) {
        processToken(token, counts, reference);
    }

    file.close();

    std::cout << "\n";
    std::cout << "========================================\n";
    std::cout << "          WORD FREQUENCY ANALYZER       \n";
    std::cout << "========================================\n";

    std::cout << "\nFile successfully processed!\n";
    std::cout << "Unique words found: " << counts.size() << "\n";

    // Compare custom HashTable results with unordered_map.
    bool passed = counts.size() == reference.size();

    for (const auto& entry : reference) {
        int* value = counts.find(entry.first);

        if (value == nullptr || *value != entry.second) {
            passed = false;
        }
    }

    std::cout << "\n--- HASH TABLE VERIFICATION ---\n";

    if (passed) {
        std::cout << "HashTable cross-check: PASS\n";
    }
    else {
        std::cout << "HashTable cross-check: FAIL\n";
    }

    // Use the custom MinHeap to find the top 10 words.
    MinHeap<WordCount> topWords;

    for (const auto& entry : reference) {
        WordCount item{entry.first, entry.second};
        topWords.insert(item);
    }

    std::cout << "\n";
    std::cout << "========================================\n";
    std::cout << "          TOP 10 MOST COMMON WORDS      \n";
    std::cout << "========================================\n";

    std::cout << std::left
              << std::setw(8) << "RANK"
              << std::setw(25) << "WORD"
              << "COUNT\n";

    std::cout << "----------------------------------------\n";

    int limit = 10;
    int rank = 1;

    while (!topWords.isEmpty() && limit > 0) {
        WordCount item = topWords.extractMin();

        std::cout << std::left
                  << std::setw(8) << rank
                  << std::setw(25) << item.word
                  << item.count << "\n";

        rank++;
        limit--;
    }

    std::cout << "========================================\n";

    return 0;
}
