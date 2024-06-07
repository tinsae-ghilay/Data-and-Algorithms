//
// Created by tgk on 6/7/24.
//

#ifndef PAIR_H
#define PAIR_H

# include <string>


// pair of key and value
typedef struct Pair{
    std::string key;
    std::string value;
    Pair* pair;
}pair;

#endif //PAIR_H
