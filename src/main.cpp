/**
 * Function Entry
 */

#include <memory>
#include <iostream>
#include "html/retriever.hpp"
#include "html/parser.hpp"

using namespace auska25;

int main(int argc, char *argv[] )
{
    std::string url("http://stackoverflow.com/questions/6646405/how-do-you-add-boost-libraries-in-cmakelists-txt");

    html::retriever retriever;

    auto parser = retriever.get_from_url(url);

    auto links = parser->get_links();

    for(auto&& i : links)
    {
        std::cout << i << std::endl;
    }

    return 0;
}
