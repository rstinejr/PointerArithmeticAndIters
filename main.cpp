#include <iostream>
#include <list>
#include <set>
#include <string>
#include <vector>

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

    std::cout << "my_list: " << std::endl;
    for (std::list<std::string>::iterator iter = my_list.begin(); iter != my_list.end(); ++iter)
    {
        std::cout << "\t" << *iter << std::endl;        
    }
    std::cout << std::endl;

    std::cout << "Initialize a set from my_list..." << std::endl;
    std::set<std::string> my_set(my_list.begin(), my_list.end());
    std::cout << "my_set:" << std::endl;
    for (std::set<std::string>::iterator sIter = my_set.begin(); sIter != my_set.end(); ++sIter)
    {
        std::cout << "\t" << *sIter << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Initialize a vector using the c++11 approach, vector<T> v {t1, t2}:" << std::endl;
    std::vector<std::string> my_vec {std::string("Good"), std::string("Golly"), std::string("Miss"), std::string("Molly")};
    std::cout << "my_vec:" << std::endl;
    for (std::vector<std::string>::iterator vIter = my_vec.begin(); vIter != my_vec.end(); ++vIter)
    {
        std::cout << "\t" << *vIter << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Done!" << std::endl;

	return 0;
}
