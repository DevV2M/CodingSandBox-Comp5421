//
// Created by Vithu Maheswaran on 2022-07-27.
//

#include "assignment5.h"

WordsVector read_words_into_vector(const std::string &inFileName) {

    std::ifstream ifs(inFileName); // Create an input file stream
    if (!ifs.is_open()) {          // Check that the file is open
        cout << "Could not open file " + inFileName << endl;
        throw std::runtime_error("Could not open file " + inFileName);
    }

    WordsVector words_vector; // an empty vector

    std::copy(std::istream_iterator<std::string>(ifs),
              std::istream_iterator<std::string>(),
              std::back_inserter(words_vector));

    return words_vector;
}

WordsMap map_and_count_words_using_lambda(const WordsVector &wvec) {

    WordsMap wmap;
    std::for_each(wvec.begin(),
                  wvec.end(),
                  [&wmap](const std::string &s) {
                      wmap[s]++;
                  }); // lambda expression
    return wmap;
}

class WordCountFunctor {
public:
    WordsMap wmap;

    void operator()(const std::string &word) { wmap[word]++; }

    bool operator()(const std::string &word, int n) { return (word.length() == n); }

    WordsMap getmap() const { return wmap; }
};

WordsMap map_and_count_words_using_functor(const WordsVector &wvec) {
    WordCountFunctor wcf{};
    wcf = std::for_each(wvec.begin(), wvec.end(), wcf);
    return wcf.getmap();
}

WordsVector remove_duplicates(const WordsVector &words_vector) {
    // make a copy of the supplied words_vector
    WordsVector words_vec{words_vector};

    // 1- use std::sort to sort words_vec alphabetically
    // so that we can locate the duplicate words in it.
    std::sort(words_vec.begin(), words_vec.end());

    // 2- use std::unique to rearrange the words in the sorted words_vec
    // so that each word appears once in the front portion of words_vec.
    // store the returned iterator, which points to the element
    // immediately after all the unique elements in the front of words_vec.
    WordsVector::iterator last = std::unique(words_vec.begin(), words_vec.end());
    // 3- use std::vector's erase member function to erase the range of non-unique
    // words in words_vec, starting at the iterator stored in step 2 above
    // to the end of words_vec.
    words_vec.erase(last, words_vec.end());
    return words_vec;
}

bool is_alphabetic(const char &c) { return !isalpha(c); }

bool is_palindrome(const std::string &phrase) {

    string temp;
    // start iterator1, end iterator1, insert iterator, predicate insert if false
    std::remove_copy_if(phrase.begin(), phrase.end(), std::back_insert_iterator<string>(temp), is_alphabetic);

    // transform alpha to lower case
    std::transform(temp.begin(), temp.end(), temp.begin(),
                   [&](char &c) -> char { return static_cast<char>(tolower(c)); });

    // check if palindrome by iterating from each end and simultaneously comparing
    bool result = std::equal(temp.begin(), temp.begin() + (temp.size() / 2), temp.rbegin());

    return result;
}


size_t count_using_lambda(const std::vector<std::string> &vec, int n) {

    size_t count = std::count_if(vec.begin(), vec.end(), [n](const string &word) -> bool {
        if (word.length() == n) return true;
        else return false;
    });

    return count;
}

bool freeFunc(std::string word, int n){
    return (word.length() == n);
}

size_t count_using_Free_Func(const std::vector<std::string> &vec, int n) {

    size_t count = std::count_if(vec.begin(), vec.end(), std::bind(freeFunc,std::placeholders::_1, n));
    return count;

}

class countFunctor {
public:
    int n;

    countFunctor(int n) : n{n} {};

    bool operator()(const std::string &word) { return (word.length() == n); }

};

size_t count_using_Functor(const std::vector<std::string> &vec, int n) {
    countFunctor cf{n};
    size_t count = std::count_if(vec.begin(), vec.end(), cf);
    return count;
}

void multisetUsingMyComparator(const std::vector<std::string> &vec) {

}

void multisetUsingDefaultComparator(const std::vector<std::string> &vec) {

}

//std::vector<int> getnerate_Fibonacci(int n) {
//
//}
