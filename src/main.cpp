/**
 * Function Entry
 */

#include <memory>
#include <iostream>
#include "html/retriever.hpp"
#include "html/parser.hpp"
#include "config_cmdine.hpp"

using namespace auska25;

int main(int argc, char *argv[] )
{
    config_cmdline config(argc, argv);

    html::retriever retriever;

    auto parser = retriever.get_from_url(config.get_url());

    auto links = parser->get_links();

    for(auto&& i : links)
    {
        std::cout << i << std::endl;
    }

    return 0;
}
