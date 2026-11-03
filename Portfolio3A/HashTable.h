#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <vector>
#include <list>
#include <utility>
#include <string>
#include <functional>
#include <type_traits>
#include <cstddef>
#include <stdexcept>

template <typename K, typename V>
class HashTable {
private:
    using Entry = std::pair<K, V>;

    std::vector<std::list<Entry>> buckets;
    std::size_t entryCount;
    double maxLoadFactor;

    std::size_t hashKey(const K& key) const {
        if constexpr (std::is_same<K, std::string>::value) {
            std::size_t hash = 0;
            const std::size_t base = 31;

            for (unsigned char character : key) {
                hash = hash * base + character;
            }

            return hash;
        } else {
            return std::hash<K>{}(key);
        }
    }

    std::size_t bucketIndex(const K& key,
                            std::size_t bucketCount) const {
        return hashKey(key) % bucketCount;
    }

    void rehash(std::size_t newBucketCount) {
        std::vector<std::list<Entry>> newBuckets(newBucketCount);

        for (const auto& bucket : buckets) {
            for (const auto& entry : bucket) {
                std::size_t index =
                    bucketIndex(entry.first, newBucketCount);

                newBuckets[index].push_back(entry);
            }
        }

        buckets.swap(newBuckets);
    }

    void checkLoadFactor() {
        if (loadFactor() > maxLoadFactor) {
            rehash(buckets.size() * 2 + 1);
        }
    }

public:
    explicit HashTable(std::size_t initialBucketCount = 11,
                       double loadFactorLimit = 0.75)
        : buckets(initialBucketCount == 0 ? 1 : initialBucketCount),
          entryCount(0),
          maxLoadFactor(loadFactorLimit) {

        if (maxLoadFactor <= 0.0) {
            throw std::invalid_argument(
                "Maximum load factor must be positive");
        }
    }

    void insert(const K& key, const V& value) {
        std::size_t index = bucketIndex(key, buckets.size());

        for (auto& entry : buckets[index]) {
            if (entry.first == key) {
                entry.second = value;
                return;
            }
        }

        buckets[index].push_back(Entry(key, value));
        ++entryCount;

        checkLoadFactor();
    }

    V* find(const K& key) {
        std::size_t index = bucketIndex(key, buckets.size());

        for (auto& entry : buckets[index]) {
            if (entry.first == key) {
                return &entry.second;
            }
        }

        return nullptr;
    }

    const V* find(const K& key) const {
        std::size_t index = bucketIndex(key, buckets.size());

        for (const auto& entry : buckets[index]) {
            if (entry.first == key) {
                return &entry.second;
            }
        }

        return nullptr;
    }

    bool remove(const K& key) {
        std::size_t index = bucketIndex(key, buckets.size());

        for (auto it = buckets[index].begin();
             it != buckets[index].end(); ++it) {

            if (it->first == key) {
                buckets[index].erase(it);
                --entryCount;
                return true;
            }
        }

        return false;
    }

    std::size_t size() const {
        return entryCount;
    }

    bool isEmpty() const {
        return entryCount == 0;
    }

    double loadFactor() const {
        return static_cast<double>(entryCount) /
               static_cast<double>(buckets.size());
    }

    std::size_t bucketCount() const {
        return buckets.size();
    }
};

#endif
