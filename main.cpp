#include <iostream>
#include <list>
#include <string>

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


    std::cout << "Address of str_array  : " << std::hex << str_array << std::endl;
    std::cout << "Value of str_array + 6: " << std::hex << str_array + 6 << std::endl;
    std::cout << std::endl;

    std::cout << "Now intialize list with an array of std::string." << std::endl;
    std::list<std::string> my_list(str_array, str_array + sizeof(str_array)/sizeof(str_array[0]));

    std::cout << "my_list: " << std::endl;
    for (std::list<std::string>::iterator iter = my_list.begin(); iter != my_list.end();  ++iter)
    {
        std::cout << "\t" << *iter << std::endl;        
    }
    std::cout << std::endl;

    std::cout << "Done!" << std::endl;

	return 0;
}
