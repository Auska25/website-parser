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
    std::string url("http://example.com");

    html::retriever retriever;

    auto parser = retriever.get_from_url(url);

    parser->dump(std::cout);

    return 0;
}
