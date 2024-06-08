//
// Created by tgk on 6/7/24.
//

#ifndef PAIR_H
#define PAIR_H

# include <string>
# include <iostream>


// pair of key and value
typedef struct Pair{
    std::string key;
    std::string value;
    Pair* pair;
}pair;

inline std::ostream& operator <<(std::ostream& os, Pair& pair){
    return os << " ["<< pair.key <<" : " <<pair.value<<"]";
}


#endif //PAIR_H
