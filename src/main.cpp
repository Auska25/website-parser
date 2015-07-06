/**
 * Function Entry
 */

#include <memory>
#include "html/retriever.hpp"

using namespace auska25;

int main(int argc, char *argv[] )
{
    std::string url("http://example.com");

    std::unique_ptr<html::retriever> retriever = std::unique_ptr<html::retriever>(new html::retriever(url));

    return 0;
}
