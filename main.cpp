#include <iostream>
#include <list>
#include <set>
#include <string>
#include <vector>

template <typename ITER>
void printColl(std::string nm, ITER start, ITER end)
{
    std::cout << nm.c_str() << ": " << std::endl;

    for (ITER iter = start; iter != end; ++iter)
    {
        std::cout << "\t" << *iter << std::endl;
    }

    std::cout << std::endl;
}

int main(int argc, char**argv)
{
    std::string empty_array[] = { };

    std::cout << "Note that an array element does not need to be allocated for sizeof() to work on it." << std::endl;
    std::cout << "E.g., sizeof(empty_array[1234]) = " << sizeof(empty_array[1234]) << ", but sizeof(empty_array) is " << sizeof(empty_array) << std::endl;
    std::cout << std::endl;

    std::string str_array[] =
        {
            std::string("mop"),
            std::string("bop"),
            std::string("a loo la"),
            std::string("mop"),
            std::string("bam"),
            std::string("boom!"),    // Comma after last element is optional.
        };

    const size_t cnt = sizeof(str_array) / sizeof(str_array[0]);

    std::cout << "Element count, str_array: "
    		  << cnt << std::endl;
    std::cout << "Address of str_array    : "
    		  << std::hex << str_array << std::endl;
    std::cout << "Value of str_array + "
    		  << cnt << "  : " << std::hex << str_array + cnt << std::endl;
    std::cout << "Value of &str_array["
    		  << cnt << "]  : " << std::hex << &str_array[cnt] << std::endl;
    std::cout << "Difference              : "
    		  << std::dec << (size_t) (str_array + cnt) - (size_t) str_array << std::endl;
    std::cout << std::endl;

    std::cout << "Now initialize list from an array of std::string." << std::endl;
    std::list<std::string> my_list(str_array, str_array + sizeof(str_array)/sizeof(str_array[0]));

    printColl<std::list<std::string>::iterator> ("my_list", my_list.begin(), my_list.end());

    std::cout << "Initialize a set from my_list..." << std::endl;
    std::set<std::string> my_set(my_list.begin(), my_list.end());

    printColl<std::set<std::string>::iterator>("my_set", my_set.begin(), my_set.end());

    std::cout << "Initialize a vector using the c++11 approach, vector<T> v {t1, t2}:" << std::endl;
    std::vector<std::string> my_vec {std::string("Good"), std::string("Golly"), std::string("Miss"), std::string("Molly")};

    printColl<std::vector<std::string>::iterator>("my_vec", my_vec.begin(), my_vec.end());

    std::cout << "Done!" << std::endl;

	return 0;
}
