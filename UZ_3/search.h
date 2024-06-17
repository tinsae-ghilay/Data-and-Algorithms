//
// Created by tgk on 6/8/24.
//

#ifndef SEARCH_H
#define SEARCH_H

# define SIZE 5000


class Search {
    private:
    int arr[SIZE];
    public:
    Search();
    unsigned long binarySearch(int item);
    unsigned long linearSearch(int item);

};



#endif //SEARCH_H
