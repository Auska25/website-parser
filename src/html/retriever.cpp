/*
 * html_retriever.cpp
 *
 *  Created on: 5 Jul 2015
 *      Author: karl
 */

#include "retriever.hpp"

#include <curlpp/cURLpp.hpp>
#include <curlpp/Options.hpp>

using namespace auska25;

using std::string;
using std::cout;
using curlpp::options::Url;

html::retriever::retriever(string& url)
{
    cout << Url(url);
}



