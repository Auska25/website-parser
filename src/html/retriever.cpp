/*
 * html_retriever.cpp
 *
 *  Created on: 5 Jul 2015
 *      Author: karl
 */

#include <curlpp/cURLpp.hpp>
#include <curlpp/Options.hpp>

#include "parser_impl.hpp"
#include "retriever.hpp"

using namespace auska25::html;

using std::string;
using curlpp::options::Url;

std::unique_ptr<parser> retriever::get_from_url( const string& url) const
{
    auto html = std::unique_ptr<std::ostringstream>(new std::ostringstream);
    *html << Url(url);

    auto ret = std::unique_ptr<parser>(new parser_impl(html, url));

    return ret;
}
